#include <stdio.h>
#include <stdlib.h>
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"
#include "utn.h"
#include "informes.h"
#include <stdio_ext.h>


int main()
{
    int aux;
    int auxIdOrquesta;
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

    while(ready!=1)
    {
        //fflush(stdin);
        __fpurge(stdin);
        getValidInt(&opcion,"1:Alta Orquesta\n2:Baja Orquesta\n3:Modificar Orquesta\n4:Alta Musico\n5:Baja Musico\n6:Modificar Musico\n7:alta Instrumento\n8:Baja Instrumento\n9:A\n10:B\n11:C\n12:D\n13:E\n14:F\n15:G\n16:H\n17:salir\n","ERROR\n",1,17,3);

        switch(opcion)
        {
            case 1:
                orquesta_alta(arrayOrquesta,50,idOrquestaAnterior);
                idOrquestaAnterior++;
                printf("\nel id de esta orquesta es:%d\n",idOrquestaAnterior);
                break;
            case 2:
                if(orquesta_baja(arrayOrquesta,50,&aux)==0)
                {
                    orquesta_bajaMusicos(arrayMusico,1000,aux);
                }
                break;
            case 3:
                orquesta_listar(arrayOrquesta,50);
                orquesta_modificar(arrayOrquesta,50);
                break;
            case 4:
                musico_alta(arrayMusico,1000,idMusicoAnterior);
                idMusicoAnterior++;
                printf("\nel id de este musico es:%d\n",idMusicoAnterior);
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
                printf("\nel id de este instrumento es:%d\n",idInstrumentoAnterior);
                break;
            case 8:
                instrumento_baja(arrayInstrumento,20);
                break;
            case 9:
                informes_puntoA(arrayOrquesta,50,arrayMusico,1000);
                break;
            case 10:
                informes_puntoB(arrayMusico,1000,
                               arrayOrquesta,50,
                               arrayInstrumento,20);
                break;
            case 11:
                informes_puntoC(arrayOrquesta,50);
                break;
            case 12:
                break;
            case 13:
                __fpurge(stdin);
                if(getValidInt(&auxIdOrquesta,"\nIngrese el id Orquesta","\nError\n",1,10000,2)==0)
                {
                    informes_puntoE(arrayMusico,1000,arrayInstrumento,20,auxIdOrquesta);
                }
                break;
            case 14:
                //informes_puntoF();
                break;
            case 15:
                //informe_puntoG(Musico *arrayMusico,int lenMusico,Instrumento *arrayInstrumento,int lenInstrumento,int order);
                break;
            case 16:
                informes_contarCantidadMusicosPorOrquesta(arrayOrquesta,50,arrayMusico,1000);
                informes_puntoH(arrayOrquesta,50);
                break;
            case 17:
                ready=1;
                break;
        }
    }
    return 0;
}
