#include "device/cgastr.h"
#include "device/watch.h"
#include "machine/cpu.h"
#include "device/keyboard.h"
#include "multiboot.h"
#include "syscall/guarded_scheduler.h"
#include "user/app_loader.h"
#include "guard/guard.h"

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

	app_loader.start();

	guard.enter();
	scheduler.schedule();


	return 0;
}
