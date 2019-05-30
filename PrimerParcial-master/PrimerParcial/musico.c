#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "musico.h"
#include "orquesta.h"
#include "instrumento.h"
#include "utn.h"
#define Nombre_LEN 51

/*void musico_menu(Musico *arrayInstrumentoMusico,int len,char* opcionesMenu, char* msgErr)
{
    int opcion;
    int ready=0;
    int id=0;

    musico_inicializar(arrayInstrumentoMusico,1000);

    while(ready!=1)
    {
        getValidInt(&opcion,opcionesMenu,msgErr,1,5,3);

        switch(opcion)
        {
            case 1:
                musico_alta(arrayInstrumentoMusico,1000,id);
                id++;
                break;
            case 2:
                musico_baja(arrayInstrumentoMusico,1000);
                break;
            case 3:
                musico_modificar(arrayInstrumentoMusico,1000);
                break;
            case 4:
                musico_promedioEdads(arrayInstrumentoMusico,1000);
                musico_ordenarPorApellido(arrayInstrumentoMusico,1000,1);
                musico_listar(arrayInstrumentoMusico,1000);
                break;
            case 5:
                ready=1;
                break;
        }
    }
}*/

int musico_inicializar(Musico *arrayInstrumentoMusico,int len)
{
    int i;
    int ret=-1;
    if(arrayInstrumentoMusico != NULL && len >= 0)
    {
        for(i=0;i<len;i++)
        {
            arrayInstrumentoMusico[i].isEmpty=1;
            ret=0;
        }
    }
    return ret;
}
int musico_lugarLibre(Musico *arrayInstrumentoMusico,int len,int *lugarLibre)
{
    int i;
    int ret=-1;
    if(arrayInstrumentoMusico != NULL && len >= 0)
    {
        for(i=0; i<len ; i++)
        {
            if(arrayInstrumentoMusico[i].isEmpty==1)
            {
                *lugarLibre = i;
                ret=0;
                break;
            }
        }
    }
    return ret;
}

int musico_alta(Musico *arrayInstrumentoMusico,int len,int idMusicoAnterior)
{
    int ret=-1;
    int flag=1; // 0 falso(dio mal) 1 verdadero(dio bien)
    int lugarLibre;
    int auxIdInstrumento;
    int auxIdOrquesta;
    int auxEdad;
    char auxNombre[Nombre_LEN];
    char auxApellido[Nombre_LEN];


    if(arrayInstrumentoMusico != NULL && len >= 0)
    {
        if(musico_lugarLibre(arrayInstrumentoMusico,1000,&lugarLibre)==0)
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
                //fflush(stdin);
                __fpurge(stdin);
            }
            if(getValidInt(&auxIdOrquesta,"Ingrese id de la orquesta en la que toca\n","ERROR!\n",1,10000,2)!=0)
            {
                flag=0;
                //fflush(stdin);
                __fpurge(stdin);
            }
            if(getValidInt(&auxEdad,"Ingrese la edad\n","ERROR!\n",1,100,2)!=0)
            {
                flag=0;
                //fflush(stdin);
                __fpurge(stdin);
            }

            if(flag==1)
            {
                strncpy(arrayInstrumentoMusico[lugarLibre].nombre,auxNombre,Nombre_LEN);
                strncpy(arrayInstrumentoMusico[lugarLibre].apellido,auxApellido,Nombre_LEN);
                arrayInstrumentoMusico[lugarLibre].idOrquesta=auxIdOrquesta;
                arrayInstrumentoMusico[lugarLibre].idInstrumento=auxIdInstrumento;
                arrayInstrumentoMusico[lugarLibre].edad=auxEdad;
                arrayInstrumentoMusico[lugarLibre].isEmpty=0;
                arrayInstrumentoMusico[lugarLibre].idMusico=idMusicoAnterior+1;
                ret=0;
            }
            else
            {
                printf("error, campo mal ingresado, el musico no se guardara");
                arrayInstrumentoMusico[lugarLibre].isEmpty=1;
            }

            /*Debuggers
            printf(" %s\n %s\n %d\n %d\n",arrayInstrumentoMusico[lugarLibre].apellido
                                         ,arrayInstrumentoMusico[lugarLibre].nombre
                                         ,arrayInstrumentoMusico[lugarLibre].sector
                                         ,arrayInstrumentoMusico[lugarLibre].edad);
            printf(" %d\n",lugarLibre);
            printf("%d\n",arrayInstrumentoMusico[lugarLibre].isEmpty);
            printf("%d\n",arrayInstrumentoMusico[lugarLibre].idMusico);*/
        }

    }
    return ret;
}

int musico_buscarID(Musico *arrayInstrumentoMusico, int size, int id, int* posicion)
{
    int ret=-1;
    int i;
    if(arrayInstrumentoMusico!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(arrayInstrumentoMusico[i].isEmpty==1)
            {
                continue;
            }
            else if(arrayInstrumentoMusico[i].idMusico==id)
            {
                ret=0;
                *posicion=i;
                break;
            }
        }
    }
    return ret;
}


int musico_modificar(Musico *arrayInstrumentoMusico,int len)
{
    int ret=-1;
    int idMusico;
    int posicionDeLaCoincidencia=0;
    int ready=0;
    int opcion;

    if(arrayInstrumentoMusico != NULL && len >= 0)
    {
        getValidInt(&idMusico,"Ingrese el id del musico a modificar\n","error\n",1,9999,3);
        if(musico_buscarID(arrayInstrumentoMusico,1000,idMusico,&posicionDeLaCoincidencia)!=0)
        {
            printf("Error, el id no existe o el arrayInstrumento es nulo\n");
        }
        else
        {
            while(ready!=1)
            {
                getValidInt(&opcion,"Ingrese valor a modificar:\n 1 para edad\n2 para orquesta donde toca\n3 para salir","Error",1,3,3);

                switch(opcion)
                {
                    case 1:
                        getValidInt(&arrayInstrumentoMusico[posicionDeLaCoincidencia].edad,"\nIngrese el nuevo valor para edad\n","\nError\n",1,100,2);
                        break;
                    case 2:
                        getValidInt(&arrayInstrumentoMusico[posicionDeLaCoincidencia].idOrquesta,"\nIngrese el nuevo valor para ID de orquesta\n","\nError\n",1,10000,2);
                        break;
                    case 3:
                        ready=1;
                        break;
                }
            }
        }
    }return ret;
}

int musico_baja(Musico *arrayInstrumentoMusico,int len)
{
    int ret=-1;
    int idMusico;
    int posicionDeLaCoincidencia=0;

    if(arrayInstrumentoMusico != NULL && len >= 0)
    {
        getValidInt(&idMusico,"\nIngrese el id del musico a dar de baja\n","\nerror\n",1,9999,3);
        if(musico_buscarID(arrayInstrumentoMusico,30,idMusico,&posicionDeLaCoincidencia)==0)
        {
            arrayInstrumentoMusico[posicionDeLaCoincidencia].isEmpty=1;
            printf("se ha dado de baja el musico en la posicion %d\n",posicionDeLaCoincidencia);
            ret=0;
        }
        else
        {
            printf("Error, el id no existe o el arrayInstrumento es nulo");
        }
    }
    return ret;
}

int musico_listar(Musico *arrayInstrumentoMusico,int len)
{
    int i;
    int ret=-1;
    if(arrayInstrumentoMusico!=NULL && len>=0)
    {
        for(i=0;i<len;i++)
        {
            if(arrayInstrumentoMusico[i].isEmpty==0)
            {
                    printf(" %s\n %s\n %d\n %d\n %d\n",arrayInstrumentoMusico[i].apellido
                                                      ,arrayInstrumentoMusico[i].nombre
                                                      ,arrayInstrumentoMusico[i].idOrquesta
                                                      ,arrayInstrumentoMusico[i].idInstrumento
                                                      ,arrayInstrumentoMusico[i].edad);
            }
        }
        ret=0;
    }
    return ret;
}

int musico_sortMusicoApellido(Musico *arrayInstrumentoMusico,int lenMusico,int order)
{
    int i;
    int j;
    Musico buffer;
    int ret = -1;

    if(arrayInstrumentoMusico != NULL && lenMusico > 0)
    {
        for(i=0;i<lenMusico-1;i++)
        {
            for(j=i+1;j<lenMusico;j++)
            {
                if(order == 1 && (strcmp(arrayInstrumentoMusico[j].apellido,arrayInstrumentoMusico[i].apellido) < 0))
                {
                    buffer = arrayInstrumentoMusico[i];
                    arrayInstrumentoMusico[i] = arrayInstrumentoMusico[j];
                    arrayInstrumentoMusico[j] = buffer;
                    ret = 0;
                }
                else if(order == 0 && (strcmp(arrayInstrumentoMusico[j].apellido,arrayInstrumentoMusico[i].apellido) > 0))
                {
                    buffer = arrayInstrumentoMusico[i];
                    arrayInstrumentoMusico[i] = arrayInstrumentoMusico[j];
                    arrayInstrumentoMusico[j] = buffer;
                    ret = 0;
                }
            }
        }
    }
    return ret;
}

