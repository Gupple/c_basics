/* Here, we can actually give definitions to what we declared in
 * the header file. You might be wondering why we don't include
 * dummy.h in this file. This is because the header file and this
 * source file serve two purposes: The header file declares functions
 * and objects, and the source file defines them. */

/* Let's take this program for example. We have dummy.h, dummy.c, and
 * sources_headers.c. We included dummy.h in sources_headers.c, so it 
 * receives all of the definitions in the header file. This allocates 
 * space for variables and lets the compiler know that the things 
 * declared (i.e. functions and structs) exist. Then we compile dummy.c 
 * which contains the actual definition of the things in the header file.
 * Finally, we link the two object files which glues the two object files
 * together to form an executable. */

/* We use the extern keyword here because we know that baz
 * lives somewhere else and we need to tell the compiler that
 * the location of baz will be resolved upon linking. */
extern char *baz;
int foo() {
	baz = "CS 162 is awesome";
	return 42;
}

struct bar {
	int x;
	char c;
	float f;
	double *d;
};

