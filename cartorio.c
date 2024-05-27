#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�es
#include <string.h> //biblioteca responss�vel por cuidar das strings

int registro()//criando a fun��o registro
{
	
	char arquivo[40];//criando o arquivo
	char cpf[40];//alocando memoria para cpf
	char nome[40];// memoria para nome
	char sobrenome[40];//memoria para sobrenome
	char cargo [40];//memoria para cargo
	
	printf("Digite o CPF a ser cadastrado: ");//solicitando o cpf
	scanf("%s", cpf);//lendo e armazenando os dados digitados na strinq %s
	
	strcpy(arquivo, cpf);//Responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");//abrindo o arquivo para escrever, criar o mesmo de fato
	fprintf(file,cpf);//salva o valor da variavel no arquivo
	fclose(file);// fechando o arquivo
	
	file = fopen(arquivo, "a");//acrescentando dados ao arquivo 
	fprintf(file,",");//dado � ser acrescentado
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");//pedindo ao usuario para digitar o nome
	scanf("%s", nome);//armazenando o nome digitado

	file = fopen(arquivo, "a");//abrindo o arquivo para acrescentar dados
	fprintf(file,nome);//acrescentando os dados dentro do arquivo
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);

	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);

	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);

	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);

	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");//dando uma pausa para a tela nao passar direto
}

int consulta()//criando a fun��o consulta

{
	setlocale(LC_ALL, "Portuguese");//definindo o idioma da tela
	
	char cpf[40];//criando variavel para armazenar dados digitados pelo ususario
	char conteudo[200];//criando variavel para armazenar dados coletados do arquivo
	
	printf("Digite o CPF a ser consultado: ");//pedido o usuario para digitar os dados a serem consultados
	scanf("%s", cpf);//coletando informa��o do usuario
	
	FILE *file;
	file = fopen(cpf,"r");//abribdo o arquivo para ler
	
	if(file == NULL)//criando erro para alertar o usuario caso o arquivo nao exista
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//puxando o arquivo para exibir ao usuario caso exista
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");
}

int deletar()//criando a fun��o deletar
{
	setlocale(LC_ALL, "Portuguese");//definindo o idioma
	
	char cpf[40];//criando variavel para armazenar dados digitados pelo usuario
	
	printf("Digite o CPF do usu�rio a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);//excluindo o arquivo
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file == NULL)//gerando erro caso o arquivo nao exista
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
	
	fclose(file);//fechando o arquivo
}

int main()//criando a fun��o principal
{
    int opcao=0; //Definindo vari�veis
    int laco=1;//criando o la�o para a tela retornar
    char senhadigitada[]="a";//criando uma variavel para armazenar a senha
    int comparacao;//criando uma variavel para fazer a compara��o entre a senha digitada e a definida
    
    printf("### Cart�rio da EBAC ###\n\n");
    printf("Login de administrador!\n\nDigite a sua senha: ");
    scanf("%s", senhadigitada);
    
    comparacao = strcmp(senhadigitada, "admin");//comparando as senhas, a digitada e a do sistema
    
    if (comparacao == 0)
	
	{
	
	for (laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
		printf("###Cart�rio da EBAC###\n\n");//in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: ");//fim do menu
	
		scanf("%d", &opcao);//armazenando a escolha do usu�rio
	
		system("cls");
		
		switch(opcao)
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;//finalizando o sistema.
			break;
			
			default:
			printf("Esta op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
				
		}
	
		
}
}

else
	printf("Senha Incorreta!");

}
	

