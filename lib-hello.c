#include <stdio.h>

#define DLLExport __declspec(dllexport)

DLLExport
void
say_hello(void) {
    puts("hello");
}


DLLExport
int
double_int(int n) {
    return n * 2;
}

DLLExport
float
double_float(float n) {
    return n * 2;
}

