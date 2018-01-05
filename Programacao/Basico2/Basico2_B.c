#include <stdio.h>
#include <stdlib.h>
#define TRUE 1

typedef struct {
    char nome[105];
    int numInscricao; /* id */
    short int classe; /*1 - 1.3xcalcSalario  2- 1.9xcalcSalario */

    double horasNormais; /*horas normais trabalhadas por mes*/
    double horasExtras; /*horas extras trabalhadas por mes*/
    double salarioHN; /*salario horas normais*/
    double salarioHE; /*salario horas extras*/
    double inss;
    double salarioLiq; /*salario liquido*/
} Empregado;

void cadastro(Empregado vec[], int);
void calcSalario(Empregado vec[], int, double);
void mostrarCC(Empregado vec[], int); /*mostra contra cheques dos funcionarios*/

int main()
{
    int n;
    double salRef; /*salario de referencia, reais por hora trabalhada*/
    Empregado fun[1005];
    printf("\n     Cadastro de funcionarios\n\n");
    printf("Digite o numero de funcionarios a serem cadastrados: ");
    scanf("%d", &n);
    fflush(stdin);
    printf("%d\n", n);
    cadastro(fun, n);
    printf("digite um salario de referencia(Reais por hora trabalhada): ");
    scanf("%lf", &salRef);

    calcSalario(fun, n, salRef);

    mostrarCC(fun, n);

    return 0;
}

void cadastro(Empregado vec[], int n)
{
    int i;


    for(i = 0; i<n; ++i)
    {
        printf("\nFicha %d\n", i+1);
        printf("Numero de inscricao: ");

        scanf("%d", &vec[i].numInscricao);

        printf("nome: ");
        fflush(stdin);
        gets(vec[i].nome);
        printf("classe: ");
        scanf("%hd", &vec[i].classe);
        printf("horas normais trabalhadas: ");
        scanf("%lf", &vec[i].horasNormais);
        printf("horas extras trabalhadas: ");
        scanf("%lf", &vec[i].horasExtras);
        fflush(stdin);
    }
}

void calcSalario(Empregado vec[], int n, double salRef)
{
    int i;
    for(i=0;i<n;++i)
    {
        if(vec[i].classe==1)
        {
            vec[i].salarioHN = (1.3*salRef)*vec[i].horasNormais;
            vec[i].salarioHE = (1.3*salRef)*(vec[i].horasExtras*1.3);
        }
        else
        {
            vec[i].salarioHN = (1.9*salRef)*vec[i].horasNormais;
            vec[i].salarioHE = (1.9*salRef)*(vec[i].horasExtras*1.3);
        }

        vec[i].inss = 0.08*(vec[i].salarioHN+vec[i].salarioHE);
        vec[i].salarioLiq = (vec[i].salarioHN+vec[i].salarioHE)-vec[i].inss;
    }
}

void mostrarCC(Empregado vec[], int n)
{
    system("cls");
    int i;
    puts("\n      Contra Cheque dos Funcionarios\n");
    for(i=0; i<n; ++i)
    {
        printf("\nNUMERO DE INSCRICAO: %d\n", vec[i].numInscricao);
        printf("NOME: "), puts(vec[i].nome);
        printf("SALARIO HORAS NORMAIS: R$%.2lf\n", vec[i].salarioHN);
        printf("SALARIO HORAS EXTRAS: R$%.2lf\n", vec[i].salarioHE);
        printf("DEDUCAO INSS: R$%.2lf\n", vec[i].inss);
        printf("SALARIO LIQUIDO: R$%.2lf\n", vec[i].salarioLiq);

    }
}
