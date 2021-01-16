/* Exercícios de lista Encadeada completo */

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE -1

int contadorRec = 0;

// Criando uma estrutura para uma lista encadeada.
typedef struct reg{
	int conteudo;
	int *prox;
}celula;

// Iniciando a lista.
celula c;

// Iniciando um apontador para a lista
celula *p;

// Imprime a quantidade de conteúdo da lista de forma recursiva
void contadorTamanhoRec(celula *c){
	if(c->prox != NULL){
		contadorRec++;
	}
	printf("%d\n", contadorRec);
}

// Imprime a quanidade de conteúdo de forma iterativa com ponteiro.
void contadorTamanhoIte(celula *c){
	celula *ponteiro = c;
	int contadorIte = 0;
	while (p != NULL){
		contadorIte++;
		p = p->prox;
	}
	printf("O numero de elementos e: %d\n", contadorIte);
	
}

//Verifica se a lista está em ordem crescente.
void verificadorOrdemCrescente(celula *c){
	celula *proximo = c->prox;
	while(c->conteudo < proximo->conteudo){
		c = c->prox;
		proximo = c->prox;
	}
	if(c->prox == NULL){
		printf("Lista esta ordenada\n");
	}else{
		printf("Lista nao esta ordenada\n")
	}
}

int main(){
	contadorTamanhoIte(p);
	system("pause");
	return 0;
}
