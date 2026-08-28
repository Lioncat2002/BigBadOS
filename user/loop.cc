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
#include "loop.h"
#include <cstdint>
#include "../guard/secure.h"
#include "../thread/scheduler.h"

Loop::Loop(char id, int pos_x, int pos_y)
    : Entrant(&stack), id(id), pos_x(pos_x), pos_y(pos_y) {}

void Loop::action() {
  for (int i = 0; i < INT64_MAX; i++) {
    {
      Secure secure;
      int x, y;
      kout.getpos(x, y);
      kout.setpos(pos_x, pos_y);
      kout << id << ": " << i << "  ";
      kout.flush();
      kout.setpos(x, y);
    }
    scheduler.schedule();
  }
}