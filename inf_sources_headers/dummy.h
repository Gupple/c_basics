/* 03. Sources and Headers */

/* Header files usually contain any necessary declarations for
 * functions, variables, structs, etc. In general, C code only
 * includes header files, not source files. When a header file
 * is included, all declarations inside of the header file are 
 * visible.
 */

/* Here, we are simply declaring foo, bar, and baz. 
 * The first declaration declares foo to a function
 * taking no parameters and returning an int.
 * The second declaration declares a struct called bar.
 * Notice how we didn't define the struct, i.e. we didn't
 * supply any of the members of the struct.
 * The third declaration declares a global variable that 
 * is a pointer to a character called baz. 
 */
#ifndef DUMMY_H
#define DUMMY_H
int foo();
struct bar;
char *baz;
#endif
/* This #ifndef, #define, #endif block is called a header guard. You
 * wrap this around the contents of your header so that header files
 * are not included more than once, as that can cause errors. */
