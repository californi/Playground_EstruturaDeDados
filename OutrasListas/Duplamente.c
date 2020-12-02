#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct tipo_no no;
void insere_em_ordem(int n, no **inicio);
void imprime(no *inicio);

struct tipo_no {
	int info;
	struct tipo_no *prox, *ant;
};

int main(int argc, char *argv[]) {
	no *reg = NULL;
	
	
	insere_em_ordem(8, &reg);
	insere_em_ordem(9, &reg);
	insere_em_ordem(7, &reg);
	insere_em_ordem(5, &reg);
	
	imprime(reg);
	
	return 0;
}

void insere_em_ordem(int n, no **inicio){
	no* aux = (no*)malloc(sizeof(no)); //Aloca espaço para o novo nó
	if(aux){ //Conseguiu alocar espaço?
		aux->info = n;
		if(!(*inicio) || (n < (*inicio)->info)) //lista vazia ou n eh menor que o primeiro elemento
		{
			(aux)->prox = (*inicio); //preeche os ponteiros do novo noh
			(aux)->ant = NULL;
			if(*inicio){
				(*inicio)->ant = aux; // liga o primeiro noh ao novo noh
			}
			(*inicio) = aux;	// o primeiro noh passa ser aux
		}else { //procura o local da inserção com o ponteiro auxiliar p
			no *p = (*inicio);
			while((p->prox != NULL) && (n > p->info))
			{
				p = p->prox;
			}
			if(p->prox == NULL){ //insere no final da lista
				p->prox = aux;
				aux->prox = NULL;
				aux->ant = p;
			}else{   //insere no meio da lista, apohs o ponteiro p
				aux->ant = p;
				aux->prox = p->prox;
				p->prox->ant = aux;
				p->prox = aux;
			}
		}
	}else{ 
		printf("Heap overflow\n");
	}
}

void imprime(no *inicio){
	while(inicio){  //enquanto houver lista
		printf("%d", inicio->info); //imprime o valor do NO
		inicio = inicio->prox;
	}
}
