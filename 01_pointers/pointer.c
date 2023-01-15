/* 01. Pointers */

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

/* Pointer Arithmetic */
void pointer_arithmetic() {
	/* This defines p to be a pointer pointing to the heap
	 * and having enough space to store 10 ints. It looks something
	 * like this:
	 * | int | int | int | int | int | int | int | int | int | int |
	 * ^
	 * |
	 * p
	 * -----------------------------------------------------------*/
	int *p = malloc(sizeof(int) * 10);

	/* You can add or subtract integers from pointers to get 
	 * another pointer. */
	printf("%p, %p, %p\n", p - 1, p, p + 1);
	/* Notice how the difference between p - 1 and p is 4, and p and
	 * p + 1 is also 4. This is because adding an integer i gives us 
	 * a pointer that is p + i * sizeof(type being pointed to). */

	/* You can access elements using two different notations. */
	printf("%d %d\n", p[5], *(p + 3));

	/* We can reassign pointers if they are not constant. */
	p = p + 5;
	/* | int | int | int | int | int | int | int | int | int | int |
	 *                               ^
	 *                               |
	 *                               p is now here.
	 * -----------------------------------------------------------*/
	free(p - 5);
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
	pointer_arithmetic();
	mult_declaration();
	point_anywhere();
}

