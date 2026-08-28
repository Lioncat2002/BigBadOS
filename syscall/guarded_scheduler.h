/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                   G U A R D E D _ S C H E D U L E R                       */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implements the system-call interface to the Scheduler.                    */
/*****************************************************************************/

#ifndef __guarded_scheduler_include__
#define __guarded_scheduler_include__

#include "thread.h"
#include "../thread/scheduler.h"

class Guarded_Scheduler:public Scheduler
/* Add your code here */ 
{
public:
	Guarded_Scheduler(const Guarded_Scheduler &copy) = delete; // prevent copying
	Guarded_Scheduler& operator=(const Guarded_Scheduler&) = delete; // prevent assignment
	Guarded_Scheduler () {}

	void ready(Thread &that);
	void exit();
	void kill(Thread &that);
	void resume(); 
};

extern Guarded_Scheduler scheduler;

#endif
