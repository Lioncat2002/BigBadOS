#include "machine/cpu.h"
#include "device/keyboard.h"
#include "user/appl.h"


int main()
{
	keyboard.plugin();
	cpu.enable_int();

	Application app;
	app.action();


	return 0;
}
