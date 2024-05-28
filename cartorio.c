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
	
	file = fopen(arquivo, "a");//abrindo o arquivo para acrescentara dados
	fprintf(file,",");//acrescentando uma virgula no arquivo
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");//pedindo ao usuario para digitar o nome
	scanf("%s", nome);//armazenando o nome digitado

	file = fopen(arquivo, "a");//abrindo o arquivo para acrescentar dados
	fprintf(file,nome);//acrescentando o nome dentro do arquivo
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo, "a");//abrindo o arquivo para acrescentara dados
	fprintf(file,",");//acrescentando uma virgula no arquivo
	fclose(file);//fechando o arquivo

	printf("Digite o sobrenome a ser cadastrado: ");//pedindo ao usuario para digitar o sobrenome
	scanf("%s", sobrenome);//armazenando o sobrenome digitado

	file = fopen(arquivo, "a");//abrindo o arquivo para acrescentar dados
	fprintf(file,sobrenome);//acrescentando o sobrenome no arquivo
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo, "a");//abrindo o arquivo para acrescentara dados
	fprintf(file,",");//acrescentando uma virgula no arquivo
	fclose(file);//fechando o arquivo

	printf("Digite o cargo a ser cadastrado: ");//pedindo ao usuario para digitar o cargo
	scanf("%s", cargo);//armazenando o cargo digitado

	file = fopen(arquivo, "a");//abrindo o arquivo para acrescentara dados
	fprintf(file,cargo);//acrescentando o cargo no arquivo
	fclose(file);//fechando o arquivo
	
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
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");//retornando erro ao usuario
	}
	
	while(fgets(conteudo, 200, file) != NULL)//puxando o arquivo para exibir ao usuario caso exista
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");//retornando positivo a solicita��o do usu�rio
		printf("%s", conteudo);//exibindo na tela os dados do arquivo
		printf("\n\n");//exibindo espa�os na tela para melhor visualiza��o
	}
	fclose(file);//fechando o arquivo
	system("pause");//dando uma pausa para a tela nao passar direto
}

int deletar()//criando a fun��o deletear
{
	char cpf[40];//criando variavel para armazenar cpf digitado
	
	printf("Digite o CPF do usu�rio a ser deletado: ");//solicitando o cpf a ser excluido
	scanf("%s",cpf);//armazenando o cpf a ser excluido
		
		
	
	FILE *file;	
	file = fopen(cpf,"r");//abrindo o arquivo
	
	if(file == NULL)//condicionando para retornar erro ao usuario
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");//retornando erro ao usuario pelo cpf nao existir
		system("pause");//dando uma pausa para a tela nao passar direto
	}
	else//condicionando para exclusao do cpf
	{
		fclose(file);//abrindo o arquivo
		remove(cpf);//excluindo o arquivo
		FILE *file;	
		file = fopen(cpf,"r");//abrindo novamente o arquivo para retornar confirma��o ao usuario
		if(file == NULL)//condicionando para retorno ao usuario
		{
			printf("Usu�rio deletado com sucesso!.\n");//retornando positivo para exclusao
			system("pause");//dando uma pausa para a tela nao passar direto
		}
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
    printf("Login de administrador!\n\nDigite a sua senha: ");//solicitando a senha ao usuario
    scanf("%s", senhadigitada);//armazenando a senha digitada
    
    comparacao = strcmp(senhadigitada, "admin");//comparando as senhas, a digitada e a do sistema
    
    if (comparacao == 0)//igualando a senha a0 para liberar o acesso 
	
	{
	
	for (laco=1;laco=1;)//definindo o la�o
	{
	
		system("cls");//limpando a tela
		
		setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
		printf("###Cart�rio da EBAC###\n\n");//in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");//solicitando ao usuario para escolher uma op��o
		printf("\t1 - Registrar nomes\n");//dando op��o de registro
		printf("\t2 - Consultar nomes\n");//dando op��o de consulta
		printf("\t3 - Deletar nomes\n");//dando op��o de deletar
		printf("\t4 - Sair do sistema\n\n");//dando op�ao de sair do sistema
		printf("Op��o: ");//fim do menu
	
		scanf("%d", &opcao);//armazenando a escolha do usu�rio
	
		system("cls");//limpando a tela
		
		switch(opcao)//definindo as a��es do software de acordo com as op��o selecionanda
		{
			case 1:
			registro();//chamando a fun��o registro caso a op��o seja 1
			break;
			
			case 2:
			consulta();//chamando a fun��o consulta caso a op��o seja 2
			break;
			
			case 3:
			deletar();//chamando a fun��o deletar caso a op��o seja 3
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;//finalizando o sistema.
			break;
			
			default:
			printf("Esta op��o n�o est� dispon�vel!\n");
			system("pause");//dando uma pausa para a tela nao passar direto
			break;
				
		}
	
		
}
}

else
	printf("Senha Incorreta!");//retornando a senha incorreta caso o valor retorne diferente de 0

}
	

