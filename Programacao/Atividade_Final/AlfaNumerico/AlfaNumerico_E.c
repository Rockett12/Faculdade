#include <stdio.h>

void inicializa(char cadeia[]);

int main()
{
    int i, j=0;
    char code[30], decode[10005], msg[10] ;
    inicializa(code);
    printf("Digite a mensagem a ser decodificada: ");
    while(scanf("%s", msg))
    {
        for(i=0; i<5; ++i)
            if(msg[i]!='9')
                break;
        if(i==5)
            break;

        for(i=0; i<5; ++i)
            decode[j++] = code[msg[i]-'A'];
    }

    decode[j] = '\0';

    printf("Mensagem: %s\n", decode);

    return 0;
}

void inicializa(char cadeia [])
{
    int i;
    char code[] = "DEFGHIJKLMNOPQRSTUVWXYZABC";
    for(i=0; i<26; ++i)
    {
        cadeia[code[i]-'A'] = 'A'+i;
    }
}
