#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tipo_no no;
void insere_inicio(int n, no **inicio);
void insere_fim(int n, no **inicio);
void imprime(no *inicio);
int pertence (int n, no *inicio);
no* busca(int n, no *inicio);
int remove_inicio(no **inicio);
int remove_segundo(no **inicio);
int remove_ultimo(no **inicio);
void teste();

struct tipo_no{
	int info;
	struct tipo_no *prox;
};

int main(int argc, char *argv[]) {
	
	teste();
	
	no *lista = NULL; // Tem que iniciar como NULL
	insere_inicio(20, &lista);
	insere_fim(30, &lista);
	insere_inicio(10, &lista);
	insere_fim(40, &lista);
	
	imprime(lista);
	
	if(pertence(10, lista)){
		printf("Numero 10 foi encontrado!\n");
		no* encontrado = busca(10, lista);
		printf("Esse eh o numero %d.\n", encontrado->info);
		printf("Depois dele vem o %d.\n", encontrado->prox->info);
	}
	
	if(!pertence(11, lista)){
		printf("Numero 11 nao foi encontrado!\n");
	}
	
	int nrem = remove_inicio(&lista);
	printf("O valor inicio removido foi o %d.\n", nrem);
	
	imprime(lista);
	
	int nres = remove_segundo(&lista);
	printf("O valor segundo removido foi o %d.\n", nres);
	
	imprime(lista);
	
	int nreu = remove_ultimo(&lista);
	printf("O ultimo valor removido foi o %d.\n", nreu);
	
	imprime(lista);

	return 0;
}

void insere_inicio(int n, no **inicio){
	no* aux = (no*)malloc(sizeof(no));		//Aloca espaço para o novo nó
	if(aux){								//Conseguiu alocar espaço?
		aux->info = n;
		if(!(*inicio)){						//lista vazia - é mesmo que if(*inicio == NULL)
			(*inicio) = aux;
			(*inicio)->prox = NULL;
		}
		else{								//lista não vazia
			aux->prox = (*inicio);			//liga o novo nó à lista
			(*inicio) = aux;				//o ínico da lista passa ser o novo nó
		}
		
	}else{
		printf("Heap cheia.\n");
	}
}

void insere_fim(int n, no **inicio){
	no* aux = (no*)malloc(sizeof(no));		//Aloca espaço para o novo nó
	if(aux){								//Conseguiu alocar espaço?
		aux->info = n;
		aux->prox = NULL; 					//Como o novo nó será inserido no final da lista, ele não terá niguem à frente
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

void teste(){
	
	printf("meu endereco %d\n", sizeof(no));
	
	no* aux1 = (no*)malloc(sizeof(no));

	printf("meu endereco %d\n", aux1);
	printf("meu endereco %d\n", sizeof(aux1));
	no* aux2 = (no*)malloc(sizeof(no));
	printf("meu endereco %d\n", aux2);
	printf("meu endereco %d\n", sizeof(aux2));
	no* aux3 = (no*)malloc(sizeof(no));
	printf("meu endereco %d\n", aux3);
	printf("meu endereco %d\n", sizeof(aux3));
	
	free(aux1);
	free(aux2);
	free(aux3);
	
	printf("meu endereco %d\n", aux1);
	printf("meu endereco %d\n", sizeof(aux1));
	no* aux2 = (no*)malloc(sizeof(no));
	printf("meu endereco %d\n", aux2);
	printf("meu endereco %d\n", sizeof(aux2));
	no* aux3 = (no*)malloc(sizeof(no));
	printf("meu endereco %d\n", aux3);
	printf("meu endereco %d\n", sizeof(aux3));
	
	no* aux4 = (no*)malloc(sizeof(no));
	
	
	while(aux4){
		aux4 = (no*)malloc(sizeof(no));
		
		
	}
	printf("meu endereco %d\n", aux4);
	
	
}


void imprime (no *inicio){
	while(inicio) 							//enquanto houver lista
	{
		//printf("meu endereco %d", inicio);
		printf("%d.\n", inicio->info);			//imprime valor nó
		inicio = inicio->prox;				//anda para o proximo nó
	}
}

int pertence (int n, no *inicio){
	while(inicio){
		if(inicio->info == n){
			return (1);
		}
		inicio = inicio->prox;
	}
	return (0);
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

int remove_inicio(no **inicio){
	if(!(*inicio)){
		return (-1);    		//Retorna a flag -1 para lista vazia
	}
	
	no *aux = (*inicio);		//guardar o primeiro No em aux
	int n = (*inicio)->info;	//guardar o valor do No para retornar
	(*inicio) = (*inicio)->prox;//anda com o início para o segundo no
	free(aux);					//libera espaço do removido
	return n;					//retorna o valor que estava no removido
}

int remove_segundo(no **inicio){
	if(!(*inicio) || !(*inicio)->prox){
		return (-1);						//A lista tinha menos de dois elementos
	}
		
	no *aux = (*inicio)->prox;			//guardar o no a ser removido
	int n = (aux)->info;				//guardar o valor do No para retornar
	(*inicio)->prox = (aux)->prox; 		//liga o nó anterior ao removido ao nó posterior
	free(aux);							//libera espaço do removido
	return n;							//retorna o valor que estava no removido
	
}

int remove_ultimo(no **inicio){
	int n;
	if(!(*inicio)){
		return (-1); 			//lista vazia
	}
	
	if(!(*inicio)->prox){		//lista com apenas um no
		n = (*inicio)->info;
		free(*inicio);
		(*inicio) = NULL;		//apenas a liberação do nó a lista passa a ser vazia
		return (n);
	}
	
	no *aux = (*inicio);		//inicializa o aux no ínicio da lista
	while(aux->prox->prox){ 	//caso tendo só dois elementos, pega informação do próximo e elemina-a, anda com o prox até o penultimo elemento
		aux = aux->prox;
	}	
	n = aux->prox->info;		//guarda o valor do último
	free(aux->prox);			//libera memoria do último
	aux->prox = NULL;			//atualiza o penultimo nó que passou a ser o último
	return(n);					//retorna o valor do nó removido
}
