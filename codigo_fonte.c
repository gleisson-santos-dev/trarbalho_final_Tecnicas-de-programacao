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

} quetionario;

//----------------------------------------------------------------------

int realizarCadastro(empresa *user);                                    // pasagem por referencia
void apresentarMenu(empresa user, quetionario questoes, FILE *arquivo); // pasagem por valor
void apresentarCadastro(empresa user);
int realizarQuestinario(quetionario questoes, FILE *arquivo);
void PesquisaSim(quetionario q);
void PesquisaNao(quetionario q);
void MenuBusca(quetionario q);
void manipulaArquivo(empresa *user, quetionario questoes, FILE *arquivo);

//-----------------------------------------------------------------------main

int main()
{
    // idioma
    setlocale(LC_ALL, "Portuguese");

    empresa user;
    quetionario questoes;
    FILE *arquivo;

    apresentarMenu(user, questoes, arquivo);

    return 0;
}

//--------------------------------------------------------------------

void apresentarMenu(empresa user, quetionario questoes, FILE *arquivo)
{
    int op;
    int situacao_cadastro = 0;

    do
    {
        printf("\tmenu\n");
        printf("1- cadstrar empresa.\n0- sair\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            situacao_cadastro = realizarCadastro(&user);
            break;

        case 0:
            printf("saindo!!!\n\n");
            break;

        default:
            printf("opcao invalida\n");
            break;
        }

    } while (op != 0);

    if (situacao_cadastro == 1)
    {
        do
        {
            printf("\tmenu\n");
            printf("1- responder questionario.\n2- conferir cadastro\n0- sair\n");
            scanf("%d", &op);

            switch (op)
            {
            case 1:
                realizarQuestinario(questoes, arquivo);
                manipulaArquivo(&user, questoes, arquivo);
                break;
            case 2:
                apresentarCadastro(user);
                break;
            case 0:
                printf("saindo!!!\n\n");
                break;

            default:
                printf("opcao invalida\n");
                break;
            }

        } while (op != 0);
    }
    else if (situacao_cadastro == 0)
    {
        printf("\npara continuar e necesario realizar o cadastro\n.");
        apresentarMenu(user, questoes, arquivo);
    }
}

int realizarCadastro(empresa *user)
{
    user->NomeDaEmpresa = malloc(50 * sizeof(char));
    user->razaoSocial = malloc(150 * sizeof(char));
    user->setorDeAtuacao = malloc(50 * sizeof(char));

    printf("qual o nome da sua empresa?\n");
    setbuf(stdin, NULL);
    fgets(user->NomeDaEmpresa, 100, stdin);

    printf("qual o CNPJ da sua empresa?\n");
    scanf("%d", &user->CNPJ);

    printf("qual o numero de funcionarios da sua empresa?\n");
    scanf("%d", &user->numeroDeFuncionarios);

    printf("qual a razao social da sua empresa?\n");
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
    printf("numero de funcionarios: %d\n", user.numeroDeFuncionarios);
    printf("razao social: %s", user.razaoSocial);
    printf("sertor: %s\n", user.setorDeAtuacao);
}

int realizarQuestinario(quetionario questoes, FILE *arquivo)
{

    strcpy(questoes.q1, "1- Sua empresa traz meios de qualidade e seguranca em seus servicos para o usuario?");
    strcpy(questoes.q2, "2- Sua empresa tem estimativas para expandir suas operacoes para paises subdesenvolvidos?");
    strcpy(questoes.q3, "3- Sua empresa tem algum programa para desenvolvimento de empresas de pequeno porte e/ou startups?");
    strcpy(questoes.q4, "4- Sua empresa possui algum projeto para reduzir ao maximo os danos ao meio ambiente ate 2030?");
    strcpy(questoes.q5, "5- Sua empresa possui alguma parceira publico/privada o para alavancar as pesquisas cientificas na sua area de atuacao?");
    strcpy(questoes.q6, "6- Sua empresa possui projetos de cunho tecnico para ajudar paises com baixo desenvolvimento tecnologico?");
    strcpy(questoes.q7, "7- Sua empresa possui uma producao que diversifica a industria e/ou agrega valor as commodities?");
    strcpy(questoes.q8, "8- Sua empresa conseguiu aumentar o acesso universal as tecnologias que produzem ate 2020?");

    printf("\n\tquestionario sobre ODS\n obs: responda as questoes com (1)pra SIM ou (0)pra Nao\n");

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

    //------------gambiara-----------------------------------
    arquivo = fopen("resultado.txt", "w+");
    fprintf(arquivo, "respostas do questionario\n");

    fprintf(arquivo, "(perqunta): %s\n", questoes.q1);
    questoes.r[0] == 0 ? fprintf(arquivo, "respota: Sim\n") : fprintf(arquivo, "resposta: Não\n");

    fprintf(arquivo, "(perqunta): %s\n", questoes.q2);
    questoes.r[1] == 0 ? fprintf(arquivo, "respota: Sim\n") : fprintf(arquivo, "resposta: Não\n");

    fprintf(arquivo, "(perqunta): %s\n", questoes.q3);
    questoes.r[2] == 0 ? fprintf(arquivo, "respota: Sim\n") : fprintf(arquivo, "resposta: Não\n");

    fprintf(arquivo, "(perqunta): %s\n", questoes.q4);
    questoes.r[3] == 0 ? fprintf(arquivo, "respota: Sim\n") : fprintf(arquivo, "resposta: Não\n");

    fprintf(arquivo,"(perqunta): %s\n", questoes.q5);
    questoes.r[4]==0 ? fprintf(arquivo,"respota: Sim\n") : fprintf(arquivo,"resposta: Não\n");

    fprintf(arquivo,"(perqunta): %s\n", questoes.q6);
    questoes.r[5]==0 ? fprintf(arquivo,"respota: Sim\n") : fprintf(arquivo,"resposta: Não\n");

    fprintf(arquivo,"(perqunta): %s\n", questoes.q7);
    questoes.r[6]==0 ? fprintf(arquivo,"respota: Sim\n") : fprintf(arquivo,"resposta: Não\n");

    fprintf(arquivo,"(perqunta): %s\n", questoes.q8);
    questoes.r[7]==0 ? fprintf(arquivo,"respota: Sim\n") : fprintf(arquivo,"resposta: Não\n");

    fclose(arquivo);
    //----------------------------fim da gambiara-------------

    MenuBusca(questoes);
}
void PesquisaSim(quetionario q)
{
    int soma = 0, i;
    for (i = 0; i < 8; i++)
    {
        if (q.r[i] == 1)
        {
            soma++;
        }
    }
    printf("\t%d Perguntas foram respondidas com sim\n\n", soma);
}
void PesquisaNao(quetionario q)
{
    int soma = 0, i;
    for (i = 0; i < 8; i++)
    {
        if (q.r[i] == 0)
        {
            soma++;
        }
    }
    printf("\t%d Perguntas foram respondidas com nao\n\n", soma);
}

void MenuBusca(quetionario q)
{
    int op;
    do
    {
        printf("\tMenu  \n");
        printf("\n 1- Buscar a quantidade de Respostas Sim");
        printf("\n 2- Pesquisar a quantidade de Respostas Nao");
        printf("\n 0- Sair\n\n");
        scanf("%d", &op);

        switch (op)
        {
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

    } while (op != 0);
}

void manipulaArquivo(empresa *user, quetionario questoes, FILE *arquivo)
{
    arquivo = fopen("resultado.txt", "a+");
    rewind(arquivo);
    fprintf(arquivo, "\nDados da empresa.\n\n");

    fprintf(arquivo, "nome: %s", user->NomeDaEmpresa);
    fprintf(arquivo, "CNPJ: %d\n", user->CNPJ);
    fprintf(arquivo, "numero de funcionarios: %d\n", user->numeroDeFuncionarios);
    fprintf(arquivo, "razao social: %s", user->razaoSocial);
    fprintf(arquivo, "sertor: %s\n", user->setorDeAtuacao);

    fclose(arquivo);
}
