#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void * crearMatriz(void **mat ,const char *msj);
void * crearMatriz_variable(void **mat ,const char *msj);
void liberarMem (void *mat);
void insertarEnMatriz (void *mat);
void mostrarVector (void *vec, int tipo, int ce);
void mostrarMatriz (void *mat);

int main()
{
    void *mat_A;

    //crearMatriz_variable (&mat_A, "A");
    crearMatriz(&mat_A, "A");

    if ( mat_A )
    {
        insertarEnMatriz(mat_A);
        mostrarMatriz(mat_A);
    }
    else
        printf("\n Error");



    free(mat_A);

    return 0;
}

void mostrarVector (void *vec, int tipo, int ce)
{
    int i;

    switch (tipo)
    {
        case -1:
            for (i=0 ; i<ce ; i++, vec+=sizeof(int))
                printf ("|%d| ", *(int *)vec);
            break;
        case -2:
            for (i=0 ; i<ce ; i++, vec+=sizeof(float))
                printf ("|%f| ", *(float *)vec);
            break;
        case -3:
            for (i=0 ; i<ce ; i++, vec+=sizeof(char))
                printf ("|%c| ", *(char *)vec);
            break;
        default:
            for (i=0 ; i<ce ; i++, vec+=tipo)
                printf ("|%s| ", (char *)vec);
            break;
    }
}

void mostrarMatriz (void *mat)
{
    int *ptrFil=mat;

    while (*ptrFil)
    {
        mostrarVector(*ptrFil,*(ptrFil+1), *(ptrFil+2) );
        printf ("\n");
        ptrFil+=4;
    }
}

void liberarMem (void *mat)
{
    int *ptrFil=mat;

    while (*ptrFil)
    {
        free(*ptrFil);
        ptrFil+=4;
    }
}

void insertarEnMatriz (void *mat)
{
    void *ptrVector;
    int *ptrFil= mat,
        *ptrTipo,
        *ptrTam,
        *ptrCE,
        i;


    while (*ptrFil)
    {
        /// Obtengo la direccion del vetor
        ptrVector = *ptrFil;
        ptrFil++;

        /// Obtengo la cantidad de bytes del tipo de elemento
        ptrTipo = ptrFil;
        ptrFil++;

        /// Obtengo la cantidad maxima de elementos (dinamico)
        ptrTam= ptrFil;
        ptrFil++;

        /// Obtengo el numero de elementos que tiene
        ptrCE = ptrFil;

        /// Inserto los elementos
        switch (*ptrTipo)
        {
            case -1:
                for (i=*ptrCE ; i<*ptrTam ; i++, ptrVector+=sizeof(int))
                {
                    printf ("\n Ingrese dato %d: ",i+1);
                    scanf("%d", ptrVector);
                }

                break;
            case -2:
                for (i=*ptrCE ; i<*ptrTam; i++, ptrVector+=sizeof(float))
                {
                    printf ("\n Ingrese dato %d: ",i+1);
                    scanf("%f", ptrVector);
                }

                break;
            case -3:
                for (i=*ptrCE ; i<*ptrTam ; i++, ptrVector+=sizeof(char))
                {
                    fflush(stdin);
                    printf ("\n Ingrese dato %d: ",i+1);
                    scanf("%c", ptrVector);
                    fflush(stdin);
                }

                break;
            default:
                for (i=*ptrCE ; i<*ptrTam; i++, ptrVector+=*ptrTipo)
                {
                    fflush(stdin);
                    printf ("\n Ingrese dato %d: ",i+1);
                    gets(ptrVector);
                    //scanf("%d", ptrVector);
                }
                break;
        }




        /// Me voy a la otra fila
        ptrFil++;
    }
}


void * crearMatriz_variable(void **mat, const char *msj)
{
    unsigned fil,
             col,
             tam,
             opc,
             i;
    void *ptrMat;
    int  *ptrFil,
         *ptrVector,
         *ptrTipo,
         *ptrTam,
         *ptrCE;

    printf ("\n Ingrese el tamanio de la matriz %s: ", msj);
    printf ("\n Filas: ");
    scanf("%d",&fil);

    /// Formato de la matriz
    /// Direccion | Bytes del tipo elemento | CE

    /// Reservo toda la memoria necesaria
    ///               Direccion        + Tipo         + TAM          + CE             * Filas + 1 (Para colocar un puntero a null en n+1)
     ptrMat = malloc( (sizeof ( int *) + sizeof (int) + sizeof (int) + sizeof (int) ) * (fil+1) ) ;

    if (!mat)
        return NULL;
    *mat = ptrMat;
    ptrFil = ptrMat;

    for ( i=0 ; i< fil ; i++ )
    {

        printf ("\n Fila: %d", i+1);
        printf ("\n Columnas: ");
        scanf("%d",&col);

        do
        {
            printf ("\n Opciones de tipo de matriz\n"
                "\n 1: Enteros"
                "\n 2: Caracteres"
                "\n 3: Cadenas de texto\n"
                "\n Ingrese opcion: ");
            scanf("%d", &opc);
            printf("\n");
            if (opc < 1 || opc > 3)
                printf("\n Opcion invalida. ");
            system ("pause");
            system ("cls");
        }while (opc < 1 || opc > 3);

        switch (opc)
        {
            case 1:
                tam= sizeof(int);
                break;
            case 2:
                tam= sizeof(char);
                break;
            case 3:
                printf ("\n Ingrese largo de cadena: ");
                scanf("%d", &tam);
                break;
            default:
                tam=0;
                break;
        }

        /// me estoy desplazando mal ?
        ptrVector = malloc ( tam * col);
        if (!ptrVector)
            return NULL;

        /// Limpio la memoria asiganada al vector - visualizacion
        memset(ptrVector, '\0',tam * col );
        /// Limpio memoria
        //memset(ptrFil,'\0', sizeof(ptrFil));

        /// Almaceno la direccion de comienzo de cada fila
        *ptrFil = (int *) ptrVector;
        ptrFil++;
        //ptrFil = ptrFil + sizeof(int);

        /// Almaceno la cantidad de bytes del tipo elemento
        ptrTipo = ptrFil;
        *ptrTipo = tam;
        ptrFil++;
        //ptrFil = ptrFil + sizeof(int);

        /// Almaceno la cantidad maxima de elementos de cada fila
        ptrTam = ptrFil;
        *ptrTam = col;
        ptrFil++;

        /// Almaceno la cantidad de elementos (en cero porque no se insertaron datos)
        ptrCE = ptrFil;
        *ptrCE = '0';
        ptrFil++;
    }

    //ptrFil++;
    *ptrFil='\0';

    return ptrMat;
}

void * crearMatriz(void **mat, const char *msj)
{
    unsigned fil,
             col,
             tam,
             opc,
             i;
    void *ptrMat;
    int  *ptrFil,
         *ptrVector,
         *ptrTipo,
         *ptrTam,
         *ptrCE;

    printf ("\n Ingrese el tamanio de la matriz %s: ", msj);
    printf ("\n Filas: ");
    scanf("%d",&fil);

    printf ("\n Columnas: ");
    scanf("%d",&col);

    do
    {
        printf ("\n Opciones de tipo de matriz\n"
                "\n 1: Enteros"
                "\n 2: Flotantes"
                "\n 3: Caracteres"
                "\n 4: Cadenas de texto\n"
                "\n Ingrese opcion: ");
        scanf("%d", &opc);
        printf("\n");
        if (opc < 1 || opc > 4)
            printf("\n Opcion invalida. ");
        system ("pause");
        system ("cls");
    }
    while (opc < 1 || opc > 4);

        switch (opc)
        {
            case 1:
                tam= sizeof(int);
                break;
            case 2:
                tam = sizeof(float);
                break;
            case 3:
                tam= sizeof(char);
                break;
            case 4:
                printf ("\n Ingrese largo de cadena: ");
                scanf("%d", &tam);
                break;
            default:
                tam=0;
                break;
        }

    /// Formato de la matriz
    /// Direccion | Bytes del tipo elemento | CE

    /// Reservo toda la memoria necesaria
    ///               Direccion        + Tipo         + TAM          + CE             * Filas + 1 (Para colocar un puntero a null en n+1)
     ptrMat = malloc( (sizeof ( int *) + sizeof (int) + sizeof (int) + sizeof (int) ) * (fil+1) ) ;

    if (!mat)
        return NULL;
    *mat = ptrMat;
    ptrFil = ptrMat;

    for ( i=0 ; i< fil ; i++ )
    {


        /// me estoy desplazando mal ?
        ptrVector = malloc ( tam * col);
        if (!ptrVector)
            return NULL;

        /// Limpio la memoria asiganada al vector - visualizacion
        memset(ptrVector, '\0',tam * col );
        /// Limpio memoria
        //memset(ptrFil,'\0', sizeof(ptrFil));

        /// Almaceno la direccion de comienzo de cada fila
        *ptrFil = (int *) ptrVector;
        ptrFil++;
        //ptrFil = ptrFil + sizeof(int);

        /// Almaceno la cantidad de bytes del tipo elemento
        ptrTipo = ptrFil;
        *ptrTipo = opc == 4 ? tam : opc*-1;
        ptrFil++;
        //ptrFil = ptrFil + sizeof(int);

        /// Almaceno la cantidad maxima de elementos de cada fila
        ptrTam = ptrFil;
        *ptrTam = col;
        ptrFil++;

        /// Almaceno la cantidad de elementos (en cero porque no se insertaron datos)
        ptrCE = ptrFil;
        *ptrCE = '\0';
        ptrFil++;
    }

    //ptrFil++;
    *ptrFil='\0';

    return ptrMat;
}


