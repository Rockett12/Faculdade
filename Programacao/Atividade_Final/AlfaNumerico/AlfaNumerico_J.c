#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int trim(const char cadeia1[], char cadeia2[]); /*retorna o tamanho da cadeia limpa*/
int isPalindrome(const char cadeia[], int tam);

int main()
{
    char cadeia1[10000], cadeia2[10000];
    int tam;
    int palin= 1;

    printf("\n\n        Determinacao de palindromos\n\nInsira uma palavra ou frase: ");
    gets(cadeia1);
    tam = trim(cadeia1, cadeia2);


    if(isPalindrome(cadeia2, tam))
        puts("\nA palavra/frase e um palindromo!\n");
    else puts("\nA palavra/frase nao e um palindromo.\n");

    return 0;
}

int trim(const char cadeia1[], char cadeia2[])
{

    int i,k=0;
    for(i=0; cadeia1[i]!='\0'; ++i)
        if((cadeia1[i]>64 && cadeia1[i]<91) || (cadeia1[i]>96 && cadeia1[i]<123))
            cadeia2[k++]=cadeia1[i];

    cadeia2[k]='\0';

    return k;
}

int isPalindrome(const char cadeia[], int tam)
{
    int i, j, palin = 1;
    for(i=0, j=tam-1; i<j; ++i, --j)
        if(cadeia[i] != cadeia[j])
        {
            if(abs((int)cadeia[i]-cadeia[j]) == 32)
                continue;

            return 0;
        }

    return 1;

}
