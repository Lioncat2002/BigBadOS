/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                G U A R D                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Using this class, we can synchronize activities with a critical section   */
/* with interrupt handlers that also access this critical section. This      */
/* synchronization takes place along the prologue/epilogue model.            */
/*****************************************************************************/

/* Add your code here */ 
#include "guard.h"
#include "../machine/cpu.h"

void Guard::relay(Gate *gate){
    cpu.disable_int();

    if(avail()){
        enter();
        gate->queued(true);
        cpu.enable_int();
        gate->epilogue();
        cpu.disable_int();
        leave();
        cpu.enable_int();
    }else{
        if(!gate->is_queued()){
            gate->queued(true);
            queue.enqueue(gate);
        }
        cpu.enable_int();
    }
}


void Guard::leave(){
    cpu.disable_int();
	Gate *gate;
	while((gate = (Gate*)queue.dequeue())){
		gate->queued(false);
		cpu.enable_int();
		gate->epilogue();
		cpu.disable_int();
	}
	retne();
	cpu.enable_int();
}


Guard guard;