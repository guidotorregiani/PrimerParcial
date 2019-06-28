#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ventas.h"
#include "utn_string.h"

Ventas* ventas_new()
{
    return (Ventas*) malloc(sizeof(Ventas));
}

Ventas* ventas_newParametros(char* idStr,char* tipoStr,char* cantidadStr,char* peso)
{

    Ventas* vent=ventas_new();
    if(vent!=NULL)
    {
        ventas_setId(vent,idStr);
        ventas_setTipo(vent,tipoStr);
        ventas_setCantidad(vent,cantidadStr);
        ventas_setPeso(vent,peso);
    }
    return vent;
}

int ventas_delete(Ventas* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int ventas_setId(Ventas* this, char* value)
{
    int auxID;
    int retorno = -1;

    if(this != NULL && value!=NULL && isNum(value))
    {
        auxID=atoi(value);
        if(auxID>=0)
        {
            this->id = auxID;
            retorno = 0;
        }
    }
    return retorno;
}


int ventas_setPeso(Ventas* this,char* value)
{
    int auxPeso;
    int retorno = -1;
    if(this != NULL && value!=NULL && isNum(value))
    {
        auxPeso=atoi(value);
        if(auxPeso>=0)
        {
            this->peso = auxPeso;
            retorno = 0;
        }
    }
    return retorno;
}

int ventas_setTipo(Ventas* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL && validarLetra(value))
    {
        if(strlen(value)>0)
        {
            strncpy(this->tipo,value,sizeof(this->tipo));
            retorno = 0;
        }
    }
    return retorno;
}


int ventas_setCantidad(Ventas* this,char* value)
{
    int auxHoras;
    int retorno = -1;
    if(this != NULL && value!=NULL && isNum(value))
    {
        auxHoras=atoi(value);
        if(auxHoras>=0)
        {
            this->cantidad = auxHoras;
            retorno = 0;
        }
    }
    return retorno;
}


int ventas_getTipo(Ventas* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->tipo,sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}

int ventas_getPeso(Ventas* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->peso;
        retorno = 0;
    }
    return retorno;
}

int ventas_getCantidad(Ventas* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->cantidad;
        retorno = 0;
    }
    return retorno;
}

int ventas_getId(Ventas* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->id;
        retorno = 0;
    }
    return retorno;
}


int ventas_initArray(Ventas* arrayEmpleado[],int lenEmpleado)
{
    int i;
    int retorno=-1;
    if(arrayEmpleado!=NULL&&lenEmpleado>0)
    {
        for(i=0; i<lenEmpleado; i++)
        {
            arrayEmpleado[i]=NULL;
        }
        retorno=0;

    }
    return retorno;
}

int ventas_findFree(Ventas* arrayVentas[], int lenVentas)
{
    int i;
    int ret=-1;
    if(arrayVentas!=NULL && lenVentas>0)
    {
        for(i=0; i<lenVentas; i++)
        {
            if(arrayVentas[i]==NULL)
            {
                ret=i;
                printf("\nSe encontro lugar libre\n");
                break;
            }
        }
    }
    return ret;
}

int ventas_sortByName(void* pFirstVentas,void* pSecondVentas)
{
    int retorno;
    Ventas* pVentasA;
    Ventas* pVentasB;

    pVentasA=(Ventas*) pFirstVentas;
    pVentasB=(Ventas*) pSecondVentas;

    if(strcmp(pVentasA->tipo,pVentasB->tipo) > 0)
    {
        retorno = 1;
    }
    else if(strcmp(pVentasA->tipo,pVentasB->tipo) < 0)
    {
        retorno = -1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

int ventrega_contarByTipoEXP(void* pFirstEntrega)
{
    int retorno = 0;
    Ventas* pVentas;

    pVentas = (Ventas*) pFirstEntrega;

    if(strcmp(pVentas->tipo,"EXP") == 0)
    {
        retorno = 1;///mayor el primero
    }
    return retorno;
}

int ventrega_contarByTipoECO(void* pFirstEntrega)
{
    int retorno = 0;
    Ventas* pVentas;

    pVentas = (Ventas*) pFirstEntrega;

    if(strcmp(pVentas->tipo,"ECO") == 0)
    {
        retorno = 1;///mayor el primero
    }

    return retorno;
}

int ventrega_contarCantidad(void* pFirstEntrega)
{
    int retorno = -1;
    Ventas* pVentas;
    pVentas = (Ventas*) pFirstEntrega;

    if(pVentas != NULL && pVentas->cantidad >= 0)
    {
        retorno = pVentas->cantidad;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int ventrega_contarPeso(void* pFirstEntrega)
{
    int retorno = -1;
    Ventas* pVentas;
    pVentas = (Ventas*) pFirstEntrega;

    if(pVentas != NULL && pVentas->peso >= 0)
    {
        retorno = pVentas->peso;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int ventrega_contarByTipoSTD(void* pFirstEntrega)
{
    int retorno = 0;
    Ventas* pVentas;

    pVentas = (Ventas*) pFirstEntrega;

    if(strcmp(pVentas->tipo,"STD") == 0)
    {
        retorno = 1;///mayor el primero
    }
    return retorno;
}
