#include <stdio.h> // puts, printf
#include <assert.h>
#include <string.h> // strlen
#include <stdlib.h> // malloc

#define false 0
#define true (!false)

/*
 * list_functions
 * get_function
 * delete_function
 */

struct function_description {
    void *func_ptr;
    char *name;
    char *args;
    char *returns;
    struct function_description *next;
};


struct kernel_ctx {
    char *name;
    struct function_description *first_function;
    struct function_description *last_function;
};


/*********************************************************************/


char*
alloc_string(const char const *s) {
    char *r = NULL;
    int sl = 0;

    assert(s != NULL);
    sl = strlen(s);

    r = malloc(sl + 1);
    assert(r != NULL);
    strncpy(r, s, sl+1);
    return r;
}


void
list_functions(struct kernel_ctx *ctx) {
    struct function_description *f = NULL;
    assert(ctx != NULL);
    f = ctx->first_function;
    fprintf(stderr, "listing functions:\n");
    while (f) {
        fprintf(stderr, "\titer: %p, %s(%s) -> %s\n", f, f->name, f->args, f->returns);
        f = f->next;
    }
    return;
}


struct function_description *
get_function(struct kernel_ctx *ctx, const char const *name) {
    struct function_description *f = NULL;
    assert(ctx != NULL);
    f = ctx->first_function;
    //fprintf(stderr, "searching for: '%s'\n", name);
    while (f) {
        //fprintf(stderr, "iter: %p, %s(%s) -> %s\n", f, f->name, f->args, f->returns);
        if (!strcmp(name, f->name)) {
            //fprintf(stderr, "found '%s'\n", f->name);
            return f;
        }
        f = f->next;
    }
    return NULL;
}


int
add_function(
        struct kernel_ctx *ctx,
        void *func_ptr,
        const char const *name,
        const char const *args,
        const char const *returns
        ) {
    struct function_description *f = NULL;

    assert(ctx != NULL);

    f = malloc(sizeof(struct function_description));
    assert(f != NULL);
    f->func_ptr = func_ptr;
    f->name = alloc_string(name);
    f->args = alloc_string(args);
    f->returns = alloc_string(returns);
    f->next = NULL;

    if (ctx->first_function == NULL) {
        ctx->first_function = f;
        ctx->last_function = f;
    } else {
        ctx->last_function->next = f;
    }

    return 0;
}




void
hello(void) {
    puts("hello");
}


void
bye(void) {
    puts("bye");
}

/*********************************************************************/

int
main(int argc, char **argv) {
    struct kernel_ctx kernel = {0};
    struct kernel_ctx *ctx = &kernel;
    int error = 0;
    struct function_description *f = NULL;
    void (*fp)(void) = NULL;

    puts("main");

    ctx->name = alloc_string("root");
    printf("context->name: '%s'\n", ctx->name);

    add_function(ctx, hello, "hello", "void", "void");
    add_function(ctx, bye, "bye", "void", "void");

    list_functions(ctx);

    f = get_function(ctx, "hello");
    assert(f != NULL);

    fp = f->func_ptr;
    assert(fp != NULL);
    fp();

    f = get_function(ctx, "bye");
    assert(f != NULL);

    fp = f->func_ptr;
    assert(fp != NULL);
    fp();

    puts("return");
    return 0;
}

