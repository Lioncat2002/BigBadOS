/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            O _ S T R E A M                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The O_Stream class defines the << operator for several pre-defined data   */
/* types and thereby realizes output functionality similar to C++'s iostream */
/* library. By default, this class supports printing characters, strings and */
/* integer numbers of various bit sizes. Another << operator allows to use   */
/* so-called 'manipulators'.                                                 */
/*                                                                           */
/* Besides class O_Stream this file also defines the manipulators hex, dec,  */
/* oct and bin for choosing the basis in number representations, and endl    */
/* for implementing an (implicitly flushing) line termination.               */
/*****************************************************************************/

#ifndef __o_stream_include__
#define __o_stream_include__

#include "strbuf.h"

using Flags = unsigned int;

class O_Stream:public Stringbuffer
{
private:
    static constexpr Flags DEC = 0x01;
    static constexpr Flags HEX = 0x02;
    static constexpr Flags OCT = 0x04;
    static constexpr Flags BIN = 0x08;
    static constexpr Flags SHOWBASE = 0x10;

    Flags flags = DEC;

	int get_base() const;
	void set_base(Flags b);
	void write_unsigned(unsigned long long value,int base);

public:
	O_Stream() = default;

	virtual void flush()=0;
	void set_dec();
	void set_hex();
	void set_oct();
	void set_bin();

	Flags get_flags() const;

	O_Stream(const O_Stream &copy) = delete; // prevent copying
	O_Stream& operator=(const O_Stream&) = delete; // prevent assignment

	O_Stream& operator<<(void* pointer);
    O_Stream& operator<<(unsigned char c);
    O_Stream& operator<<(char c);

    O_Stream& operator<<(unsigned short number);
    O_Stream& operator<<(short number);
    O_Stream& operator<<(unsigned int number);
    O_Stream& operator<<(int number);
    O_Stream& operator<<(unsigned long number);
    O_Stream& operator<<(long number);

    O_Stream& operator<<(const char* text);
    O_Stream& operator<<(O_Stream& (*fkt)(O_Stream&));
/* Add your code here */ 
};

O_Stream& endl(O_Stream& os);
O_Stream& dec(O_Stream& os);
O_Stream& hex(O_Stream& os);
O_Stream& oct(O_Stream& os);
O_Stream& bin(O_Stream& os);

#endif
