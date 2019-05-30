#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>
#include "orquesta.h"
#include "musico.h"
#include "utn.h"
#define Nombre_LEN 51

/*void orquesta_menu(Orquesta *arrayOrquesta,int len,char* opcionesMenu, char* msgErr)
{
    int opcion;
    int ready=0;
    int id=0;

    orquesta_inicializar(arrayOrquesta,1000);

    while(ready!=1)
    {
        getValidInt(&opcion,opcionesMenu,msgErr,1,5,3);

        switch(opcion)
        {
            case 1:
                orquesta_alta(arrayOrquesta,1000,id);
                id++;
                break;
            case 2:
                orquesta_baja(arrayOrquesta,1000);
                break;
            case 3:
                orquesta_modificar(arrayOrquesta,1000);
                break;
            case 4:
                orquesta_promedioTipos(arrayOrquesta,1000);
                orquesta_ordenarPorLugar(arrayOrquesta,1000,1);
                orquesta_listar(arrayOrquesta,1000);
                break;
            case 5:
                ready=1;
                break;
        }
    }
}*/

int orquesta_inicializar(Orquesta *arrayOrquesta,int len)
{
    int i;
    int ret=-1;
    if(arrayOrquesta != NULL && len >= 0)
    {
        for(i=0;i<len;i++)
        {
            arrayOrquesta[i].isEmpty=1;
            arrayOrquesta[i].cantMusicos=0;
            ret=0;
        }
    }
    return ret;
}
int orquesta_lugarLibre(Orquesta *arrayOrquesta,int len,int *lugarLibre)
{
    int i;
    int ret=-1;
    if(arrayOrquesta != NULL && len >= 0)
    {
        for(i=0; i<len ; i++)
        {
            if(arrayOrquesta[i].isEmpty==1)
            {
                *lugarLibre = i;
                ret=0;
                break;
            }
        }
    }
    return ret;
}

int orquesta_alta(Orquesta *arrayOrquesta,int len,int idOrquestaAnterior)
{
    int ret=-1;
    int flag=1; // 0 falso(dio mal) 1 verdadero(dio bien)
    int lugarLibre;
    int auxTipo;
    char auxNombre[Nombre_LEN];
    char auxLugar[Nombre_LEN];


    if(arrayOrquesta != NULL && len >= 0)
    {
        if(orquesta_lugarLibre(arrayOrquesta,50,&lugarLibre)==0)
        {
            if(getString(auxNombre,"Ingrese un nombre: \n", "ERROR!\n", 1, Nombre_LEN, 2)!=0)
            {
                flag=0;
            }
            if(getString(auxLugar,"Ingrese lugar: \n", "ERROR!\n", 1, Nombre_LEN, 2)!=0)
            {
                flag=0;
            }
            if(getValidInt(&auxTipo,"Ingrese el tipo\n","ERROR!\n",1,3,2)!=0)
            {
                flag=0;
            }

            if(flag==1)
            {
                strncpy(arrayOrquesta[lugarLibre].nombre,auxNombre,Nombre_LEN);
                strncpy(arrayOrquesta[lugarLibre].lugar,auxLugar,Nombre_LEN);
                arrayOrquesta[lugarLibre].tipo=auxTipo;
                arrayOrquesta[lugarLibre].isEmpty=0;
                arrayOrquesta[lugarLibre].idOrquesta=idOrquestaAnterior+1;
                ret=0;
            }
            else
            {
                printf("error, campo mal ingresado, el orquesta no se guardara");
                arrayOrquesta[lugarLibre].isEmpty=1;
            }

            /*Debuggers
            printf(" %s\n %s\n %d\n %d\n",arrayOrquesta[lugarLibre].lugar
                                         ,arrayOrquesta[lugarLibre].nombre
                                         ,arrayOrquesta[lugarLibre].sector
                                         ,arrayOrquesta[lugarLibre].tipo);
            printf(" %d\n",lugarLibre);
            printf("%d\n",arrayOrquesta[lugarLibre].isEmpty);
            printf("%d\n",arrayOrquesta[lugarLibre].idOrquesta);*/
        }

    }
    return ret;
}

int orquesta_buscarID(Orquesta *arrayOrquesta, int size, int id, int* posicion)
{
    int ret=-1;
    int i;
    if(arrayOrquesta!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(arrayOrquesta[i].isEmpty==1)
            {
                continue;
            }
            else if(arrayOrquesta[i].idOrquesta==id)
            {
                ret=0;
                *posicion=i;
                break;
            }
        }
    }
    return ret;
}


int orquesta_modificar(Orquesta *arrayOrquesta,int len)
{
    int ret=-1;
    int idOrquesta;
    int posicionDeLaCoincidencia=0;
    int ready=0;
    int opcion;

    if(arrayOrquesta != NULL && len >= 0)
    {
        getValidInt(&idOrquesta,"Ingrese el id del orquesta a modificar\n","error\n",1,50,3);
        if(orquesta_buscarID(arrayOrquesta,1000,idOrquesta,&posicionDeLaCoincidencia)!=0)
        {
            printf("Error, el id no existe o el array es nulo\n");
        }
        else
        {
            while(ready!=1)
            {
                __fpurge(stdin);
                //__fpurge(stdin);
                getValidInt(&opcion,"Ingrese valor a modificar:\n 1 para nombre\n2 para lugar\n3para tipo\4 para salir","Error",1,4,3);

                switch(opcion)
                {
                    case 1:
                        getString(arrayOrquesta[posicionDeLaCoincidencia].nombre,"\nNuevo valor para nombre:\n","\nError\n",1,Nombre_LEN,2);
                        break;
                    case 2:
                        getString(arrayOrquesta[posicionDeLaCoincidencia].lugar,"\nNuevo valor para lugar:\n","\nError\n",1,Nombre_LEN,2);
                        break;
                    case 3:
                        getValidInt(&arrayOrquesta[posicionDeLaCoincidencia].tipo,"\nIngrese el nuevo valor para tipo\n","\nError\n",1,3,2);
                        break;
                    case 4:
                        ready=1;
                        break;
                }
            }
        }
    }return ret;
}

int orquesta_baja(Orquesta *arrayOrquesta,int len,int* auxId)
{

    int ret=-1;
    int idOrquesta;
    int posicionDeLaCoincidencia=0;

    if(arrayOrquesta != NULL && len >= 0)
    {
        getValidInt(&idOrquesta,"\nIngrese el id del orquesta a dar de baja\n","\nerror\n",1,9999,3);
        if(orquesta_buscarID(arrayOrquesta,30,idOrquesta,&posicionDeLaCoincidencia)==0)
        {
            arrayOrquesta[posicionDeLaCoincidencia].isEmpty=1;
            printf("se ha dado de baja el orquesta en la posicion %d\n",posicionDeLaCoincidencia);
            *auxId=idOrquesta;
            ret=0;
        }
        else
        {
            printf("Error, el id no existe o el array es nulo");
        }
    }
    return ret;
}
int orquesta_bajaMusicos(Musico *arrayMusico, int len, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(arrayMusico!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            if(arrayMusico[i].idOrquesta==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                arrayMusico[i].isEmpty=1;
            }
        }
        retorno=0;
    }
    return retorno;
}


int orquesta_listar(Orquesta *arrayOrquesta,int len)
{
    int i;
    int ret=-1;
    if(arrayOrquesta!=NULL && len>=0)
    {
        printf("\nOrquestas");
        for(i=0;i<len;i++)
        {
            if(arrayOrquesta[i].isEmpty==0)
            {
                    printf(" %s\n %s\n %d\n %d\n",arrayOrquesta[i].lugar
                                                 ,arrayOrquesta[i].nombre
                                                 ,arrayOrquesta[i].tipo
                                                 ,arrayOrquesta[i].idOrquesta);
            }
        }
    }
    return ret;
}

/*int orquesta_sortOrquestaCantMusicos(Orquesta *arrayOrquesta,int lenOrquesta)
{
    int i;
    int j;
    Orquesta buffer;
    int ret = -1;

    if(arrayOrquesta != NULL && len > 0)
    {
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if((strcmp(arrayOrquesta[j].name,arrayOrquesta[i].name) < 0))
                {
                    buffer = arrayOrquesta[i];
                    arrayOrquesta[i] = arrayOrquesta[j];
                    arrayOrquesta[j] = buffer;
                    ret = 0;
                }
                else if((strcmp(arrayOrquesta[j].name,arrayOrquesta[i].name) > 0))
                {
                    buffer = arrayOrquesta[i];
                    arrayOrquesta[i] = arrayOrquesta[j];
                    arrayOrquesta[j] = buffer;
                    ret = 0;
                }
            }
        }
    }
    return ret;
}*/
