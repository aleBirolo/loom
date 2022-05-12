#include "vectores.h"

void mostrarVector (int *vec, int col)
{
    int i;

    for (i=0; i< col; i++, vec++)
            printf(" |%d|", *vec);
}


booleano esVectorDisjunto (int *vec_1, int ce_1, int *vec_2, int ce_2)
{
    int *ptr_v1=vec_1,
        *ptr_v2=vec_2;

    for ( ;  (ptr_v1 - vec_1  ) < ce_1 ; ptr_v1++)
        for ( ; (ptr_v2 - vec_2 ) < ce_2 ; ptr_v2++)
            if (*ptr_v1 == *ptr_v2)
                return falso;

    return verdadero;
}
