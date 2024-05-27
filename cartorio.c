#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por regiões
#include <string.h> //biblioteca responssável por cuidar das strings

int registro()//criando a função registro
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
	fprintf(file,",");//dado à ser acrescentado
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

int consulta()//criando a função consulta

{
	setlocale(LC_ALL, "Portuguese");//definindo o idioma da tela
	
	char cpf[40];//criando variavel para armazenar dados digitados pelo ususario
	char conteudo[200];//criando variavel para armazenar dados coletados do arquivo
	
	printf("Digite o CPF a ser consultado: ");//pedido o usuario para digitar os dados a serem consultados
	scanf("%s", cpf);//coletando informação do usuario
	
	FILE *file;
	file = fopen(cpf,"r");//abribdo o arquivo para ler
	
	if(file == NULL)//criando erro para alertar o usuario caso o arquivo nao exista
	{
		printf("Não foi possìvel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//puxando o arquivo para exibir ao usuario caso exista
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");
}

int deletar()//criando a função deletar
{
	setlocale(LC_ALL, "Portuguese");//definindo o idioma
	
	char cpf[40];//criando variavel para armazenar dados digitados pelo usuario
	
	printf("Digite o CPF do usuário a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);//excluindo o arquivo
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file == NULL)//gerando erro caso o arquivo nao exista
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
	
	fclose(file);//fechando o arquivo
}

int main()//criando a função principal
{
    int opcao=0; //Definindo variáveis
    int laco=1;//criando o laço para a tela retornar
    char senhadigitada[]="a";//criando uma variavel para armazenar a senha
    int comparacao;//criando uma variavel para fazer a comparação entre a senha digitada e a definida
    
    printf("### Cartório da EBAC ###\n\n");
    printf("Login de administrador!\n\nDigite a sua senha: ");
    scanf("%s", senhadigitada);
    
    comparacao = strcmp(senhadigitada, "admin");//comparando as senhas, a digitada e a do sistema
    
    if (comparacao == 0)
	
	{
	
	for (laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
		printf("###Cartório da EBAC###\n\n");//início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");//fim do menu
	
		scanf("%d", &opcao);//armazenando a escolha do usuário
	
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
			printf("Esta opção não está disponível!\n");
			system("pause");
			break;
				
		}
	
		
}
}

else
	printf("Senha Incorreta!");

}
	

