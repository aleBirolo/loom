#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define SEPARADOR '.'

#define ES_BLANCO(x) (x==' ' || x=='\t' || x=='\n')
#define ES_MINUS(x) ('a'<=x && x<='z')
#define ES_MAYUS(x) ('A'<=x && x<='Z')
#define ES_LETRA(x) (ES_MINUS(x) || ES_MAYUS(x) )
#define ES_SEPARADOR(x) (x==SEPARADOR)
#define A_MAYUS(x) (x-' ')
#define A_MINUS(x) (x+' ')

#define TAM 100


char * normalizar(char *cad);
char * normalizar_1 (char *cad);
char *normalizar_conToken (char *cad, const char c);
char * normalizar_2(char * cad);
char *normalizar_3 (char *cad);
char *normalizar_tok_3 (char *cad, char tok);
char *normalizar_2tok_3 (char *cad, char tok, char sep);
#endif // CADENA_H_INCLUDED
