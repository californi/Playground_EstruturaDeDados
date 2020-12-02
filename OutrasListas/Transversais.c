#include <stdio.h>
#include <stdlib.h>

typedef struct tipo_no2 no2;

struct tipo_no2{
	char nome[20];
	struct tipo_no2 *p;
	struct tipo_no2 *next;
};

int main(int argc, char *argv[]) {

	no2 * FAVORITAS = NULL;
	
	return 0;
}

