#include <stdio.h>

int main() {
	int x = 42;
	/* This declares y to be a pointer to an integer. Do not use
	 * uninitialized pointers! */
	int *y;

	/* This defines z to be a pointer to an integer that is storing the
	 * address of x. */
	int *z = &x;
	printf("%p\n", z);
	
	/* In order to get the value pointed to by a pointer, you need
         * to dereference the pointer: */
	printf("%d\n", *z);

	/* In order to set a value pointed to by a pointer, you need to
	 * dereference and assign a new value: */
	*z = 0;
	printf("This changes the value of x: %d\n", x);
}
