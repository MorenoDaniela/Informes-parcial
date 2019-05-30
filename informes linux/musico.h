#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED

//#include "musico.h"
#include "instrumento.h"
#include "orquesta.h"

typedef struct
{
    int idMusico;
    int idOrquesta;
    int idInstrumento;
    char nombre[31];
    char apellido[31];
    int edad;
    int isEmpty;//estado habilitado 0 no habilitado 1
}Musico;

int musicos_initStruct(Musico* arrayMusico, int limite);
int musicos_findEmpty (Musico* arrayMusico,int limite, int* resultado);
int musicos_alta(Musico* arrayMusico, Orquesta* arrayOrquesta,Instrumento* arrayInstrumento,int *id,int limiteMusico,int limiteOrquesta, int limiteInstrumento);
int musicos_baja(Musico* arrayMusico,int limiteMusico);
void musicos_print(Musico* arrayMusico, int limite);
int musico_print(Musico* arrayMusico, int limiteMusico, Instrumento* arrayInstrumento, int limiteInstrumento);
void harcodearMusicos(Musico* arrayA, int limite);
int musicos_modificar(Musico* arrayMusico,Orquesta* arrayOrquesta,int limiteOrquesta, int limiteMusico);
int musico_buscarID(Musico* arrayMusico, int limite, int valorBuscado, int* posicion) ;
void harcodearTODO(Musico* arrayMusico,int limiteMusico, Instrumento* arrayInstrumento, int limiteInstrumento, Orquesta* arrayOrquesta, int limiteOrquesta);
int orquesta_baja(Orquesta* arrayOrquesta, Musico* arrayMusico, int limiteOrquesta, int limiteMusico);

#endif // MUSICO_H_INCLUDED
