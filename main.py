from ctypes import cdll, c_double

my_library = cdll.LoadLibrary("libs/libmylib.so")

# Python assumes by default that every C function returns int

# We need to tell Python the return type of this function is double (c_double)
my_library.very_expensive_function.restype = c_double

# We need to tell Python the return type of this function is void (None)
my_library.print_hello.restype = None

# Now that loading is done, we can call our functions!

my_library.print_hello("Hi from Python!".encode())
# Note the `.encode()` at the end of the above string argument

super_pi = my_library.very_expensive_function(10)

print(f"Result from super expensive function: {super_pi}")