/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I C                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interrupt Controller.                                        */
/* By using the PIC, hardware interrupts can be enabled or suppressed        */
/* individually. This way we can control whether interrupts of a specific    */
/* device are forwarded to the CPU at all. Even then, the interrupt handler  */
/* gets only activated if the CPU is ready to react to interrupts. This can  */
/* be controlled by using class CPU.                                         */
/*****************************************************************************/

/* Add your code here */
#include "pic.h"

void PIC::allow(int interrupt_device) {
  if (interrupt_device < 8) {
    unsigned char mask = master_mask.inb();
    mask &= ~(1 << interrupt_device);
    master_mask.outb(mask);
  } else {
    unsigned char mask = slave_mask.inb();
    mask &= ~(1 << (interrupt_device-8));
    slave_mask.outb(mask);
  }
}

void PIC::forbid(int interrupt_device) {
  if (interrupt_device < 8) {
    unsigned char mask = master_mask.inb();
    mask |= ~(1 << interrupt_device);
    master_mask.outb(mask);
  } else {
    unsigned char mask = slave_mask.inb();
    mask |= ~(1 << (interrupt_device-8));
    slave_mask.outb(mask);
  }
}

bool PIC::is_masked(int interrupt_device){
    if (interrupt_device < 8) {
		return (master_mask.inb() & (1 << interrupt_device)) != 0;
	} else {
		return (slave_mask.inb() & (1 << (interrupt_device - 8))) != 0;
	}
}

PIC pic;