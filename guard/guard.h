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

#ifndef __Guard_include__
#define __Guard_include__
#include "locker.h"
#include "gate.h"
#include "../object/queue.h"
/* Add your code here */ 

class Guard : public Locker {
private:
	Queue queue;
public:
	Guard (const Guard &copy) = delete; // prevent copying
	Guard& operator=(const Guard&) = delete; // prevent assignment
	Guard () {}

	void leave();
	void relay(Gate *gate);
/* Add your code here */ 
};

extern Guard guard;

#endif
