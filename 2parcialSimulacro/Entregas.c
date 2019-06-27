#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Entregas.h"
#include "utn_string.h"

Entregas* entregas_new()
{
    return (Entregas*) malloc(sizeof(Entregas));
}

Entregas* entregas_newParametros(char* idStr,char* tipoStr,char* cantidadStr,char* peso)
{

    Entregas* ent=entregas_new();
    if(ent!=NULL)
    {
        entregas_setId(ent,idStr);
        entregas_setTipo(ent,tipoStr);
        entregas_setCantidad(ent,cantidadStr);
        entregas_setPeso(ent,peso);
    }
    return ent;
}

int entregas_delete(Entregas* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int entregas_setId(Entregas* this, char* value)
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


int entregas_setPeso(Entregas* this,char* value)
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

int entregas_setTipo(Entregas* this, char* value)
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


int entregas_setCantidad(Entregas* this,char* value)
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


int entregas_getTipo(Entregas* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->tipo,sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}

int entregas_getPeso(Entregas* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->peso;
        retorno = 0;
    }
    return retorno;
}

int entregas_getCantidad(Entregas* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->cantidad;
        retorno = 0;
    }
    return retorno;
}

int entregas_getId(Entregas* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->id;
        retorno = 0;
    }
    return retorno;
}


int entregas_initArray(Entregas* arrayEmpleado[],int lenEmpleado)
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

int entregas_findFree(Entregas* arrayEntregas[], int lenEntregas)
{
    int i;
    int ret=-1;
    if(arrayEntregas!=NULL && lenEntregas>0)
    {
        for(i=0; i<lenEntregas; i++)
        {
            if(arrayEntregas[i]==NULL)
            {
                ret=i;
                printf("\nSe encontro lugar libre\n");
                break;
            }
        }
    }
    return ret;
}

int entregas_sortByName(void* pFirstEntregas,void* pSecondEntregas)
{
    int retorno;
    Entregas* pEntregasA;
    Entregas* pEntregasB;

    pEntregasA=(Entregas*) pFirstEntregas;
    pEntregasB=(Entregas*) pSecondEntregas;

    if(strcmp(pEntregasA->tipo,pEntregasB->tipo) > 0)
    {
        retorno = 1;
    }
    else if(strcmp(pEntregasA->tipo,pEntregasB->tipo) < 0)
    {
        retorno = -1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

int entrega_contarByTipoEXP(void* pFirstEntrega)
{
    int retorno = 0;
    Entregas* pEntregas;

    pEntregas = (Entregas*) pFirstEntrega;

    if(strcmp(pEntregas->tipo,"EXP") == 0)
    {
        retorno = 1;///mayor el primero
    }
    return retorno;
}

int entrega_contarByTipoECO(void* pFirstEntrega)
{
    int retorno = 0;
    Entregas* pEntregas;

    pEntregas = (Entregas*) pFirstEntrega;

    if(strcmp(pEntregas->tipo,"ECO") == 0)
    {
        retorno = 1;///mayor el primero
    }

    return retorno;
}

int entrega_contarCantidad(void* pFirstEntrega)
{
    int retorno = -1;
    Entregas* pEntregas;
    pEntregas = (Entregas*) pFirstEntrega;

    if(pEntregas != NULL && pEntregas->cantidad >= 0)
    {
        retorno = pEntregas->cantidad;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int entrega_contarPeso(void* pFirstEntrega)
{
    int retorno = -1;
    Entregas* pEntregas;
    pEntregas = (Entregas*) pFirstEntrega;

    if(pEntregas != NULL && pEntregas->peso >= 0)
    {
        retorno = pEntregas->peso;
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int entrega_contarByTipoSTD(void* pFirstEntrega)
{
    int retorno = 0;
    Entregas* pEntregas;

    pEntregas = (Entregas*) pFirstEntrega;

    if(strcmp(pEntregas->tipo,"STD") == 0)
    {
        retorno = 1;///mayor el primero
    }
    return retorno;
}
