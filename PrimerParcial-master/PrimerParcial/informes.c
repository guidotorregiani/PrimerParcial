#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "musico.h"
#include "orquesta.h"
#include "instrumento.h"
#include "utn.h"
#include "informes.h"
#define Nombre_LEN 51


int informes_contarCantidadMusicosPorOrquesta(Orquesta *arrayOrquesta,int lenOrquesta,Musico *arrayMusico,int lenMusico)
{
    int aux;
    int i;
    int j;
    for(j=0;j<lenOrquesta;j++)
    {
        if(arrayMusico!=NULL && lenMusico>0)
        {
            aux=0;
            for(i=0;i<lenMusico;i++)
            {
                if(arrayMusico[i].idOrquesta==arrayOrquesta[j].idOrquesta)
                {
                    aux++;
                }
            }
            arrayOrquesta[j].cantMusicos=aux;
        }
    }
    return 0;
}

/*int informes_ordenarPorCantidadMusicos(Orquesta *arrayOrquesta,int lenOrquesta,Musico *arrayMusico,int lenMusico,int lenContador,int orden)
{
    informes_contarCantidadMusicosPorOrquesta(arrayOrquesta,lenOrquesta,arrayMusico,lenMusico,lenContador);
    int ret=-1;
    int i;
    int j;
    Orquesta buffer;

    if(arrayOrquesta!= NULL && lenOrquesta>0)
    {
        for(i=0;i<lenOrquesta-1;i++)
        {
            for(j=i+1;j<lenOrquesta;j++)
            {
                if(orden==1 && contador[j]<contador[i])
                {
                    buffer = arrayOrquesta[i];
                    arrayOrquesta[i] = arrayOrquesta[j];
                    arrayOrquesta[j] = buffer;
                    ret=0;
                }
                else if(orden==1 && contador[j]>contador[i])
                {
                    buffer = arrayOrquesta[i];
                    arrayOrquesta[i] = arrayOrquesta[j];
                    arrayOrquesta[j] = buffer;
                    ret=0;
                }
            }
        }
    }
    return ret;
}*/

/*int orquesta_sortOrquestaNameType(Orquesta* pOrquestas,int len,int order)
{
    int i;
    int j;
    Orquesta buffer;
    int ret = -1;

    if(pOrquestas != NULL && len > 0)
    {
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if(order == 1 && (strcmp(pOrquestas[j].name,pOrquestas[i].name) < 0))
                {
                    buffer = pOrquestas[i];
                    pOrquestas[i] = pOrquestas[j];
                    pOrquestas[j] = buffer;
                    ret = 0;
                }
                else if(order == 0 && (strcmp(pOrquestas[j].name,pOrquestas[i].name) > 0))
                {
                    buffer = pOrquestas[i];
                    pOrquestas[i] = pOrquestas[j];
                    pOrquestas[j] = buffer;
                    ret = 0;
                }
                else if(strcmp(pOrquestas[j].name,pOrquestas[i].name) == 0)
                {
                    if(pOrquestas[i].type > pOrquestas[j].type)
                    {
                        buffer = pOrquestas[i];
                        pOrquestas[i] = pOrquestas[j];
                        pOrquestas[j] = buffer;
                        ret = 0;
                    }
                }
            }
        }
    }
    return ret;
}
*/

int informes_cantidadTotalPromedioEdadesDeMusico(Musico *arrayMusico,int lenMusico)
{
    int i;
    int acumulador = 0;
    int contador = 0;
    float promedio;

    if(arrayMusico != NULL && lenMusico > 0)
    {
        for(i=0;i<lenMusico;i++)
        {
            if(arrayMusico[i].isEmpty == 0)
            {
                acumulador=acumulador+arrayMusico[i].edad;
                contador++;
            }
        }

    promedio = acumulador / contador;

    printf("\nEl total de musicos es: %d\n",contador);
    printf("La suma de las edades es: %d",acumulador);
    printf("El promedio entre las edades de musicos es: %.2f",promedio);
    }
    return 0;
}

int informes_puntoA(Orquesta *arrayOrquesta,int lenOrquesta,Musico *arrayMusico,int lenMusico)
{
    int i;

    informes_contarCantidadMusicosPorOrquesta(arrayOrquesta,lenOrquesta,arrayMusico,lenMusico);

    for(i=0;i<lenOrquesta;i++)
    {
        if(arrayOrquesta[i].cantMusicos>5)
        {
            printf("%d\n %s\n %s\n",arrayOrquesta[i].idOrquesta,arrayOrquesta[i].nombre,arrayOrquesta[i].lugar);
            switch(arrayOrquesta[i].tipo)
            {
                case 1:
                    printf("\nSinfonica\n");
                    break;
                case 2:
                    printf("\nFilarmonica\n");
                    break;
                case 3:
                    printf("\nCaja\n");
                    break;
            }
        }
    }
    return 0;
}

int informes_puntoB(Musico *arrayMusico,int lenMusico,Orquesta *arrayOrquesta,int lenOrquesta,Instrumento *arrayInstrumento,int lenInstrumento)
{
    int i;
    int posIdInstrumento;
    int posIdOrquesta;
    for(i=0;i<lenMusico;i++)
    {
        if(arrayMusico[i].edad>=30)
        {
            printf("%d\n %s\n %s\n %d\n",arrayMusico[i].idMusico
                                        ,arrayMusico[i].nombre
                                        ,arrayMusico[i].apellido
                                        ,arrayMusico[i].edad);
            if(instrumento_buscarID(arrayInstrumento,lenInstrumento,arrayMusico[i].idInstrumento,&posIdInstrumento)!=0)
            {
                printf("%s",arrayInstrumento[posIdInstrumento].nombre);
            }
            if(orquesta_buscarID(arrayOrquesta,lenOrquesta,arrayOrquesta[i].idOrquesta,&posIdOrquesta)!=0)
            {
                printf("%s",arrayOrquesta[posIdOrquesta].nombre);
            }
        }
    }
    return 0;
}

int informes_puntoC(Orquesta *arrayOrquesta,int lenOrquesta)
{
    int i;
    char aux[51];
    if(getString(aux,"\nIngrese el nombre de la orquesta a buscar\n","\nError\n",1,51,2)!=0)
    {
        for(i=0;i<lenOrquesta;i++)
        {
            if(strcmp(arrayOrquesta[i].nombre,aux)==0)
            {
                printf("%d\n %s\n %s\n",arrayOrquesta[i].idOrquesta
                                        ,arrayOrquesta[i].nombre
                                        ,arrayOrquesta[i].lugar);
                switch(arrayOrquesta[i].tipo)
                {
                    case 1:
                        printf("\nSinfonica\n");
                        break;
                    case 2:
                        printf("\nFilarmonica\n");
                        break;
                    case 3:
                        printf("\nCamara\n");
                        break;
                }
            }
        }
    }
    return 0;
}

/*int informes_puntoD(Orquesta *arrayOrquesta,int lenOrquesta)
{
    int i;
    for(i=0;i<lenOrquesta;i++)
    {

    }
    return 0;
}*/

int informes_puntoE(Musico *arrayMusico,int lenMusico,Instrumento *arrayInstrumento, int lenInstrumento,int valorBuscado)
{
    int retorno=-1;
    int i;
    int auxPosIdInstrumento;

    if(arrayMusico!=NULL && lenMusico>0)
    {
        for(i=0;i<lenMusico;i++)
        {
            if(arrayMusico[i].idOrquesta==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                printf("%s\n %s\n %d\n",arrayMusico[i].nombre
                                       ,arrayMusico[i].apellido
                                       ,arrayMusico[i].edad);
                if(instrumento_buscarID(arrayInstrumento,lenInstrumento,arrayMusico[i].idInstrumento,&auxPosIdInstrumento)!=0)
                {
                    printf("%s\n %d\n",arrayInstrumento[auxPosIdInstrumento].nombre
                                      ,arrayInstrumento[auxPosIdInstrumento].tipo);
                }
            }
        }
        retorno=0;
    }
    return retorno;
}

/*int informes_puntoG(Musico *arrayMusico,int lenMusico,Instrumento *arrayInstrumento,int lenInstrumento,int order)
{
    int i;
    int auxPosIdInstrumento;
    musico_sortMusicoApellido(arrayMusico,lenMusico,order);

    for(i=0;i<lenMusico;i++)
    {
        if(arrayMusico[i].tipo==1)
        {
            printf("%s\n %s\n %d\n",arrayMusico[i].nombre
                                   ,arrayMusico[i].apellido
                                   ,arrayMusico[i].edad);
           if(instrumento_buscarID(arrayInstrumento,lenInstrumento,arrayMusico[i].idInstrumento,&auxPosIdInstrumento)!=0)
                {
                    printf("%s\n %d\n",arrayInstrumento[auxPosIdInstrumento].nombre
                                      ,arrayInstrumento[auxPosIdInstrumento].tipo);
                }
        }
    }

    return 0;
}*/

int informes_puntoH(Orquesta *arrayOrquesta,int lenOrquesta)
{
    // ES NECESARIO CORRER LA FUNCION CONTAR MUSICOS ANTES QUE ESTA
    int i;
    float promedio;
    int acumuladorMusicos=0;
    int contadorOrquestas=0;
    if(arrayOrquesta!=NULL && lenOrquesta>0)
    {
        for(i=0;i<lenOrquesta;i++)
        {
            if(arrayOrquesta[i].isEmpty==0)
            {
                acumuladorMusicos=acumuladorMusicos+arrayOrquesta[i].cantMusicos;
                contadorOrquestas++;
            }
        }
    }
    promedio=acumuladorMusicos/(float)contadorOrquestas;
    printf("\nEl promedio de musicos por orquesta es :%.2f\n",promedio);
    return 0;
}
