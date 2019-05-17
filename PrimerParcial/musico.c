#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "musico.h"
#include "utn.h"
#define Nombre_LEN 51

/*void musico_menu(Musico *arrayMusico,int len,char* opcionesMenu, char* msgErr)
{
    int opcion;
    int ready=0;
    int id=0;

    musico_inicializar(arrayMusico,1000);

    while(ready!=1)
    {
        getValidInt(&opcion,opcionesMenu,msgErr,1,5,3);

        switch(opcion)
        {
            case 1:
                musico_alta(arrayMusico,1000,id);
                id++;
                break;
            case 2:
                musico_baja(arrayMusico,1000);
                break;
            case 3:
                musico_modificar(arrayMusico,1000);
                break;
            case 4:
                musico_promedioEdads(arrayMusico,1000);
                musico_ordenarPorApellido(arrayMusico,1000,1);
                musico_listar(arrayMusico,1000);
                break;
            case 5:
                ready=1;
                break;
        }
    }
}*/

int musico_inicializar(Musico *arrayMusico,int len)
{
    int i;
    int ret=-1;
    if(arrayMusico != NULL && len >= 0)
    {
        for(i=0;i<len;i++)
        {
            arrayMusico[i].isEmpty=1;
            ret=0;
        }
    }
    return ret;
}
int musico_lugarLibre(Musico *arrayMusico,int len,int *lugarLibre)
{
    int i;
    int ret=-1;
    if(arrayMusico != NULL && len >= 0)
    {
        for(i=0; i<len ; i++)
        {
            if(arrayMusico[i].isEmpty==1)
            {
                *lugarLibre = i;
                ret=0;
                break;
            }
        }
    }
    return ret;
}

int musico_alta(Musico *arrayMusico,int len,int idMusicoAnterior)
{
    int ret=-1;
    int flag=1; // 0 falso(dio mal) 1 verdadero(dio bien)
    int lugarLibre;
    int auxIdInstrumento;
    int auxIdOrquesta;
    int auxEdad;
    char auxNombre[Nombre_LEN];
    char auxApellido[Nombre_LEN];


    if(arrayMusico != NULL && len >= 0)
    {
        if(musico_lugarLibre(arrayMusico,1000,&lugarLibre)==0)
        {
            if(getString(auxNombre,"Ingrese un nombre: \n", "ERROR!\n", 1, Nombre_LEN, 2)!=0)
            {
                flag=0;
            }
            if(getString(auxApellido,"Ingrese apellido: \n", "ERROR!\n", 1, Nombre_LEN, 2)!=0)
            {
                flag=0;
            }
            if(getValidInt(&auxIdInstrumento,"Ingrese id del instrumento que toca\n","ERROR!\n",1,1000,2)!=0)
            {
                flag=0;
                __fpurge(stdin);
            }
            if(getValidInt(&auxIdOrquesta,"Ingrese id de la orquesta en la que toca\n","ERROR!\n",1,10000,2)!=0)
            {
                flag=0;
                __fpurge(stdin);
            }
            if(getValidInt(&auxEdad,"Ingrese la edad\n","ERROR!\n",1,100,2)!=0)
            {
                flag=0;
                __fpurge(stdin);
            }

            if(flag==1)
            {
                strncpy(arrayMusico[lugarLibre].nombre,auxNombre,Nombre_LEN);
                strncpy(arrayMusico[lugarLibre].apellido,auxApellido,Nombre_LEN);
                arrayMusico[lugarLibre].idOrquesta=auxIdOrquesta;
                arrayMusico[lugarLibre].idInstrumento=auxIdInstrumento;
                arrayMusico[lugarLibre].edad=auxEdad;
                arrayMusico[lugarLibre].isEmpty=0;
                arrayMusico[lugarLibre].idMusico=idMusicoAnterior+1;
                ret=0;
            }
            else
            {
                printf("error, campo mal ingresado, el musico no se guardara");
                arrayMusico[lugarLibre].isEmpty=1;
            }

            /*Debuggers
            printf(" %s\n %s\n %d\n %d\n",arrayMusico[lugarLibre].apellido
                                         ,arrayMusico[lugarLibre].nombre
                                         ,arrayMusico[lugarLibre].sector
                                         ,arrayMusico[lugarLibre].edad);
            printf(" %d\n",lugarLibre);
            printf("%d\n",arrayMusico[lugarLibre].isEmpty);
            printf("%d\n",arrayMusico[lugarLibre].idMusico);*/
        }

    }
    return ret;
}

int musico_buscarID(Musico *arrayMusico, int size, int id, int* posicion)
{
    int ret=-1;
    int i;
    if(arrayMusico!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(arrayMusico[i].isEmpty==1)
            {
                continue;
            }
            else if(arrayMusico[i].idMusico==id)
            {
                ret=0;
                *posicion=i;
                break;
            }
        }
    }
    return ret;
}


int musico_modificar(Musico *arrayMusico,int len)
{
    int ret=-1;
    int idMusico;
    int posicionDeLaCoincidencia=0;
    int ready=0;
    int opcion;

    if(arrayMusico != NULL && len >= 0)
    {
        getValidInt(&idMusico,"Ingrese el id del musico a modificar\n","error\n",1,9999,3);
        if(musico_buscarID(arrayMusico,1000,idMusico,&posicionDeLaCoincidencia)!=0)
        {
            printf("Error, el id no existe o el array es nulo\n");
        }
        else
        {
            while(ready!=1)
            {
                getValidInt(&opcion,"Ingrese valor a modificar:\n 1 para edad\n2 para orquesta donde toca\n3 para salir","Error",1,3,3);

                switch(opcion)
                {
                    case 1:
                        getValidInt(&arrayMusico[posicionDeLaCoincidencia].edad,"\nIngrese el nuevo valor para edad\n","\nError\n",1,100,2);
                        break;
                    case 2:
                        getValidInt(&arrayMusico[posicionDeLaCoincidencia].idOrquesta,"\nIngrese el nuevo valor para ID de orquesta\n","\nError\n",1,10000,2);
                        break;
                    case 3:
                        ready=1;
                        break;
                }
            }
        }
    }return ret;
}

int musico_baja(Musico *arrayMusico,int len)
{
    int ret=-1;
    int idMusico;
    int posicionDeLaCoincidencia=0;

    if(arrayMusico != NULL && len >= 0)
    {
        getValidInt(&idMusico,"\nIngrese el id del musico a dar de baja\n","\nerror\n",1,9999,3);
        if(musico_buscarID(arrayMusico,30,idMusico,&posicionDeLaCoincidencia)==0)
        {
            arrayMusico[posicionDeLaCoincidencia].isEmpty=1;
            printf("se ha dado de baja el musico en la posicion %d\n",posicionDeLaCoincidencia);
        }
        else
        {
            printf("Error, el id no existe o el array es nulo");
        }
    }
    return ret;
}

int musico_listar(Musico *arrayMusico,int len)
{
    int i;
    int ret=-1;
    if(arrayMusico!=NULL && len>=0)
    {
        for(i=0;i<len;i++)
        {
            if(arrayMusico[i].isEmpty==0)
            {
                    printf(" %s\n %s\n %d\n %d\n %d\n",arrayMusico[i].apellido
                                                      ,arrayMusico[i].nombre
                                                      ,arrayMusico[i].idOrquesta
                                                      ,arrayMusico[i].idInstrumento
                                                      ,arrayMusico[i].edad);
            }
        }
        ret=0;
    }
    return ret;
}
