#include <stdio.h>
#include <math.h>
#define PI 3.14159
#define TRUE 1

double erf(double);
double fat(int);
double binExp(double, int);
int main()
{
    double x;
    printf("Escolha um argumento para a serie erf(x)\nX = ");
    scanf("%lf", &x);
    printf("\nerf(%.2lf) = %.4lf\n", x, erf(x));

    return 0;

}

double erf(double x)
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

    return 2.0*ans/sqrt(PI);
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
    double ans = 1;
    while(exp)
    {
        if(exp&1) ans*=base;
        base*=base;

        exp>>=1;
    }

    return ans;
}
