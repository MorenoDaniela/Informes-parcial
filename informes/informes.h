#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "orquesta.h"
#include "instrumento.h"
#include "musico.h"

int inf_A_orquestasSegunLugar (Orquesta* arrayOrquesta, int limiteOrquesta);
int inf_B_musicosQueNoSuperan25(Musico* arrayMusicos,int limiteMusicos,Instrumento* arrayInstrumento, int limiteInstrumento, Orquesta* arrayOrquesta, int limiteOrquesta);
int inf_C_orquestasMenosDeSeisMusicos(Musico* arrayMusico,int limiteMusico, Orquesta* arrayOrquesta, int limiteOrquesta);
int inf_D_instrumentosSolicitadosPorOrquesta(Musico* arrayMusicos, Orquesta* arrayOrquesta,Instrumento* arrayInstrumento, int limiteMusico, int limiteOrquesta, int limiteInstrumento);
int inf_E_orquestaCompleta(Musico* arrayMusico,Orquesta* arrayOrquesta, Instrumento* arrayInstrumento, int limiteMusico,int limiteOrquesta, int limiteInstrumento);
int inf_F_orquestaConMenosMusicos(Orquesta* arrayOrquesta, int limiteOrquesta, Musico* arrayMusico, int limiteMusico);
int inf_G_instrumentoPorOrquesta(Musico* arrayMusico, Orquesta* arrayOrquesta, int limiteMusico, int limiteOrquesta);
int inf_H_musicosNoViento(Musico* arrayMusico,Instrumento* arrayInstrumento, int limiteMusico, int limiteInstrumento);
int inf_H_musicosPorApellido(Musico* arrayMusico, int limiteMusico, int orderFirst, int orderSecond);

#endif // INFORMES_H_INCLUDED
