/* Verificador de tamanho de célula */

#include <stdio.h>
#include <stdlib.h>

// Criando e definindo um tipo que tem um conteúdo e aponta para o próximo.
typedef struct reg{
	int conteudo;
	int *prox;
}celula;

// Iniciando um tipo célula.
celula c;

int main(){
	printf("O tamanho em bytes do tipo e: %d bytes\n",sizeof(celula));
	system("pause");
	return 0;
}
