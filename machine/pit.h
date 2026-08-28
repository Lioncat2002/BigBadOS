/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/

#ifndef __pit_include__
#define __pit_include__

class PIT {
public:
	PIT(const PIT &copy) = delete; // prevent copying
	PIT& operator=(const PIT&) = delete; // prevent assignment
	int us_interval;
public:
	PIT(int us) {
		interval (us);
	}
	int interval() {
		return us_interval;
	}
	void interval(int us);
};

#endif
