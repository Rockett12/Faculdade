#include <stdio.h>
#include <math.h>
int main()
{
    double p;
    int res, cinq, vin, ten, five, one;

    scanf("%lf", &p);
    p = 1-p;
    res = round(p*100);
    cinq = res/50;
    res %= 50;
    vin = res/25;
    res %= 25;
    ten = res/10;
    res %= 10;
    five = res/5;
    res %= 5;
    one = res;

    printf("%d moedas de 50 cents\n%d moedas de 25 cents\n%d moedas de 10 cents\n%d moedas de 5 cents\n%d moedas de 1 cents\n", cinq, vin, ten, five, one);
}
