#include <libtcc.h>
#include <stdio.h>

int dble(int n) {
    puts("double1");
    printf("got %x\n", n);
    puts("double2");
    return n * 2;
}

int main(void) {
    puts("hi");
    TCCState *tcc = tcc_new();
    tcc_set_output_type(tcc, TCC_OUTPUT_MEMORY);
    tcc_add_symbol(tcc, "dble", (void*)&dble);
    tcc_compile_string(tcc, "\
            #include <stdio.h>\n\
            int dble(int n);\n\
            int quad(int i) {\n\
                puts(\"quad\");\n\
                int j = dble(i) * 2;\n\
                puts(\"quad2\");\n\
                return j;\n\
                }");
    tcc_relocate(tcc, TCC_RELOCATE_AUTO);
    int (*quad)(int) = (void(*)())tcc_get_symbol(tcc, "quad");
    int r = quad(2);
    printf("r: %d\n", r);
    puts("bye");
}

