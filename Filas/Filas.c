#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct fila fila;

void inserir(struct fila *f, int valor);
int consumir(struct fila *f);
void imprimir(struct fila f);

struct fila{
	int dados[TAM];
	int inicio;
	int fim;
};

void main() {
	
	int valor = -1; //variavel que recebera o valor consumido
	struct fila f;
	f.inicio = 0;
	f.fim = -1;
	
	int i;
	for(i = 0; i < TAM; i++){
		f.dados[i] = -1;
	}
	
	valor = consumir(&f);
	imprimir(f);
	
	inserir(&f, 10);
	inserir(&f, 20);
	inserir(&f, 30);
	imprimir(f);
	
	valor = consumir(&f);
	valor = consumir(&f);
	imprimir(f);
	
	inserir(&f, 40);
	inserir(&f, 50);
	valor = consumir(&f);
	imprimir(f);
}

void inserir(struct fila *f, int valor){
	if((f->fim + 1) < TAM){ // Verifica se nao chegamos ao final da Fila
		f->fim++;//atualiza a posicao final para inserir um novo valor
		f->dados[f->fim] = valor;//insere o valor na posicao
		printf("Valor %d foi inserido\n", valor);//imprime na tela	
	}else{
		printf("Sem espaco na fila!\n");
	}
}

int consumir(struct fila *f){
	int valor;
	if(f->inicio < TAM){
		if((f->inicio == 0) && (f->dados[f->inicio] == -1)){
			printf("Consume elemento que nao existe.\n");
			valor = -1;
		}else{
			valor = f->dados[f->inicio];
			f->inicio++;
			printf("Valor %d foi consumido\n", valor);
		}
	}else{
		printf("Consume elemento que nao existe.\n");
	}
	
	return valor;
}

void imprimir(struct fila f){
	printf("\n\n----Fila atual----");
	int i;
	for(i = f.inicio; i <= f.fim; i++){
		if(i == f.inicio)
			printf("inicio[%d], ", f.dados[i]);
		else if(i == f.fim)
			printf(" fim[%d]", f.dados[i]);
		else
			printf(" %d, ", f.dados[i]);
	}
	
	if(f.inicio == (f.fim + 1))
		printf("Fila vazia\n");

	printf("\n--------------\n");
}
