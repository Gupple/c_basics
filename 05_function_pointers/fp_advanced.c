/* 05. Function Pointers */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool compare_less(int a, int b) {
	return a < b;
}

bool compare_more(int a, int b) {
	return a > b;
}

/* A not so efficient merge sort. Note how it takes a custom
 * comparator function. */
void sort(int *arr, size_t size, bool (*cmp) (int, int)) {
	if (size <= 1) {
		return;
	}

	if (size == 2) {
		if (!cmp(arr[0], arr[1])) {
			int temp = arr[0];
			arr[0] = arr[1];
			arr[1] = temp;
		}
		return;
	}

	int pivot = size / 2;
	sort(arr, pivot, cmp);
	sort(arr + pivot, size - pivot, cmp);

	int first = 0;
	int second = pivot;
	int index = 0;
	while (first != pivot && second != size) {
		if (cmp(arr[first], arr[second])) {
			arr[index] = arr[first];
			++index;
			++first;
		} else {
			int val = arr[second];
			memmove(arr + first + 1, 
	                 arr + first, 
			 (second - first) * sizeof(int));
			arr[index] = val;
			++index;
			++first;
			++second;
			++pivot;
		}
	}
}
int main() {
	int values[] = {1, 5, 40, -37, 100, -52, 25, 175, 162, 89};
	sort(values, sizeof(values) / sizeof(int), compare_less);
	for (int i = 0; i < sizeof(values) / sizeof(int); ++i) {
		printf("%d ", values[i]);
	}
	printf("\n");
	sort(values, sizeof(values) / sizeof(int), compare_more);
	for (int i = 0; i < sizeof(values) / sizeof(int); ++i) {
		printf("%d ", values[i]);
	}
	printf("\n");
}

