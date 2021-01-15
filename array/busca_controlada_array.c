/* Encontrando o maior e menor valor do array e quantos zeros seguidos tem em um array*/

#include <stdio.h>
#include <stdlib.h>

int vetor[10] = {3, 5, 8, 4, 12, 2, 7, 6, 9, 14};
int vetor2[20] = {3, 1, 0, 0, 0, 10, 2, 7, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


// Decobre o maior valor de v.
// Recebe n e v sendo n o tamanho do vetor e v o vetor.
// Ao final do loop ele retorna o maior valor do vetor.
int valorMax(int n, int v[]){
	int j;
	int m = v[0];
	for(j = 1; j < n; j++)
		if(m < v[j]) m = v[j];
	return m;
}

// Descobre o menor valor do v.
// recebe n e v, sendo n o tamanho do vetor e v o vetor.
// ele verifica se m(menor) e maior que o a posição do vetor v[j], se for, ele troca pela posição do vetor v[j].
int menorValor(int n, int v[]){
	int j;
	int maxZero;
	int count;
	int m = v[0];
	for(j = 1; j < n; j++)
		if(m > v[j]) m = v[j];
	return m;
}

// Descobre o maior número de zeros seguidos em um array.
// recebe n e v, sendo n o tamanho do vetor e v o vetor.
// tem um contado e um retorno ret, o for percorre o vetor inteiro.
// se ele encontra um zero ele adiciona mais 1 ao count, se ele recebe um número diferente de zero, ele armazena em ret e zera o count, no final ele retorna o ret.
int carretaZero(int n, int v[]){
	int ret = 0;
	int j;
	int count = 0;
	for(j = 0; j < n; j++){
		if(v[j] == 0){
			if(count > ret){
				count++;
			}else{
				count++;
			}
		}
		if(v[j] != 0){
			ret = count;
			count = 0;
		}
	}
	ret = count;
	return ret;
}

int main(){
	printf("O valor maximo e: %d\n", valorMax(10, vetor));
	printf("O menor valor de vetor e: %d\n", menorValor(10, vetor));
	printf("O menor valor de vetor2 e: %d\n", menorValor(20, vetor2));
	printf("O maior repeticao de zero no vetor2 e: %d\n", carretaZero(20, vetor2));
	system("pause");
	return 0;
}
