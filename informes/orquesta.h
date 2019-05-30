#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED

typedef struct
{
    int idOrquesta;
    char nombre[31];
    char lugar[31];
    int tipo;//tipo de orquesta
    int isEmpty;//estado habilitado 0 no habilitado 1
}Orquesta;


int orquesta_initStruct(Orquesta* arrayOrquesta, int limite);
int orquesta_findEmpty (Orquesta* arrayOrquesta,int limite, int* resultado);
int orquesta_alta(Orquesta* arrayOrquesta,int *id, int limite);
void orquesta_print(Orquesta* arrayOrquesta, int limite);
int orquesta_buscarID(Orquesta* arrayOrquesta, int limite, int valorBuscado, int* posicion);
void harcodearOrquestas(Orquesta* arrayOrquesta, int limite);

#endif // ORQUESTA_H_INCLUDED
