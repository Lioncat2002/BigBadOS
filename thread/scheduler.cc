/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          S C H E D U L E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Scheduler implementation.                                                 */
/*****************************************************************************/

#include "scheduler.h"
#include "../machine/cpu.h"
#include "entrant.h"


void Scheduler::ready(Entrant &that){
    ready_queue.enqueue(&that);
}

void Scheduler::schedule(){
    Entrant *next = (Entrant*)ready_queue.dequeue();
    if(next){
        Entrant *current = (Entrant*)active();
        if(current){
            ready_queue.enqueue(current);
        }
        dispatch(*next);
    }
}

void Scheduler::exit(){
    Entrant *next = (Entrant*)ready_queue.dequeue();
    if(next){
        dispatch(*next);
    }else{
        cpu.disable_int();
        while(true){
            cpu.halt();
        }
    }
}

void Scheduler::kill(Entrant &that){
    if(active()==&that){
        exit();
    }else{
        ready_queue.remove(&that);
    }
}

void Scheduler::resume() {
	Entrant* next = (Entrant*)ready_queue.dequeue();
	if (next) {
		go(*next);
	}
}

Scheduler scheduler;