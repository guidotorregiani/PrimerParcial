#include <stdio.h>
#include <stdlib.h>
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"
#include "utn.h"
#include <stdio_ext.h>


int main()
{
    int opcion;
    int ready=0;
    int idMusicoAnterior=0;
    int idOrquestaAnterior=0;
    int idInstrumentoAnterior=0;

    Orquesta arrayOrquesta[50];
    Musico arrayMusico[1000];
    Instrumento arrayInstrumento[20];

    orquesta_inicializar(arrayOrquesta,50);
    musico_inicializar(arrayMusico,1000);
    instrumento_inicializar(arrayInstrumento,20);
    __fpurge(stdin);

    while(ready!=1)
    {
        __fpurge(stdin);
        getValidInt(&opcion,"1:AltaO\n2:BajaO\n3:ModificarO\n4:AltaM\n5:BajaM\n6:ModificarM\n7:altaI\n8:BajaI\n9ModificarI:\n10:salir\n","ERROR\n",1,10,3);

        switch(opcion)
        {
            case 1:
                orquesta_alta(arrayOrquesta,50,idOrquestaAnterior);
                idOrquestaAnterior++;
                break;
            case 2:
                orquesta_baja(arrayOrquesta,50);
                break;
            case 3:
                orquesta_listar(arrayOrquesta,50);
                orquesta_modificar(arrayOrquesta,50);
                break;
            case 4:
                musico_alta(arrayMusico,1000,idMusicoAnterior);
                idMusicoAnterior++;
                break;
            case 5:
                musico_baja(arrayMusico,1000);
                break;
            case 6:
                musico_listar(arrayMusico,1000);
                musico_modificar(arrayMusico,1000);
                break;
            case 7:
                instrumento_alta(arrayInstrumento,20,idInstrumentoAnterior);
                idInstrumentoAnterior++;
                break;
            case 8:
                instrumento_baja(arrayInstrumento,20);
                break;
            case 9:
                /*
                instrumento_listar(arayInstrumento,20);
                instrumento_modificar(arrayInstrumento,20);*/
                break;
            case 10:
                ready=1;
                break;
        }
    }
    return 0;
}
