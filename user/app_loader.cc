#include "app_loader.h"
#include "../syscall/guarded_scheduler.h"
#include "appl.h"
#include "loop.h"

static char app_stack[4096];
Application app(&app_stack[4096]);

Loop loop1('A',0,20);
Loop loop2('B', 40, 20);

void ApplicationLoader::start()
{
    scheduler.ready(app);
    scheduler.ready(loop1);
    scheduler.ready(loop2);
}

ApplicationLoader app_loader;