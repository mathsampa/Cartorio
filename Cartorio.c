#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por gerenciar as strings

//fun��es das op��es do sistema
int registro() //fun��o feita para cadastrar os usu�rios no banco de dados.
{
	//variaveis necess�rias para o registro.
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char idade[40];
	char genero[40];
	char nacionalidade[40];
	char cargo[40];
	char telefone[40];

	printf("\t--- Registro de Usu�rios ---\n\n"); //menu da area de registro!
	printf("\tDigite o CPF a ser cadastrado no sistema: ");
	scanf("%s",cpf); //%s � usado para armazenar as strings na mem�ria.
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings.
	
	FILE *file; //cria o arquivo.
	file = fopen(arquivo, "w"); //criando e abrindo o arquivo. "w" de write!
	fprintf(file,cpf); //salvando o valor da vari�vel.
	fclose(file); //fecha o arquivo.
	
	file = fopen(arquivo, "a"); //atualiza o arquivo.
	fprintf(file,", "); //adiciona a virgula para maior facilidade de entendimento na hora da consulta.
	fclose(file); //fechando o arquivo.
	
	printf("\tDigite o nome a ser cadastrado no sistema: ");
	scanf("%s",nome); //coletando a string de nome.
	
	file = fopen(arquivo, "a"); //atualizando os dados.
	fprintf(file,nome); //adicionando o nome aos dados.
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("\tDigite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome); //coletando a string de sobrenome.
	
	file = fopen(arquivo, "a"); //atualizando os dados.
	fprintf(file,sobrenome); //adicionando o sobrenome aos dados.
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("\tDigite a Idade a ser cadastrada: ");
	scanf("%s",idade); //coletando a string de idade.
	
	file = fopen(arquivo, "a");
	fprintf(file,idade);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("\tDigite o G�nero a ser cadastrado: ");
	scanf("%s",genero); //coletando a string de genero.
	
	file = fopen(arquivo, "a");
	fprintf(file,genero);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("\tDigite a nacionalidade a ser cadastrada: ");
	scanf("%s",nacionalidade); //coletando a string de nacionalidade.
	
	file = fopen(arquivo, "a");
	fprintf(file,nacionalidade);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("\tDigite o cargo respectivo a ser cadastrado: ");
	scanf("%s",cargo); //coletando a string de cargo.
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	system("pause");
}
int consulta() //fun��o de consultas
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF para ser consultado no sistema: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //abrindo o file e lendo o mesmo para fornecer as informa��es. "r" de read!
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel localizar o usu�rio.\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}
int deletar() //fun��o de deletar os usu�rios
{
	char cpf[40];
	
	printf("\t--- Deletar Usu�rios ---\n\n");
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
		if(file != NULL);
	{
		system("cls"); //limpa-se a tela para adicionar as novas informa��es sem confundir o cliente.
		printf("Usu�rio deletado com sucesso!\n\n");
		remove(cpf);
		system("pause"); //pausa o sistema nessa tela para que ele possa ler e n�o se perca na utiliza��o do programa.
	}
		if(file == NULL)
	{
		printf("Esse usu�rio n�o foi localizado para ser deletado!!\n\n");
		system("pause");
	}
	
}
int erro() //fun��o caso algum bot�o al�m de 1,2 e 3 sejam usados.
{
	printf("\t--- Essa fun��o n�o est� disponivel!! ---\n\n"); // \t d� um espa�o para criar algo mais est�tico, nada que realmente influencie no c�digo
	system("pause");
}
			
int main() //fun��o principal de todo o projeto, ou seja o menu principal
{
	int opcao=0;
	int laco=1;

	for(laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //setando a localiza��o e textos para PT-BR.
	
		printf("\t--- Cart�rio da EBAC ---\n\n"); //menu inicial
		printf("Escolha a op��o desejada do menu:\n\n"); // \n ele � utilizado para pular uma linha dentro do programa.
	
	//op��es para o usu�rio escolher.
		printf("\t1 - Registrar Usu�rios!\n");
		printf("\t2 - Consultar Usu�rios!\n");
		printf("\t3 - Deletar Usu�rios!\n"); 
		printf("\t4 - Sair do Sistema!\n\n");
		printf("Qual op��o deseja acessar? : ");//fim do menu inicial

	//o scanf � feito para scanear o que o usu�rio digita/coloca.
	//%d � feito para armazenar uma informa��o de variavel no tipo inteiro da qual o usu�rio digitar.
		scanf("%d", &opcao);
	
		system("cls"); //isso � usado para dar um clear na tela.

	//respostas para cada uma das op��es previamente citadas.
	switch (opcao)
	{
		case 1: //case 1, significa que a pessoa est� tentando puxar o primeiro caso.
		registro(); //puxando a nossa fun��o de registro.
		break; // e voltando para se criar o loop.
		
		case 2:
		consulta(); // puxando a fun��o de consulta.
		break; // e voltando para se criar o loop.
		
		case 3:
		deletar(); //puxando a fun��o de deletar.
		break; // e voltando para se criar o loop.
		
		case 4:
		printf("Obrigado por utilizar o sistema!!\n\n");
		return 0;
		break;
		
		default:
		erro(); // puxando a nossa fun��o de erro.
		break; // e voltando para se criar o loop.
	}//fim das sele��es
	
	}
}

