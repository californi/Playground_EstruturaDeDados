#include <stdio.h>
#include <stdlib.h>

char *s;
int *r;
char *t;
int *z;

main() {
	s = (char*)malloc(2000);
	r = (int*)malloc(40*sizeof(int));
	t = (char*)malloc(800);
	z = (int*)calloc(100, sizeof(int));
	t = (char*)realloc(t,1000);
	t = (char*)malloc(2000);
}
