#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ventas.h"
#include "utn_string.h"

Ventas* ventas_new()
{
    return(Ventas*)malloc(sizeof(Ventas));
}

Ventas* ventas_newParametros(char* idStr,char* fechaStr,char* tipoStr,char* cantidadStr,char* precioStr,char* cuitStr)
{

    Ventas* vent=ventas_new();
    if(vent!=NULL)
    {
        ventas_setId(vent,idStr);
        ventas_setFecha(vent,fechaStr);
        ventas_setTipo(vent,tipoStr);
        ventas_setCantidad(vent,cantidadStr);
        ventas_setPrecio(vent,precioStr);
        ventas_setCuit(vent,cuitStr);
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

    if(this != NULL && value!=NULL)
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


int ventas_setPrecio(Ventas* this,char* value)
{
    float auxPrecio;
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        auxPrecio=atof(value);
        if(auxPrecio>=0)
        {
            this->precio = auxPrecio;
            retorno = 0;
        }
    }
    return retorno;
}

int ventas_setTipo(Ventas* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
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
    if(this != NULL && value!=NULL)
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

int ventas_setFecha(Ventas* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        if(strlen(value)>0)
        {
            strncpy(this->fecha,value,sizeof(this->fecha));
            retorno = 0;
        }
    }
    return retorno;
}

int ventas_setCuit(Ventas* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        if(strlen(value)>0)
        {
            strncpy(this->cuit,value,sizeof(this->cuit));
            retorno = 0;
        }
    }
    return retorno;
}

int ventas_getCuit(Ventas* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->cuit,sizeof(this->cuit));
        retorno = 0;
    }
    return retorno;
}


int ventas_getFecha(Ventas* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->fecha,sizeof(this->fecha));
        retorno = 0;
    }
    return retorno;
}

int ventas_getTipo(Ventas* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->tipo,sizeof(this->fecha));
        retorno = 0;
    }
    return retorno;
}

int ventas_getPrecio(Ventas* this, float* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->precio;
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

int venta_contarCantidad(void* pFirstVenta)
{
    int retorno = 0;
    Ventas* pVentas;

    pVentas=(Ventas*)pFirstVenta;

    if(pFirstVenta!=NULL)
    {
        retorno=pVentas->cantidad;
    }
    return retorno;
}

int venta_contarVentaPorMonto(void* pFirstVenta)
{
    int retorno = 0;
    Ventas* pVentas;

    pVentas=(Ventas*)pFirstVenta;

    if(pVentas!=NULL && pVentas->precio>150)
    {
        retorno=pVentas->cantidad;
    }
    return retorno;
}


int venta_contarVentaPorMonto2(void* pFirstVenta)
{
    int retorno = 0;
    Ventas* pVentas;

    pVentas=(Ventas*)pFirstVenta;

    if(pVentas!=NULL && pVentas->precio>300)
    {
        retorno=pVentas->cantidad;
    }
    return retorno;
}
