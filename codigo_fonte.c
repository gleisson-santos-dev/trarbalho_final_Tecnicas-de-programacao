#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct
{
    char *NomeDaEmpresa;
    int CNPJ;
    int numeroDeFuncionarios;
    char *razaoSocial;
    char *setorDeAtuacao;

} empresa;

typedef struct
{
    char q1[100];
    int r[8];
    char q2[100];
    char q3[100];  
    char q4[100];
    char q5[150];
    char q6[150];
    char q7[100];
    char q8[100];

}quetionario;

//---------------------------------------------------------

int realizarCadastro(empresa *user); //pasagem por referencia
void apresentarMenu(empresa user, quetionario questoes); //pasagem por valor
void apresentarCadastro(empresa user);
void realizarQuestinario(quetionario questoes);
void PesquisaSim(quetionario q);
void PesquisaNao(quetionario q);
void MenuBusca(quetionario q);


//---------------------------------------------------------main

 int main()
{
    // idioma
    setlocale(LC_ALL, "Portuguese");
    
    empresa user;
    quetionario questoes;

    apresentarMenu(user, questoes);
    
    return 0;
}

//--------------------------------------------------------------------

void apresentarMenu(empresa user, quetionario questoes)
{
    int op;
    int situação_cadastro = 0;
    do
    {
        printf("\tmenu\n");
        printf("1- cadstrar empresa.\n0- sair\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            situação_cadastro = realizarCadastro(&user);
            break;

        case 0:
            printf("saindo!!!\n\n");
            break;

        default:
            printf("opção invalida\n");
            break;
        }

    }while(op != 0);

    if(situação_cadastro == 1)
    {
        do
        {
             printf("\tmenu\n");
        printf("1- responder questionario.\n2- conferir cadastro\n0- sair\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            realizarQuestinario(questoes);
            break;
        case 2:
            apresentarCadastro(user);
            break;
        case 0:
            printf("saindo!!!\n\n");
            break;

        default:
            printf("opção invalida\n");
            break;
        }

        }while(op != 0);
    }
    else if(situação_cadastro == 0){
        printf("\npara continuar é necesario realizar o cadastro\n.");
        
        apresentarMenu(user,questoes);
    }

}

int realizarCadastro(empresa *user)
{
    user->NomeDaEmpresa = malloc(50 * sizeof(char));
    user->razaoSocial = malloc(150 * sizeof(char));
    user->setorDeAtuacao = malloc(50 * sizeof(char));

    printf("qual o nome da sua empresa?\n");
    setbuf(stdin, NULL);
    fgets(user->NomeDaEmpresa, 100,stdin);

    printf("qual o CNPJ da sua empresa?\n");
    scanf("%d", &user->CNPJ);

    printf("qual o número de funcionarios da sua empresa?\n");
    scanf("%d", &user->numeroDeFuncionarios);
    
    printf("qual a razão social da sua empresa?\n");
    setbuf(stdin, NULL);
    fgets(user->razaoSocial, 150, stdin);

    printf("qual o setor em que sua empresa atua?\n");
    setbuf(stdin, NULL);
    fgets(user->setorDeAtuacao, 50, stdin);

    printf("cadastro realizado com sucesso\n");

    return 1;
}

void apresentarCadastro(empresa user)
{
    printf("\tnome: %s\n", user.NomeDaEmpresa);
    printf("CNPJ: %d\n", user.CNPJ);
    printf("número de funcionarios: %d\n", user.numeroDeFuncionarios);
    printf("razão social: %s", user.razaoSocial);
    printf("sertor: %s\n", user.setorDeAtuacao);
}

void realizarQuestinario(quetionario questoes){

    strcpy(questoes.q1,"1- Sua empresa traz meios de qualidade e segurança em seus serviços para o usuário?");
    strcpy(questoes.q2,"2- Sua empresa tem estimativas para expandir suas operações para países subdesenvolvidos?");
    strcpy(questoes.q3,"3- Sua empresa tem algum programa para desenvolvimento de empresas de pequeno porte e/ou startups?");
    strcpy(questoes.q4,"4- Sua empresa possui algum projeto para reduzir ao máximo os danos ao meio ambiente até 2030?");
    strcpy(questoes.q5,"5- Sua empresa possui alguma parceira público/privada o para alavancar as pesquisas científicas na sua area de atuação?");
    strcpy(questoes.q6,"6- Sua empresa possui projetos de cunho técnico para ajudar países com baixo desenvolvimento tecnológico?");
    strcpy(questoes.q7,"7- Sua empresa possui uma produção que diversifica a insústria e/ou agrega valor às commodities?");
    strcpy(questoes.q8,"8- Sua empresa conseguiu aumentar o acesso universal às tecnologias que produzem até 2020?");
    
    printf("\n\tquestionario sobre ODS\n obs: responda as questões com (1)pra SIM ou (0)pra NÃO\n");
    puts(questoes.q1);
    scanf("%d", &questoes.r[0]);
    
    
    puts(questoes.q2);
    scanf("%d", &questoes.r[1]);
    
    
    puts(questoes.q3);
    scanf("%d", &questoes.r[2]);
    
    
    puts(questoes.q4);
    scanf("%d", &questoes.r[3]);
    

    puts(questoes.q5);
    scanf("%d", &questoes.r[4]);
    

    puts(questoes.q6);
    scanf("%d", &questoes.r[5]);
    
    puts(questoes.q7);
    scanf("%d", &questoes.r[6]);
    
    
    puts(questoes.q8);
    scanf("%d", &questoes.r[7]);
   
     MenuBusca(questoes);

}
void PesquisaSim(quetionario q){
	int soma = 0, i;
	for(i=0;i<8;i++){
	if(q.r[i] == 1){
		soma ++;
	}
	}
	printf("\t%d Perguntas foram respondidas com sim\n\n", soma);

}
void PesquisaNao(quetionario q){
	int soma = 0, i;
	for(i=0;i<8;i++){
	if(q.r[i] == 0){
		soma ++;
	}
	}
	printf("\t%d Perguntas foram respondidas com nao\n\n", soma);

}

void MenuBusca(quetionario q){
	int op;
	do{
	printf("\tMenu  \n");
	printf("\n 1- Buscar a quantidade de Respostas Sim");
	printf("\n 2- Pesquisar a quantidade de Respostas Nao");
	printf("\n 0- Sair\n\n");
	scanf("%d", &op);
	
	switch(op){
		case 1:
			PesquisaSim(q);
			break;
		case 2:
			PesquisaNao(q);
			break;
		case 0:
			printf("\nsaindo!!\n\n");
			break;
		default:
			printf("\nopcao invalida\n");
	}
	
}	while(op != 0);
}
