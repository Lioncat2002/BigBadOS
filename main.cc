#include "machine/cgascr.h"
#include "device/cgastr.h"
#include "machine/key.h"
#include "machine/keyctrl.h"

int main()
{
	screen.print("                    ", 20, 0x07);
	

	kout<<"HELIX OS 0.0.1"<<endl;
	kout << "Hello O_Stream!" << endl;
	kout << "Number: " << 42 << endl;
	kout << "Char test: " << 'A' << endl;

	kout << "Test          <stream result> -> <expected>" << endl;
	kout << "zero:         " << 0 << " -> 0" << endl;
	kout << "decimal:      " << dec << 42 << " -> 42" << endl;
	kout << "binary:       " << bin << 42 << dec << " -> 0b101010" << endl;
	kout << "octal:        " << oct << 42 << dec << " -> 052" << endl;
	kout << "hex:          " << hex << 42 << dec << " -> 0x2a" << endl;
	kout << "uint64_t max: " << ~((unsigned long)0) << " -> 18446744073709551615"
		<< endl;
	kout << "int64_t max:  " << ~(1l << 63) << " -> 9223372036854775807" << endl;
	kout << "int64_t min:  " << (1l << 63) << " -> -9223372036854775808" << endl;
	kout << "some int64_t: " << (-1234567890123456789)
		<< " -> -1234567890123456789" << endl;
	kout << "some int64_t: " << (1234567890123456789) << " -> 1234567890123456789"
		<< endl;
	kout << "pointer:      " << reinterpret_cast<void *>(1994473406541717165ul)
		<< " -> 0x1badcafefee1dead" << endl;
	kout << "smiley:       " << static_cast<char>(1) << endl;

	while (true) {
    Key k = keyboard.key_hit();
    if (k.valid()) {
      bool changed = false;
      

      if (changed) {
      } else if (k.ascii() != 0) {
        kout << k.ascii();
      }
      kout.flush();
    }
  }
	return 0;
}
