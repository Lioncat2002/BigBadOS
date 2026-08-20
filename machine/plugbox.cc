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

/* Add your code here */ 
#include "plugbox.h"

void Plugbox::assign(unsigned int slot, Gate &gate){
    if(slot<64){
        slots[slot] = &gate;
    }
}

Gate& Plugbox::report(unsigned int slot){
    return *slots[slot];
}

Plugbox plugbox;