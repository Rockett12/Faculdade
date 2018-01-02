#include <stdio.h>
#include <ctype.h>
int main()
{
    char nome[1005][105],a, nomeref[1005];
    int i=0, j=0, k =0;
    printf("Insira seu nome para ver como ficaria em uma referencia bibliografica: ");
    while(a=getchar(), a!='\n')
    {
        if(a==' ')
        {
            while(a = getchar(), a==' ');
            nome[i][j] = '\0';
            ++i;
            j = 0;
        }

        nome[i][j++] = a;

    }

    nome[i][j] = '\0';
    for(j = 0; j<i; ++j)
        {
        nomeref[k++] = nome[j][0];
        nomeref[k++] = '.';
        nomeref[k++] = ' ';
    }


    nomeref[k] = '\0';
    j=0;
    while(nome[i][j])
    {
        putchar(toupper(nome[i][j]));
        ++j;
    }
    printf(", %s", nomeref);

    return 0;


}
