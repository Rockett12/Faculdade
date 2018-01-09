#include <stdio.h>
int preprocess(const char*, int*);
void sylDiv(char*, int*, int);


int main()
{
    char word[100];
    int i, sombra[100];
    printf("\n           Divisor Silabico\n\n");
    printf("Escreva uma palavra(com letras minusculas e sem acento): ");
    scanf("%s", word);

    i = preprocess(word, sombra);
    sylDiv(word, sombra, i);
    puts("");

}

void sylDiv(char word[], int sombra[], int i)
{
    int j;
    for(j=0; j<i; ++j)
    {

        if(!sombra[j]) /** se vogal **/
        {

            if(j+2<i) /** se podemos olhar pra posiçao atual+2 **/
            {
                if(word[j]==word[j+1]) /** vogais identicas **/
                {
                    putchar(word[j]);
                    putchar('-');
                }
                else if(sombra[j+2] && sombra[j+1]==1) /** padrao VC-CV **/
                {
                    putchar(word[j++]);
                    putchar(word[j]);
                    putchar('-');
                }
                else if(sombra[j+2]==1 && sombra[j+1]==0) /** hiatos **/
                {
                    putchar(word[j++]);
                    putchar('-');
                    putchar(word[j]);
                    if(j+2<i)
                        putchar('-');
                }
                else if(sombra[j+2]==2) /** digrafos inseparáveis ch, lh, nh**/
                {
                        putchar(word[j]);
                        putchar('-');
                }
                else if(sombra[j+2]==3) /** digrafos inseparaveis qu, gu **/
                {
                    putchar(word[j++]);
                    putchar('-');
                    putchar(word[j++]);
                    putchar(word[j]);

                }
                else if(!sombra[j+2]) /** padrao V-CV **/
                {
                    putchar(word[j]);
                    putchar('-');
                }
				else
				{
					putchar(word[j]);
				}
            }
            else if(j+1<i && word[j]==word[j+1]) /** vogais identicas **/
            {
                putchar(word[j]);
                putchar('-');
            }
            else if(j+1<i && !sombra[j] && !sombra[j+1] && j<2) /** hiatos em palavras pequenas **/
            {
                putchar(word[j++]);
                putchar('-');
                putchar(word[j]);
            }
            else
            {
                putchar(word[j]);
            }
        }
        else if(sombra[j]==2) /** digrafos inseparáveis ch, lh, nh**/
        {
            putchar(word[j++]);
            putchar(word[j]);
        }
        else if(sombra[j]==3) /** digrafos inseparaveis qu, gu **/
        {
            putchar(word[j++]);
            putchar(word[j]);
        }
        else
        {
            putchar(word[j]);
        }

    }
}

int preprocess(const char word[], int sombra[])
{
    int i;
    for(i = 0; word[i]!='\0'; ++i)
    {
        if(word[i]=='a' || word[i]=='e' ||word[i]=='i' || word[i]=='o' || word[i]=='u')
        {
            if(word[i]=='u')
            {
                if(i)
                {
                    if(word[i-1]=='g' || word[i-1]== 'q')
                    {
                        sombra[i-1]=3;
                    }
                }
            }
            sombra[i] = 0;
        }
        else if(word[i]=='h')
        {
            if(i)
            {
                if(word[i-1]=='c' || word[i-1]=='n' ||word[i-1]=='l' )
                {
                    sombra[i] = sombra[i-1] = 2;
                }
                else
                {
                    sombra[i]= 1;
                }
            }
            else
            {
                sombra[i]=1;
            }
        }
        else if(word[i]=='l' || word[i]=='r')
        {
            if(i)
            {
                if(word[i-1]=='b' || word[i-1]=='c' || word[i-1]=='d' ||
                   word[i-1]=='f' || word[i-1]=='g' || word[i-1]=='p' ||
                   word[i-1]=='t' || word[i-1]=='v')
                {
                    sombra[i] = sombra[i-1] = 2;
                }
                else
                {
                    sombra[i]= 1;
                }
            }
            else
            {
                sombra[i]=1;
            }
        }
        else
        {
            sombra[i]=1;
        }
    }

    return i;
}
