 /* autor: Rafael Trindade
 * versão: 3.0.0
 * opcional (alertas visuais e sonoros contra erros, ampliação da quantidade de produtos que podem ser cadastrados e redução de linhas)
 * O trabalho pode ser entregue em algoritmo, linguagem C ou Pascal. Deve ser enviado um arquivo com o código escrito.
 * Não é para entregar o código executável.
 */

#define L 10
#define C 50
#define D 100
/*
 * (#define L) = quantidade máxima de produtos que podem ser cadastrados,
 * esse valor pode ser alterado conforme suas nececidades.
 *
 * (#define C & D) = quantiade máxima de caracteres para os nomes e descrições dos produtos respectivamente.
 * esse valor pode ser alterado conforme suas nececidades.
 */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

// variaveis globais
int tot=0, cod[L], q[L], c, qt[L], tp;
char nome[L][C], dp[L][D], SISTEMA;
float v[L], vt;

/*
 *Passo 1 - Fazer a leitura de produtos para colocar no estoque.
 *As informações de cada produto são um código numérico, uma descrição, quantidade de itens e o valor unitário de cada item.
 *Deverão ser lidos 10 produtos diferentes;
 */
char apresenta(){
	/*
	.::::.  ::      .::::.  ||
	::  ::  ::      ::  ::  ||
	::  ::  ::      ::::::  ||
	*::::*  ::::::  ::  ::  ::
    */
	printf("\t.::::.  ::      .::::.  ||\n");
	usleep(200000);
	printf("\t::  ::  ::      ::  ::  ||\n");
	usleep(200000);
	printf("\t::  ::  ::      ::::::  ||\n");
	usleep(200000);
	printf("\t*::::*  ::::::  ::  ::  ::\n\n");
	printf("\tPOR GENTILEZA, INFORME QUAL SISTEMA OPERACIONAL VC UTILIZA:\nD=DOS\nU=UNIX\n\n");
	printf("\tDUVIDAS? DIGITE (i) PARA MAIS INFORMAÇÕES\n");
	pergunta:
	fflush(stdin);
	scanf("%c",&SISTEMA);
	SISTEMA=toupper(SISTEMA);
	switch(SISTEMA){
		case 'D':
		system("cls");
		fflush(stdin);
		break;
		case 'U':
		system("clear");
		getchar();
		break;
		case 'I':
		printf("\nDOS = Window\nUNIX = Mac e Linux(há exeções)");
		getchar();
		goto pergunta;
		break;
		default:
		printf("\nENTRADA INVALIDA, FAVOR DIGITAR SOMENTE AS LETRAS INDICADAS\n");
		goto pergunta;
	}
	return SISTEMA;
}

void cadastro(){
	setlocale(LC_ALL,"portuguese");

	//UTILIZE A VIRGULA "," PARA SEPARAR VALORES DECIMAIS E NAO O PONTO "."

	tot++;
	printf("NOME DO PRODUTO: ");
	if (SISTEMA=='D')
		fflush(stdin);
	else
		getchar();
	fgets(nome[tot], C, stdin);
	printf("VALOR DO PRODUTO: ");
	fflush(stdin);
	scanf("%f",&v[tot]);
	printf("DESCRIÇÃO DO PRODUTO: ");
	if (SISTEMA=='D')
		fflush(stdin);
	else
		getchar();
	fgets(dp[tot], C, stdin);
	cod[tot]=tot;

}

/*
 *Passo 2 - A partir da leitura inicial, poderão ser realizadas as seguintes operações:
 *Inclusão de novos itens no estoque, para produtos já cadastrados anteriormente no primeiro passo. 
 *Nesse momento basta que seja lido o código do produto e quantos itens deseja-se inserir.
 *Após isso, atualizar a quantidade de itens no estoque.
 */

void ADD(){
	setlocale(LC_ALL,"portuguese");

	printf("QUANTAS UNIDADES DO PRODUTO %s VC DESEJA add AO ESTOQUE? ",nome[c]);
	scanf("%d",&q[c]);

	if (q[c]<=0)
	{
		printf("\nDIGITE VALORES MAIORES QUE 0! \n");
		exit;
	}

	else
	{
		qt[c]+=q[c];
		printf("VC add %d UNIDADES DO PRODUTO %s AO ESTOQUE\nVALOR UNITÁRIO: %.2f\nVALOR TOTAL DA TRANSAÇÃO: R$%.2f \n",q[c],nome[c],v[c],v[c]*q[c]);
		sleep(3);
	}
}

/*
 *Passo 2 - A partir da leitura inicial, poderão ser realizadas as seguintes operações:
 *Retirada de tens no estoque. Nesse momento basta que seja lido o código do produto e quantos itens deseja-se retirar.
 *Caso a quantidade a ser retirada for maior do que atual em estoque, deve ser dada uma mensagem dizendo "Estoque Insuficiente".
 *Caso contrário atualizar a quantidade em estoque.
 */

void retirar(){
	setlocale(LC_ALL,"portuguese");

	printf("QUANTAS UNIDADES DO PRODUTO %s VC DESEJA RETIRAR DO ESTOQUE? ",nome[c]);
	scanf("%d",&q[c]);

	if (q[c]>qt[c])
	{
		printf("\n\t\aESTOQUE INSUFICIENTE! \n");
		sleep(1);
		if (SISTEMA=='D')
			system("pause");
		else
			getchar();
		fflush(stdin);
		exit;
	}

	else if (q[c]<=0)
	{
		printf("\n\t\aDIGITE VALORES MAIORES QUE 0! \n");
		exit;
	}

	else
	{
		qt[c]-=q[c];
		printf("VC RETIROU %d UNIDADES DO PRODUTO %s AO ESTOQUE\nVALOR UNITÁRIO: %.2f\nVALOR TOTAL DA TRANSAÇÃO: R$%.2f \n",q[c],nome[c],v[c],v[c]*q[c]);
		sleep(3);
	}
}

void produtos(){
	setlocale(LC_ALL,"portuguese");

	if (tot==1)
	{
		printf("\nO SEGUINTE PRODUTO ESTÁ CADASTRADO:\t\n");
	}

	else if (tot>1)
	{
		printf("\nOS SEGUINTES PRODUTOS ESTÃO CADASTRADOS:\t\n");
	}

	int i;

	for (i = 1; i <= tot; ++i)
	{
		linha();
		printf("cod: %d nome: %s valor: R$%.2f ",cod[i],nome[i],v[i]);
		linha();
	}
}

/*
 *Passo 3 - Após a finalização do passo 2, deve-se mostrar na tela:
 *- a quantidade atual em estoque de cada um dos 10 produtos (quantidade de itens de cada produto e o valor total em estoque de cada produto).
 *- valor total do estoque (a soma dos valores totais de cada produto).
 */

void detalhes(){
	setlocale(LC_ALL,"portuguese");

	printf("\nDETALHES: \t\n");
	int i;

	for (i = 1; i <= tot; ++i)
	{
		linha();
		printf("cod: %d nome: %s valor unitário: R$%.2f\ndescrição: %s\nunidades: %d  valor total: R$%.2f ",cod[i],nome[i],v[i],dp[i],qt[i],v[i]*qt[i]);
		linha();
		getchar();
		fflush(stdin);
	}
}
void linha(){
	if(SISTEMA=='U')
		usleep(100000);
	printf("\n");
	for (int i = 0; i < 60; ++i)
	{
		printf("=");
		if(SISTEMA=='D')
			usleep(20000);
	}
	if(SISTEMA=='U')
		usleep(100000);
	printf("\n");
}

// A atividade destina-se a construir um algoritmo ou programa que trate do fluxo de estoque de uma empresa:

int main(){

	setlocale(LC_ALL,"portuguese");
	// variaveis locais (main)

	int menu, i;
	char op, s;
	float vt;
	SISTEMA = apresenta();
	menu:
	
	if (tot>0)
	{
		if (SISTEMA=='D')
			system("cls");
		else
			system("clear");
		
		printf("\n============MENU============\n\n");
	}
	tp=0;
	vt=0;
	for (i = 1; i <= tot; ++i)
	{
		tp+=qt[i];
		vt+=qt[i]*v[i];
	}
	printf("(1) CADASTRAR  NOVO  PRODUTO              %d\n",tot);
	printf("(2) ADD  ITENS  AO   ESTOQUE\n");
	printf("(3) RETIRAR ITENS DO ESTOQUE              %d\n",tp);
	printf("(4) INFORMAÇÕES  DO  ESTOQUE \n");
	printf("(5) SAIR \n");

	erro:

	scanf("%d",&menu);

	switch(menu)
	{
		case 1:
		goto cadastro;
		break;

		case 2:
		if(tot>0){
			produtos();
			op='a';
			goto add;
		}

		else{
			printf("\n\t\aPARA ADD PRODUTOS AO ESTOQUE VC PRECISA CADASTRA-LOS PRIMEIRO\n");
			printf("\n\tDESEJA CADASTRAR UM NOVO PRODUTO AGORA? S=SIM N=NÃO\n");
			fflush(stdin);
			scanf("%c",&s);

			if (s=='s'||s=='S')
			{
				cadastro();
				goto cadastro;
			}

			else{
				goto menu;
			}
		}
		break;

		case 3:
		if(tot>0){
			produtos();
			op='r';
			goto add;
		}

		else
		{

			printf("\n\t\aPARA RETIRAR PRODUTOS DO ESTOQUE VC PRECISA CADASTRA-LOS PRIMEIRO\n");
			printf("\n\t\aDESEJA CADASTRAR UM NOVO PRODUTO AGORA? S=SIM N=NÃO\n");
			fflush(stdin);
			scanf("%c",&s);

			if (s=='s'||s=='S')
			{
				cadastro();
				goto cadastro;
			}

			else
			{
				goto menu;
			}
		}
		break;

		case 4:
		if (tot>0)
		{
			detalhes();
			linha();
			printf("TOTAL DE PRODUTOS NO ESTOQUE: %d  \nVALOR TOTAL EM ESTOQUE: R$%.2f",tp,vt);
			linha();
		}

		else
		{
			printf("\n\t\aPARA VISUALIZAR OS DETALHES DOS PRODUTOS DO ESTOQUE VC PRECISA CADASTRA-LOS PRIMEIRO\n");
			printf("\n\tDESEJA CADASTRAR UM NOVO PRODUTO AGORA? S=SIM N=NÃO\n");
			fflush(stdin);
			scanf("%c",&s);

			if (s=='s'||s=='S')
			{
				cadastro();
				goto cadastro;
			}

			else
			{
				goto menu;
			}
		}
		break;

		case 5:
		goto fim;
		break;

		default:

		printf("\n\t\aOPÇÃO INVALIDA!\n");
		fflush(stdin);
		if (SISTEMA=='D')
			system("pause");
		else
			getchar();
		goto erro;
		break;
	}

	cadastro:


	do
	{
		erro1:

		if (tot==0)
		{
			linha();
			s='s';
		}

		else if (tot==1)
		{
			printf("\nVC CADASTROU SEU 1° PRODUTO NO ESTOQUE\nDESEJA CADASTRAR UM NOVO PRODUTO? \nS = sim N = não ");
			fflush(stdin);
			scanf("%c",&s);
			linha();
		}

		else
		{
			printf("\nVC TEM %d PRODUTOS CADASTRADOS NO ESTOQUE\nDESEJA CADASTRAR UM NOVO PRODUTO? \nS = sim N = não ",tot);
			fflush(stdin);
			scanf("%c",&s);
			linha();
		}

		if(s=='n'||s=='N')
		{
			goto menu;
		}

		else if (tot>=L)
		{
			linha();
			printf("\n\t\aVC ATINGIU O LIMITE DE PRODUTOS QUE PODEM SER CADASTRADOS.\n");
			goto menu;
		}

		else if (s=='s'||s=='S')
		{
			cadastro();
		}

		else
		{
			printf("\n\n\t\aDIGITE APENAS S OU N! OUTROS VALORES SERÃO IGNORADOS.");
			linha();
			goto erro1;
		}
	}

	while(s=='s'||s=='S');

	add:

	if (op=='a'||op=='A')
	{

		erro3:

		printf("\ncod DO PRODUTO: ");
		fflush(stdin);
		scanf("%d",&c);
		printf("\n");


		if (c<=tot && c>0)
		{
			ADD();
			goto menu;
		}

		else
		{
			printf("\n\n\t\a=======CÓDIGO INVALIDO!=======\n\n");
			goto erro3;
		}
	}

	/*Retirada de tens no estoque. Nesse momento basta que seja lido o código do produto e quantos itens deseja-se retirar.
	 *Caso a quantidade a ser retirada for maior do que atual em estoque, deve ser dada uma mensagem dizendo "Estoque Insuficiente".
	 *Caso contrário atualizar a quantidade em estoque.
	 */

	else if (op=='r'||op=='R'){

		erro4:

		printf("\ncod DO PRODUTO: ");
		fflush(stdin);
		scanf("%d",&c);
		printf("\n");
		if (c<=tot && c>0)
		{
			retirar();
			goto menu;
		}

		else
		{
			printf("\n\n\t\a=======CÓDIGO INVALIDO!=======\n\n");
			goto erro4;
		}
	}

	fim:
	return 0;
}





