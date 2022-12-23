#include <stdio.h>

__declspec(dllexport)
void
say_hello(void) {
    puts("hello");
}

