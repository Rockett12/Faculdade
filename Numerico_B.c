#include <stdio.h>

double funcao_G(double);
double busca_b(double, double);

int main()
{
    double a, b,resp;
    printf("        Calculo do zero da funcao f(x)=x+2\n\n");
    printf("Escolha um x tal que f(x)<0: ");
    scanf("%lf", &a);
    printf("Escolha um x tal que f(x)>0: ");
    scanf("%lf", &b);
    resp = busca_b(a, b);
    printf("x_0 = %.3lf\n", resp );

}

double busca_b(double ini, double fim)
{
    double mid = (ini+fim)/2.0, fmid;
    int i=0;

    fmid = funcao_G(mid);
    //printf("%lf %lf\n",mid, fmid);

    while(fmid!=0.0 && i++!=1000)
    {
        //printf("%lf %lf\n",mid, fmid);

        if(fmid > 0)
            fim = mid;
        else if(fmid < 0)
            ini = mid;

        mid = (ini+fim)/(double)2.0;
        fmid = funcao_G(mid);
    }

    return mid;


}

double funcao_G(double x)
{
    return x+2;
}
