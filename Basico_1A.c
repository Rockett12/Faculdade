#include <stdio.h>
#include <math.h>

int main() {
	int n, m, soma;
	printf("Entre com um dois valores, um limite inferior e um superior \npara classificacao dos numeros desse intervalo: \n");
	scanf("%d %d", &n, &m);
	int i;

    for(; n<=m; ++n)
    {
        soma = 1;
		printf("%d ", n);
		if(n==1){
			puts("deficiente");
			continue;
		}

        for(i=2; i*i<=n; ++i)
        {
			if(n%i==0)
			{
				soma += i;
				if(n/i != i)
					soma+=n/i;
			}
		}
		if(soma<n)
			puts("Deficiente");
		else if(soma>n)
			puts("Abundante");
		else
			puts("Perfeito");


	}



	return 0;
}
