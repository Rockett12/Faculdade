#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int*, int);
void selectionSort(int*, int);
void mergeSort(int, int, int*);
static void merge(int, int ,int, int*);
static int particiona(int*, int, int);
void quickSort(int*, int, int);

int main()
{
    srand(time(NULL));
    int i, n, v[200000], aux[200000];
    printf("Escolha um tamanho para o vetor\n\n");
    printf("10 - digite 1\n100 - digite 2\n1000 - digite 3\n10000 - digite 4\n100000 - digite 5\n\n");
    scanf("%d", &n);
//    n = 5;
    if(n == 1)
        n = 10;
    else if(n == 2)
        n = 100;
    else if(n == 3)
        n = 1000;
    else if(n == 4)
        n = 10000;
    else
        n = 100000;

    for(i = 0; i<n; ++i)
        v[i] = rand()%999999999;

    printf("Escolha o algoritmo de ordenacao\n\n");
    printf("Selection Sort - digite 1\n");
    printf("Bubble Sort - digite 2\n");
    printf("Merge Sort - digite 3\n");
    printf("Quick Sort - digite 4\n");

    scanf("%d", &i);
//    i = 4;
    if(i == 1)
        selectionSort(v, n);
    else if(i == 2)
        bubbleSort(v, n);
    else if(i == 3)
        mergeSort(0, n,v);
    else
        quickSort(v,0,n-1);

    for(i = 0; i<n ; ++i)
        printf("%d ", v[i]);
    puts("\n");

    return 0;

}

void selectionSort(int v[], int tam)
{
    int i, j, aux, menor;
    for(i = 0; i<tam-1; ++i)
    {
        menor = i;
        for(j = i+1; j<tam; ++j)
        {
            if(v[j]<v[menor])
                menor = j;
        }

        if(v[i]!=v[menor])
        {
            aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
        }
    }
}

void bubbleSort(int v[], int tam)
{
    int i, j, aux;
    for(i = tam-1; i>=0; --i)
        for(j = 0; j<i; ++j)
        {
            if(v[j]>v[j+1])
            {
                aux = v[j+1];
                v[j+1] = v[j];
                v[j] = aux;
            }
        }
}

void mergeSort(int ini, int fim, int v[])
{
    if (ini < fim-1) {
      int mid = (ini + fim)/2;

      mergeSort (ini, mid, v);
      mergeSort (mid, fim, v);
      merge (ini, mid, fim, v);
   }

}

static void merge (int ini, int mid, int fim, int v[])
{
    int i, j, k, *w;
    w = (int*) malloc ((fim-ini) * sizeof (int));

    for (i = ini; i < mid; ++i)
        w[i-ini] = v[i];

    for (j = mid; j < fim; ++j)
        w[fim-ini+mid-j-1] = v[j];

    i = 0; j = fim-ini-1;

    for (k = ini; k < fim; ++k)
        if (w[i] <= w[j])
            v[k] = w[i++];
        else
            v[k] = w[j--];

    free (w);
}

void quickSort (int v[], int ini, int fim)
{
    int pivo;
    if (ini < fim)
    {
        pivo = particiona (v, ini, fim);
        quickSort (v, ini, pivo-1);
        quickSort (v, pivo+1, fim);
    }
}

static int particiona(int v[], int ini, int fim)
{
    int c = v[ini], i = ini+1, j = fim, t;
    while (/*A*/ i <= j)
    {
        if (v[i] <= c)
            ++i;
        else if (c < v[j])
            --j;
        else
        {
            t = v[i], v[i] = v[j], v[j] = t;
            ++i; --j;
        }
    }

    v[ini] = v[j], v[j] = c;
    return j;
}



