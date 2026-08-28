/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/

/* Add your code here */ 
#include "pit.h"
#include "io_port.h"

void PIT::interval(int us){
	us_interval = us;
	unsigned short divisor = (1193182UL * us)/1000000;// 1,193,182 Hz is PIT input clk freq
							  // int every 1 ms
	IO_Port command(0x43);// PIT command reg
	IO_Port data(0x40);// data reg for channel 0 aka system timer of PIT

	command.outb(0x36); // channel 0 LSB/MSB mode 3
	data.outb(divisor & 0xff); // LSB
	data.outb(divisor >> 8); // MSB
}