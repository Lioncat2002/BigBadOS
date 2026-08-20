/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Keyboard driver.                                                          */
/*****************************************************************************/

/* Add your code here */ 
/* Add your code here */ 
 
#include "keyboard.h"
#include "../machine/plugbox.h"
#include "../machine/pic.h"
#include "cgastr.h"

void Keyboard::plugin(){
    plugbox.assign(Plugbox::keyboard, *this);
    pic.allow(PIC::keyboard);
}

bool Keyboard::prologue(){
    k = key_hit();
    if (k.valid()) {
		if (k.ctrl() && k.alt() && k.scancode() == Key::scan::del) {
			reboot();
		} //else if (k.ascii() != 0) {
		//	kout << k.ascii();
	//	kout.flush();
	//	}
	}

    return k.valid() && k.ascii()!=0;
}

void Keyboard::epilogue(){
    if(k.ascii()){
        kout << k.ascii();
        kout.flush();
    }
}


Keyboard keyboard;