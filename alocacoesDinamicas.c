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
	no* aux = (no*)malloc(sizeof(no));		//Aloca espa�o para o novo n�
	if(aux){								//Conseguiu alocar espa�o?
		aux->info = n;
		if(!(*inicio)){						//lista vazia - � mesmo que if(*inicio == NULL)
			(*inicio) = aux;
			(*inicio)->prox = NULL;
		}
		else{								//lista n�o vazia
			aux->prox = (*inicio);			//liga o novo n� � lista
			(*inicio) = aux;				//o �nico da lista passa ser o novo n�
		}
		
	}else{
		printf("Heap cheia.\n");
	}
}

void insere_fim(int n, no **inicio){
	no* aux = (no*)malloc(sizeof(no));		//Aloca espa�o para o novo n�
	if(aux){								//Conseguiu alocar espa�o?
		aux->info = n;
		aux->prox = NULL; 					//Como o novo n� ser� inserido no final da lista, ele n�o ter� niguem � frente
		if(!(*inicio)){						//lista vazia - � mesmo que if(*inicio == NULL)
			(*inicio) = aux;
		}else{								//lista n�o vazia
			no *p = (*inicio);				//usaremos o ponteiro p para encontrar o �ltimo n�
			while(p->prox != NULL){
				p = p->prox;
			}
			p->prox = aux; 					//ligaremos o �ltimo n� ao novo n� da lista
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
		printf("%d.\n", inicio->info);			//imprime valor n�
		inicio = inicio->prox;				//anda para o proximo n�
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
	(*inicio) = (*inicio)->prox;//anda com o in�cio para o segundo no
	free(aux);					//libera espa�o do removido
	return n;					//retorna o valor que estava no removido
}

int remove_segundo(no **inicio){
	if(!(*inicio) || !(*inicio)->prox){
		return (-1);						//A lista tinha menos de dois elementos
	}
		
	no *aux = (*inicio)->prox;			//guardar o no a ser removido
	int n = (aux)->info;				//guardar o valor do No para retornar
	(*inicio)->prox = (aux)->prox; 		//liga o n� anterior ao removido ao n� posterior
	free(aux);							//libera espa�o do removido
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
		(*inicio) = NULL;		//apenas a libera��o do n� a lista passa a ser vazia
		return (n);
	}
	
	no *aux = (*inicio);		//inicializa o aux no �nicio da lista
	while(aux->prox->prox){ 	//caso tendo s� dois elementos, pega informa��o do pr�ximo e elemina-a, anda com o prox at� o penultimo elemento
		aux = aux->prox;
	}	
	n = aux->prox->info;		//guarda o valor do �ltimo
	free(aux->prox);			//libera memoria do �ltimo
	aux->prox = NULL;			//atualiza o penultimo n� que passou a ser o �ltimo
	return(n);					//retorna o valor do n� removido
}
