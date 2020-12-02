#include <stdio.h>
#include <stdlib.h>
#define GRAU 4

typedef struct tipo_no no;
typedef int tipo_dado;

struct tipo_no{
	int nro_chaves;
	tipo_dado chaves[GRAU];
	no *apontadores[GRAU + 1];
};

void main() {
	
}

void ordenado(no *Raiz){
	int j, Ni;
	if(Raiz != NULL){
		Ni = Raiz->nro_chaves;				//O numero de chaves para o no j
		for(j = 0; j < Ni; j++){			//Percorre as chaves no noh j
			ordenado(Raiz->apontadores[j]);	//Percorre a j-esima do noh j
			printf("%d", Raiz->chaves[j]);	//Imprime a chave do j-esimo noh
		}									
		ordenado(Raiz->apontadores[j]);		//Percorre a ultima subarvore do noh j
	}
}

void busca_no(no *Raiz, tipo_dado ch, no **i, int *j){
	int Ni;
	if(Raiz == NULL){ // Não existe mais subarvores para procurar ch, ou seja, ch nao existe
		*i = NULL;
		*j = -1;
	}else{
		*i = Raiz;
		Ni = (*i)->nro_chaves;
		for(*j = 0; *j < Ni; (*j)++){	//primeira posicao do vetor chaves eh 0 (zero)
			printf("Chave visitada = %d\n", (*i)->chaves[*j]); //mostra a chave visitada durante a busca
			if((*i)->chaves[*j] == ch){ //encontrou a chave ch procurada
				return; //finaliza a busca, sendo i o noh e j a posicao da chave ch
			}else if(ch < (*i)->chaves[*j]){ //chave ch deve estar na j-esima subarvore apontada no noh i
				break;	//interrompe o laco para buscar a chave ch na j-esima subarvore
			}
		}
		busca_no((*i)->apontadores[*j], ch, &(*i), &(*j));
	}
}

void busca_no_ins(no *Raiz, tipo_dado ch, no **i, int *j){
	int Ni;
	//se (Raiz == NULL) eh porque nao existe mais subarvores para procurar ch e no i esta sem espaco
	//Finaliza a busca, ja tendo a posicao j do no i como ponto onde o noh devera ser criado para a insercao de ch
	if(Raiz != NULL){
		*i = Raiz;
		Ni = (*i)->nro_chaves;
		for(*j = 0; *j < Ni; (*j)++){ //Procura pela 1 chave do noh i maior que ch
			if((*i)->chaves[*j] == ch){ //chave ch ja existe na arvore
				*j = -1;
				return; //finaliza a busca
			}
			else if(ch < (*i)->chaves[*j]){ // encontrou no noh (*i) uma chave maior que ch
				if(Ni < GRAU-1){ //existe espaco no noh i para a insercao de uma chave menor que uma jah existente
					return; //finaliza a busca, sendo i o noh para a insercao e j a posicao da chave
				}else{
					break; //interrompe o laco para buscar a chave ch na j-esima subarvore
				}	
			}
		}
		busca_no_ins((*i)->apontadores[*j],ch,&(*i),&(*j));
	}
}

void inserir_n_naria(no **Raiz, tipo_dado ch){
	no *i;	//apontador para o noh onde sera inserida a chave ch
	int j;	//Posicao no noh para insercao ordernada da chave ch
	int Ni, k;
	
	if(*Raiz == NULL){	//Primeiro elemento da arvore
		*Raiz = (no*)malloc(sizeof(no)); //aloca espaco correspondente ao noh raiz
		for(k = 0; k < GRAU-1; k++){
			(*Raiz)->chaves[k] = -1; //inicializa o noh com vazio
			(*Raiz)->apontadores[k] = NULL;
		}
		(*Raiz)->apontadores[k] = NULL; //inicializa o endereco da ultima subarvore
		(*Raiz)->chaves[0] = ch; // insere o conteudo (chave) como primeira chave do noh
		(*Raiz)->nro_chaves = 1; //inicializa o numero de chaves contidas no noh
	}else{
		i = *Raiz;	//Inicializa i e j
		j = 0;
		busca_no_ins(*Raiz,ch,&i,&j);
		if(j == -1){
			printf("Chave ja existente na arvore\n");
		}else{
			Ni = i->nro_chaves;
			if(Ni ==GRAU-1){ //nao existe espaco no noh de insercao de ch
				no *E;	//cria novo noh
				E = (no*)malloc(sizeof(no)); //aloca espaco na memoria correspondente ao noh E
				for(k = 0; k < Ni; k++){ //inicializa o noh com vazio
					E->chaves[k] = -1;
					E->apontadores[k] = NULL;
				}
				E->apontadores[k] = NULL;  //Inicializa o endereco da ultima subarbore
				E->chaves[0] = ch; //insere o conteudo (chave) como primeira chave do noh 
				E->nro_chaves = 1; //inicializa o numero de chaves contidas no noh
				i->apontadores[j] = E; //insere o noh E como a j-esima subarvore do noh i
			}
			else{
				if(j == Ni){ //A chave ch sera a ultima do noh i
					i->apontadores[j+1] = NULL; //inicializa o endereco da ultima (j-esima + 1) subarvore
				}else{ // Rearranja o Noh i, mantendo a ordenacao de suas chaves e subsarvores
					i->apontadores[j+1] = i->apontadores[Ni]; // Desloca ultima subarvore
					for(k = Ni; k > j; k--){ //abre espaco para a chave ch, deslocando as chaves e subarvores
						i->chaves[k] = i->chaves[k-1];
						i->apontadores[k] = i->apontadores[k-1];
					}
					i->apontadores[j] = NULL; //inicializa o endereco da j-esima subarvore
				}
				i->chaves[j] = ch; //insere a chave ch na posicao
				i->nro_chaves = i->nro_chaves + 1; //incrementa o numero de chaves no noh i			
			}
		}
	}
}
