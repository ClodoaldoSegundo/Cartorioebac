#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro () //fun��o respons�vel por cadastrar os us�arios no sistema
{
	//inicio da cria��o de variave�s/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variave�s/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando as informa��es do us�ario
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" sign�fica "escrever"
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
 	
	char cpf[40];//char significa uma das variave�s que est�o nas strings
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
	printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
	}	
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	printf("\nEssas s�o as informa��es do us�ario: ");
	printf("%s", conteudo);
	printf("\n\n");
	}
	
	system("pause");
	fclose(file);
	
	
	}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do us�ario a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL);
	{
	printf("O usu�rio n�o se encontra no sistema.\n");
	system("pause");
	}
	
	
	
}




int main()
{
	int opcao=0; //definindo vari�veis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
		
		
		system("cls"); //respons�vel por limpar a tela
	
	  setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	  printf("##### Cart�rio da EBAC #####\n\n"); //inicio do menu
	  printf("Escolha a op��o que deseja no menu:\n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar os nomoes\n");
	  printf("\t3 - Deletar nomes\n\n");
	  printf("\t4 - Sair do sistema\n\n");
	  printf("Op��o: ");//fim do menu
	
	  scanf("%d", &opcao); //armazenando a escolha do usuario
	
	  system("cls"); //respons�vel por limpar a tela
	  
	  switch(opcao)
	  {
	  	case 1:
	  	registro(); //chamada de fun��es
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
	 	printf("Esta opcao n�o esta disponivel!\n");
		system("pause");
		break;
		
	   }		
	
	}	

}

