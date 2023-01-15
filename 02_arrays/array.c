/* 02. Arrays */

#include <stdio.h>

void pointer_decay_1(int arr[]) {
	printf("%lu\n", sizeof(arr));
	++arr;
}

void pointer_decay_2(int arr[10]) {
	printf("%lu\n", sizeof(arr));
	++arr;
}
int main() {
	/* This defines foo to be an int array of 10 elements. 
	*  Since the array has not been written to, the contents
	*  it stores are indeterminate. */
	int foo[10];

	/* This explicitly initializes the array using an initializer list. */
	char bar[] = {'H', 'e', 'l', 'l', 'o', '\0'};

	/* You can have arrays of more complicated types as well. */
	int grid[8][8];
	char* strings[20];
	struct data {
		int i;
		float j;
	};
	struct data all_info[100];

	/* In order to get and set elements from an array, you can use 
	 * two different notations. */
	printf("%c %c\n", bar[0], *bar);
	printf("%c %c\n", bar[1], *(bar + 1));

	/* In general, arr[i] == *(arr + i). */

	for (int i = 0; i < 10; ++i) {
		foo[i] = i;
	}
	/* Array to pointer decay: When an array when assigned to 
	 * a pointer type. */
	int *p = foo;

	/* You can still do much of the same things with pointers. */
	printf("%d, %d\n", p[3], foo[7]);
	p[5] = 42;

	/* However, p loses information about its dimensionality. */
	printf("%lu %lu\n", sizeof(p), sizeof(foo));
	/* sizeof(p) will print the size needed to store a pointer,
	 * typically 4 or 8 depending on your system. However, sizeof(foo) will
	 * equal the number of elements * the size of each element, which in this
	 * case, is 40. */

	/* Additionally, pointers are not reassignable. You cannot change the 
	 * value of foo once defined, only the contents of foo. Pointers, on 
	 * the other hand,are reassignable as long as the pointer is not 
	 * constant. */
	p = p + 1;
	for (int i = 0; i < 9; ++i) {
		printf("%d ", p[i]);
	}
	printf("\n");

	/* In both of these function signatures, the type system will not
	 * deduce that the formal parameter, arr, is an array. arr is still
	 * very much a pointer. */
	pointer_decay_1(foo);
	pointer_decay_2(foo);
}
