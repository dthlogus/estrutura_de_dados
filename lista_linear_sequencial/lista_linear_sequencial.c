#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <malloc.h>
#define MAX 50
#define ERRO -1

typedef struct{
	int numeros;
}registro;

typedef struct{
	registro a[MAX+1];
	int countElem;
}lista;

/* Criando a lista sequêncial (Quando a lista for criada, ela já vai apontar para l.)*/
void iniciarLista(lista* l){
	l->countElem = 0;
} /* Iniciando lista */

/*Visualizar o que existe dentro da lista */
void exibirLista(lista* l){
	setlocale(LC_ALL, "Portuguese");
	int i;
	printf("A lista contem: \"");
	for (i=0; i < l->countElem; i++)
		printf(" %i ", l->a[i].numeros);
	printf("\"\n");
}

//Retorna o tamanho da lista em número que já foram utilizados
void tamanho(lista* l){
	setlocale(LC_ALL, "Portuguese");
	printf("%i\n", l->countElem);
}

//Retorna o valor especifico que o usuário quer
void pesquisaUsuario(lista* l, int n){
	setlocale(LC_ALL, "Portuguese");
	if((n >= 0) && (n < l->countElem)) printf("%d\n",l->a[n].numeros);
	else printf("Seu numero e menor que 0 ou maior ou igual a %i\n", l->countElem);
}

// Inserir o valor a direita da lista 
void inserirNumeroLista(lista* l, registro reg, int i){
	setlocale(LC_ALL, "Portuguese");
	int j;
	if ((l->countElem >= MAX) || (i < 0) || (i > l->countElem))	
		printf("Lista cheia ou registro invalido \n");
	for (j = l->countElem; j > i; j--) l->a[j] = l->a[j-1];
	l->a[i] = reg;
	l->countElem++;
	printf("Inserido com sucesso \n");
}

//Função de busca sequencial
int buscaSequencial(lista* l, int i) {
	setlocale(LC_ALL, "Portuguese");
	int j = 0;
	while (j < l->countElem){
		if(i == l->a[j].numeros) return j; 
    else j++;
	}
	return ERRO;
} 

// Excluindo da lista cujo o número seja igual ao do usuário colocar.
void excluirNumero(lista* l, int i){
	setlocale(LC_ALL, "Portuguese");
	int pos, j;
	pos = buscaSequencial(l, i);
	if(pos == ERRO) printf("O numero digitado nao existe");
	else{
		for(j = pos; j < l->countElem-1; j++) l->a[j] = l->a[j+1];
		l->countElem--;
		printf("numero %i excluido", i);
	}
}

/* Menu para o usuário interagir e fazer o que deseja com a lista sequêncial */
int main(){
	setlocale(LC_ALL, "Portuguese");
	int conti = 1;
	int addNum = 0;
	int numAux;
	lista* l = (lista*) malloc(sizeof(lista));
	iniciarLista(l);
		printf("\nOla esse e um programa para gerenciar uma lista de apenas um dado \n");
		printf("Use os numeros de 0 a 4 do teclado para navegar no menu.\n");
		printf("Comece digitando em qual menu deseja entrar.\n\n");
	do{
		printf("1: Inserir numero na lista\n");
		printf("2: Mostrar os numeros ja utilizado da lista\n");
		printf("3: Buscar numeros na lista\n");
		printf("4: Excluir lista ou apenas um numero\n");
		printf("0: Sair\n");
		scanf("%d", &conti);
		system("cls || clear");
		
		switch(conti){
			case 1:
				printf("Qual numero voce deseja adicionar?\n");
				registro reg;
				scanf("%d",&reg.numeros);
				inserirNumeroLista(l, reg, addNum);
				addNum++;
				printf("\n---------------------------------\n");
				break;
			case 2:
				printf("Esses sao os numeros.\n");
				exibirLista(l);
				tamanho(l);
				printf("\n---------------------------------\n");
				break;
			case 3:
				printf("Qual a casa que voce deseja buscar?\n");
				scanf("%d",&numAux);
				pesquisaUsuario(l, numAux);
				printf("\n---------------------------------\n");
				break;
			case 4:
				printf("Qual casa deseja excluir?\n");
				scanf("%d",&numAux);
				excluirNumero(l, numAux);
				printf("\n---------------------------------\n");
				break;
			case 0:
				printf("Obrigado e ate mais tarde.\n");
				printf("\n---------------------------------\n");
				break;
			
			default:
				printf("Digite um numero de 0 a 4, por favor.\n");
				printf("\n---------------------------------\n");
		}
	}while(conti);
}