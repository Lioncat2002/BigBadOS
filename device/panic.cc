/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Default interrupt handler.                                                */
/*****************************************************************************/
/* Add your code here */ 
/* Add your code here */ 
#include "panic.h"
#include "../machine/cpu.h"
#include "cgastr.h"

bool Panic::prologue(){
	kout.setpos(0, 0);
	kout << "PANIC: Unexpected interrupt! System halted." << endl;
	kout.flush();
	cpu.halt();	
    return true;
}

Panic panic;