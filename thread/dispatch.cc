/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          D I S P A T C H E R                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Dispatcher implementation.                                                */
/* The Dispatcher maintains the life pointer that points to the currently    */
/* active coroutine. go() initializes the life pointer and starts the first  */
/* coroutine, all further context switches are triggered by dispatch().      */
/* active() returns the life pointer.                                        */
/*****************************************************************************/

#include "dispatch.h"
#include "coroutine.h"

void Dispatcher::go(Coroutine &first){
    life = &first;
    first.go();
}

void Dispatcher::dispatch(Coroutine &next){
    Coroutine *previous = life;
    life = &next;
    previous->resume(next);
}

Coroutine* Dispatcher::active() {
	return life;
}