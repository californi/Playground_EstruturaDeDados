#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipo_no no;
typedef struct tipo_no2 no2;

no* busca(int n, no *inicio);
void insere_fim(int n, no **inicio);
void insere_inicio(char *nome, no2 *ini);

struct tipo_no2{
	char nome[20];
	struct tipo_no2 *p;
};

struct tipo_no{
	int info;
	struct tipo_no *prox;
	struct tipo_no2 *ini;
};

int main(int argc, char *argv[]) {

	no* reg = NULL;
	//insercao do tipo
	insere_fim(1, &reg);
	insere_fim(4, &reg);
	insere_fim(6, &reg);
	insere_fim(3, &reg);
	
	if(busca(4, reg) == NULL){
		printf("Entrou 4");
		insere_fim(4, &reg);
	}
	
	if(busca(5, reg) == NULL){
		printf("Entrou 5");
		insere_fim(5, &reg);
	}
	
	//exemplo de uma possivel insercao do elemento
	no *aux;
	aux = busca(4, reg);
	insere_inicio("Teste1", aux->ini);
	insere_inicio("Teste2", aux->ini);
	insere_inicio("Teste3", aux->ini);
	
	return 0;
}

no* busca(int n, no *inicio){
	while(inicio){
		if(inicio->info == n){
			return (inicio); //Encontrou o elemento
		}
		inicio = inicio->prox;
	}
	return (NULL); //acabou a lista sem encontrar o elemento.
}

//Insercao de um tipo no final da lista
void insere_fim(int n, no **inicio){
	no* aux = (no*)malloc(sizeof(no));		//Aloca espaço para o novo nó
	if(aux){								//Conseguiu alocar espaço?
		aux->info = n;
		aux->prox = NULL; 					//Como o novo nó será inserido no final da lista, ele não terá niguem à frente
		aux->ini = NULL;					//a lista de elementos começa vazia até que algum elemento seja inserido (principal diferença)
		if(!(*inicio)){						//lista vazia - é mesmo que if(*inicio == NULL)
			(*inicio) = aux;
		}else{								//lista não vazia
			no *p = (*inicio);				//usaremos o ponteiro p para encontrar o último nó
			while(p->prox != NULL){
				p = p->prox;
			}
			p->prox = aux; 					//ligaremos o último nó ao novo nó da lista
		}
	}else{
		printf("Heap cheia.\n");
	}

}

//Insercao de um elemento no inicio da lista (de acordo com o respectivo noh)
void insere_inicio(char *nome, no2 *ini){
	no2* aux = (no2*)malloc(sizeof(no2)); //aloca espaco para o novo node
	if(aux) //conseguiu alocar espaco
	{
		strcpy(nome, aux->nome);
		aux->p = ini->p;
		ini->p = aux;
	}else{
		printf("Heap overflow\n");
	}
}
