#include "matriz.h"

void mostrarVector (int *vec, int col)
{
    int i;

    for (i=0; i< col; i++, vec++)
            printf(" |%d|", *vec);
}

void mostrarMatriz (int *mat, int fil, int col)
{
    int j;

    for (j=0; j< fil; j++, mat+=col)
    {
        mostrarVector(mat,col);
        printf("\n");
    }
}

booleano esSimetrica (int mat[][COL], int fil, int col)
{
    int i,
        j;

    if (fil!=col)
        return falso;

    for (i=0; i<fil; i++)
        for (j=i+1; j<col; j++)
            if ( mat[i][j] != mat[j][i] )
                return falso;
    return verdadero;
}
