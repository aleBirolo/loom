#include "cadena.h"

char * normalizar(char *cad)
{

    char *orig,
         *dest;

    orig=cad;
    dest=cad;

    while (*dest)
    {
        /// TRIM Frontal
        while (*dest && (ES_BLANCO(*dest) || ES_SEPARADOR(*dest)) )
            dest++;

        /// Primer Letra a mayuscula
        *orig = (ES_LETRA(*dest) && ES_MINUS(*dest)) ? A_MAYUS(*dest): *dest ;
        orig++;
        dest++;

        /// Todas las demas letras de la misma palabra a minuscula
        while (*dest && !ES_BLANCO(*dest) && !ES_SEPARADOR(*dest))
        {
            *orig = (ES_LETRA(*dest) && ES_MAYUS(*dest)) ? A_MINUS(*dest): *dest ;
            orig++;
            dest++;
        }

        /// TRIM entre palabras
        while (*dest && ES_BLANCO(*dest))
            dest++;

        /// Un espacio entre letras
        if (*dest && ES_LETRA(*dest))
        {
            *orig=' ';
            orig++;
        }

        /// Letra punto espacio
        if (*dest && ES_SEPARADOR(*dest))
        {
            *orig=*dest;
            orig++;
            *orig=' ';
            orig++;
            dest++;
        }
    }

    *orig='\0';
    orig--;

    if (*orig && ES_BLANCO(*orig))
        *orig='\0';

    return cad;
}

char * normalizar_1 (char *cad)
{
    char *orig=cad,
         *dest=cad;

    while (*orig)
    {
        while (ES_BLANCO(*orig))
            orig++;

        if (*orig)
        {
            *dest=A_MAYUS(*orig);
            dest++;
            orig++;

            while ( !ES_BLANCO(*orig) && *orig)
            {
                *dest=A_MINUS(*orig);
                dest++;
                orig++;
            }

            if (ES_BLANCO(*orig))
            {
                *dest=' ';
                dest++;
                orig++;
            }
        }
    }

    if (dest>cad && *(dest-1)==' ')
        dest--;
    *dest='\0';

    return cad;
}

char *normalizar_conToken (char *cad, const char c)
{
    char *orig=cad,
         *dest=cad;

    while (*orig)
    {
        while (ES_BLANCO(*orig))
            orig++;

        if (*orig)
        {
            if (dest==cad || *dest==c || *dest==' ')
            {
                *dest=A_MAYUS(*orig);
                dest++;
                orig++;
            }

            while (*orig !=c&& *orig && !ES_BLANCO(*orig)    )
            {
                *dest=A_MINUS(*orig);
                dest++;
                orig++;
            }

            if (ES_BLANCO(*orig))
               {
                   *dest=' ';
                   dest++;
                   orig++;
               }

            if (*orig==c)
            {
                *dest=*orig;
                *(dest+1)=' ';
                dest+=2;
                orig++;
            }
        }
    }

    if (dest>cad && *(dest-1)==' ')
        dest--;
    *dest='\0';

    return cad;
}

char * normalizar_2(char * cad)
{
    char * orig = cad,
         * dest = cad;

    while (*orig)
    {
        while(ES_BLANCO(*orig))
            orig++;
        if(*orig)
        {
            *dest=A_MAYUS(*orig);
            dest++;
            orig++;

          while(!ES_BLANCO(*orig)&&*orig)
          {
              *dest=A_MINUS(*orig);
              dest++;
              orig++;
          }
            if(ES_BLANCO(*orig))
            {
                *dest=' ';
                dest++;
                orig++;
            }
        }
    }

    if(dest>cad && *(dest-1)==' ')
    {
       dest--;
       *dest='\0';
    }


    return cad;
}

char *normalizar_3 (char *cad)
{
    char *orig=cad,
         *dest=cad;

    while (*orig)
    {
        while (*orig && ES_BLANCO(*orig))
            orig++;

        if (*orig)
        {
            *dest=A_MAYUS(*orig);
            orig++;
            dest++;

            while (*orig && !ES_BLANCO(*orig) )
            {
                *dest=A_MINUS(*orig);
                orig++;
                dest++;
            }

            if (ES_BLANCO(*orig))
            {
                *dest=' ';
                orig++;
                dest++;
            }
        }
    }

    if (dest>cad && *(dest-1)==' ')
        dest--;
    *dest='\0';

    return cad;
}

char *normalizar_tok_3 (char *cad, char tok)
{

    char *orig=cad,
         *dest=cad;

    while (*orig)
    {

        while (*orig && ES_BLANCO(*orig))
            orig++;
        /// Primer letra
        if (dest==cad)
        {
           *dest=A_MAYUS(*orig);
            orig++;
            dest++;
        }
        /// Punto
        if (*orig==tok )
        {
            if (ES_BLANCO(*(dest-1) ))
                dest--;
            *dest=*orig;
            orig++;
            dest++;

            while (*orig && ES_BLANCO(*orig))
                orig++;

            *dest=' ';
            dest++;
            *dest=A_MAYUS(*orig);
            orig++;
            dest++;

        }
        else
        {
            /// Resto
            while (*orig && !ES_BLANCO(*orig) && *orig!=tok )
            {
                *dest=A_MINUS(*orig);
                orig++;
                dest++;
            }
            /// Blanco
            if (ES_BLANCO(*orig))
            {
                *dest=' ';
                orig++;
                dest++;
            }
        }
    }
    /// Punto final
   if ( dest>cad && *(dest-1)== ' '  )
        dest--;

    if ( dest>cad && *(dest-1)==tok  )
        *dest='\0';
    else
    {
        *dest=tok;
        dest++;
        *dest='\0';
    }

    return cad;
}

char *normalizar_2tok_3 (char *cad, char tok, char sep)
{
    char *orig=cad,
         *dest=cad;

    while (*orig)
    {
        while (ES_BLANCO(*orig))
            orig++;
        /// Primer letra
        if (dest==cad)
        {
            *dest=A_MAYUS(*orig);
            dest++;
            orig++;
        }
        /// Punto
        if (*orig==tok )
        {
            if (ES_BLANCO(*(dest-1) ))
                dest--;
            *dest=*orig;
            orig++;
            dest++;
            while (*orig && ES_BLANCO(*orig))
                orig++;
            *dest=' ';
            dest++;
            *dest=A_MAYUS(*orig);
            orig++;
            dest++;
        }
        else
        {
            /// Resto
            while (*orig && !ES_BLANCO(*orig) && *orig!=tok && *orig!=sep)
            {
                *dest=A_MINUS(*orig);
                orig++;
                dest++;
            }
            /// Coma
            if (*orig==sep)
            {
                if (ES_BLANCO(*(dest-1)))
                    dest--;
                *dest=*orig;
                orig++;
                dest++;
                while (*orig && ES_BLANCO(*orig))
                    orig++;
                *dest=' ';
                dest++;
                *dest=*orig;
                orig++;
                dest++;
            }
            /// Espacio
            if (ES_BLANCO(*orig))
            {
                *dest=' ';
                orig++;
                dest++;
            }
        }

    }

    if ( dest>cad && *(dest-1)== ' '  )
        dest--;

    if (*(dest-1)==sep)
    {
        *(dest-1)=tok;
        *dest='\0';
    }

    if ( dest>cad && *(dest-1)==tok  )
        *dest='\0';
    else
    {
        *dest=tok;
        dest++;
        *dest='\0';
    }

    return cad;
}
