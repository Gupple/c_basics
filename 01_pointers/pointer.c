#include <stdio.h>
#include <stdlib.h>
int m = 56;

/* Declaring a Pointer */
void declaration() {
	int x = 42;
	/* This declares y to be a pointer to an integer. Do not use
	 * uninitialized pointers! */
	int *y;

	/* This defines z to be a pointer to an integer that is storing the
	 * address of x. */
	int *z = &x;
	printf("%p\n", z);
}

/* Dereferencing Basics */
void dereferencing() {
	int x = 42;
	int *z = &x;
	/* In order to get the value pointed to by a pointer, you need
         * to dereference the pointer: */
	printf("%d\n", *z);

	/* In order to set a value pointed to by a pointer, you need to
	 * dereference and assign a new value: */
	*z = 0;
	printf("This changes the value of x: %d\n", x);
}

/* Multiple Declaration with Pointers */
void mult_declaration() {
	/* The pitfalls of multiple declaration */
	/* x is a pointer to an int but y is an int, not a pointer to one. */
	int *x, y;

	/* Now a and b are both pointers to ints. */
	int *a, *b;
}

/* A pointer can point anywhere. */
void point_anywhere() {
	int y = 42;
	/* Currently, x is pointing to an address on the stack. */
	int *x = &y;
	
	/* Currently, x is pointing to an address on the heap. */
	x = malloc(16);
	free(x);
	/* Currently, x is pointing a freed region of heap memory. 
	 * This memory is no longer valid, so you cannot dereference
	 * it anymore! */
	
	/* Now, x is pointing to a region in static memory. This memory
	 * is valid for the lifetime of the program. */
	x = &m;
	*x = 42;

	/* x is now holding NULL, which is not a valid address. Dereferencing
	 * a NULL pointer is undefined behavior, but most implementations will
	 * give you a segmentation fault. */
	x = NULL;
	// *x; // DON'T!
}

int main() {
	declaration();
	dereferencing();
	mult_declaration();
	point_anywhere();
}

