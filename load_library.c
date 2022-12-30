#include <stdio.h>
#include <windows.h>

typedef void (*func_ptr) (void);

HINSTANCE hinstDLL;
func_ptr HelloWorld;
int fFreeDLL;

int
main(int argc, char **argv)
{
    puts("hi");

    hinstDLL = LoadLibrary("lib-hello.dll");
    if (!hinstDLL) {
        puts("error");
        return 1;
    }

    HelloWorld = (func_ptr) GetProcAddress(hinstDLL, "say_hello");
    if (!HelloWorld) {
        puts("error");
        return 1;
    }

    HelloWorld();

    fFreeDLL = FreeLibrary(hinstDLL);

    puts("bye");
    return 0;
}

