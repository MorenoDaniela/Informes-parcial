#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED

typedef struct
{
    int idInstrumento;
    char nombre[31];
    int tipo;//tipo de insturmento
    int isEmpty;//estado habilitado 0 no habilitado 1
}Instrumento;

int instrumento_initStruct(Instrumento* arrayInstrumento, int limite);
int instrumento_findEmpty (Instrumento* arrayInstrumento,int limite, int* resultado);
int instrumento_alta(Instrumento* arrayInstrumento,int* id, int limite);
void instrumento_print(Instrumento* arrayInstrumento, int limite);
int instrumento_baja(Instrumento* arrayInstrumento,int limite);
void harcodearInstrumento(Instrumento* arrayInstrumento, int limite);
int instrumento_buscarID(Instrumento* arrayInstrumento, int limite, int valorBuscado, int* posicion);

#endif // INSTRUMENTO_H_INCLUDED
