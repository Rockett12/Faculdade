#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TRUE 1
typedef struct {
    char nome[105];
    double media;
    short int recomendacao; /*1- Altamente rec. 2- Fortemente rec. 3- Recomendado 4 - Nao recomendado*/
} Solicitante;

void setRecommend(Solicitante* aluno);
void getRecommend(short int);
double mediaGeral(const Solicitante alunos[], int n, int vec[]);


int main()
{
    char end[105] = "FIM DA LISTA";
    int recs[5] = {0}; /* vetor que guarda o a quantidade de cada recomendacao*/
    Solicitante aluno[500];
    int i=0, n;
    double mediag;

    while(TRUE)
    {
        printf("digite o nome do solicitante (ou FIM DA LISTA): ");
        gets(aluno[i].nome);
        if(strcmp(aluno[i].nome, end)==0)
            break;
        printf("insira a media do historico escolar desse estudante: ");
        scanf("%lf%*c", &aluno[i].media);
        fflush(stdin);
        setRecommend(aluno+i);
        i++;

    }
    n = i;
	system("cls");
    printf("\n       Relacao de solicitantes\n\n");
    for(i = 0; i<n; ++i)
    {
        printf("\nSolicitante %d:\n", i+1);
        printf("Nome: "), puts(aluno[i].nome);
        printf("Media: %.2lf%%\n", aluno[i].media);
        getRecommend(aluno[i].recomendacao);
    }

    mediag = mediaGeral(aluno, n, recs);

    printf("\nMedia Geral dos Solicitantes: %.2lf%%\n", mediag);
    printf("Numero de solicitantes Altamente Recomendados: %d\n", recs[1]);
    printf("Numero de solicitantes Fortemente Recomendados: %d\n", recs[2]);
    printf("Numero de solicitantes Recomendados: %d\n", recs[3]);
    printf("Numero de solicitantes Nao Recomendados: %d\n", recs[4]);

    return 0;
}

void setRecommend(Solicitante* aluno)
{
    if(aluno->media >= 90)
        aluno->recomendacao = 1;
    else if(aluno->media >= 80)
        aluno->recomendacao = 2;
    else if(aluno->media >= 70)
        aluno->recomendacao = 3;
    else
        aluno->recomendacao = 4;
}

void getRecommend(short int j)
{
    if(j==1)
        puts("Altamente Recomendado");
    else if(j==2)
        puts("Fortemente Recomendado");
    else if(j==3)
        puts("Recomendado");
    else
        puts("Nao Recomendado");
}

double mediaGeral(const Solicitante alunos[],int n,int vec[])
{
    int i, j;
    double medg=0;
    for(i =0; i<n; ++i)
    {
        medg+= alunos[i].media;
        j = (int) alunos[i].recomendacao;

        ++vec[j];
    }

    return medg/(double) n;
}
