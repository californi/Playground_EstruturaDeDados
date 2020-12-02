#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct tipo_no no;

void insere_inicio(int n, no *inicio);

int remove_inicio(no **inicio);
void imprime(no *inicio);

struct tipo_no {
	int info;
	struct tipo_no *prox;
};

int main(int argc, char *argv[]) {
	no *reg = (no*)malloc(sizeof(no));
	reg->info = 0;
	reg->prox = reg; // principal ponto!
	
	insere_inicio(5, reg);
	insere_inicio(1, reg);
	insere_inicio(4, reg);
	insere_inicio(3, reg);
	
	imprime(reg);
	
	int excluido = remove_inicio(&reg);
	
	printf("O excluido foi %d", excluido);
	
	imprime(reg);
	
	return 0;
}

int remove_inicio(no **inicio){
	if(!(*inicio))
		return (-1); //retorna flag -1 para informar que a lista estava vazia
	
	no *aux = (*inicio); //guarda o primeiro noh em aux
	int n = (*inicio)->info; //guarda o valor do noh para retornar
	if((*inicio)->prox == (*inicio))	//se houver apenas um noh na lista
	{
		(*inicio) = NULL; //a lista passa a ser vazia
		free(aux); // libera espaco de memorio
		return (n); // retorna valor removido
	}
	else{	//lista com mais de um elemento
		while(aux->prox != (*inicio)){
			aux = aux->prox; //achar o ultimo noh para ligar com o primeiro
		}
		aux->prox = (*inicio)->prox; // ligando o último ao segundo
		free(*inicio);
		(*inicio) = aux->prox; // anda com o incio para o segundo
		return (n);
	}
	
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
	if(inicio){ //se a lista nao for vazia
		no *aux = inicio; //aux comeca no inicio da lista
		do{
			printf("%d\n", aux->info); //imprime o valor no
			aux= aux->prox; //anda para o proximo no
		}while(aux != inicio); //ate aux dar a volta na lista
	}
}
