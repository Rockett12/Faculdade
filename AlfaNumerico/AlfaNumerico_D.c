#include<stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializa(int*); 
int rtoa(int*,char*, int); /** roman to arabic/romano pra arabico **/

int main()
{
	/** Converte de numero romano pra arabico de I(1) até MMMCMXCIX(3999) **/
	char str_num[20];
	int i, roman[30];
	inicializa(roman);
	
	gets(str_num);
	for(i = 0; str_num[i]!='\0'; ++i);
	
	i = rtoa(roman, str_num, i);
	printf("%d\n", i);
	
}

void inicializa(int roman[])
{
	int i;
	for(i=0; i<30; ++i)
		roman[i]=0;
	
	roman[(int)'I'-'A'] = 1;
	roman[(int)'V'-'A'] = 5;
	roman[(int)'X'-'A'] = 10;
	roman[(int)'L'-'A'] = 50;
	roman[(int)'C'-'A'] = 100;
	roman[(int)'D'-'A'] = 500;
	roman[(int)'M'-'A'] = 1000;
}
//
int rtoa(int roman[],char str_num[], int tam)
{
	int i=0, atual, anterior, soma=0;
	if(tam!=1)
	{
		for(i=1; i<tam; ++i)
		{
			atual = roman[(int)str_num[i]-'A'];
			anterior = roman[(int)str_num[i-1]-'A'];
			
			if(i != tam-1)
			{
				if(atual < anterior || atual == anterior)
					soma+= anterior;
				else
					soma-= anterior;
			}
			else
			{
				if(atual < anterior || atual == anterior)
					soma+= atual+anterior;
				else
					soma+= atual-anterior;
			}
		}
		
		return soma;
	}
	
	return roman[(int)str_num[i]-'A'];
}
