/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             C G A _ S C R E E N                           */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* This class allows accessing the PC's screen.  Accesses work directly on   */
/* the hardware level, i.e. via the video memory and the graphic adapter's   */
/* I/O ports.                                                                */
/*****************************************************************************/

#include "cgascr.h"
#include "../multiboot.h"
#include "font.h"

void CGA_Screen::init(MultibootInfo *mbi) {
  if (!(mbi->flags & (1 << 12))) {
    return;
  }

  video = (uint8_t *)mbi->framebuffer_addr;
  pitch = mbi->framebuffer_pitch;
  width = mbi->framebuffer_width;
  height = mbi->framebuffer_height;
  bpp = mbi->framebuffer_bpp;

  x = 0;
  y = 0;
}

void CGA_Screen::putpixel(int x, int y, uint32_t color)
{
    if (!video)
        return;

    if (x < 0 || y < 0)
        return;

    if (x >= (int)width || y >= (int)height)
        return;

    uint32_t *pixel =
        (uint32_t *)(video + y * pitch + x * 4);

    *pixel = color;
}

void CGA_Screen::show(
    int x,
    int y,
    char c,
    unsigned char attrib)
{
    if (c < 0 || c >= 128)
        return;

    const uint8_t *glyph =
        font8x8[(unsigned char)c];

    uint32_t fg = 0x00FFFFFF;
    uint32_t bg = 0x00000000;

    int px = x * 8;
    int py = y * 8;

    for (int row = 0; row < 8; row++) {

        for (int col = 0; col < 8; col++) {

            uint32_t color;

            if (glyph[row] & (1 << (7 - col)))
                color = fg;
            else
                color = bg;

            putpixel(px + col, py + row, color);
        }
    }
}

void CGA_Screen::setpos(int x, int y) {
  this->x = x;
  this->y = y;

  int pos = y * 80 + x;

  // Set low byte
  index_port.outb(15);
  data_port.outb(pos & 0xff);

  // Set high byte
  index_port.outb(14);
  data_port.outb((pos >> 8) & 0xff);
}

void CGA_Screen::getpos(int &x, int &y) {
  x = this->x;
  y = this->y;
}

void CGA_Screen::print(char *text, int length, unsigned char attrib) {

  for (int i = 0; i < length; i++) {
    char c = text[i];

    if (c == '\n') {
      x = 0;
      y++;
    } else if (c == '\r') {
      x = 0; // Support for CRLF line endings
    } else {
      show(x, y, text[i], attrib);
      x++;
    }
    if (x >= width) {
      x = 0;
      y++;
    }

    if (y >= height) {
      scroll();
      y = height - 1;
    }
  }
  setpos(x, y);
}

void CGA_Screen::scroll() {
  int row = width * 2;

  for (int y = 1; y < height; y++) {
    for (int x = 0; x < row; x++) {
      video[(y - 1) * row + x] = video[y * row + x];
    }
  }

  int last_row = (height - 1) * row;

  for (int x = 0; x < width; x++) {
    video[last_row + x * 2] = ' ';
    video[last_row + x * 2 + 1] = 0x07;
  }
}

CGA_Screen screen;