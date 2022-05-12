#include <stdio.h>
#include <stdlib.h>

#define TAM_CAD 20

#define LOTE_1 "123"
#define LOTE_2 "+123"
#define LOTE_3 "-123"
#define LOTE_4 "12j1"
#define LOTE_5 "12-4"
#define LOTE_6 "12 4"
#define LOTE_7 "12.3"
#define LOTE_8 "12,3"
#define LOTE_9 ""

#define ES_NUMERO(x) ('0'<=x && x<='9')

int a_toi (const char *cad);

int main()
{
    char cad[TAM_CAD]=LOTE_1;


    printf ("\n atoi de libreria: Cadena: |%s| -> Entero: |%d|", cad, atoi(cad));
    printf ("\n atoi de personal: Cadena: |%s| -> Entero: |%d|", cad, a_toi(cad));
    return 0;
}


int a_toi (const char *cad)
{
    int signo=1,
        num=0;

    if (!*cad)
        return num;

    if (*cad == '-')
    {
        signo=-1;
        cad++;
    }
    else
        if (*cad == '+')
            cad++;

    while (*cad && ES_NUMERO(*cad))
    {
        num+= (*cad - '0');
        num*=10;
        cad++;
    }

    num/=10;

    return num*=signo;
}
