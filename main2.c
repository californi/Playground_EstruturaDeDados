#include <stdio.h>
 
int soma(int n)
{
    if(n == 1)
        return 1;
    else
        return ( n + soma(n-1) );
}

int soma2(int n)
{
	int soma;
	int i;
	for(i = 1; i <= n; i++){
		soma = soma + i;
	}
	return soma;
}
 
int main()
{
    int n;
    printf("Digite um inteiro positivo: ");
    scanf("%d", &n);
 
    printf("Soma: %d\n", soma(n));
}
