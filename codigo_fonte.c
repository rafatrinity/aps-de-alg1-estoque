 /* autor: Rafael Trindade
 * versão: 2.2.1
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
#include "stdio.h"
#include "stdlib.h"
#include "locale.h"
#include <string.h>

// variaveis globais
int tot=0, cod[L], q[L], c, qt[L], tp;
char nome[L][C], dp[L][D];
float v[L], vt;

/*
 *Passo 1 - Fazer a leitura de produtos para colocar no estoque.
 *As informações de cada produto são um código numérico, uma descrição, quantidade de itens e o valor unitário de cada item.
 *Deverão ser lidos 10 produtos diferentes;
 */

void cadastro(){
	setlocale(LC_ALL,"portuguese");

	//UTILIZE A VIRGULA "," PARA SEPARAR VALORES DECIMAIS E NAO O PONTO "."

	tot++;
	printf("NOME DO PRODUTO: ");
	fflush(stdin);
	gets(nome[tot]);
	printf("VALOR DO PRODUTO: ");
	fflush(stdin);
	scanf("%f",&v[tot]);
	printf("DESCRIÇÃO DO PRODUTO: ");
	fflush(stdin);
	gets(dp[tot]);
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
		printf("\n===========================================================\n");
		printf("cod: %d nome: %s valor: R$%.2f ",cod[i],nome[i],v[i]);
		printf("\n===========================================================\n");
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
		printf("\n===========================================================\n");
		printf("cod: %d nome: %s valor unitário: R$%.2f\ndescrição: %s\nunidades: %d  valor total: R$%.2f ",cod[i],nome[i],v[i],dp[i],qt[i],v[i]*qt[i]);
		printf("\n===========================================================\n");
	}
}

// A atividade destina-se a construir um algoritmo ou programa que trate do fluxo de estoque de uma empresa:

int main(){

	setlocale(LC_ALL,"portuguese");
	printf("\n====CONTROLE DE ESTOQUE=====\n\n");

	// variaveis locais (main)

	int menu, i;
	char op, s;
	float vt;

	menu:
	
	if (tot>0)
	{
		system("cls");
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
			printf("\n===========================================================\n");
			printf("TOTAL DE PRODUTOS NO ESTOQUE: %d  \nVALOR TOTAL EM ESTOQUE: R$%.2f",tp,vt);
			printf("\n===========================================================\n\n");
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
		goto erro;
		break;
	}

	cadastro:


	do
	{
		erro1:

		if (tot==0)
		{
			printf("\nVC AINDA NÃO TEM PRODUTOS CADASTRADOS NO ESTOQUE\nCADASTRE UM PRODUTO \n==========================================\n");
			s='s';
		}

		else if (tot==1)
		{
			printf("\nVC CADASTROU SEU 1° PRODUTO NO ESTOQUE\nDESEJA CADASTRAR UM NOVO PRODUTO? \nS = sim N = não ");
			fflush(stdin);
			scanf("%c",&s);
			printf("==========================================\n\n");
		}

		else
		{
			printf("\nVC TEM %d PRODUTOS CADASTRADOS NO ESTOQUE\nDESEJA CADASTRAR UM NOVO PRODUTO? \nS = sim N = não ",tot);
			fflush(stdin);
			scanf("%c",&s);
			printf("==========================================\n\n");
		}

		if(s=='n'||s=='N')
		{
			goto menu;
		}

		else if (tot>=L)
		{
			printf("\n==========================================\n\n\t\aVC ATINGIU O LIMITE DE PRODUTOS QUE PODEM SER CADASTRADOS.\n");
			goto menu;
		}

		else if (s=='s'||s=='S')
		{
			cadastro();
		}

		else
		{
			printf("\n\n\t\aDIGITE APENAS S OU N! OUTROS VALORES SERÃO IGNORADOS.");
			printf("\t\n=====================================================\n");
			goto erro1;
		}
	}

	while(s=='s'||s=='S');

	add:

	if (op=='a'||op=='A')
	{

		erro3:

		printf("\ncod DO PRODUTO: ");
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





