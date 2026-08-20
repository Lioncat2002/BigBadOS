/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              P L U G B O X                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Abstracts an interrupt vector table. Allows to configure handler routines */
/* for every hardware and software interrupt and every CPU exception.        */
/*****************************************************************************/

#ifndef __Plugbox_include__
#define __Plugbox_include__

#include "../guard/gate.h"
#include <cstddef>
#include "../device/panic.h"
class Plugbox {
public:
	Plugbox(const Plugbox &copy) = delete; // prevent copying
	Plugbox& operator=(const Plugbox&) = delete; // prevent assignment
	static const unsigned int timer = 32;
	static const unsigned int keyboard = 33;
	Plugbox(){
		for (size_t i=0;i<64;i++) {
			slots[i]=&panic;
		}
	}
	void assign(unsigned int slot, Gate &gate);
	Gate& report(unsigned int slot);
private:
	Gate *slots[64];
};

extern Plugbox plugbox;

#endif
