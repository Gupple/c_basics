/* 03. Strings */

#include <stdio.h>
#include <string.h>

int main() {
	/* C-style strings are pointers to char, with the additional
	 * caveat that the string is null-terminated. For example:
	 * char *str = "Hello"; is actually
	 * | 'H' | 'e' | 'l' | 'l' | 'o' | '\0' |
	 * ^
	 * |
	 * str
	 * -----------------------------------------------------*/

	/* Since C-style strings are character pointers, we can use
	 * regular pointer syntax to work with them. */
	/* str currently points to a string in static memory. Static
	 * strings are immutable. */
	char *str = "Hello!";
	printf("%c %c\n", str[3], *(str + 1));
	printf("%s\n", str + 1);

	/* It's a good idea to familiarize yourself with the basic functions
	* in string.h. This is because string.h functions work at the byte level
	* (a char is 1 byte). For example: */
	
	/* This is probably the fastest and cleanest way to 
	 * 0-initialize an array. */
	int arr[10];
	memset(arr, 0, sizeof(arr));

	/* Short hand for declaring a char array on the stack. */
	char hello[] = "Dennis Ritchie";
	
	/* memcpy does not care about null terminator. It will copy 6
	 * characters regardless of the content. */
	memcpy(hello, str, 6);
	printf("%s\n", hello);
	/* Make sure the strings you are working with are null-terminated.
	 * This is a very common source of bugs and can be somewhat nefarious
	 * to find. */

	/* CPP Reference is a good place to look at the string.h functions: 
	 * https://en.cppreference.com/w/cpp/header/cstring */
}

