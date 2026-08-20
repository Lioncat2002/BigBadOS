/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               L O C K E R                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Locker class implements a lock that can be used to protect critical   */
/* sections. However, the variable only indicates whether the critical       */
/* section is free. Potentially necessary waiting, and protection for        */
/* counting functionality, must be implemented elsewhere.                    */
/*****************************************************************************/

#ifndef __Locker_include__
#define __Locker_include__
#include "../device/cgastr.h"
#include "../machine/cpu.h"
class Locker {
private:
	volatile bool locked;
public:
	Locker(const Locker &copy) = delete; // prevent copying
	Locker& operator=(const Locker&) = delete; // prevent assignment

	Locker(): locked(false){}

	void enter(){
		if (locked){
			kout<<"LOCK ERROR: DOUBLE enter()"<<endl;
			cpu.halt();
		}
		locked = true;
	}

	void retne(){
		if (!locked){
			kout<<"LOCK ERROR: DOUBLE retne()"<<endl;
			cpu.halt();
		}
		locked = false;
	}

	bool avail(){
		return !locked;
	}
};

#endif
