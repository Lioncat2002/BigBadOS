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

#include "io_port.h"

class CGA_Screen {
private:
  /* Add your code here */
  volatile unsigned char *video; // 0xB8000
  int x;
  int y;
  int width;
  int height;
  IO_Port index_port;
  IO_Port data_port;

public:
  CGA_Screen(const CGA_Screen &copy) = delete;        // prevent copying
  CGA_Screen &operator=(const CGA_Screen &) = delete; // prevent assignment
  CGA_Screen()
      : video((unsigned char *)0xb8000), x(0), y(0), width(80), height(25),
        index_port(0x3d4), data_port(0x3d5) {}
  void show(int x, int y, char c, unsigned char attrib);
  void setpos(int x, int y);
  void getpos(int &x, int &y);
  void print(char *text, int length, unsigned char attrib);
  void scroll();
};

extern CGA_Screen screen;

#endif
