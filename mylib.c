// mylib.c
#include <stdio.h>
#include "mylib.h"

double very_expensive_function(int iterations) {
    double d = 1.0;

    for(int i = 0; i < iterations; ++i) {
        d *= 3.1415926535;
    }

    return d;
}

void print_hello(char *msg) {
    printf("Hello, but with: %s!\n", msg);
}