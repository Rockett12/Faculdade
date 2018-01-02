#include<stdio.h>
#define MAXN 100005
void preprocessamento(char*, int*, int); /** pre processamento do padrao **/
void kmp(char*,char*, int*, int, int); /** Algoritmo Knuth-Morris-Pratt para string matching **/

int main()
{
    char texto[MAXN], padrao[MAXN];
    int aux[MAXN], i, j;
    puts("\n     -------- Remocao de subcadeia -----------\n\n");

    printf("Insira uma frase: ");
    gets(texto);

    printf("\nInsira uma subcadeia para eliminar da frase original: ");
    gets(padrao);

    for(i = 0; texto[i]!='\0'; ++i);
    for(j = 0; padrao[j]!='\0'; ++j);

    preprocessamento(padrao, aux, j);
    kmp(texto, padrao, aux, i, j);

    printf("Frase limpa: ");
    int state = 1;
    for(i = 0; texto[i]!='\0'; ++i)
    {
        if(j>1)
            if(texto[i]=='|')
                state = !state;

        if(state && texto[i]!='|')
        {
            putchar(texto[i]);
        }
    }

    puts("\n");



}

void kmp(char texto[], char padrao[],int aux[], int tam_txt, int tam_pad)
{
    int i = 0; /** Indexa o texto **/
    int j = 0; /** Indexa o padrao **/

    while(i<tam_txt)
    {
        if(padrao[j]==texto[i])
        {
            ++i;
            ++j;
        }

        if(j == tam_pad)
        {
            texto[i-j]= texto[i-1] = '|';
            j = aux[j-1];
        }

        if(i<tam_txt && padrao[j]!=texto[i])
        {
            if(j)
                j = aux[j-1];
            else
                ++i;
        }
    }
}

void preprocessamento(char padrao[],int aux[], int tam_pad)
{
    aux[0] = 0;
    int j = 0, i = 1;

    while(i<tam_pad)
    {
        if(padrao[i]==padrao[j])
        {
            ++j;
            aux[i] = j;
            ++i;
        }
        else if(j)
        {
            j = aux[j-1];
        }
        else
        {
            aux[i]=0;
            ++i;
        }
    }

}
