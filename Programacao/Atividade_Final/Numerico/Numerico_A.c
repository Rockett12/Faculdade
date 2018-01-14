#include <stdio.h>

double fObj_PI(double);
double calculo_PI(double);
double fObf_G(double);
double calculo_integral_D(double, double, double);

int main()
{
    int choice;
    double h, pi,a,b, resp;
    printf("escolha o que fazer:\n1 - Calcular o valor de PI\n2 - Calcular a integral definida de x^2\n");
    scanf("%d", &choice);

    if(choice==1)
    {
        printf("\n\n      Calculo do valor de PI\n\n");
        printf("determine o passo de integracao (no intervalo [0,1]): ");

	scanf("%lf", &h);
        pi = calculo_PI(h);

        printf("valor de PI: %.6lf\n", pi);
    }
    else
    {
        printf("\n\n     Calculo da integral definida de x^2\n\n");
        printf("defina os limites de integracao [a,b]\nvalor de a: ");
        scanf("%lf", &a);
        printf("valor de b: ");
        scanf("%lf", &b);
        printf("defina o passo de integracao: ");
        scanf("%lf", &h);
        resp = calculo_integral_D(a, b, h);

        printf("O valor da integral definida de x^2 de %.2lf a %.2lf e: %.5lf\n\n", a, b, resp);

    }


    return 0;

}

double fObf_G(double x) /*Funcao objetivo genérica*/
{
    return x*x;
}

double calculo_integral_D(double a, double b, double h)/*calculo da integral definida*/
{
    double tmp, x, area=0;
    if(a>b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    x = a;
    while(x+h<=b)
    {
        area+=(fObf_G(x)+fObf_G(x+h))*h/2.0;
        x+=h;
    }

    return area;

}

double fObj_PI(double x) /*Função objetivo para PI*/
{

    return 1/(1.0+x*x);
}

double calculo_PI(double h)
{
    double x=0, area=0;
    while(x+h<=1)
    {
        area+=(fObj_PI(x)+fObj_PI(x+h))*h/2.0;
        x+=h;
    }

    return 4*area;
}
