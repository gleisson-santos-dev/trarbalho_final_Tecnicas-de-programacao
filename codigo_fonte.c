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
    int r1;
    char q2[100];
    int r2;
    char q3[100];
    int r3;
    char q4[100];
    int r4;
    char q5[100];
    int r5;
    char q6[100];
    int r6;
    char q7[100];
    int r7;
    char q8[100];
    int r8;

}quetionario;

//---------------------------------------------------------

int realizarCadastro(empresa *user); //pasagem por referencia
void apresentarMenu(empresa user, quetionario questoes); //pasagem por valor
void apresentarCadastro(empresa user);
void realizarQuestinario(quetionario questoes);



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
    
    printf("\n\tquestionari sobre ODS\n obs: responda as questões com (1)pra SIM ou (0)pra NÃO\n");
    puts(questoes.q1);
    scanf("%d", &questoes.r1);

    puts(questoes.q2);
    scanf("%d", &questoes.r2);

    puts(questoes.q3);
    scanf("%d", &questoes.r3);
    
    puts(questoes.q4);
    scanf("%d", &questoes.r4);

    puts(questoes.q5);
    scanf("%d", &questoes.r5);

    puts(questoes.q6);
    scanf("%d", &questoes.r6);

    puts(questoes.q7);
    scanf("%d", &questoes.r7);

    puts(questoes.q8);
    scanf("%d", &questoes.r8);

}
