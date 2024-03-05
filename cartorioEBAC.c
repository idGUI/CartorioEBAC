#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() // função responsável por cadastrar os usuários no sistema
{
	//início crianção de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim crianção de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: \n"); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo e o "w" significa escrever
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file, cpf); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualizar informação
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualizar informação
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualizar informação
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
	file = fopen(cpf,"r"); //lê o arquivo
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
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
		printf("Não localizado em Sistema. ");
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
		
		system("cls"); // responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese");
		
		printf("### Cartório da EBAC ###\n\n");
		printf("Ecolha uma das opções abaixo:\n");
		printf("\t1 - Resgitrar Nome\n");
		printf("\t2 - Consultar Nome\n");
		printf("\t3 - Deletar   Nome\n");
		printf("\t4 - Sair do Programa\n\n");
		printf("Opção: ");
		
		scanf("%d", &opcao);
		
		system("cls");
		
		switch(opcao)
		{ //início da seleção de opção
			case 1:
			registro();//chamada de função
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
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
		}//fim da seleção
	
	}

}
