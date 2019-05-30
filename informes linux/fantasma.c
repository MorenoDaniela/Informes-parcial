#ifndef FANTASMA_C_INCLUDED
#define FANTASMA_C_INCLUDED
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fantasma.h"
#include <stdio_ext.h>//para linux

#include "funciones.h"

#define TRIES 3

* \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array fantasma Array of fantasma
* \param limite int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*

int ocho_initStruct(Fantasma* arrayFantasma, int limite)
{
    int retorno = -1;
    int i;
    if (arrayFantasma!=NULL && limite>0)
    {
        for (i = 0; i < limite; i++)
        {
            arrayFantasma[i].isEmpty = 1;
            retorno=0;
        }
    }
    return retorno;
}
 \brief Busca el primer lugar vacio en un array
* \param array fantasma Array de fantasma
* \param limite int Tamaño del array
* \param resultado int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*

int ocho_findEmpty (Fantasma* arrayFantasma,int limite, int* resultado)
{
    int retorno=-1;
    int i;
    if (arrayFantasma!=NULL && limite>=0 && resultado!=NULL)
    {
        for (i=0;i<=limite;i++)
        {
            if (arrayFantasma[i].isEmpty==1)
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
 \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array fantasma Array de fantasma
* \param limite int Tamaño del array
* \param ID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*

int ocho_alta(Fantasma* arrayFantasma,int *id, int limite)
{
    int retorno=-1;
    int lugarVacio;
    __fpurge(stdin);
    //fflush(stdin);
    if (limite>0 && id!=NULL )
    {
        if(ocho_findEmpty(arrayFantasma,limite,&lugarVacio)!=-1)
        {
            if (getName("\nIngrese nombre: \n","Error, nombre no valido.\n",3,30,TRIES,arrayFantasma[lugarVacio].nombre)==0 &&
                getApellido("\nIngrese apellido: \n","Error, apellido no valido.\n",3,30,TRIES,arrayFantasma[lugarVacio].apellido)==0)
            {
               arrayFantasma[lugarVacio].idFantasma=*id;
                (*id)++;
               arrayFantasma[lugarVacio].isEmpty=0;
               printf("\nSe cargaron con exito los datos.\n");
               retorno=0;
            }else
                {
                    printf("\nNo se pudo cargar con exito.\n");
                }
        }else
        {
            printf("No hay espacio vacio.\n");
        }
    }
    return retorno;
}
 \brief Lista los elementos de un array
* \param array fantasma Array de fantasma
* \param limite int Tamaño del array
* \return void
*

void ocho_print(Fantasma* arrayFantasma, int limite)
{
    int i;
    for (i=0;i<=limite;i++)
    {
        if (arrayFantasma[i].isEmpty==0)
        {
            printf ("\n********************************************");
            printf ("\nNombre del fantasma: %s ",arrayFantasma[i].nombre);
            printf ("\nApellido del fantasma: %s ",arrayFantasma[i].apellido);
            printf ("\nId del fantasma: %d ",arrayFantasma[i].idFantasma);
            printf ("\nPosicion: %d ",i);
            printf ("\nEstado : %d \n",arrayFantasma[i].isEmpty);
        }
    }
}
 \brief Borra un elemento del array por ID
* \param array fantasma Array de fantasma
* \param limite int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*
int ocho_baja(Fantasma* arrayFantasma,int limite)
{
    int posicion;
    int retorno=-1;
    if (arrayFantasma!=NULL && limite>0)
    {
        ocho_print(arrayFantasma,limite);
        switch (ocho_findById("\nIngrese el id del fantasma a dar de baja: \n",arrayFantasma,&posicion,limite))
        {
            case 0:
            if (arrayFantasma[posicion].isEmpty==0)
            {
                arrayFantasma[posicion].isEmpty=1;
                printf ("\nSe borro el id: %d \n",arrayFantasma[posicion].idFantasma);
                retorno=0;
            }
            break;
            case 1:
                printf ("\nNo se encontro el id.\n");
                break;
            default:
                printf ("\nNo encontro el id.\n");
                break;
        }
    }
    return retorno;
}
//ESTA NO
int ocho_getId(char*msj,Fantasma* arrayFantasma,int limite)
{
    int i;
    int retorno=-1;
    Fantasma auxFantasma;
    if (getInt(msj,"\nOpcion no valida.\n",0,limite,TRIES,&auxFantasma.idFantasma)==0)
    {
        for (i=0;i<=limite;i++)
        {
            if (arrayFantasma[i].idFantasma == auxFantasma.idFantasma)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
 \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array fantasma Array de fantasma
* \param limite int Tamaño del array
* \param idEncontrado int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*

int ocho_findById(char* msj,Fantasma* arrayFantasma,int* idEncontrado, int limite)
{
    int i;
    int retorno=1;
    int auxFantasma;
    //revisar limite aca abajo
    if (msj!=NULL && arrayFantasma !=NULL && idEncontrado!=NULL && limite>0)
    {
        if (getInt(msj,"\nOpcion no valida.\n",0,limite,TRIES,&auxFantasma)==0)
        {
            for (i=0;i<=limite;i++)
            {
                if (arrayFantasma[i].isEmpty==0)
                {
                    if (arrayFantasma[i].idFantasma == auxFantasma)
                    {
                        retorno=0;
                        *idEncontrado=i;
                        break;
                    }
                }
            }
        }
    }
    return retorno;
}
\brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array fantasma Array de fantasma
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
/*
int ocho_buscarInt(Fantasma* arrayFantasma, int limite, int valorBuscado, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(arrayFantasma!= NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(arrayFantasma[i].isEmpty==1)
                continue;
            else if(arrayFantasma[i].varInt==valorBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
*/
/** \brief Busca un string en un array
* \param array fantasma Array de fantasma
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/

/*
int ocho_buscarString(Fantasma* arrayFantasma, int limite, char* valorBuscado, int* indice)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(arrayFantasma!=NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(arrayFantasma[i].isEmpty==1)
                continue;
            else if(strcmp(arrayFantasma[i].varString,valorBuscado)==0)                                        //cambiar campo varString
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}


 \brief Busca un elemento por ID y modifica sus campos
* \param array fantasma Array de fantasma
* \param limite int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*

int ocho_modificar(Fantasma* arrayFantasma,int limite)
{
    int retorno=-1;
    int posicion;
    int opcion;
    char auxNombre;
    char auxApellido;
    char auxDni;
    int auxEdad;
    if (arrayFantasma!=NULL && limite>0)
    {
        ocho_print(arrayFantasma,limite);
        //ocho_findById("Ingrese el id del fantasma a modificar",arrayFantasma,&posicion,limite);
        //posicion=ocho_getId(msj,arrayFantasma,limite);
        if (ocho_findById("Ingrese el id del fantasma a modificar: \n",arrayFantasma,&posicion,limite)==0)
        {
            while (opcion!=3)
            {
                getInt("\n1-Modificar nombre. \n2-Modificar apellido.\n3-Salir de modificacion.\n","Opcion no valida\n",1,3,TRIES,&opcion);
                //system("cls");//
                system("clear");
                //fflush(stdin);
                __fpurge(stdin);
                switch(opcion)
                {
                    case 1:
                    if (getName("Ingrese nuevo nombre: \n","Nombre no valido.\n",3,31,TRIES,arrayFantasma[posicion].nombre)==0)
                    {
                        //strncpy(arrayFantasma[posicion].nombre,&auxNombre,limiteof(arrayFantasma[posicion].nombre));
                        printf ("Modificacion con exito.\n");
                    }else
                        {
                            printf ("Modificacion sin exito.\n");
                        }
                    break;
                    case 2:
                    if (getApellido("Ingrese nuevo apellido: \n","Error, apellido no valido.\n",2,31,TRIES,arrayFantasma[posicion].apellido)==0)
                    {
                        //strncpy(arrayFantasma[posicion].apellido,&auxApellido,limiteof(auxApellido));
                        printf ("Modificacion con exito.\n");
                    }else
                        {
                            printf ("Modificacion sin exito.\n");
                        }
                        break;
                    case 3:
                        break;
                }//fin switch
            }
            retorno=0;//fin while
        }else
            printf("\nNo se encontro el id.\n");
    }
    return retorno;
}

 \brief  Ordena una doble cadena de letras
 *
 * \param Puntero al array fantasma
 * \param limite del array
 * \return retorna -1 si puntero nulo o limite menor a 0, retorna 0 si salio todo bien
 *

int ocho_ordenarDobleCadena(Fantasma* arrayFantasma,int limite)
{
    int i;
    Fantasma buffer;
    int retorno=-1;
    if (arrayFantasma!=NULL && limite>0)
    {
        for (i=0;i<=limite-1;i++)
        {
            if (arrayFantasma[i].isEmpty==1 || arrayFantasma[i+1].isEmpty==1)
            {
                continue;
            }
                if (strncmp(arrayFantasma[i].nombre,arrayFantasma[i+1].nombre,31)>0)
                {
                    buffer = arrayFantasma[i];
                    arrayFantasma[i]= arrayFantasma[i+1];
                    arrayFantasma[i+1]=buffer;
                }
                    else if(strncmp(arrayFantasma[i].nombre,arrayFantasma[i+1].nombre,31)==0)
                    {
                        if (strncmp(arrayFantasma[i].apellido, arrayFantasma[i+1].apellido,31)>0)
                        {
                            buffer= arrayFantasma[i];
                            arrayFantasma[i]=arrayFantasma[i+1];
                            arrayFantasma[i+1]=buffer;
                        }
                    }
        }
        retorno=0;
    }
    return retorno;
}

int ocho_ordenarTitulo(Fantasma* arrayFantasma,int limite)//usar para ordenar una sola cadena string
{
    int i;
    Fantasma buffer;
    int retorno=-1;
    if (arrayFantasma!=NULL && limite>0)
    {
        for (i=0;i<=limite-1;i++)
        {
            if (arrayFantasma[i].isEmpty==1 || arrayFantasma[i+1].isEmpty==1)
            {
                continue;
            }
                if (strncmp(arrayFantasma[i].nombre,arrayFantasma[i+1].nombre,51)>0)
                {
                    buffer = arrayFantasma[i];
                    arrayFantasma[i]= arrayFantasma[i+1];
                    arrayFantasma[i+1]=buffer;
                }
        }
        retorno=0;
    }
    return retorno;
}
void harcodearFantasmas(Fantasma* arrayFantasma, int limite)
{
    strcpy(arrayFantasma[0].nombre,"BBB");
    strcpy(arrayFantasma[0].apellido,"DDD");
    arrayFantasma[0].isEmpty=0;
    arrayFantasma[0].idFantasma=1;
    strcpy(arrayFantasma[1].nombre,"BBB");
    strcpy(arrayFantasma[1].apellido,"CCC");
    arrayFantasma[1].isEmpty=0;
    arrayFantasma[1].idFantasma=3;
    strcpy(arrayFantasma[2].nombre,"CCC");
    strcpy(arrayFantasma[2].apellido,"BBB");
    arrayFantasma[2].isEmpty=0;
    arrayFantasma[2].idFantasma=5;
    strcpy(arrayFantasma[3].nombre,"CCC");
    strcpy(arrayFantasma[3].apellido,"AAA");
    arrayFantasma[3].isEmpty=0;
    arrayFantasma[3].idFantasma=2;
}
*/

#endif // FANTASMA_C_INCLUDED
