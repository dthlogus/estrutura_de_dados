/* Verificador de tamanho de c�lula */

#include <stdio.h>
#include <stdlib.h>

// Criando e definindo um tipo que tem um conte�do e aponta para o pr�ximo.
typedef struct reg{
	int conteudo;
	int *prox;
}celula;

// Iniciando um tipo c�lula.
celula c;

int main(){
	printf("O tamanho em bytes do tipo e: %d bytes\n",sizeof(celula));
	system("pause");
	return 0;
}
