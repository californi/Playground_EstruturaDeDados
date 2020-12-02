#include <stdio.h>
#include <stdlib.h>

typedef struct tipo_no no;
void insere_inicio(int n, no *inicio);
void imprime(no *inicio);

struct tipo_no {
	int info;
	struct tipo_no *prox;
};

int main(int argc, char *argv[]) {
	no *reg = (no*)malloc(sizeof(no)); //aloca espaco para o novo noh
	reg->info = 1;
	reg->prox = NULL;
	
	insere_inicio(4, reg);
	insere_inicio(0, reg);
	insere_inicio(5, reg);
	insere_inicio(1, reg);
	
	imprime(reg);
	
	return 0;
}

void insere_inicio(int n, no *inicio){
	no* aux = (no*)malloc(sizeof(no)); //aloca espaco para o novo noh
	if(aux){  //conseguiu alocar espaço
		aux->info = n;
		aux->prox = inicio->prox;
		inicio->prox = aux;
	}
	else{
		printf("Heap overflow\n");
	}	
}

void imprime(no *inicio){
	while(inicio){  //enquanto houver lista
		printf("%d", inicio->info); //imprime o valor do NO
		inicio = inicio->prox;
	}
}
