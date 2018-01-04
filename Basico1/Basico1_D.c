#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,x;
    printf("Insira seu numero: ");
    scanf("%d",&x);
    for(i=2;i*i<=x;i++){
        if(x%i==0){
            printf("Numero nao primo.\n");
            return 0;
        }
    }
    if(x==1){
        printf("Numero nao primo.\n");
        return 0;
    }
    printf("Numero primo!\n");
    return 0;
}
