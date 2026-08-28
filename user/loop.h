/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 L O O P                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Loop is a thread that does nothing else but count upwards and print this  */
/* on the screen. In between, it yields the CPU. The Scheduler then decides  */
/* which thread shall run next.                                              */
/*****************************************************************************/

#ifndef __loop_include__
#define __loop_include__

#include "../syscall/thread.h"

class Loop : public Thread {
private:
	char stack[4096];
	int pos_x, pos_y;
	char id;
public:
	Loop(char id, int pos_x, int pos_y);
	void action();
};
 
#endif
