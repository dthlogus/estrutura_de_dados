/* Esse código é feito para encontrar a resposta para vida, o universo e tudo mais. Enquanto o usuário digita ele vai verificar quais números foram digitados e parar quando o usuário escrever 42, assim que ele parar ele vai ordem os números do maior para o menor e depois apresentar os mesmo para o usuário. */

/* Regras: 1. números acima de dois dígitos não serão contados. 2. O usuário pode adicionar quantos números quiser dentro do limite do array, mas o programa só vai parar até chegar no 42 ou no final do array. 3. O array tem que ser apresentado ao usuário de forma ordenada do maior para o menor. 4. Se chegar ao final do array e não tiver encontrado o 42 o programa tem que retornar os números e depois falar que não foi encontrado a resposta para a vida, o universo e tudo mais. */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAX 50

typedef struct{
	int answer;
}everthing;

typedef struct{
	everthing A[MAX];
	int count;
}answers;

// Iniciando o array answers na memória.
// Quando for iniciado ele vai apontar para a
void initiateAnswers(answers* a){
	a->count = 0;
}// Fim do initiateAnswers

// A função recebe um número
// verifica se number tem dois dígitos e devolve sendo verdadeiro ou falso
int checkNumbers(everthing number)
{
	if ((number.answer >= 0) && (number.answer <= 99)) 
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

// Insere number dentro do ponteiro a.
// Onde number é um número inteiro de dois digitos e pos é a posição dentro do array que ele será adicionado
void insert(answers* a, everthing number, int pos)
{
	if (checkNumbers(number))
	{
		if ((a->count >= MAX) || (pos > a->count))
		{
			printf("Nao adicionado, o array ja esta cheio.\n");
		}
		else
		{
			for (int liberador = a->count; liberador > pos; liberador--) a->A[pos] = a->A[liberador-1];
			a->A[pos] = number;
			a->count++;
			printf("Inserido com sucesso\n");
		}
	}
	else
	{
		printf("Nao adicioando, acima de 2 digitos ou nao e um numero\n");
	}
}// Fim do insert

// Ordena o vertor apontado em a
// Ele compara a posição atual com a próxima posição
// Se a posição atual for menor ele fica no seu lugar, se maior ele fazer a troca das duas posição.
void bubbleSort(answers* a){
	int aux;
	for (int lengthA = 0; lengthA < a->count; lengthA++)
	{
		for (int turn = 0; turn < a->count-1; turn++)
		{
			if (a->A[turn].answer > a->A[turn+1].answer)
			{
				aux = a->A[turn].answer;
				a->A[turn].answer = a->A[turn+1].answer;
				a->A[turn+1].answer = aux;
			}
		}
	}
}

//Verifica os números até a->A[n] = 42 ou até o final do array
//Se chegar ao final ele avisa que não foi encontrado a resposta para a vida
void untilAnswerLife(answers* a){
	int checker;
	printf(" \"");
	for (checker = 0; (checker <= a->count-1) && (a->A[checker].answer != 42); checker++){
		printf(" %d ", a->A[checker].answer);
	}
	printf(" \"\n");
	if ((checker == a->count) && (a->A[checker].answer != 42))
	{
		printf("\nA resposta para vida, o universo e tudo mais nao foi encontrado\n");
	}
	else
	{
		printf("\nA resposta para vida, o universo e tudo mais foi encontrado\n");
	}

}

// Transforma o array a vazio novamente.
// Ao coloca a->count=0 ele limpa as posições adjacentes
void empty(answers* a){
	a->count = 0;
}

int main(){
	int conti = 1;
	int position = 0;
	answers* a = (answers*) malloc(sizeof(answers));
	initiateAnswers(a);
	printf("Use os numeros de 0 a 4 do teclado para navegar no menu.\n");
	printf("Comece digitando em qual menu deseja entrar.\n\n");
	do{
		printf("1: Inserir numero na lista\n");
		printf("2: Ordenar Lista\n");
		printf("3: Mostrar os numeros ate a resposta da vida\n");
		printf("4: Limpar o array\n");
		printf("0: Sair\n");
		scanf("%d", &conti);
		system("cls || clear");
		
		switch(conti){
			case 1:
				printf("Qual numero voce deseja adicionar?\n");
				everthing number;
				scanf("%d",&number.answer);
				insert(a, number, position);
				position++;
				printf("\n---------------------------------\n");
				break;
			case 2:
				bubbleSort(a);
				printf("Array ordenado com bubble sort\n");
				printf("\n---------------------------------\n");
				break;
			case 3:
				untilAnswerLife(a);
				printf("\n---------------------------------\n");
				break;
			case 4:
				empty(a);
				printf("Array Limpo.\n");
				printf("\n---------------------------------\n");
				break;
			case 0:
				printf("Obrigado e ate mais tarde.\n");
				printf("\n---------------------------------\n");
				break;
			default:
				printf("Digite um numero de 0 a 3, por favor.\n");
				printf("\n---------------------------------\n");
		}
	}while(conti);
}