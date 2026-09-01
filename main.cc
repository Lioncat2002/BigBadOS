#include "device/cgastr.h"
#include "device/watch.h"
#include "machine/cpu.h"
#include "device/keyboard.h"
#include "multiboot.h"
#include "syscall/guarded_scheduler.h"
#include "user/appl.h"
#include "user/loop.h"
#include "guard/guard.h"

static char app_stack[4096];
Application app(&app_stack[4096]);

Loop loop1('A',0,20);
Loop loop2('B', 40, 20);

void putpixel(MultibootInfo *mbi, int x, int y, uint32_t color)
{
    uint8_t *fb =
        reinterpret_cast<uint8_t *>(mbi->framebuffer_addr);

    uint32_t *pixel =
        reinterpret_cast<uint32_t *>(
            fb + y * mbi->framebuffer_pitch + x * 4
        );

    *pixel = color;
}

extern "C" int kmain(MultibootInfo *mbi)
{
	kout.init(mbi);
	keyboard.plugin();
	watch.windup();

	cpu.enable_int();

	scheduler.ready(app);
	scheduler.ready(loop1);
	scheduler.ready(loop2);
	guard.enter();
	scheduler.schedule();


	return 0;
}
