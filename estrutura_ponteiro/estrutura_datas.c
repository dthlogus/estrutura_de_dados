
/* Implementar uma estrutura que recebe dia, mes e ano, e depois pode ser calculado para retorna alcance de outras datas estipuladas */

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

// Criando uma estrutura que tem dia, mes e ano com referencia em dma e recebendo o nome data.
typedef struct dma{
	int dia;
	int mes;
	int ano;
}data;

// Criando Array que contem os m�s que tem 31 dias.
int mesGrande[7] = {1, 3, 5, 7, 8, 10, 12};

// Verifica se ano � bissexto ou n�o
// Se ano n�o for divisivel por 4 mas � divisivel por 400 � bissexto
// Se ano for divisivel por 4 e divisivel por 100 n�o � bissexto
int verificadorAnoBissexto(int ano){
	if(ano % 4 != 0){
		if(ano % 400 == 0){
			return TRUE;
		}else{
			return FALSE;
		}
	}else{
		if(ano % 100 == 0){
			return FALSE;
		}else{
			return TRUE;
		}
	}
}

// Usa o Array de mesGrande, para verificar se o mes tem 31 dias ou n�o.
int verificadorDeMesGrande(int mes){
	int verificador;
	for(verificador = 0 ;verificador < 7 ;verificador++){
		if(mes == mesGrande[verificador]) return TRUE;
	}
	return FALSE;
}

// Aumenta o n�mero de dias na v�riavel acres.dia, e verifica se o ano � bissexto ou se � o �ltimo dia daquele m�s ou ano.
// Retorna o ano j� modificado para o usu�rio.
data acrecentadorDeDias(data acres){
	if(verificadorAnoBissexto(acres.ano)){
		if(acres.dia == 29 && acres.mes == 2){
			acres.dia = 1;
			acres.mes = 3;
			return acres;
		}
	}
	if(verificadorDeMesGrande(acres.mes) == TRUE && acres.dia == 31){
		if(acres.mes == 12){
			acres.dia = 1;
			acres.mes = 1;
			acres.ano++;
			return acres;
		}
		acres.dia = 1;
		acres.mes++;
		return acres;
	}
	if(verificadorDeMesGrande(acres.mes) != TRUE && acres.dia == 30){
		acres.dia = 1;
		acres.mes++;
		return acres;
	}
	acres.dia++;
	return acres;
}

// Calcula em que dia vai terminar a dura��o
// Em exemplo: dura��o = 15 de 01 01 2021 � 15 01 2021
// retorna a data para o usu�rio.
data fimEvento(data inicio, int duracao){
	unsigned long int contador;
	for(contador = 0 ;contador < duracao ;contador++){
		inicio = acrecentadorDeDias(inicio);
	}
	return inicio;
}

// Verifica se as datas do primeiro e do segundo s�o iguais
// Vai ser usado na fun��o valorEntreDatas.
int datasIguais(data primeira, data segunda){
	if(primeira.dia == segunda.dia){
		if(primeira.mes == segunda.mes){
			if(primeira.ano == segunda.ano){
				return 1;
			} else return 0;
		}else return 0;
	}else return 0;
}

// C�lcula quantos dias tem entre a data de in�cio 'data inicio' e a data final 'data fim'.
// Devolve um contador com o n�mero que representa esses dias.
void valorEntreDatas(data inicio, data fim){
	unsigned long int contador;
	while(datasIguais(inicio, fim) != 1){
		inicio = acrecentadorDeDias(inicio);
		contador++;
	}
	printf ("A diferenca entre os duas datas e: %d\n",contador);
}

int main(){
   data inicio, fim;
   printf ("Digite dia, mes e ano do inicial \n");
   scanf ("%d %d %d", &inicio.dia, &inicio.mes, &inicio.ano);
   printf("Digite dia, mes e ano final\n");
   scanf ("%d %d %d", &fim.dia, &fim.mes, &fim.ano);
   valorEntreDatas (inicio, fim);
   system("pause");
   return 0;
}
