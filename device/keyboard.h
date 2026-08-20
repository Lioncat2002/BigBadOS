/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Keyboard driver.                                                          */
/*****************************************************************************/

#ifndef __Keyboard_include__
#define __Keyboard_include__

#include "../machine/keyctrl.h"
#include "../guard/gate.h"
#include "../machine/key.h"
 
class Keyboard:public Gate, public Keyboard_Controller
/* Add your code here */ 
{
	private:
	Key k;
public:
	Keyboard(const Keyboard &copy) = delete; // prevent copying
	Keyboard& operator=(const Keyboard&) = delete; // prevent assignment

	Keyboard(){}
/* Add your code here */ 
 
/* Add your code here */ 
 
	// PLUGIN: "Plugs in" the keyboard (driver). From now on, keypresses are handled.
	void plugin();

	//void trigger() override;
	bool prologue() override;
	void epilogue() override;
/* Add your code here */ 

};

extern Keyboard keyboard;

#endif
