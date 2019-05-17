#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "instrumento.h"
#include "utn.h"
#define Nombre_LEN 51


int instrumento_inicializar(Instrumento *arrayInstrumento,int len)
{
    int i;
    int ret=-1;
    if(arrayInstrumento != NULL && len >= 0)
    {
        for(i=0;i<len;i++)
        {
            arrayInstrumento[i].isEmpty=1;
            ret=0;
        }
    }
    return ret;
}
int instrumento_lugarLibre(Instrumento *arrayInstrumento,int len,int *lugarLibre)
{
    int i;
    int ret=-1;
    if(arrayInstrumento != NULL && len >= 0)
    {
        for(i=0; i<len ; i++)
        {
            if(arrayInstrumento[i].isEmpty==1)
            {
                *lugarLibre = i;
                ret=0;
                break;
            }
        }
    }
    return ret;
}

int instrumento_alta(Instrumento *arrayInstrumento,int len,int idInstrumentoAnterior)
{
    int ret=-1;
    int flag=1; // 0 falso(dio mal) 1 verdadero(dio bien)
    int lugarLibre;
    int auxTipo;
    char auxNombre[Nombre_LEN];


    if(arrayInstrumento != NULL && len >= 0)
    {
        if(instrumento_lugarLibre(arrayInstrumento,20,&lugarLibre)==0)
        {
            if(getString(auxNombre,"Ingrese un nombre: \n", "ERROR!\n", 1, Nombre_LEN, 2)!=0)
            {
                flag=0;
            }
            if(getValidInt(&auxTipo,"Ingrese el tipo\n","ERROR!\n",1,4,2)!=0)
            {
                flag=0;
            }

            if(flag==1)
            {
                strncpy(arrayInstrumento[lugarLibre].nombre,auxNombre,Nombre_LEN);
                arrayInstrumento[lugarLibre].tipo=auxTipo;
                arrayInstrumento[lugarLibre].isEmpty=0;
                arrayInstrumento[lugarLibre].idInstrumento=idInstrumentoAnterior+1;
                ret=0;
            }
            else
            {
                printf("error, campo mal ingresado, el instrumento no se guardara");
                arrayInstrumento[lugarLibre].isEmpty=1;
            }

            /*Debuggers
            printf(" %s\n %s\n %d\n %d\n",arrayInstrumento[lugarLibre].apellido
                                         ,arrayInstrumento[lugarLibre].nombre
                                         ,arrayInstrumento[lugarLibre].sector
                                         ,arrayInstrumento[lugarLibre].tipo);
            printf(" %d\n",lugarLibre);
            printf("%d\n",arrayInstrumento[lugarLibre].isEmpty);
            printf("%d\n",arrayInstrumento[lugarLibre].idInstrumento);*/
        }

    }
    return ret;
}

int instrumento_buscarID(Instrumento *arrayInstrumento, int size, int id, int* posicion)
{
    int ret=-1;
    int i;
    if(arrayInstrumento!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(arrayInstrumento[i].isEmpty==1)
            {
                continue;
            }
            else if(arrayInstrumento[i].idInstrumento==id)
            {
                ret=0;
                *posicion=i;
                break;
            }
        }
    }
    return ret;
}


/*int instrumento_modificar(Instrumento *arrayInstrumento,int len)
{
    int ret=-1;
    int idInstrumento;
    int posicionDeLaCoincidencia=0;
    int ready=0;
    int opcion;

    if(arrayInstrumento != NULL && len >= 0)
    {
        getValidInt(&idInstrumento,"Ingrese el id del instrumento a modificar\n","error\n",1,9999,3);
        if(instrumento_buscarID(arrayInstrumento,1000,idInstrumento,&posicionDeLaCoincidencia)!=0)
        {
            printf("Error, el id no existe o el array es nulo\n");
        }
        else
        {
            while(ready!=1)
            {
                getValidInt(&opcion,"Ingrese valor a modificar:\n 1 para nombre\n2 para apellido\n3 para sector\4 para tipo\5 para salir","Error",1,5,3);

                switch(opcion)
                {
                    case 1:
                        getString(arrayInstrumento[posicionDeLaCoincidencia].nombre,"\nNuevo valor para nombre:\n","\nError\n",1,Nombre_LEN,2);
                        break;
                    case 2:
                        getString(arrayInstrumento[posicionDeLaCoincidencia].apellido,"\nNuevo valor para apellido:\n","\nError\n",1,Nombre_LEN,2);
                        break;
                    case 3:
                        getValidInt(&arrayInstrumento[posicionDeLaCoincidencia].sector,"\nIngrese el nuevo valor para sector\n","\nError\n",1,8,2);
                        break;
                     case 4:
                        getValidInt(&arrayInstrumento[posicionDeLaCoincidencia].tipo,"\nIngrese el nuevo valor para tipo\n","\nError\n",1,2500,2);
                        break;
                    case 5:
                        ready=1;
                        break;
                }
            }
        }
    }return ret;
}*/

int instrumento_baja(Instrumento *arrayInstrumento,int len)
{
    int ret=-1;
    int idInstrumento;
    int posicionDeLaCoincidencia=0;

    if(arrayInstrumento != NULL && len >= 0)
    {
        getValidInt(&idInstrumento,"\nIngrese el id del instrumento a dar de baja\n","\nerror\n",1,9999,3);
        if(instrumento_buscarID(arrayInstrumento,30,idInstrumento,&posicionDeLaCoincidencia)==0)
        {
            arrayInstrumento[posicionDeLaCoincidencia].isEmpty=1;
            printf("se ha dado de baja el instrumento en la posicion %d\n",posicionDeLaCoincidencia);
        }
        else
        {
            printf("Error, el id no existe o el array es nulo");
        }
    }
    return ret;
}

int instrumento_listar(Instrumento *arrayInstrumento,int len)
{
    int i;
    int ret=-1;
    if(arrayInstrumento!=NULL && len>=0)
    {
        for(i=0;i<len;i++)
        {
            if(arrayInstrumento[i].isEmpty==0)
            {
                    printf(" %s\n %d\n %d\n",arrayInstrumento[i].nombre
                                            ,arrayInstrumento[i].idInstrumento
                                            ,arrayInstrumento[i].tipo);
            }
        }
        ret=0;
    }
    return ret;
}
