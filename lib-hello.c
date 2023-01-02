#include <stdio.h>
#include <windows.h>

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


BOOL WINAPI DllMain(
        HINSTANCE hinstDLL,
        DWORD fdwReason,
        LPVOID lpvReserved )
{
    ;
    switch (fdwReason) {
        case DLL_PROCESS_ATTACH:
            puts("DllMain process attach");
            break;
        case DLL_THREAD_ATTACH:
            puts("DllMain thread attach");
            break;
        case DLL_THREAD_DETACH:
            puts("DllMain thread detach");
            break;
        case DLL_PROCESS_DETACH:
            puts("DllMain process detact");
            if (lpvReserved != NULL) {
                break;
            }
            puts("clean up");
            break;
    }
    return TRUE; // successful DLL_PROCESS ATTACH
}

