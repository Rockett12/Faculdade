#include <stdio.h>
#include <stdlib.h>
int isPrime(int);

int main()
{
    int i,x;
    printf("Insira seu numero: ");
    scanf("%d",&x);
    if(isPrime(x))
        printf("%d eh primo!\n", x);
    else
        printf("%d nao eh primo!\n", x);

    return 0;
}

int isPrime(int x)
{
    int i;
    if(x==1)
        return 0;
    for(i = 2; i*i<=x; ++i)
        if(x%i==0)
            return 0;

    return 1;
}
