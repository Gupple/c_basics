#include <stdio.h>

/* We include dummy.h, which makes foo, bar, and baz available to us.
 * This makes foo and bar visible, and allocates space for baz on
 * compilation. */
#include "dummy.h"

int main() {
	baz = "Hello World!";
	printf("%s\n", baz);
	printf("%d\n", foo());
	printf("%s\n", baz);
}

