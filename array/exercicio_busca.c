/*  Escreva uma função que receba x, v e n e devolva 1 se x está em v[0..n-1] e 0 em caso contrário. */

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE -1

// Criando um vetor de inteiros com 10 espaço na memória.
int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// Criando a função busca que recebe x, v e n
// x representa o número que é buscado, v é o vetor da busca e n o tamanho do vetor
// Se encontrar o número retorna TRUE, caso contrário retorna FALSE;
int busca(int x, int v[], int n){
	int k = n-1;
	while(k >= 0 && v[k] != x ){
		k--;
	}
	if(v[k] == x){
		return TRUE;
	}else{
		return FALSE;
	}
}

int main(){
	printf("Colocando um numero que pode ser encontrado, x = 4.\n");
	if(busca(4, vetor, 10) == TRUE){
		printf("Numero encontrado.\n");
	}else{
		printf("Numero nao encontrado.\n");
	}
	printf("Colocando um numero que nao pode ser encontrado, x = 11.\n");
	if(busca(11, vetor, 10) == FALSE){
	printf("Numero nao encontrado.\n");
	}else{
		printf("Numero encontrado.\n");
	}
	system("pause");
}
