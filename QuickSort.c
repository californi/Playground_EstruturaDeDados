#include <stdio.h>
#include <stdlib.h>
 
	void troca(int *x, int *y);
	int escolherPivo(int i, int j);
	void quicksort(int lista[], int m, int n);
	void mostrar(int lista[], int n);
	 
	void main()
	{
	    const int tamanho = 10;
	    int lista[tamanho];
	 
	    int i = 0;
	 
	    /* gerando numeros randomicos */
	    for(i = 0; i < tamanho; i++ )
	        lista[i] = rand();
	 
	    printf("Lista inicial:\n");
	    mostrar(lista, tamanho);
	 
	    /* realiza ordenacao */
	    quicksort(lista, 0, tamanho - 1);
	 
	    printf("Lista apos ordenacao:\n");
	    mostrar(lista, tamanho);
	}
	 
	void troca(int *x, int *y)
	{
	    int temp;
	    temp = *x;
	    *x = *y;
	    *y = temp;
	}
	 
	int escolherPivo(int i, int j )
	{
	    return((i+j) /2);
	}
	 
	void quicksort(int lista[], int inicio, int fim)
	{
	    int elemento, i, j, pivo;
	    if(inicio < fim)
	    {
	        pivo = escolherPivo(inicio, fim);
	        troca(&lista[inicio], &lista[pivo]);
	        elemento = lista[inicio];
	        i = inicio + 1;
	        j = fim;
	        while(i <= j)
	        {
	            while((i <= fim) && (lista[i] <= elemento))
	                i++;
	            while((j >= inicio) && (lista[j] > elemento))
	                j--;
	            if( i < j)
	                troca(&lista[i], &lista[j]);
	        }
	        /* troca dois elementos */
	        troca(&lista[inicio], &lista[j]);
	 
	        /* recursivamente ordena a lista menor*/
	        quicksort(lista, inicio, j-1);
	        quicksort(lista, j + 1, fim);
	    }
	}
	
	void mostrar(int lista[], int fim)
	{
	    int i;
	    for(i=0; i < fim; i++)
	        printf("%d\t", lista[i]);
	}
