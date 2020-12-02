#include <stdio.h>
#include <stdlib.h>

typedef struct tipo_no no;
typedef int tipo_dado;
void pre_ordem(no *Raiz);
void em_ordem(no *Raiz);
void pos_ordem(no *Raiz);
void inserir_binaria(no **Raiz, tipo_dado valor);
tipo_dado retornar_maior(no **X);
void remover_binaria(no **Raiz, tipo_dado valor);

struct tipo_no{
	tipo_dado dado;
	struct tipo_no *esq;
	struct tipo_no *dir;
};

void main() {
	no* mr = NULL;
	inserir_binaria(&mr, 50);
	inserir_binaria(&mr, 40);
	inserir_binaria(&mr, 62);
	inserir_binaria(&mr, 15);
	inserir_binaria(&mr, 47);
	inserir_binaria(&mr, 93);
	inserir_binaria(&mr, 22);
	
	printf("Pre-ordem:\n");
	pre_ordem(mr);
	printf("\nEm-ordem:\n");
	em_ordem(mr);
	printf("\nPos-ordem:\n");
	pos_ordem(mr);
	printf("\n");
	
	remover_binaria(&mr, 40); //testando exclusao de no com subarvores a esquerda e a direita
	printf("Pre-ordem:\n");
	pre_ordem(mr);
	
	remover_binaria(&mr, 62); //testando exclusao de no com subarvore somente a direita
	printf("Pre-ordem:\n");
	pre_ordem(mr);
	
	remover_binaria(&mr, 47); //testando exclusoes para subarvores somente a esquerda
	remover_binaria(&mr, 22); //testando exclusoes para subarvores somente a esquerda
	printf("Pre-ordem:\n");
	pre_ordem(mr);
}

void pre_ordem(no *Raiz){
	if(Raiz != NULL){
		printf("%d ", Raiz->dado);
		pre_ordem(Raiz->esq);
		pre_ordem(Raiz->dir);
	}
}

void em_ordem(no *Raiz){
	if(Raiz != NULL){
		em_ordem(Raiz->esq);
		printf("%d ", Raiz->dado);
		em_ordem(Raiz->dir);
	}
}

void pos_ordem(no *Raiz){
	if(Raiz != NULL){
		pos_ordem(Raiz->esq);
		pos_ordem(Raiz->dir);
		printf("%d ", Raiz->dado);
	}
}

void inserir_binaria(no **Raiz, tipo_dado valor){
	no *E;
	if(*Raiz == NULL){
		E = (no*)malloc(sizeof(no));
		E->dado = valor;
		E->esq = NULL;
		E->dir = NULL;
		*Raiz = E;
	}
	else if(valor < (*Raiz)->dado){
		inserir_binaria(&(*Raiz)->esq, valor);
	}
	else if(valor > (*Raiz)->dado){
		inserir_binaria(&(*Raiz)->dir, valor);
	}else{
		printf("Elemento ja existente\n");
	}
}

tipo_dado retornar_maior(no **X){
	tipo_dado valor;
	no *Aux;
	
	if((*X)->dir != NULL){
		return(retornar_maior(&(*X)->dir));
	}else{
		Aux = *X;
		valor = (*X)->dado;
		*X = (*X)->esq;
		
		free(Aux);
		return(valor);
	}
}

void remover_binaria(no **Raiz, tipo_dado valor){
	no *Aux;
	if(*Raiz != NULL){
		if((*Raiz)->dado == valor){
			Aux = *Raiz;
			if((*Raiz)->esq == NULL){
				*Raiz = (*Raiz)->dir;
				free(Aux);
			}else if((*Raiz)->dir == NULL){
				*Raiz = (*Raiz)->esq;
				free(Aux);
			}else{
				(*Raiz)->dado = retornar_maior(&(*Raiz)->esq);
			}
		}else if((*Raiz)->dado < valor){
			remover_binaria(&(*Raiz)->dir, valor);
		}else if((*Raiz)->dado > valor){
			remover_binaria(&(*Raiz)->esq, valor);
		}
		
	}else{
		printf("Elemento inexistente!\n");
	}
}
