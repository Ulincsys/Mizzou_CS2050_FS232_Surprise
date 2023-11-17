# Library examples

This repo contains examples of compiling, linking, and loading C libraries in both C and Python.

## Building in C

The provided makefile defines three targets for building, as a way to demonstrate each method of linking.

* `make main-static`
  * Compile main.c and mylib.c and link statically
* `make main-shared`
  * Compile main.c and mylib.c and link as shared library
* `make main-dynamic`
  * Compile dyn_main.c and mylib.c, and do not link

## Running in C

For the `main-static` and `main-dynamic` build targets, you can simply run the resulting executable with:

```bash
./a.out
```

However, the `main-shared` target requires you to add the libs folder to the `LD_LIBRARY_PATH`, a la:

```bash
LD_LIBRARY_PATH=libs:$LD_LIBRARY_PATH ./a.out
```

The `LD_LIBRARY_PATH` variable tells the shared object loader where to find library files on startup. By default, programs will look in your system library folders (IE: `/usr/lib` on Linux) first, and then wherever you tell them to after.