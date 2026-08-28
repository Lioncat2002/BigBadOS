/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             T H R E A D                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implements user interface of a thread.                                    */
/*****************************************************************************/

#ifndef __thread_include__
#define __thread_include__
#include "../thread/entrant.h"
/* Add your code here */ 
 
class Thread: public Entrant
/* Add your code here */ 
 
{
public:
	Thread(const Thread &copy) = delete; // prevent copying
	Thread& operator=(const Thread&) = delete; // prevent assignment
	Thread(void *tos):Entrant(tos){}
 
};

#endif
