#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Parser.h"
#include "Entregas.h"
//#include "utn_string.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (texto).
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEntregas)
{
    FILE* pFile;
    int retorno=-1;
    if(pArrayListEntregas!=NULL)
    {
        pFile = fopen(path,"r");
        if(pFile!=NULL)
        {
            parser_EntregasFromText(pFile , pArrayListEntregas);
            fclose(pFile);
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int controller_ListEntregas(LinkedList* pArrayListEntregas)
{
    Entregas* pE;
    int auxId;
    int auxPeso;
    int auxCantidad;
    char auxTipo[4096];
    int size;
    int i;

    if(pArrayListEntregas!=NULL)
    {
        size=ll_len(pArrayListEntregas);
        for(i=0;i<size;i++)
        {
            pE=ll_get(pArrayListEntregas,i);
            entregas_getId(pE,&auxId);
            entregas_getTipo(pE,auxTipo);
            entregas_getPeso(pE,&auxPeso);
            entregas_getCantidad(pE,&auxCantidad);
            if(pE!=NULL)
            {
                printf("%d,%s,%d,%d\n",auxId
                                      ,auxTipo
                                      ,auxPeso
                                      ,auxCantidad);
            }
        }
    }
   return 1;
}


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int controller_sortEntregas(LinkedList* pArrayListEntregas)
{
    int retorno=-1;
    if(pArrayListEntregas!=NULL)
    {
        ll_sort(pArrayListEntregas,entregas_sortByName,1);
        retorno=0;
    }
    return retorno;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (texto).
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEntregas)
{
    Entregas* pE;
    int auxId;
    int auxPeso;
    int auxCantidad;
    char auxTipo[4096];
    int size;
    int i;

    FILE* fp=fopen(path,"w+");
    if(fp!=NULL && pArrayListEntregas!=NULL)
    {
        fprintf(fp,"id,nombre,horasTrabajadas,sueldo\n");

        size=ll_len(pArrayListEntregas);

        for(i=0;i<size;i++)
        {
            pE=ll_get(pArrayListEntregas,i);
            entregas_getId(pE,&auxId);
            entregas_getTipo(pE,auxTipo);
            entregas_getPeso(pE,&auxPeso);
            entregas_getCantidad(pE,&auxCantidad);
            if(pE!=NULL)
            {
                fprintf(fp,"%d,%s,%d,%d\n",auxId
                                          ,auxTipo
                                          ,auxPeso
                                          ,auxCantidad);
            }
        }
        fclose(fp);
        return 0;
    }
    return 1;
}
