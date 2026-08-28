/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          S C H E D U L E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Scheduler implementation.                                                 */
/*****************************************************************************/

#ifndef __schedule_include__
#define __schedule_include__

#include "dispatch.h"
#include "entrant.h"
#include "../object/queue.h"
/* Add your code here */ 

class Scheduler:public Dispatcher
{
private:
	Queue ready_queue;
public:
	Scheduler (const Scheduler &copy) = delete; // prevent copying
	Scheduler& operator=(const Scheduler&) = delete; // prevent assignment

	Scheduler(){}

	void ready(Entrant &that);
	void schedule();
	void exit();
	void kill(Entrant &that);
	void resume();
 
};


#endif
