/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              W A T C H                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Handles timer interrupts by managing a time slice and triggering a        */
/* process switch if necessary.                                              */
/*****************************************************************************/

#include "watch.h"
#include "../machine/plugbox.h"
#include "../machine/pic.h"
#include "../syscall/guarded_scheduler.h"

void Watch::windup(){
    plugbox.assign(Plugbox::timer, *this);
    pic.allow(PIC::timer);
}


bool Watch::prologue(){
    return true;
}

void Watch::epilogue(){
    scheduler.Scheduler::resume();
}

Watch watch(100000);