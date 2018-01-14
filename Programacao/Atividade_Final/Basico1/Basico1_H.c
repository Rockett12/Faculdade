#include <stdio.h>
#include <math.h>
#define TRUE 1
#define PI 3.14159
double fat(int); /*fatorial*/
double expEuler(double); /*funcao exponencial*/
double binExp(double, int); /*Exponenciacao binaria*/
double seno(double); /*funcao seno*/
double cosseno(double); /*funcao cosseno*/
int main()
{
    int n;
    double x;
    printf("\n     Escolha uma funcao:\nExponencial - Digite 1\nCosseno - Digite 2\nSeno - Digite 3\n");
    while(scanf("%d", &n)!=1 || n<1 || n>3)
    {
        fflush(stdin);
        puts("Escolha Invalida, tente novamente.");
        printf("\n     Escolha uma funcao:\nExponencial - Digite 1\nCosseno - Digite 2\nSeno - Digite 3\n");
    }
    fflush(stdin);
    printf("Digite o argumento (x) da funcao: ");
    scanf("%lf", &x);
    if(n==1)
        printf("Exponencial de %.2lf: %.4lf\n",x, expEuler(x));
    else if(n==2)
        printf("Cosseno de %.2lf rad: %.4lf rad\n",x, cosseno(x));
    else
        printf("Seno de %.2lf rad: %.4lf rad\n",x, seno(x));




}

double expEuler(double x)
{
    int i=1;
    double ans=0, old=0, newIncr=0;

    ans += 1;
    while(TRUE)
    {
        newIncr = binExp(x, i)/fat(i);
        ans+=newIncr;
        if(fabs(newIncr-old)<0.001)
            break;
        old = newIncr;
        ++i;
    }

    return ans;
}

double cosseno(double x)
{
    double ans=1, newIncr, old=0;
    int i=1;
    while(TRUE)
    {
        newIncr = binExp(-1, i)*binExp(x, 2*i)/fat(2*i);
        ans+=newIncr;
        if(fabs(newIncr-old)<0.001)
            break;
        old = newIncr;
        ++i;
    }

    return ans;
}

double seno(double x)
{
    double ans=0, newIncr, old=0;
    int i=0;
    while(TRUE)
    {
        newIncr = binExp(-1, i)*binExp(x, 2*i+1)/fat(2*i+1);
        ans+=newIncr;
        if(fabs(newIncr-old)<0.001)
            break;
        old = newIncr;
        ++i;
    }

    return ans;
}

double fat(int a)
{
    int i;
    double ans = 1;
    for(i =1; i<=a; ++i)
    {
        ans*= (double)i;
    }

    return ans;
}

double binExp(double base, int exp)
{
    double ans =1;
    while(exp)
    {
        if(exp&1) ans*=base;
        base*=base;

        exp>>=1;
    }

    return ans;
}
