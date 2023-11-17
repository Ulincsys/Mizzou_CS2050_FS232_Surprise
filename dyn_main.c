#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

// Notice the lack of #include "mylib.h"

int main() {
    // Dynamically load our shared library file
    void *my_library = dlopen("libs/libmylib.so", RTLD_LAZY);
    // The RTLD_LAZY flag tells the loader to only load symbols when needed

    if(!my_library) {
        puts("ERROR: Could not load library file");
        return EXIT_FAILURE;
    }

    // Create a function pointer of type "void fn(char *)"
    void (*library_print)(char *);
    /* Notice that our function pointer (library_print)
       doesn't need to have the same name as the symbol
       we're loading (print_hello in this case).
    */

   /* Note that the general syntax for a function pointer type in C is:
        RETURN_TYPE (*VARIABLE_NAME)(PARAMETER_LIST)
      
      So, for instance, the definition of a pointer to:
        float do_stuff(int a, void *b);

      would be:
        float (*fn_ptr)(int, void *);
   */

   // Ask the loader to locate and return the `print_hello` symbol
   library_print = dlsym(my_library, "print_hello");
   /* Note that the ISO Standard dictates that you cannot implicitly
      assign a void pointer to a function pointer. I have chosen to
      disable Wpedantic here, since GNU C allows you to do so.

      With -Wpedantic enabled, we would instead need to do:
      "library_print = (void (*)(char *))dlsym(...);"
   */

   // Call our dynamically loaded function!
   library_print("Hi from dynamic main!");
}
