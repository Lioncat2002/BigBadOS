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

#include "o_stream.h"

void O_Stream::set_base(Flags b) {
    flags &= ~(DEC | HEX | OCT | BIN); // clear all base flags
    flags |= b;                        // set new base
}

int O_Stream::get_base() const {
    if (flags & HEX) return 16;
    if (flags & OCT) return 8;
    if (flags & BIN) return 2;
    return 10;
}

void O_Stream::set_dec() {
    set_base(DEC);
}

void O_Stream::set_hex() {
    set_base(HEX);
}

void O_Stream::set_oct() {
    set_base(OCT);
}

void O_Stream::set_bin() {
    set_base(BIN);
}


void O_Stream::write_unsigned(unsigned long long value, int base)
{
    char tmp[64];
    int i = 0;
    const char* digits = "0123456789abcdef";

    if (base == 16) { put('0'); put('x'); }
    else if (base == 2) { put('0'); put('b'); }
    else if (base == 8) { put('0'); }

    if (value == 0) {
        put('0');
        return;
    }

    while (value > 0) {
        tmp[i++] = digits[value % base];
        value /= base;
    }

    while (i--) {
        put(tmp[i]);
    }
}

O_Stream& O_Stream::operator<<(void* pointer)
{
    unsigned long long addr = (unsigned long long)pointer;

    write_unsigned(addr, 16);

    return *this;
}


O_Stream& O_Stream::operator<<(unsigned char c){
    put(c);
    return *this;
};

O_Stream& O_Stream::operator<<(char c){
    put(c);
    return *this;
};

O_Stream& O_Stream::operator<<(unsigned short number) {
    write_unsigned(number, get_base());
    return *this;
}

O_Stream& O_Stream::operator<<(short number) {
    if (get_base() == 10 && number < 0) {
        put('-');
        write_unsigned((unsigned long long)(-number), 10);
    } else {
        write_unsigned((unsigned long long)(unsigned short)number, get_base());
    }
    return *this;
}


O_Stream& O_Stream::operator<<(unsigned int number) {
    write_unsigned(number, get_base());
    return *this;
}

O_Stream& O_Stream::operator<<(int number) {
    if (get_base() == 10 && number < 0) {
        put('-');
        write_unsigned((unsigned long long)(-number), 10);
    } else {
        write_unsigned((unsigned long long)(unsigned int)number, get_base());
    }
    return *this;
}

O_Stream& O_Stream::operator<<(unsigned long number) {
    write_unsigned(number, get_base());
    return *this;
}


O_Stream& O_Stream::operator<<(long number) {
    if (get_base() == 10 && number < 0) {
        put('-');
        write_unsigned((unsigned long long)(-number), 10);
    } else {
        write_unsigned((unsigned long long)(unsigned long)number, get_base());
    }
    return *this;
}

O_Stream& O_Stream::operator<<(const char* text) {
    if (!text) return *this;

    while (*text) {
        put(*text++);
    }
    return *this;
}

O_Stream& O_Stream::operator<<(O_Stream& (*fkt)(O_Stream&)) {
    return fkt(*this);
}

O_Stream& endl(O_Stream& os) {
    os << '\n';
    os.flush();
    return os;
}

O_Stream& hex(O_Stream& os) {
    os.set_hex();
    return os;
}

O_Stream& dec(O_Stream& os) {
    os.set_dec();
    return os;
}

O_Stream& oct(O_Stream& os) {
    os.set_oct();
    return os;
}

O_Stream& bin(O_Stream& os) {
    os.set_bin();
    return os;
}
