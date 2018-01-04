#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
 
void sleep(double delay)
{
    double tempo;
    time_t tempoini,tempofin;
    time(&tempoini);
    while(1){
        time(&tempofin);
        tempo=difftime(tempofin,tempoini);
        if(tempo==delay)
            break;
       }
}
int main()
{
    int x,i=1,c;
    printf("Seu palpite(entre 1 e 37): ");
    scanf("%d",&x);
    printf("Palpite salvo!\n");
    printf("Pressione qualquer tecla para continuar...");
    getch();
    system("cls");
    srand(time(NULL));
    c=rand()%37+1;
    while(1){
        printf("%d ",i);
        if(i==c){
            printf("\nSeu palpite foi o numero %d",x);
            printf("\nNumero sorteado foi %d\n",i);
            if(c==x)
                printf("Seu palpite estava correto!!\n");
            else
                printf("Vc errou.\n");
            break;
        }
        i++;
        if(i==7 || i==14 || i==21 || i==28)
            printf("\n");
        if(i==38){
            i=1;
            system("cls");
        }
        sleep(1);
    }
    return 0;
}
