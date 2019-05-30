#include "musico.h"
#include "instrumento.h"
#include "orquesta.h"
#include "utn.h"
#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int informes_contarCantidadMusicosPorOrquesta(Orquesta *arrayOrquesta,int lenOrquesta,Musico *arrayMusico,int lenMusico);
int informes_ordenarPorCantidadMusicos(Orquesta *arrayOrquesta,int lenOrquesta,Musico *arrayMusico,int lenMusico,int orden);
int informes_cantidadTotalPromedioEdadesDeMusico(Musico *arrayMusico,int lenMusico);
int informes_puntoA(Orquesta *arrayOrquesta,int lenOrquesta,Musico *arrayMusico,int lenMusico);
int informes_puntoB(Musico *arrayMusico,int lenMusico,
                    Orquesta *arrayOrquesta,int lenOrquesta,
                    Instrumento *arrayInstrumento,int lenInstrumento);
int informes_puntoC(Orquesta *arrayOrquesta,int lenOrquesta);
int informes_puntoD(Orquesta *arrayOrquesta,int lenOrquesta,Instrumento *arrayInstrumento, int lenInstrumento,Musico *arrayMusico,int lenMusico);
int informes_puntoE(Musico *arrayMusico,int lenMusico,Instrumento *arrayInstrumento, int lenInstrumento,int valorBuscado);
int informes_puntoF(Orquesta *arrayOrquesta,int lenOrquesta);
int informes_puntoG(Musico *arrayMusico,int lenMusico,Instrumento *arrayInstrumento,int lenInstrumento,int order);
int informes_puntoH(Orquesta *arrayOrquesta,int lenOrquesta);
#endif // INFORMES_H_INCLUDED
