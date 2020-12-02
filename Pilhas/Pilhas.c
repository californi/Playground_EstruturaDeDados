#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct pilha pilha;

void push(struct pilha *p, int info);
int pop(struct pilha *p);
void imprimir(struct pilha p);

struct pilha{
	int topo;
	int dados[TAM];
};

void main(){
	int i = 0;
	int valor_retirado;
	struct pilha pi;
	pi.topo = 0;
	for(i = 0; i < TAM; i++)
		pi.dados[i]; 
		
	push(&pi, 10);
	imprimir(pi);
	push(&pi, 20);
	imprimir(pi);
	push(&pi, 50);
	imprimir(pi);
	push(&pi, 30);
	imprimir(pi);
	push(&pi, 40);
	imprimir(pi);
	
	valor_retirado = pop(&pi);
	imprimir(pi);
	valor_retirado = pop(&pi);
	imprimir(pi);
	valor_retirado = pop(&pi);
	imprimir(pi);
	valor_retirado = pop(&pi);
	imprimir(pi);
	valor_retirado = pop(&pi);
	imprimir(pi);
}

void push(struct pilha *p, int info){
	if(p->topo < TAM){
		printf("Inserindo %", info);
		p->dados[p->topo] = info;
		p->topo++;
	}else{
		printf("Pilha cheia");
	}	
}

int pop(struct pilha *p){
	int valor;
	if(p->topo > 0){
		p->topo--;
		valor = p->dados[p->topo];
		p->dados[p->topo] = -1;
		printf("Retirando %d\n", valor);
		return valor;
	}else{
		printf("Pilha vazia\n");
	}
	return -1;
}

//apenas para exemplificar, nao se pode acessar alem do topo
void imprimir(struct pilha p){
	printf("Pilha\n");
	int i;
	for(i = 0; i < p.topo; i++)
		printf(" %d\n\n", p.dados[i]);
}
