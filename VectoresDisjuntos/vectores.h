#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define TAM_1 3
#define TAM_2 5

typedef enum
{
    verdadero=1,
    falso=0
}booleano;

void mostrarVector (int *vec, int col);
booleano esVectorDisjunto (int *vec_1, int ce_1, int *vec_2, int ce_2);

#endif // VECTORES_H_INCLUDED
