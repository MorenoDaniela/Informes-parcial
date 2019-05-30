#ifndef MUSICO_C_INCLUDED
#define MUSICO_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musico.h"
#include "orquesta.h"
#include "instrumento.h"
//#include <stdio_ext.h>//para linux
#include "funciones.h"
#define TRIES 3

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array musico Array of musico
* \param limite int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int musicos_initStruct(Musico* arrayMusico, int limite)
{
    int retorno = -1;
    int i;
    if (arrayMusico!=NULL && limite>0)
    {
        for (i = 0; i<=limite; i++)
        {
            arrayMusico[i].isEmpty = 1;
            retorno=0;
        }
    }
    return retorno;
}
/** \brief Busca el primer lugar vacio en un array
* \param array musico puntero al Array de musico
* \param limite int Tamaño del array
* \param resultado int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int musicos_findEmpty (Musico* arrayMusico,int limite, int* resultado)
{
    int retorno=-1;
    int i;
    if (arrayMusico!=NULL && limite>=0 && resultado!=NULL)
    {
        for (i=0;i<=limite;i++)
        {
            if (arrayMusico[i].isEmpty==1)
            {
                *resultado=i;
                retorno=0;
                break;
            }
            //retorno = 1;
        }
    }
    return retorno;
}
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param arrayMusico puntero al Array de musicos
* \param limiteMusico int Tamaño del array musico
* \param ID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \param limiteOrquesta int tamaño del array de orquestas
* \param arrayOrquesta puntero al Array de orquestas
* \param arrayInstrumento puntero al Array de instrumentos
* \param limiteInstrumentos int Tamaño del array de instrumentos
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int musicos_alta(Musico* arrayMusico, Orquesta* arrayOrquesta,Instrumento* arrayInstrumento,int *id,int limiteMusico,int limiteOrquesta, int limiteInstrumento)
{
    int retorno=-1;
    int lugarVacio;
    int idOrquesta;
    int idInstrumento;
    int auxEdad;
    int posicion;
    //__fpurge(stdin);
    fflush(stdin);

    if (limiteOrquesta>0 && id!=NULL && limiteMusico>0 && limiteInstrumento>0)
    {
        orquesta_print(arrayOrquesta,limiteOrquesta);
        if (getInt("\nIngrese id de la orquesta: \n","\nError, id no valido.\n",1,limiteOrquesta,TRIES,&idOrquesta)==0)
        {
            if (orquesta_buscarID(arrayOrquesta,limiteOrquesta,idOrquesta,&posicion)==0)
            {
                instrumento_print(arrayInstrumento,limiteInstrumento);
                if (getInt("\nIngrese id de instrumento: \n","\nError, id no valido.\n",1,limiteInstrumento,TRIES,&idInstrumento)==0)
                {
                    if (instrumento_buscarID(arrayInstrumento,limiteInstrumento,idInstrumento,&posicion)==0)
                    {
                        if(musicos_findEmpty(arrayMusico,limiteMusico,&lugarVacio)!=-1)
                        {
                            if(getName("\nIngrese nombre del musico: \n","Error, nombre no valido.\n",1,31,TRIES,arrayMusico[lugarVacio].nombre)==0 &&
                                getApellido("\nIngrese apellido: \n","Error, apellido no valido.\n",1,12,TRIES,arrayMusico[lugarVacio].apellido)==0 &&
                                getInt("\nIngrese edad: \n","Error, edad no valido.\n",18,200,TRIES,&auxEdad)==0)
                            {
                               arrayMusico[lugarVacio].idMusico=*id;
                               arrayMusico[lugarVacio].idOrquesta=idOrquesta;
                               arrayMusico[lugarVacio].idInstrumento=idInstrumento;
                               arrayMusico[lugarVacio].edad=auxEdad;
                                (*id)++;
                               arrayMusico[lugarVacio].isEmpty=0;
                               printf("\nSe cargaron con exito los datos.\n");
                               retorno=0;
                            }else
                                {
                                    printf("\nNo se pudo cargar con exito.\n");
                                }
                        }else
                            {
                                printf("\nNo hay espacio vacio.\n");
                            }
                    }else
                        {
                            printf ("\nId del instrumento no encontrado.\n");
                        }
                }
            }else
            {
                printf ("\nId de orquesta no encontrado.\n");
            }
        }
    }
    return retorno;
}
/** \brief Lista los elementos del array de musicos con especificaciones de sus instrumentos
* \param arrayMusico Array de musico
* \param limiteMusico int Tamaño del array de musico
* \param arrayInstrumento Array de instrumentos
* \param limiteInstrumento int Tamaño del array de instrumentos
* \return int(-1)  largo no valido o NULL pointer (0) si logro listar todo correctamente
*
*/
int musico_print(Musico* arrayMusico, int limiteMusico, Instrumento* arrayInstrumento, int limiteInstrumento)
{
    int retorno=-1;
    int i;
    int j;
    char buffer[20];

    if (arrayMusico!=NULL && arrayInstrumento!=NULL && limiteInstrumento>0 && limiteMusico>0)
    {
        for (i=0;i<limiteMusico;i++)
        {
            if (arrayMusico[i].isEmpty==1)
                continue;
            if (arrayMusico[i].isEmpty==0)
            {
                for (j=0;j<limiteInstrumento;j++)
                {
                    if (arrayInstrumento[j].isEmpty==1)
                        continue;
                    if (arrayInstrumento[j].isEmpty==0)
                    {
                        if (arrayInstrumento[j].idInstrumento==arrayMusico[i].idInstrumento)
                        {

                            switch (arrayInstrumento[j].tipo)
                            {
                            case 1:
                                strncpy(buffer,"Cuerdas.",sizeof(buffer));
                                break;
                            case 2:
                                strncpy(buffer,"Viento-Madera.",sizeof(buffer));
                                break;
                            case 3:
                                strncpy(buffer,"Viento-Metal.",sizeof(buffer));
                                break;
                            case 4:
                                strncpy(buffer,"Percusion.",sizeof(buffer));
                                break;
                            }
                            printf ("\n********************************************");
                            printf ("\nNombre del musico: %s ",arrayMusico[i].nombre);
                            printf ("\nApellido del musico: %s ",arrayMusico[i].apellido);
                            printf ("\nTipo de instrumento : %s",buffer);
                            printf ("\nId de orquesta : %d",arrayMusico[i].idOrquesta);
                            printf ("\nNombre de instrumento: %s",arrayInstrumento[j].nombre);
                            printf ("\nId de instrumento : %d",arrayMusico[i].idInstrumento);
                            printf ("\nId del musico: %d ",arrayMusico[i].idMusico);
                        }
                    }
                }
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief  Lista los elementos del array de musicos
 *
 * \param arrayMusico Array de musico
 * \param limiteMusico int Tamaño del array de musico
 * \return void
 *
 */

void musicos_print(Musico* arrayMusico, int limite)
{
    int i;
    for (i=0;i<limite;i++)
    {
        if (arrayMusico[i].isEmpty==0)
        {
            printf ("\n********************************************");
            printf ("\nNombre del musico: %s ",arrayMusico[i].nombre);
            printf ("\nApellido del musico: %s ",arrayMusico[i].apellido);
            printf ("\nEdad del musico: %d ",arrayMusico[i].edad);
            printf ("\nId de instrumento : %d",arrayMusico[i].idInstrumento);
            printf ("\nId del musico: %d ",arrayMusico[i].idMusico);
        }
    }
}

/** \brief Borra un elemento del array por ID
* \param array musico Array de musico
* \param limite int Tamaño del array de musicos
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musicos_baja(Musico* arrayMusico,int limiteMusico)
{
    int posicion;
    int idMusico;
    int retorno=-1;
    if (arrayMusico!=NULL && limiteMusico>0)
    {
        musicos_print(arrayMusico,limiteMusico);
        if (getInt("\nIngrese el id del musico a dar de baja: \n","Error, id no valido.",1,limiteMusico,TRIES,&idMusico)==0)
        {
            if (musico_buscarID(arrayMusico,limiteMusico,idMusico,&posicion)==0)
            {
                if (arrayMusico[posicion].isEmpty==0)
                {
                    arrayMusico[posicion].isEmpty=1;
                    printf ("\nSe borro el id: %d \n",arrayMusico[posicion].idMusico);
                    retorno=0;
                }
            }else
                printf ("\nNo se encontro el id del musico.\n");
        }
    }
    return retorno;
}

/** \brief Busca un elemento por ID y modifica sus campos
* \param array Musico Array de Musico
* \param limiteMusico int Tamaño del array de musicos
* \param array Orquesta Array de orquestas
* \param limiteOrquesta int Tamaño del array de orquestas
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/

int musicos_modificar(Musico* arrayMusico,Orquesta* arrayOrquesta,int limiteOrquesta, int limiteMusico)
{
    int retorno=-1;
    int posicion;
    int opcion;
    int idOrquesta;
    int idMusico;
    int auxEdad;//
    if (arrayMusico!=NULL && limiteMusico>0 && limiteOrquesta>0 && arrayOrquesta!=NULL)
    {
        musicos_print(arrayMusico,limiteMusico);
        if (getInt("\nIngrese id del musico a modificar: \n","\nError, id no valida.\n",1,limiteMusico,TRIES,&idMusico)==0)
        {
            if (musico_buscarID(arrayMusico,limiteMusico,idMusico,&posicion)==0)
            {
                while (opcion!=3)
                {
                    getInt("\n1-Modificar edad.\n2-Modificar id de orquesta.\n3-Salir de modificacion.\n","Opcion no valida\n",1,3,TRIES,&opcion);
                    system("cls");//
                    //system("clear");
                    fflush(stdin);
                    //__fpurge(stdin);
                    switch(opcion)
                    {
                        case 1:
                            if (getInt("\nIngrese nueva edad: \n","Edad no valido.\n",18,200,TRIES,&auxEdad)==0)
                            {
                                arrayMusico[posicion].edad=auxEdad;
                                printf ("Modificacion con exito.\n");
                            }else
                                {
                                    printf ("\nModificacion sin exito.\n");
                                }
                            break;
                        case 2:
                            if (getInt("\nIngrese nuevo id de la orquesta: \n","\nError, id no valido",1,limiteOrquesta,TRIES,&idOrquesta)==0)
                            {
                                if (orquesta_buscarID(arrayOrquesta,limiteOrquesta,idOrquesta,&posicion)==0)
                                {
                                    arrayMusico[posicion].idOrquesta=idOrquesta;
                                    printf ("Modificacion con exito.\n");
                                }else
                                    {
                                        printf ("\nNo se encontro el id.\n");
                                    }
                            }
                            break;
                        default:
                            printf("\nOpcion no valida.\n");
                            break;
                    }//fin switch
                }//fin while
                retorno=0;
            }else
                printf("\nNo se encontro el id.\n");
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array Musico Array de Musico
* \param limite int Tamaño del array
* \param valorbuscado int el valor a buscar en el array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [tamaño invalido o NULL pointer] - (0) si encuentra el valor buscado
*
*/

int musico_buscarID(Musico* arrayMusico, int limite, int valorBuscado, int* posicion)                    //cambiar musico
{
    int retorno=-1;
    int i;
    if(arrayMusico!= NULL && limite>=0)
    {
        for(i=0;i<=limite;i++)
        {
            if(arrayMusico[i].isEmpty==1)
                continue;
            else if(arrayMusico[i].idMusico==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Borra un elemento del arrayOrquesta por ID ademas borra los musicos que se encontraban en esa orquesta
 *
 * \param Orquesta puntero el array de orquestas
 * \param limite orquesta int tamaño del array de orquestas
  * \param Musico puntero el array de musicos
 * \param limite musico int tamaño del array de musicos
 * \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
 *
 */

int orquesta_baja(Orquesta* arrayOrquesta, Musico* arrayMusico, int limiteOrquesta, int limiteMusico)
{
    int retorno=-1;
    int i;
    int j;
    int idBaja;
    int flag=-1;

    if (arrayMusico!=NULL && arrayOrquesta!=NULL && limiteMusico>0 && limiteOrquesta>0)
    {
        orquesta_print(arrayOrquesta,limiteOrquesta);
        if (getInt("Ingrese id de orquesta a dar de baja: ","Error, id no valido.",1,limiteOrquesta,TRIES,&idBaja)==0)
        {
            for (i=0;i<limiteOrquesta;i++)
            {
                if (arrayOrquesta[i].isEmpty==1)
                    continue;
                if (arrayOrquesta[i].isEmpty==0)
                {
                    if (arrayOrquesta[i].idOrquesta==idBaja)
                    {
                        arrayOrquesta[i].isEmpty=1;
                        printf ("\nSe borro la orquesta de id: %d",arrayOrquesta[i].idOrquesta);
                        flag=0;

                        for (j=0;j<limiteMusico;j++)
                        {
                            if (arrayMusico[j].isEmpty==1)
                                continue;
                            if (arrayMusico[j].isEmpty==0)
                            {
                                if (arrayMusico[j].idOrquesta==idBaja)
                                {
                                    arrayMusico[j].isEmpty=1;
                                }
                            }
                        }
                    }
                }
            }

        if (flag==-1)
        {
            printf ("El id de esa orquesta no fue encontrado.\n");
        }
        retorno=0;
        }

    }
    return retorno;
}

void harcodearMusicos(Musico* arrayMusico, int limite)
{
    strcpy(arrayMusico[0].nombre,"Mus1");
    strcpy(arrayMusico[0].apellido,"Amus1");
    arrayMusico[0].edad=30;
    arrayMusico[0].idInstrumento=2;
    arrayMusico[0].idOrquesta=1;
    arrayMusico[0].isEmpty=0;
    arrayMusico[0].idMusico=1;

    strcpy(arrayMusico[1].nombre,"Mus2");
    strcpy(arrayMusico[1].apellido,"Amus2");
    arrayMusico[1].edad=20;
    arrayMusico[1].idInstrumento=5;
    arrayMusico[1].idOrquesta=2;
    arrayMusico[1].isEmpty=0;
    arrayMusico[1].idMusico=2;

    strcpy(arrayMusico[2].nombre,"Mus3");
    strcpy(arrayMusico[2].apellido,"Amus3");
    arrayMusico[2].edad=25;
    arrayMusico[2].idInstrumento=2;
    arrayMusico[2].idOrquesta=4;
    arrayMusico[2].isEmpty=0;
    arrayMusico[2].idMusico=3;

    strcpy(arrayMusico[4].nombre,"Mus5");
    strcpy(arrayMusico[4].apellido,"Amus5");
    arrayMusico[4].edad=22;
    arrayMusico[4].idInstrumento=3;
    arrayMusico[4].idOrquesta=1;
    arrayMusico[4].isEmpty=0;
    arrayMusico[4].idMusico=5;

    strcpy(arrayMusico[5].nombre,"Mus6");
    strcpy(arrayMusico[5].apellido,"Amus6");
    arrayMusico[5].edad=35;
    arrayMusico[5].idInstrumento=4;
    arrayMusico[5].idOrquesta=3;
    arrayMusico[5].isEmpty=0;
    arrayMusico[5].idMusico=6;

    strcpy(arrayMusico[3].nombre,"Mus4");
    strcpy(arrayMusico[3].apellido,"Amus4");
    arrayMusico[3].edad=27;
    arrayMusico[3].idInstrumento=1;
    arrayMusico[3].idOrquesta=4;
    arrayMusico[3].isEmpty=0;
    arrayMusico[3].idMusico=4;

    ////////
    /////////**************************************

  //Utilizar para probar orquestas completas
    strcpy(arrayMusico[6].nombre,"Mus7");
    strcpy(arrayMusico[6].apellido,"Amus7");
    arrayMusico[6].edad=31;
    arrayMusico[6].idInstrumento=2;
    arrayMusico[6].idOrquesta=1;
    arrayMusico[6].isEmpty=0;
    arrayMusico[6].idMusico=7;

    strcpy(arrayMusico[7].nombre,"Mus8");
    strcpy(arrayMusico[7].apellido,"Amus8");
    arrayMusico[7].edad=32;
    arrayMusico[7].idInstrumento=3;
    arrayMusico[7].idOrquesta=1;
    arrayMusico[7].isEmpty=0;
    arrayMusico[7].idMusico=8;

    strcpy(arrayMusico[8].nombre,"Mus9");
    strcpy(arrayMusico[8].apellido,"Amus9");
    arrayMusico[8].edad=33;
    arrayMusico[8].idInstrumento=5;
    arrayMusico[8].idOrquesta=1;
    arrayMusico[8].isEmpty=0;
    arrayMusico[8].idMusico=9;

    strcpy(arrayMusico[9].nombre,"Mus10");
    strcpy(arrayMusico[9].apellido,"Amus10");
    arrayMusico[9].edad=34;
    arrayMusico[9].idInstrumento=1;
    arrayMusico[9].idOrquesta=1;
    arrayMusico[9].isEmpty=0;
    arrayMusico[9].idMusico=10;

    strcpy(arrayMusico[10].nombre,"Mus11");
    strcpy(arrayMusico[10].apellido,"Amus11");
    arrayMusico[10].edad=35;
    arrayMusico[10].idInstrumento=1;
    arrayMusico[10].idOrquesta=1;
    arrayMusico[10].isEmpty=0;
    arrayMusico[10].idMusico=11;

    strcpy(arrayMusico[11].nombre,"Mus12");
    strcpy(arrayMusico[11].apellido,"Amus12");
    arrayMusico[11].edad=36;
    arrayMusico[11].idInstrumento=1;
    arrayMusico[11].idOrquesta=1;
    arrayMusico[11].isEmpty=0;
    arrayMusico[11].idMusico=12;

    strcpy(arrayMusico[12].nombre,"Mus13");
    strcpy(arrayMusico[12].apellido,"Amus13");
    arrayMusico[12].edad=37;
    arrayMusico[12].idInstrumento=1;
    arrayMusico[12].idOrquesta=1;
    arrayMusico[12].isEmpty=0;
    arrayMusico[12].idMusico=13;

    //segunda orquesta completa ******************
    strcpy(arrayMusico[13].nombre,"Mus14");
    strcpy(arrayMusico[13].apellido,"Amus14");
    arrayMusico[13].edad=38;
    arrayMusico[13].idInstrumento=1;
    arrayMusico[13].idOrquesta=4;
    arrayMusico[13].isEmpty=0;
    arrayMusico[13].idMusico=14;

    strcpy(arrayMusico[14].nombre,"Mus15");
    strcpy(arrayMusico[14].apellido,"Amus15");
    arrayMusico[14].edad=39;
    arrayMusico[14].idInstrumento=1;
    arrayMusico[14].idOrquesta=4;
    arrayMusico[14].isEmpty=0;
    arrayMusico[14].idMusico=15;

    strcpy(arrayMusico[15].nombre,"Mus16");
    strcpy(arrayMusico[15].apellido,"Amus16");
    arrayMusico[15].edad=40;
    arrayMusico[15].idInstrumento=1;
    arrayMusico[15].idOrquesta=4;
    arrayMusico[15].isEmpty=0;
    arrayMusico[15].idMusico=16;

    strcpy(arrayMusico[16].nombre,"Mus17");
    strcpy(arrayMusico[16].apellido,"Amus17");
    arrayMusico[16].edad=41;
    arrayMusico[16].idInstrumento=2;
    arrayMusico[16].idOrquesta=4;
    arrayMusico[16].isEmpty=0;
    arrayMusico[16].idMusico=17;

    strcpy(arrayMusico[17].nombre,"Mus18");
    strcpy(arrayMusico[17].apellido,"Amus18");
    arrayMusico[17].edad=42;
    arrayMusico[17].idInstrumento=5;
    arrayMusico[17].idOrquesta=4;
    arrayMusico[17].isEmpty=0;
    arrayMusico[17].idMusico=18;

    strcpy(arrayMusico[18].nombre,"Mus19");
    strcpy(arrayMusico[18].apellido,"Amus19");
    arrayMusico[18].edad=43;
    arrayMusico[18].idInstrumento=2;
    arrayMusico[18].idOrquesta=4;
    arrayMusico[18].isEmpty=0;
    arrayMusico[18].idMusico=19;

    strcpy(arrayMusico[19].nombre,"Mus20");
    strcpy(arrayMusico[19].apellido,"Amus20");
    arrayMusico[19].edad=44;
    arrayMusico[19].idInstrumento=2;
    arrayMusico[19].idOrquesta=4;
    arrayMusico[19].isEmpty=0;
    arrayMusico[19].idMusico=20;


}

void harcodearTODO(Musico* arrayMusico,int limiteMusico, Instrumento* arrayInstrumento, int limiteInstrumento, Orquesta* arrayOrquesta, int limiteOrquesta)
{
    harcodearOrquestas(arrayOrquesta,limiteOrquesta);
    harcodearInstrumento(arrayInstrumento,limiteInstrumento);
    harcodearMusicos(arrayMusico,limiteMusico);
}
#endif // MUSICO_C_INCLUDED
