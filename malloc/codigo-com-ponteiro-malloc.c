#include <stdio.h>
#include <malloc.h>
#define ALTURAMAXIMA 300

typedef struct{
	int peso;
	int altura;
}pesoAltura;

int main(){
	pesoAltura* pessoa1 = (pesoAltura*) malloc(sizeof(pesoAltura));
	printf("================================\n");
	printf("==   Verificador de Altura    ==\n");
	printf("================================\n");
	printf("Por favor! digite seu peso.\n");
	scanf(" %i*c", &pessoa1->peso);
	printf("Por favor! digite sua altura.\n");
	scanf(" %i*c", &pessoa1->altura);
	if (pessoa1->altura <= ALTURAMAXIMA)
		printf("Sua altura e menor do que a altura maxima\n");
	else
		printf("Sual altura e maior que a altura maxima estipulada.\n");
	printf("================================\n");
	printf("==   Fim do Programa          ==\n");
	printf("================================\n");
	return 0;
}