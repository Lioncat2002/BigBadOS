/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  G A T E                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Class of objects that handle interrupts.                                  */
/*****************************************************************************/

#ifndef __Gate_include__
#define __Gate_include__
#include "../object/chain.h"
class Gate : public Chain {

private:
  volatile bool in_queue;

public:
  virtual bool prologue()=0;
  virtual void epilogue() {}

  void queued(bool q) { in_queue = q; }

  bool is_queued() { return in_queue; }
};

#endif
