#include "machine/cpu.h"
#include "device/keyboard.h"
#include "syscall/guarded_scheduler.h"
#include "user/appl.h"
#include "user/loop.h"

static char app_stack[4096];
Application app(&app_stack[4096]);

Loop loop1('A',0,20);
Loop loop2('B', 40, 20);

int main()
{
	keyboard.plugin();
	cpu.enable_int();

	scheduler.ready(app);
	scheduler.ready(loop1);
	scheduler.ready(loop2);

	scheduler.resume();


	return 0;
}
