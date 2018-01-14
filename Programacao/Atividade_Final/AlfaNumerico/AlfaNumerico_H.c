#include <stdio.h>
#include <string.h>
#define TRUE 1
typedef long long int ll;

void codificador(char*,ll*, int*);
ll decodificador(ll*, int);
void conversor(char*, ll);

int main()
{
    char a, palavra[100], qreais[100];
    int i=0, j=0;
    ll coder[100], quantia=0LL;

    printf("Escreva uma quantia por extenso e com letras maiusculas: ");
    while(TRUE)
    {
        a = getchar();
        //printf("%d", j);
        if(a==' ')
        {
            palavra[i]='\0';
            codificador(palavra, coder, &j);
            i=0;
            continue;
        }
        else if(a=='\n')
        {
            palavra[i]='\0';
            codificador(palavra, coder, &j);
            break;
        }
        palavra[i++]=a;
    }
    //printf("ALOO\n");

    quantia = decodificador(coder, j);
    printf("Quantia (Centavos): %lld\n\n", quantia);
    conversor(qreais, quantia);
    printf("Valor em reais: R$%s\n\n", qreais);

    return 0;
}

void conversor(char reais[], ll quantia)
{
    int i=0, j=0, k;
    char pilha[100];
    while(quantia)
    {
        pilha[j++] = (char) '0'+ (quantia%10);
        quantia/=10LL;

        if(j==2)
        {
            pilha[j++]=',';
        }
        else if(j>2)
        {
            ++i;
            if(i==3)
            {
                pilha[j++]='.';
                i=0;
            }

        }

    }

    pilha[j]='\0';
    if(j>3)
    {
        if(pilha[j-1]=='.')
            j--;
        for(i=j-1, k=0;i>=0; --i)
        {
            reais[k++] = pilha[i];
        }
    }
    else
    {
        reais[0] = '0';
        reais[1] = '0';

        k=2;
        if(j<2)
        {
            reais[2] = ',';
            reais[3] = '0';
            k=4;
        }
        for(i=j-1;i>=0; --i)
        {
            reais[k++] = pilha[i];
        }
    }


    reais[k]='\0';
}

ll decodificador(ll coder[], int tam)
{
    ll montante=0LL, modificador=100LL;
    int i;
    //printf("ALOOO\n %d\n", tam);
    for(i=tam-1; i>=0; --i)
    {
        //printf("%lld\n", coder[i]);
        if(coder[i]<0) /*multiplicadores*/
        {
            if(coder[i]==-1)
            {
                if(i!=0)
                {


                    if(coder[i-1]<0)
                    {
                        montante+=1000LL;
                        continue;
                    }
                    montante += coder[i-1]*1000LL*modificador;
                    i--;
                }
                else
                    montante+=1000LL*modificador;

            }
            else if(coder[i]==-2)
            {
                if(coder[i-1]<0)
                {
                    montante+=1000000LL*modificador;
                    continue;
                }
                montante += coder[i-1]*1000000LL*modificador;
                i--;
            }
            else if(coder[i]==-3)
            {
                if(coder[i-1]<0)
                {
                    montante+=1000000000LL*modificador;
                    continue;
                }
                montante += coder[i-1]*1000000000LL*modificador;
                i--;
            }
            else if(coder[i]==-4)
                modificador = 1LL;

            else if(coder[i]==-5)
                modificador = 100LL;


        }
        else /*valoracao*/
        {
            montante+=coder[i]*modificador;
        }
    }

    return montante;
}

void codificador(char palavra[], ll coder[], int* setter)
{


    if(strcmp(palavra, "E")==0)
        return;
    /*MULTIPLICADORES*/
    if(strcmp(palavra, "MIL")==0)
        coder[(*setter)++] = -1;
    else if(strcmp(palavra, "MILHAO")==0 || strcmp(palavra, "MILHOES")==0)
        coder[(*setter)++] = -2;
    else if(strcmp(palavra, "BILHAO")==0 || strcmp(palavra, "BILHOES")==0)
        coder[(*setter)++] = -3;

    /*VALORACAO*/
    else if(strcmp(palavra, "UM")==0)
        coder[(*setter)++] = 1;
    else if(strcmp(palavra, "DOIS")==0)
        coder[(*setter)++] = 2;
    else if(strcmp(palavra, "TRES")==0)
        coder[(*setter)++] = 3;
    else if(strcmp(palavra, "QUATRO")==0)
        coder[(*setter)++] = 4;
    else if(strcmp(palavra, "CINCO")==0)
        coder[(*setter)++] = 5;
    else if(strcmp(palavra, "SEIS")==0)
        coder[(*setter)++] = 6;
    else if(strcmp(palavra, "SETE")==0)
        coder[(*setter)++] = 7;
    else if(strcmp(palavra, "OITO")==0)
        coder[(*setter)++] = 8;
    else if(strcmp(palavra, "NOVE")==0)
        coder[(*setter)++] = 9;
    else if(strcmp(palavra, "DEZ")==0)
        coder[(*setter)++] = 10;
    else if(strcmp(palavra, "ONZE")==0)
        coder[(*setter)++] = 11;
    else if(strcmp(palavra, "DOZE")==0)
        coder[(*setter)++] = 12;
    else if(strcmp(palavra, "TREZE")==0)
        coder[(*setter)++] = 13;
    else if(strcmp(palavra, "QUATORZE")==0)
        coder[(*setter)++] = 14;
    else if(strcmp(palavra, "QUINZE")==0)
        coder[(*setter)++] = 15;
    else if(strcmp(palavra, "DEZESSEIS")==0)
        coder[(*setter)++] = 16;
    else if(strcmp(palavra, "DEZESSETE")==0)
        coder[(*setter)++] = 17;
    else if(strcmp(palavra, "DEZOITO")==0)
        coder[(*setter)++] = 18;
    else if(strcmp(palavra, "DEZENOVE")==0)
        coder[(*setter)++] = 19;
    else if(strcmp(palavra, "VINTE")==0)
        coder[(*setter)++] = 20;
    else if(strcmp(palavra, "TRINTA")==0)
        coder[(*setter)++] = 30;
    else if(strcmp(palavra, "QUARENTA")==0)
        coder[(*setter)++] = 40;
    else if(strcmp(palavra, "CINQUENTA")==0)
        coder[(*setter)++] = 50;
    else if(strcmp(palavra, "SESSENTA")==0)
        coder[(*setter)++] = 60;
    else if(strcmp(palavra, "SETENTA")==0)
        coder[(*setter)++] = 70;
    else if(strcmp(palavra, "OITENTA")==0)
        coder[(*setter)++] = 80;
    else if(strcmp(palavra, "NOVENTA")==0)
        coder[(*setter)++] = 90;
    else if(strcmp(palavra, "CEM")==0 || strcmp(palavra, "CENTO")==0)
        coder[(*setter)++] = 100;
    else if(strcmp(palavra, "DUZENTOS")==0)
        coder[(*setter)++] = 200;
    else if(strcmp(palavra, "TREZENTOS")==0)
        coder[(*setter)++] = 300;
    else if(strcmp(palavra, "QUATROCENTOS")==0)
        coder[(*setter)++] = 400;
    else if(strcmp(palavra, "QUINHENTOS")==0)
        coder[(*setter)++] = 500;
    else if(strcmp(palavra, "SEISCENTOS")==0)
        coder[(*setter)++] = 600;
    else if(strcmp(palavra, "SETECENTOS")==0)
        coder[(*setter)++] = 700;
    else if(strcmp(palavra, "OITOCENTOS")==0)
        coder[(*setter)++] = 800;
    else if(strcmp(palavra, "NOVECENTOS")==0)
        coder[(*setter)++] = 900;

    /*MODIFICARES*/
    else if(strcmp(palavra, "CENTAVO")==0 || strcmp(palavra, "CENTAVOS")==0)
        coder[(*setter)++] = -4;
    else if(strcmp(palavra, "REAL")==0 || strcmp(palavra, "REAIS")==0)
        coder[(*setter)++] = -5;

}
