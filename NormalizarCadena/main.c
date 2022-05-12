#include "cadena.h"

#define LOTE_0  " diego armando. maradona "
#define LOTE_1  "diego armando. maradona"
#define LOTE_2  "          diego armando. maradona"
#define LOTE_3  "              diego armando. maradona             "
#define LOTE_4  "              diego       armando. maradona             "
#define LOTE_5  "              diego       armando      . maradona             "
#define LOTE_6  "              diego       armando      .      maradona             "
#define LOTE_7  "              dIEGO       aRMANDO      .      mARADONA             "
#define LOTE_8  "              DIEGO       ARMANDO      .      MARADONA             "
#define LOTE_9  "              diego       armando.maradona             "
#define LOTE_10 "             diego       armando..maradona             "
#define LOTE_11 "             diego       armando...maradona             "
#define LOTE_12 "             diego       armando. . .maradona             "
#define LOTE_13 "      ....       diego       armando. . .maradona             "
#define LOTE_14 "      ....       diego       armando. . .maradona     ....        "

/// EL lote 14 no funciona

int main()
{
    char cad[TAM]= LOTE_0;


    printf ("\n|%s|", cad);
     printf ("\n|%s|", normalizar_3(cad));
    //printf ("\n|%s|", normalizar_conToken(cad,'.'));
    return 0;
}
