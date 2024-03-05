#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() // fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio crian��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim crian��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: \n"); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo e o "w" significa escrever
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file, cpf); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualizar informa��o
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualizar informa��o
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualizar informa��o
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //l� o arquivo
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	printf("Digite o CPF a ser Deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o localizado em Sistema. ");
		system("pause");
	}
	
	fclose(file);
	
}

int main ()
{
	
	int opcao = 0;
	int laco = 1;
	
	for(laco = 1; laco = 1;)
	{
		
		system("cls"); // respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese");
		
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Ecolha uma das op��es abaixo:\n");
		printf("\t1 - Resgitrar Nome\n");
		printf("\t2 - Consultar Nome\n");
		printf("\t3 - Deletar   Nome\n");
		printf("\t4 - Sair do Programa\n\n");
		printf("Op��o: ");
		
		scanf("%d", &opcao);
		
		system("cls");
		
		switch(opcao)
		{ //in�cio da sele��o de op��o
			case 1:
			registro();//chamada de fun��o
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Programa encerrado. Pressione Enter para ferchar a janela.");
			return(0);
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		}//fim da sele��o
	
	}

}
