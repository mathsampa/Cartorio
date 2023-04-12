#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por gerenciar as strings

//funções das opções do sistema
int registro() //função feita para cadastrar os usuários no banco de dados.
{
	//variaveis necessárias para o registro.
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char idade[40];
	char genero[40];
	char nacionalidade[40];
	char cargo[40];
	char telefone[40];

	printf("\t--- Registro de Usuários ---\n\n"); //menu da area de registro!
	printf("\tDigite o CPF a ser cadastrado no sistema: ");
	scanf("%s",cpf); //%s é usado para armazenar as strings na memória.
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings.
	
	FILE *file; //cria o arquivo.
	file = fopen(arquivo, "w"); //criando e abrindo o arquivo. "w" de write!
	fprintf(file,cpf); //salvando o valor da variável.
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
	
	printf("\tDigite o Gênero a ser cadastrado: ");
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
int consulta() //função de consultas
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF para ser consultado no sistema: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //abrindo o file e lendo o mesmo para fornecer as informações. "r" de read!
	
	if(file == NULL)
	{
		printf("Não foi possível localizar o usuário.\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}
int deletar() //função de deletar os usuários
{
	char cpf[40];
	
	printf("\t--- Deletar Usuários ---\n\n");
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
		if(file != NULL);
	{
		system("cls"); //limpa-se a tela para adicionar as novas informações sem confundir o cliente.
		printf("Usuário deletado com sucesso!\n\n");
		remove(cpf);
		system("pause"); //pausa o sistema nessa tela para que ele possa ler e não se perca na utilização do programa.
	}
		if(file == NULL)
	{
		printf("Esse usuário não foi localizado para ser deletado!!\n\n");
		system("pause");
	}
	
}
int erro() //função caso algum botão além de 1,2 e 3 sejam usados.
{
	printf("\t--- Essa função não está disponivel!! ---\n\n"); // \t dá um espaço para criar algo mais estético, nada que realmente influencie no código
	system("pause");
}
			
int main() //função principal de todo o projeto, ou seja o menu principal
{
	int opcao=0;
	int laco=1;

	for(laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //setando a localização e textos para PT-BR.
	
		printf("\t--- Cartório da EBAC ---\n\n"); //menu inicial
		printf("Escolha a opção desejada do menu:\n\n"); // \n ele é utilizado para pular uma linha dentro do programa.
	
	//opções para o usuário escolher.
		printf("\t1 - Registrar Usuários!\n");
		printf("\t2 - Consultar Usuários!\n");
		printf("\t3 - Deletar Usuários!\n"); 
		printf("\t4 - Sair do Sistema!\n\n");
		printf("Qual opção deseja acessar? : ");//fim do menu inicial

	//o scanf é feito para scanear o que o usuário digita/coloca.
	//%d é feito para armazenar uma informação de variavel no tipo inteiro da qual o usuário digitar.
		scanf("%d", &opcao);
	
		system("cls"); //isso é usado para dar um clear na tela.

	//respostas para cada uma das opções previamente citadas.
	switch (opcao)
	{
		case 1: //case 1, significa que a pessoa está tentando puxar o primeiro caso.
		registro(); //puxando a nossa função de registro.
		break; // e voltando para se criar o loop.
		
		case 2:
		consulta(); // puxando a função de consulta.
		break; // e voltando para se criar o loop.
		
		case 3:
		deletar(); //puxando a função de deletar.
		break; // e voltando para se criar o loop.
		
		case 4:
		printf("Obrigado por utilizar o sistema!!\n\n");
		return 0;
		break;
		
		default:
		erro(); // puxando a nossa função de erro.
		break; // e voltando para se criar o loop.
	}//fim das seleções
	
	}
}

