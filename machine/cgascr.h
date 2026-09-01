#ifndef __screen_include__
#define __screen_include__

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

#include "../multiboot.h"
#include "io_port.h"
#include <stdint.h>
class FB_Screen {
private:
  /* Add your code here */
  volatile unsigned char *video; // 0xB8000
  int x;
  int y;
  int width;
  int height;
  uint32_t pitch;
  uint8_t bpp;

  IO_Port index_port;
  IO_Port data_port;

public:
  FB_Screen(const FB_Screen &copy) = delete;        // prevent copying
  FB_Screen &operator=(const FB_Screen &) = delete; // prevent assignment
  FB_Screen()
      : video(nullptr), x(0), y(0), width(0), height(0), pitch(0), bpp(0),
        index_port(0x3d4), data_port(0x3d5) {}
  void init(MultibootInfo *mbi);
  void show(int x, int y, char c, unsigned char attrib);
  void setpos(int x, int y);
  void getpos(int &x, int &y);
  void print(char *text, int length, unsigned char attrib);
  void scroll();

  void putpixel(int x, int y, uint32_t color);
  void clear(uint32_t color);
};

extern FB_Screen screen;

#endif
