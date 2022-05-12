#include "vectores.h"

#define LOTE_1 {1,2,3}

#define LOTE_2 {4,5,6}

#define LOTE_3 {4,5,1}

#define LOTE_4 {4,5,6,7,8}

#define LOTE_5 {}

int main()
{
    int vec_1[TAM_1]= LOTE_1,
        vec_2[TAM_2]= LOTE_4,
        ce_1=TAM_1,
        ce_2=TAM_2;

    printf ("\n Vector 1: ");
    mostrarVector(vec_1,ce_1);

    printf ("\n Vector 2: ");
    mostrarVector(vec_2,ce_2);

    if (esVectorDisjunto(vec_1, ce_1, vec_2, ce_2))
        printf ("\n Son vectores disjuntos");
    else
        printf ("\n No son vectores disjuntos");


    return 0;
}
