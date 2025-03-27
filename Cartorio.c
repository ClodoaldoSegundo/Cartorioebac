#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro () //função responsável por cadastrar os usúarios no sistema
{
	//inicio da criação de variaveís/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveís/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando as informações do usúario
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" signífica "escrever"
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecho o arquivo aqui
	
	file = fopen(arquivo, "a");//o "a" significa "analisar"
	fprintf(file,",");
	fclose(file); //fecho o arquivo aqui
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen (arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
	
}

int consulta()
{
	
 	setlocale(LC_ALL, "Portuguese");// feito para funcionar os acentos e outros
 	
	char cpf[40];//char significa uma das variaveís que estão nas strings
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
	printf("Não foi possivel abrir o arquivo, não localizado!\n");
	}	
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	printf("\nEssas são as informações do usúario: ");
	printf("%s", conteudo);
	printf("\n\n");
	}
	
	system("pause");
	fclose(file);
	
	
	}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usúario a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL);
	{
	printf("O usuário não se encontra no sistema.\n");
	system("pause");
	}
	
	
	
}




int main()
{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
		
		
		system("cls"); //responsável por limpar a tela
	
	  setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	  printf("##### Cartório da EBAC #####\n\n"); //inicio do menu
	  printf("Escolha a opção que deseja no menu:\n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar os nomoes\n");
	  printf("\t3 - Deletar nomes\n\n");
	  printf("\t4 - Sair do sistema\n\n");
	  printf("Opção: ");//fim do menu
	
	  scanf("%d", &opcao); //armazenando a escolha do usuario
	
	  system("cls"); //responsável por limpar a tela
	  
	  switch(opcao)
	  {
	  	case 1:
	  	registro(); //chamada de funções
		break;
		
		case 2:
	  	consulta();
		break;
		
		case 3:
	  	deletar();
		break;
		
		case 4:
		printf("Obrigada por utilizar o sistema!");
		return 0;
		break;
		
		
		
		default:
	 	printf("Esta opcao não esta disponivel!\n");
		system("pause");
		break;
		
	   }		
	
	}	

}

