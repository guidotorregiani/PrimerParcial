#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"
#include "utn.h"
#include "informes.h"
//#include <stdio_ext.h>


int main()
{
    Orquesta arrayOrquesta[50];
    Musico arrayMusico[1000];
    Instrumento arrayInstrumento[20];

    int aux;
    int auxIdOrquesta;
    int opcion;
    int ready=0;
    int idMusicoAnterior=0;
    int idOrquestaAnterior=0;
    int idInstrumentoAnterior=0;

    orquesta_inicializar(arrayOrquesta,50);
    musico_inicializar(arrayMusico,1000);
    instrumento_inicializar(arrayInstrumento,20);

      //hardcoded down here
    arrayOrquesta[0].idOrquesta=1;
    arrayOrquesta[1].idOrquesta=2;
    arrayOrquesta[2].idOrquesta=3;
    arrayOrquesta[3].idOrquesta=4;
    strncpy(arrayOrquesta[0].nombre,"orquesta1",51);
    strncpy(arrayOrquesta[1].nombre,"orquesta2",51);
    strncpy(arrayOrquesta[2].nombre,"orquesta3",51);
    strncpy(arrayOrquesta[3].nombre,"orquesta4",51);
    strncpy(arrayOrquesta[0].lugar,"lugarA",51);
    strncpy(arrayOrquesta[1].lugar,"lugarA",51);
    strncpy(arrayOrquesta[2].lugar,"lugarB",51);
    strncpy(arrayOrquesta[3].lugar,"lugarC",51);
    arrayOrquesta[0].tipo=1;
    arrayOrquesta[1].tipo=2;
    arrayOrquesta[2].tipo=3;
    arrayOrquesta[3].tipo=3;

    //
    arrayMusico[0].idMusico=1;
    strncpy(arrayMusico[0].nombre,"mus1",51);
    strncpy(arrayMusico[0].apellido,"Amus1",51);
    arrayMusico[0].edad=30;
    arrayMusico[0].idOrquesta=1;
    arrayMusico[0].idInstrumento=2;
    //
    arrayMusico[1].idMusico=2;
    strncpy(arrayMusico[1].nombre,"mus2",51);
    strncpy(arrayMusico[1].apellido,"Amus2",51);
    arrayMusico[1].edad=20;

    arrayMusico[1].idOrquesta=2;
    arrayMusico[1].idInstrumento=5;
    //
    arrayMusico[2].idMusico=3;
    strncpy(arrayMusico[2].nombre,"mus3",51);
    strncpy(arrayMusico[2].apellido,"Amus3",51);
    arrayMusico[2].edad=25;
    arrayMusico[2].idOrquesta=4;
    arrayMusico[2].idInstrumento=2;
    //
    arrayMusico[3].idMusico=4;
    strncpy(arrayMusico[3].nombre,"mus4",51);
    strncpy(arrayMusico[3].apellido,"Amus4",51);
    arrayMusico[3].edad=27;
    arrayMusico[3].idOrquesta=4;
    arrayMusico[3].idInstrumento=1;
    //
    arrayMusico[4].idMusico=5;
    strncpy(arrayMusico[4].nombre,"mus5",51);
    strncpy(arrayMusico[4].apellido,"Amus5",51);
    arrayMusico[4].edad=22;
    arrayMusico[4].idOrquesta=1;
    arrayMusico[4].idInstrumento=3;
    //
    arrayMusico[5].idMusico=6;
    strncpy(arrayMusico[5].nombre,"mus6",51);
    strncpy(arrayMusico[5].apellido,"Amus6",51);
    arrayMusico[5].edad=35;
    arrayMusico[5].idOrquesta=3;
    arrayMusico[5].idInstrumento=4;
    //
    arrayInstrumento[0].idInstrumento=1;
    arrayInstrumento[1].idInstrumento=2;
    arrayInstrumento[2].idInstrumento=3;
    arrayInstrumento[3].idInstrumento=4;
    arrayInstrumento[4].idInstrumento=5;
    arrayInstrumento[0].tipo=1;
    arrayInstrumento[1].tipo=2;
    arrayInstrumento[2].tipo=2;
    arrayInstrumento[3].tipo=3;
    arrayInstrumento[4].tipo=4;
    strncpy(arrayInstrumento[0].nombre,"inst1",51);
    strncpy(arrayInstrumento[1].nombre,"inst2",51);
    strncpy(arrayInstrumento[2].nombre,"inst3",51);
    strncpy(arrayInstrumento[3].nombre,"inst4",51);
    strncpy(arrayInstrumento[4].nombre,"inst5",51);

    arrayOrquesta[0].isEmpty=0;
    arrayOrquesta[1].isEmpty=0;
    arrayOrquesta[2].isEmpty=0;
    arrayOrquesta[3].isEmpty=0;
    arrayInstrumento[0].isEmpty=0;
    arrayInstrumento[1].isEmpty=0;
    arrayInstrumento[2].isEmpty=0;
    arrayInstrumento[3].isEmpty=0;
    arrayInstrumento[4].isEmpty=0;
    arrayMusico[0].isEmpty=0;
    arrayMusico[1].isEmpty=0;
    arrayMusico[2].isEmpty=0;
    arrayMusico[3].isEmpty=0;
    arrayMusico[4].isEmpty=0;
    arrayMusico[5].isEmpty=0;


    while(ready!=1)
    {
        fflush(stdin);
        //__fpurge(stdin);
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
                informes_puntoD(arrayOrquesta,50,arrayInstrumento,20,arrayMusico,1000);
                break;
            case 13:
                fflush(stdin);
                //__fpurge(stdin);
                if(getValidInt(&auxIdOrquesta,"\nIngrese el id Orquesta\n","\nError\n",1,10000,2)==0)
                {
                    informes_puntoE(arrayMusico,1000,arrayInstrumento,20,auxIdOrquesta);
                }
                break;
            case 14:
                informes_contarCantidadMusicosPorOrquesta(arrayOrquesta,50,arrayMusico,1000);
                informes_puntoF(arrayOrquesta,50);
                break;
            case 15:
                informes_puntoG(arrayMusico,1000,arrayInstrumento,20,1);
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
