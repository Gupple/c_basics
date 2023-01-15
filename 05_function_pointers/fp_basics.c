/* 05. Function Pointers */

#include <stdio.h>

int x = 0;

void func_one(int a, char b) {
	printf("%d %c\n", a, b);
}
int func_two() {
	return 4;
}

int main() {
	/* Function pointers have a somewhat tricky syntax. */
	/* This declares foo to be a function pointer that takes in
	 * an int and a char (in that order) and returns nothing. */
	void (*foo) (int, char); 

	/* This declares bar as a function pointer taking in nothing
	* and returning an int. */
	int (*bar) (void);

	/* This declares baz as a function taking in nothing and returning
	 * nothing. */
	void (*baz) (void);

	/* You can assign functions to function pointers. */
	foo = func_one;
	bar = func_two;

	/* You can call function pointers like regular functions. */
	foo(1, 'c');
	printf("%d\n", bar());
	
	/* Infinite loop! */
	/* int (*for_demo_purposes) (void) = main;
	 * printf("%d ", x++);
	 * foo(); */
}

