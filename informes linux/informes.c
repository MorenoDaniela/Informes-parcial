#ifndef INFORMES_C_INCLUDED
#define INFORMES_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>//para linux
#include "informes.h"
#include "musico.h"
#include "instrumento.h"
#include "orquesta.h"
#include "funciones.h"

//A
/** \brief Solicita un lugar y lista las orquestas correspondientes a ese lugar.
 *
 * \param arrayOrquesta puntero al Array de Orquesta
 * \param limiteOrquesta int Tamaño del array
 * \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
 *
 */
int inf_A_orquestasSegunLugar (Orquesta* arrayOrquesta, int limiteOrquesta)
{
    int retorno=-1;
    int i;
    char auxLugar[50];

    if (arrayOrquesta!=NULL && limiteOrquesta>0)
    {
        getString("\nIngrese el nombre del lugar para saber si alguna orquesta se encuentra ahi: \n","\nError, lugar no valido.\n",5,50,3,auxLugar);
            for (i=0;i<=limiteOrquesta;i++)
            {
                if (arrayOrquesta[i].isEmpty==1)
                continue;

                if (arrayOrquesta[i].isEmpty==0)
                {
                    if (strcmp(arrayOrquesta[i].lugar,auxLugar)==0)
                    {
                        printf ("\nId de orquesta: %d. \n",arrayOrquesta[i].idOrquesta);
                        printf ("Nombre de orquesta: %s .\n",arrayOrquesta[i].nombre);
                        printf ("Lugar de orquesta: %s \n",arrayOrquesta[i].lugar);
                        switch (arrayOrquesta[i].tipo)
                        {
                        case 1:
                            printf ("Tipo de orquesta : Sinfonica.\n");
                            break;
                        case 2:
                            printf ("Tipo de orquesta: Filarmonica.\n");
                            break;
                        case 3:
                            printf ("Tipo de orquesta: Camara.\n");
                            break;
                        }
                    }
                }
            }
        retorno=0;
    }
    return retorno;
}

//B
/** \brief Lista los musicos que no superan la edad de 25 años.
 *
 * \param Musico puntero al array de musicos.
 * \param limiteMusico int tamaño del array de musicos.
 * \param Instrumento puntero al array de instrumentos.
 * \param limiteInstrumento int tamaño del array de instrumentos.
 * \param Orquesta puntero al array de orquestas
 * \param  limiteOrquesta int tamaño del array de orquestas.
 * \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) Ok
 *
 */

int inf_B_musicosQueNoSuperan25(Musico* arrayMusicos,int limiteMusicos,Instrumento* arrayInstrumento, int limiteInstrumento, Orquesta* arrayOrquesta, int limiteOrquesta)
{
    int retorno=-1;
    int i;
    int posicionInstrumento;
    int posicionOrquesta;
    int edad=25;
    int musicosQueNoSuperan=0;

    if (arrayMusicos!=NULL && limiteMusicos>0)
    {
        for (i=0;i<=limiteMusicos;i++)
        {
            if (arrayMusicos[i].isEmpty==1)
                continue;
            if (arrayMusicos[i].isEmpty==0)
            {
                if (arrayMusicos[i].edad<edad)
                {
                    printf ("\nNombre del musico: %s \n",arrayMusicos[i].nombre);
                    printf ("Apellido del musico: %s\n",arrayMusicos[i].apellido);
                    printf ("Edad del musico: %d. \n",arrayMusicos[i].edad);
                    printf ("Id musico: %d \n",arrayMusicos[i].idMusico);
                    printf ("Id instrumento %d \n",arrayMusicos[i].idInstrumento);
                    musicosQueNoSuperan++;
                    instrumento_buscarID(arrayInstrumento,limiteInstrumento,arrayMusicos[i].idInstrumento,&posicionInstrumento);
                    orquesta_buscarID(arrayOrquesta,limiteOrquesta,arrayMusicos[i].idOrquesta,&posicionOrquesta);
                    printf ("Nombre del instrumento: %s \n",arrayInstrumento[posicionInstrumento].nombre);
                    printf ("Nombre de orquesta: %s \n",arrayOrquesta[posicionOrquesta].nombre);
                }
            }
        }
        printf ("\nLa cantidad de musicos que no superan la edad 25 es: %d \n",musicosQueNoSuperan);
        retorno=0;
    }
    return retorno;
}

//C
/** \brief Lista las orquestas con menos de 6 musicos, imprimiendo su id, lugar y nombre.
 *
 * \param Musico puntero al array de musicos.
 * \param Orquesta puntero al array de orquestas.
 * \param limiteMusico int tamaño del array de musicos.
 * \param limiteOrquesta int tamaño del array de orquestas.
 * \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) Ok
 *
 */

int inf_C_orquestasMenosDeSeisMusicos(Musico* arrayMusico,int limiteMusico, Orquesta* arrayOrquesta, int limiteOrquesta)
{
    int i;
    int j;
    int retorno=-1;
    int contador=0;
    int flag=-1;

    if (arrayMusico!=NULL && arrayOrquesta!=NULL && limiteMusico>0 && limiteOrquesta>0)
    {
        for (i=0;i<limiteOrquesta;i++)
        {
            if (arrayOrquesta[i].isEmpty==1)
                continue;
            if (arrayOrquesta[i].isEmpty==0)
            {
                for(j=0;j<limiteMusico;j++)
                {
                    if (arrayMusico[j].isEmpty==1)
                        continue;
                    if (arrayMusico[j].isEmpty==0)
                    {
                        if(arrayOrquesta[i].idOrquesta==arrayMusico[j].idOrquesta)
                        {
                            contador++;
                        }
                    }
                }
                if (contador<6)
                {
                    printf ("\nId de orquesta: %d. \n",arrayOrquesta[i].idOrquesta);
                    printf ("Nombre de orquesta: %s. \n",arrayOrquesta[i].nombre);
                    printf ("Lugar de orquesta: %s.\n",arrayOrquesta[i].lugar);
                    switch (arrayOrquesta[i].tipo)
                    {
                        case 1:
                            printf ("Tipo de orquesta : Sinfonica.\n");
                        break;
                        case 2:
                            printf ("Tipo de orquesta: Filarmonica.\n");
                        break;
                        case 3:
                            printf ("Tipo de orquesta: Camara.\n");
                        break;
                    }
                    flag=0;
                }
                contador=0;
            }
        }

        if (flag==-1)
        {
            printf ("No se encontro ninguna orquesta con menos de 6 musicos.\n");
        }
        retorno=0;
    }
    return retorno;
}

//D-
/** \brief Lista los instrumentos que fueron solicitados por una orquesta determinada.
 *
 * \param Musico puntero al array de musicos.
 * \param Orquesta puntero al array de orquestas.
 * \param Instrumento puntero al array de instrumentos.
 * \param int limiteMusico tamaño del array de musicos
 * \param int limiteOrquesta tamaño del array de orquestas
 * \param int limiteInstrumento tamaño del array de instrumentos.
 * \return int Return (-1) si Error [largo no valido o NULL pointer o ID no encontrado] - (0) Ok
 *
 */

int inf_D_instrumentosSolicitadosPorOrquesta(Musico* arrayMusicos, Orquesta* arrayOrquesta,Instrumento* arrayInstrumento, int limiteMusico, int limiteOrquesta, int limiteInstrumento)
{
    int retorno=-1;
    int i;
    int auxId;
    int posicion;
    int posInstrumento;
    int contador=0;

    if (arrayOrquesta!=NULL && arrayMusicos!= NULL && arrayInstrumento!=NULL && limiteOrquesta>0 && limiteMusico>0 && limiteInstrumento>0)
    {
        orquesta_print(arrayOrquesta,limiteOrquesta);
        getInt("\nIngrese el id de la orquesta para saber que instrumentos solicito: \n","\nError, id no valido.\n",1,limiteOrquesta,3,&auxId);
        if (orquesta_buscarID(arrayOrquesta,limiteOrquesta,auxId,&posicion)==0)
        {
            for (i=0;i<=limiteMusico;i++)
            {
                if (arrayMusicos[i].isEmpty==1)
                continue;

                if (arrayMusicos[i].isEmpty==0)
                {
                    if (arrayMusicos[i].idOrquesta==auxId)
                    {
                        printf ("\nId de instrumento que solicito: %d. \n",arrayMusicos[i].idInstrumento);
                        printf ("Musico que lo toca: %s \n",arrayMusicos[i].nombre);
                        instrumento_buscarID(arrayInstrumento,limiteInstrumento,arrayMusicos[i].idInstrumento,&posInstrumento);
                        printf ("Nombre de instrumento: %s. \n",arrayInstrumento[posInstrumento].nombre);
                        switch (arrayInstrumento[posInstrumento].tipo)
                        {
                            case 1:
                                printf ("Tipo de instrumento: Cuerdas.\n");
                                break;
                            case 2:
                                printf ("Tipo de instrumento: Viento-Madera.\n");
                                break;
                            case 3:
                                printf ("Tipo de instrumento: Viento-Metal.\n");
                                break;
                            case 4:
                                printf ("Tipo de instrumento: Percusion.\n");

                        }
                        printf ("**********************************\n");
                        contador++;
                    }
                }
            }
            printf ("\nLa cantidad de instrumentos que solicito esta orquesta es: %d.\n",contador);
            retorno=0;
        }else
            printf ("\nNo se encontro este id.\n");
    }
    return retorno;
}

//E
/** \brief Lista las orquestas completas de acuerdo a la cantidad de instrumentos que estas poseen.
 *
 * \param Musico puntero al array de musicos.
 * \param Orquesta puntero al array de orquestas.
 * \param Instrumento puntero al array de instrumentos.
 * \param limiteMusico int tamaño del array de musicos.
 * \param limiteOrquesta int tamaño del array de orquestas.
 * \param limiteInstrumento int tamaño del array de instrumentos.
 * \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) Ok
 *
 */

int inf_E_orquestaCompleta(Musico* arrayMusico, Orquesta* arrayOrquesta, Instrumento* arrayInstrumento,int limiteMusico, int limiteOrquesta, int limiteInstrumento)
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int flag=-1;
    int contadorCuerda=0;
    int contadorViento=0;
    int contadorPercusion=0;

    if (arrayMusico!=NULL && arrayOrquesta!=NULL && arrayInstrumento!=NULL && limiteMusico>0 && limiteOrquesta>0 && limiteInstrumento>0)
    {
        for (i=0;i<limiteOrquesta;i++)
        {
            if (arrayOrquesta[i].isEmpty==1)
                continue;
            if (arrayOrquesta[i].isEmpty==0)
            {
                for (j=0;j<limiteMusico;j++)
                {
                    if (arrayMusico[j].isEmpty==1)
                        continue;
                    if (arrayMusico[j].isEmpty==0)
                    {
                        for (k=0;k<limiteInstrumento;k++)
                        {
                            if (arrayInstrumento[k].isEmpty==1)
                                continue;
                            if (arrayInstrumento[k].isEmpty==0)
                            {
                                if (arrayOrquesta[i].idOrquesta==arrayMusico[j].idOrquesta && arrayInstrumento[k].idInstrumento==arrayMusico[j].idInstrumento)
                                {
                                    switch (arrayInstrumento[k].tipo)
                                    {
                                        case 1:
                                            contadorCuerda++;
                                            break;
                                        case 2:
                                            contadorViento++;
                                            break;
                                        case 3:
                                            contadorViento++;
                                            break;
                                        case 4:
                                            contadorPercusion++;
                                            break;
                                    }
                                }
                            }
                        }
                    }
                }

                if (contadorCuerda>=4 && contadorViento>=4 && contadorPercusion>=1)
                {
                    printf ("\nOrquesta completa id: %d.\n",arrayOrquesta[i].idOrquesta);
                    printf ("Orquesta completa nombre: %s.\n",arrayOrquesta[i].nombre);
                    printf ("Orquesta completa lugar: %s.\n",arrayOrquesta[i].lugar);
                    flag=0;
                }

                contadorCuerda=0;
                contadorViento=0;
                contadorPercusion=0;
            }
        }

        if (flag==-1)
        {
            printf ("No se encontraron orquestas completas.\n");
        }
        retorno=0;
    }
    return retorno;
}

//F
/** \brief Lista las orquestas que tienen la menor cantidad de musicos.
 *
 * \param Orquesta puntero al array de orquestas.
 * \param Musico puntero al array de musicos.
 * \param limiteMusico int tamaño del array de musicos.
 * \param limiteOrquesta int tamaño del array de orquestas.
 * \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) Ok
 *
 */

int inf_F_orquestaConMenosMusicos(Orquesta* arrayOrquesta, int limiteOrquesta, Musico* arrayMusico, int limiteMusico)
{
    int retorno=-1;
    int i;
    int j;
    int contador=0;
    int indiceMaximo=0;
    int indiceMinimo=1000;

    if (arrayMusico!=NULL && arrayOrquesta!=NULL && limiteMusico>0 && limiteOrquesta>0)
    {
        for (i=0;i<limiteOrquesta;i++)
        {
            if (arrayOrquesta[i].isEmpty==1)
                continue;
            if (arrayOrquesta[i].isEmpty==0)
            {
                for (j=0;j<limiteMusico;j++)
                {
                    if (arrayMusico[j].isEmpty==1)
                        continue;
                    if (arrayMusico[j].isEmpty==0)
                    {
                        if (arrayOrquesta[i].idOrquesta==arrayMusico[j].idOrquesta)
                        {
                            contador++;
                        }
                    }
                }

                if (contador>indiceMaximo)
                {
                    indiceMaximo=contador;
                }else if (contador<=indiceMinimo)
                    {
                        indiceMinimo=contador;
                        printf ("\nId de orquesta: %d. \n",arrayOrquesta[i].idOrquesta);
                        printf ("Nombre de orquesta: %s. \n",arrayOrquesta[i].nombre);
                        printf ("Lugar de orquesta: %s.\n",arrayOrquesta[i].lugar);
                        printf ("Cantidad de musicos: %d\n",contador);
                        printf ("indice maximo %d\n",indiceMaximo);
                        printf ("indice minimo %d\n",indiceMinimo);
                        switch (arrayOrquesta[i].tipo)
                        {
                            case 1:
                                printf ("Tipo de orquesta : Sinfonica.\n");
                            break;
                            case 2:
                                printf ("Tipo de orquesta: Filarmonica.\n");
                            break;
                            case 3:
                                printf ("Tipo de orquesta: Camara.\n");
                            break;
                        }
                    }

                contador=0;
            }
        }

        retorno=0;
    }
    return retorno;
}

//G
/** \brief Imprime por pantalla el promedio de instrumentos por orquesta.
 *
 * \param Musico puntero al array de musicos.
 * \param Orquesta puntero al array de orquestas.
 * \param limiteMusico int tamaño del array de musicos.
 * \param limiteOrquesta int tamaño del array de orquestas.
 * \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) Ok
 *
 */

int inf_G_instrumentoPorOrquesta(Musico* arrayMusico, Orquesta* arrayOrquesta, int limiteMusico, int limiteOrquesta)
{
    int retorno=-1;
    int i;
    int contadorMusico=0;
    int contadorOrquesta=0;
    float promedio=0;

    if (arrayMusico!=NULL && arrayOrquesta!=NULL && limiteMusico>0 && limiteOrquesta>0)
    {
        for (i=0;i<=limiteMusico;i++)
        {
            if (arrayMusico[i].isEmpty==1)
                continue;
            if (arrayMusico[i].isEmpty==0)
            {
                contadorMusico++;
            }
        }

        for (i=0;i<=limiteOrquesta;i++)
        {
            if (arrayOrquesta[i].isEmpty==1)
                continue;
            if (arrayOrquesta[i].isEmpty==0)
            {
                contadorOrquesta++;
            }
        }
        promedio=contadorMusico/(float)contadorOrquesta;
        printf("\nEl promedio de instrumentos por orquesta es: %.2f",promedio);
        retorno=0;
    }
    return retorno;
}

//H
/** \brief Lista por pantalla los musicos que no utilizan instrumentos de tipo viento.
 *
 * \param Musico puntero al array de musicos.
 * \param Instrumento puntero al array de instrumentos.
 * \param limiteMusico int tamaño del array de musicos.
 * \param limiteInstrumento int tamaño del array de instrumentos
 * \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) Ok
 *
 */

int inf_H_musicosNoViento(Musico* arrayMusico,Instrumento* arrayInstrumento, int limiteMusico, int limiteInstrumento)
{
    int i;
    int j;
    int retorno=-1;

    if (arrayMusico!= NULL && arrayInstrumento!= NULL && limiteMusico >0 && limiteInstrumento>0)
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
                            if (arrayInstrumento[j].tipo!=2 && arrayInstrumento[j].tipo!=3)
                            {
                                printf ("\nNombre del musico: %s.\n",arrayMusico[i].nombre);
                                printf ("Apellido del musico: %s.\n",arrayMusico[i].apellido);
                                printf ("Edad: %d.\n",arrayMusico[i].edad);
                                printf ("Nombre del instrumento: %s.\n",arrayInstrumento[j].nombre);
                                printf ("Tipo de instrumento: %d.\n",arrayInstrumento[j].tipo);
                                switch (arrayInstrumento[j].tipo)
                                {
                                case 1:
                                    printf ("Tipo de instrumento: cuerdas.\n");
                                    break;
                                case 4:
                                    printf ("Tipo de instrumento: percusion.\n");
                                    break;
                                }
                            }
                        }
                    }
                }
            }

        }
        retorno=0;
    }
    return retorno;
}

//H2
/** \brief Ordena el array de musicos por apellido, si encuentra algun apellido igual ordena por nombre
 *
 * \param Musico puntero al array de musicos.
 * \param limiteMusico int tamaño del array de musicos.
 * \param orderFirst int primer parametro por el que va a ordenar.
 * \param orderSecond int segundo parametro por el que va a ordenar.
 * \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) Ok
 *
 */

int inf_H_musicosPorApellido (Musico* arrayMusico, int limiteMusico, int orderFirst, int orderSecond)
{
    int retorno=-1;
    int i;
    Musico buffer;
    int flagSwap;

    if(arrayMusico!=NULL && limiteMusico>0)
    {
        do
        {
            flagSwap=0;
            for (i=0; i<limiteMusico-1; i++)
            {
                if (arrayMusico[i].isEmpty==1)
                    continue;
                if (arrayMusico[i].isEmpty==0)
                {
                    if( ((strncmp(arrayMusico[i].apellido,arrayMusico[i+1].apellido,31) < 0) && orderFirst) ||
                        ((strncmp(arrayMusico[i].apellido,arrayMusico[i+1].apellido,31) >0) && !orderFirst) )
                    {

                        buffer = arrayMusico[i];
                        arrayMusico[i] = arrayMusico[i+1];
                        arrayMusico[i+1] = buffer;
                        flagSwap=1;
                    }
                    else if(strncmp(arrayMusico[i].apellido,arrayMusico[i+1].apellido,31) == 0)
                    {
                        if( ((strncmp(arrayMusico[i].nombre,arrayMusico[i+1].nombre,31) <0) && orderSecond) ||
                           ((strncmp(arrayMusico[i].nombre,arrayMusico[i+1].nombre,31) >0) && !orderSecond) )
                        {

                            buffer = arrayMusico[i];
                            arrayMusico[i] = arrayMusico[i+1];
                            arrayMusico[i+1] = buffer;
                            flagSwap=1;
                        }
                    }
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

#endif // INFORMES_C_INCLUDED
