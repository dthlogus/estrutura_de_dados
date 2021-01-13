// Recebe um valor em minutos e descreve quantas horas esse valor representa.
// Exemplo: 120 minutos equivalem a 2 horas.
#include <stdio.h>
#include <math.h>

typedef struct hm{
	int horas;
	int minutos;
}horas;

void conversorDeMinutos(int minuto){
	horas retorno;
	retorno.horas = minuto / 60;
	retorno.minutos = minuto % 60;
	if(retorno.minutos != 0){
		round(retorno.minutos);
	}
	printf("%d minutos, equivalem a %d horas e %d minutos.\n", minuto, retorno.horas, retorno.minutos);
}

int main () {
	int minuto;
	printf("Bem vindo ao conversor de minutos por favor, digite quantos minutos quer que seja calculado.\n");
	scanf("%d",&minuto);
	conversorDeMinutos(minuto);
	system("pause");
}
