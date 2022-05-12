#include "matriz.h"

#define LOTE_1 { {1,2,3},\
                 {4,5,6},\
                 {7,8,9}\
               }

#define LOTE_2 { {1,1,5},\
                 {1,2,3},\
                 {5,3,4}\
               }

#define LOTE_3 {}

#define LOTE_4 { {1,1,5},\
                 {1,2,3},\
                 {5,3,1}\
               }

#define LOTE_5 { {1,1,5},\
                 {5,2,3},\
                 {5,3,1}\
               }

int main()
{
    int mat[FIL][COL]= LOTE_1;

    mostrarMatriz(*mat, FIL, COL);

    if (esSimetrica(mat, FIL, COL))
        printf ("\n Es matriz simetrica");
    else
        printf ("\n No es matriz simetrica");
    return 0;
}
