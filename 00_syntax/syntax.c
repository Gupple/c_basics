/* 00. C Syntax Tour */

// Two styles of comments: Line comments and
/* Multi
 * line
 * comments. 
 */

/* To include a header file from the standard library, use <>. */
#include <stdio.h>
#include <assert.h>

/* Forward declaring a function */
void forward_declared(void);

/* Function definition */
void forward_declared() {
	printf("Hi there!\n");
}

/* Initialization, Assignment, Reassignment, Pre/Post Increment */
void initialization_assignment() {
	/* Definition of an uninitialized variable. Do not read from
	 * uninitialized variables! Make sure to always write to them
	 * first. */
	double y;

	/* Definition of an initialized variable */
	int x = 1 + 2;

	/* Reassignment */
	x = 5;

	/* Two types of increments: pre-increment and post-increment */
	int z = 0;
	assert(++z == 1);
	assert(z++ == 1);
	assert(z == 2);
}

/* Multiple Declarations */
void mult_declaration() {
	int x, y;
	long a = 5, b = 4;
	char c = 'a', d;
	short e, f = 6;
	char m = 'a', n, o = 'Z', p;
}

/* Conditionals */
void conditionals() {
	int x = 3;
	if (x == 1 + 2) { /* <-- Start of if-else block */
		printf("Welcome to 162!\n");
		x = 4;
	} else if (x == 4) {
		printf("This does not get reached.\n");
	} else {
		printf("How did we even get here?\n");
	} /* <-- End of if-else block */
	if (x == 4) { /* <-- Start of new block */
		printf("This gets reached, however.\n"); 
	} /* <-- End of new block */
}

/* Switch statements */
void switch_statement() {
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
}

/* Loops */
void loops() {
	/* A for loop has 3 parts. The first part is for initializing
	 * loop variables. The second part is the terminating condition.
	 * The third part is for advancing the loop variable. Note that
	 * for loops are not just limited to integers. */
	for (int i = 0; i < 16; ++i) {
		printf("%d ", i);
	}
	printf("\n");

	{
	int i = 0;
	/* Same exact loop, but while. Note how we had to introduce the
	 *  loop variable outside before using it in the body, however. */
	while (i != 16) {
		printf("%d ", i);
		++i;
	}
	printf("\n");
	}

	{
	/* Do while loops are slightly different, in that the body
	* is executed before the loop condition is checked. This guarantees
	* that the loop body is executed at least once. */
	int i = 0;
	do {
		printf("%d ", i);
		++i;
	} while (i < 0);
	printf("\n");
	printf("That executed once!\n");
	}
}

int main() {
	/* Function calls */
	forward_declared();
	initialization_assignment();
	mult_declaration();
	conditionals();
	switch_statement();
	loops();
}

