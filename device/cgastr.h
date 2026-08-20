/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         C G A _ S T R E A M                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The CGA_Stream class allows to print different data types as text strings */
/* to a PC's CGA screen.                                                     */
/* For attributes/colors and cursor positioning use the methods of class     */
/* CGA_Screen.                                                               */
/*****************************************************************************/

#ifndef __cgastr_include__
#define __cgastr_include__

#include "../object/o_stream.h"
#include "../machine/cgascr.h"

class CGA_Stream: public O_Stream
/* Add your code here */ 
{
private:
	CGA_Screen screen;
public:
	CGA_Stream() = default;
	CGA_Stream(CGA_Stream &copy) = delete; // prevent copying
	CGA_Stream& operator=(const CGA_Stream&) = delete; // prevent assignment
    void flush() override;
    void setpos(int x, int y) { screen.setpos(x, y); }
    void getpos(int &x, int &y) { screen.getpos(x, y); }
};

extern CGA_Stream kout;

#endif
