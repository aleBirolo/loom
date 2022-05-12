#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define COL 3
#define FIL 3

typedef enum
{
    verdadero=1,
    falso=0
}booleano;

void mostrarVector (int *vec, int col);
void mostrarMatriz (int *mat, int col, int fil);
booleano esSimetrica (int mat[][COL], int fil, int col);

#endif // MATRIZ_H_INCLUDED
