#include <stdio.h>

/* This declares a struct. Note how we haven't defined the struct
 * at all. */
struct foo;

/* This actually defines the struct. */
struct foo {
	int x;
	char c;
	float f;
	char *p;
};

/* We can typedef the struct as well, so that we don't 
 * need to write struct all the time. Opinions are split 
 * on whether you should do this. */
typedef struct foo foo_t;

int main() {
	/* This declares f to be a struct foo. */
	struct foo f;

	/* This initializes g using an initializer list. 
	 * Can only do this when declaring and initializing. */
	struct foo g = {42, 'c', 3.0, NULL};
	
	/* We can access the members like so. */
	printf("{%d, %c, %f, %p}\n", g.x, g.c, g.f, g.p);

	/* We can also change the values of the members using 
	 * dot notation. */
	f.x = 3;
	f.c = 'c';
	f.f = 34.8;
	f.p = &f.c;
	printf("{%d, %c, %f, %p}\n", f.x, f.c, f.f, f.p);

	/* When we have pointers to structs, the notation slightly
	 * changes. */
	struct foo *pf = &f;
	pf->x = 32;
	pf->c = 'a';
	printf("{%d, %c, %f, %p}\n", pf->x, pf->c, pf->f, pf->p);
	/* pf->x is essentially equivalent to (*pf).x */
}

