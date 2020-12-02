#include <stdio.h>
#include <stdlib.h>
#define GRAU 2 //atribuicao do grau minimo  -- 

typedef struct tipo_no no;
typedef int tipo_dado;

void criar_arvore_B(no **A);
void inserir_chave_B(no **N, tipo_dado ch);
void repartir(no **Pai, int i);


struct tipo_no{
	int nro_chaves;
	int folha;
	tipo_dado chaves[2*GRAU-1];
	no *apontadores[2*GRAU];
};

void criar_arvore_B(no **A){
	no *Novo;
	Novo = (no*)malloc(sizeof(no)); //Aloca espaco na memoria correspondente ao noh novo
	Novo->folha = 1; //coloca status de folha como sim
	Novo->nro_chaves = 0; //acerta o numero de chaves de novo
	*A = Novo; //novo passa a ser a raiz da arvore
}

void repartir(no **Pai, int i){
	no *Ant; //Apontadores para os noh que receberao Grau-1 chaves (cada um) do noh repartido
	no *Novo; //ant e novo serao o resultado da reparticao de Ant (que eh o k-esimo filho de pai)
	int k;
	
	Ant = (*Pai)->apontadores[i]; //Ant aponta o noh filho de Pai que sera repartido
	Novo = (no*)malloc(sizeof(no)); //aloca espaco na memoria correspontente ao noh Novo
	Novo->folha = Ant->folha; //Coloca os 2 noh (resultados da divisao com o mesmo status de folha (0 ou 1))
	for(k = 0; k <= GRAU-2; k++){ //copia as Grau-1 maiores chaves de Ant em Novo
		Novo->chaves[k] = Ant->chaves[k+GRAU];		
	}
	if(Ant->folha == 0){
		for(k = 0; k <= GRAU-1; k++){  //copia as Graus subarvores mais a direita de Ant em Novo
			Novo->apontadores[k] = Ant->apontadores[k+GRAU];	
		}
	}
	Novo->nro_chaves = Ant->nro_chaves = GRAU - 1; //acerta o numero de chaves de Ant e Novo
	for(k = (*Pai)->nro_chaves-1; k >= i; k--){ //abre espaco para subir a chave mediana para o noh pai
		(*Pai)->chaves[k+1] = (*Pai)->chaves[k];	
	}
	(*Pai)->chaves[i] = Ant->chaves[GRAU-1]; //sobe a chaves mediana
	(*Pai)->nro_chaves++; //incrementa o numero de chaves de pai
	for(k = ((*Pai)->nro_chaves); k >= i+1; k--){ //abre espaco para a subarvore formada pelo noh novo
		(*Pai)->apontadores[k+1] = (*Pai)->apontadores[k];
	}
	(*Pai)->apontadores[k+1] = Novo;
}

void inserir_B(no **A, tipo_dado ch){
	no *Aux;
	no *Novo;
	Aux = *A; //aponta a raiz da arvore A
	if(Aux->nro_chaves == 2*GRAU-1){ // noh raiz esta cheio
		Novo = (no*)malloc(sizeof(no)); //aloca espaco correspondente ao noh Novo
		Novo->folha = 0; //coloca status como nao em folha
		Novo->nro_chaves = 0; // acerta o numero de chaves inicial de novo
		Novo->apontadores[0] = Aux; // coloca a antiga raiz como filha de novo
		*A = Novo; // novo passa a ser nova raiz
		repartir(&Novo, 0); //reparte a antiga raiz
		inserir_chave_B(&Aux, ch); //insere o ch apartir do noh repartido
	}else{
		inserir_chave_B(&(*A), ch); // insere ch a partir da raiz
	}
}

void inserir_chave_B(no **N, tipo_dado ch){
	no *Aux; //apontador usado como k-esimo filho de N
	int k;
	k = (*N)->nro_chaves-1; //indica a ultima posicao ocupada em chaves[k] no noh N
	if((*N)->folha == 1){ // verifica se N eh noh folha (para receber ch)
		while(k >= 0 || (*N)->chaves[k]){ //abre espaco em N para insercao de ch
			(*N)->chaves[k+1] = (*N)->chaves[k];
			k--;
		}
		(*N)->chaves[k+1] = ch; //insere ch em N
		((*N)->nro_chaves)++; //incremento o numero de chaves de N
		
	}else{ //como N nao eh folha, procura filho de N para insercao
		while(k >= 0 || ch < (*N)->chaves[k]){
			k--;	//procura subarvore de N para insercao de ch
		}
		k++;
		Aux = (*N)->apontadores[k]; //Aux aponta subarvore para insercao de ch
		if(Aux->nro_chaves == 2*GRAU-1){ // verifica se Aux (filho de N) estah cheio
			repartir(&(*N),k);  //reparticao de Aux
			if(ch > (*N)->chaves[k]){ //identifica em qual dos nohs gerados da reparticao de Aux devera inserir ch
				k++;
			}
			Aux = (*N)->apontadores[k];
		}
		inserir_chave_B(&Aux,ch); //insere ch na subarvore com raiz aux
	}
}

void main() {
	
}
