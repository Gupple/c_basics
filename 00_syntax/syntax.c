/* 00. C Syntax Tour */

/* To include a header file from the standard library, use <>. */
#include <stdio.h>

/* This defines the main method of this file. This is the entrypoint into
 * the program, i.e. the first function that will be ran when this program
 * starts executing. The return type of main is an int, which is commonly
 * interpreted as a status code. This is useful when we want to report any 
 * type of error that occurred during the execution of this program, or lack
 * thereof. The input parameter argv is the array of arguments we passed 
 * in, and argc is the number of arguments passed in. For example, if the 
 * executable is called "executable", and we ran it on the command line as
 * ./executable 5 abc hello, then argv will look like
 * {"./executable", "5", "abc", "hello", NULL}, and argc will be 4. Note how 
 * the first argument is the path of the executable running, how all of the 
 * arguments are strings, and how argv[argc] is NULL. */

/* If you do not care about the passed in arguments, you can also declare
 * main as int main() {...} */
int main(int argc, char **argv) {
	/* This declares a variable of type double called y. Note how 
	 * we didn't initialize it. Do not read from uninitialized 
	 * variables! Make sure to always write to them first. */
	double y;

	/* This defines a variable of type int called x that stores 
	 * the result of the computation of 1 + 2. */
	int x = 1 + 2;

	/* This is how you call a function, in particular, printf will
	 * print the arguments using the passed-in formatted string, which
	 * in this case, is 3. */
	printf("%d\n", x);

	/* Two types of increments: pre-increment and post-increment.
	 */
	int z = 0;
	printf("A pre-increment increments first and then returns the value:");
	printf(" %d\n", ++z);
	printf("A post-increment increments the value but returns the value");
	printf(" before incrementing: %d\n", z++);
	printf("This variable did get incremented, though: %d\n", z);

	// Two styles of comments: Line comments and
	/* Multi-line comments. */

	/* Conditionals */
	if (x == 1 + 2) {
		printf("Welcome to 162!\n");
	} else if (x == 4) {
		printf("Something else.\n");
	} else {
		printf("How did we even get here?\n");
	}

	/* Switch statements */
	char c = 'c';
	printf("Make sure to break out of your cases!\n");
	switch (c) {
		case 'a':
			printf("Why?\n");
		break;
		case 'c':
			printf("Otherwise you will ");
		case 'b':
			printf("fall through!\n");
		break;
		default:
			printf("This is your catch-all case.\n");
		break;
	}

	/* Conditionals */
	/* A for loop has 3 parts. The first part is for initializing
	 * loop variables. The second part is the terminating condition.
         * The third part is for advancing the loop variable. Note how
	 * this is not just limited to integers. */
	for (int i = 0; i < 16; ++i) {
		printf("%d ", i);
	}
	printf("\n");

	int i = 0;
	/* Same exact loop, but while. */
	while (i != 16) {
		printf("%d ", i);
		++i;
	}
	printf("\n");

	/* Do while loops are slightly different, in that the body
	 * is executed before the loop condition is checked. This guarantees
	 * that the loop body is executed at least once. */
	i = 0;
	do {
		printf("%d ", i);
		++i;
	} while (i < 0);
	printf("\nThat executed once!\n");
}

