#include <stdio.h>
void inicializa(double mat[][21]);
void lerMat(double mat[][21], int, int);
void matCross(double mat1[][21],double mat2[][21],double prod[][21], int ,int ,int);
void mostraMat(double mat[][21], int ,int);
int main()
{

    double A[21][21], B[21][21], C[21][21];
    inicializa(C);
    puts("\n\n    Matriz A_3x4, Digite seus elementos: ");
    lerMat(A, 3, 4);
    puts("\n\n    Matriz B_4x2, Digite seus elementos: ");
    lerMat(B, 4, 2);

    matCross(A, B, C, 3, 4, 2);
    system("cls");

    puts("    Matriz A_3x4\n\n");
    mostraMat(A, 3, 4);
    puts("    Matriz B_4x2\n\n");
    mostraMat(B, 4, 2);
    puts("    Matriz A*B_3x2\n\n");
    mostraMat(C, 3, 2);


    return 0;
}
void inicializa(double mat[][21])
{
    int i, j;
    for(i=0;i<21;++i)
        for(j=0;j<21;++j)
            mat[i][j]=0;
}

void lerMat(double mat[][21], int m, int p)
{
    int i, j;
    for(i=0; i<m; ++i)
        for(j=0; j<p; ++j)
            printf("\ninsira o elemento da posicao [%d,%d] = ", i, j), scanf("%lf", &mat[i][j]);
}

void matCross(double mat1[][21], double mat2[][21], double prod[][21],  int m,int p,int n)
{
    int i, j, k;
    for(i=0; i<m; ++i)
        for(j=0; j<p; ++j)
            for(k=0; k<n; ++k)
                prod[i][k] += mat1[i][j]*mat2[j][k];


}

void mostraMat(double mat[][21], int m, int p)
{
    int i, j;
    for(i=0; i<m; ++i)
    {
        for(j=0; j<p; ++j)
            printf("%.2lf ", mat[i][j]);
        puts("");
    }

    puts("\n");

}
