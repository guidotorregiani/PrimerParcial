#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Parser.h"
#include "Ventas.h"
#include "utn_string.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (texto).
 *
 * \param path char*
 * \param pArrayListVentas LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListVentas)
{
    FILE* pFile;
    int retorno=-1;
    if(pArrayListVentas!=NULL)
    {
        pFile = fopen(path,"r");
        if(pFile!=NULL)
        {
            parser_VentasFromText(pFile , pArrayListVentas);
            fclose(pFile);
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (texto).
 *
 * \param path char*
 * \param pArrayListVentas LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListVentas)
{
    Ventas* pE;
    int auxId;
    float auxPrecio;
    int auxCantidad;
    char auxFecha[4096];
    char auxTipo[4096];
    char auxCuit[4096];
    int size;
    int i;

    FILE* fp=fopen(path,"w+");
    if(fp!=NULL && pArrayListVentas!=NULL)
    {
        fprintf(fp,"id,nombre,horasTrabajadas,sueldo\n");

        size=ll_len(pArrayListVentas);

        for(i=0;i<size;i++)
        {
            pE=ll_get(pArrayListVentas,i);
            ventas_getId(pE,&auxId);
            ventas_getTipo(pE,auxTipo);
            ventas_getPrecio(pE,&auxPrecio);
            ventas_getCantidad(pE,&auxCantidad);
            ventas_getCuit(pE,auxCuit);
            ventas_getFecha(pE,auxFecha);
            if(pE!=NULL)
            {
                fprintf(fp,"%d,%s,%f,%d,%s,%s",auxId
                                              ,auxTipo
                                              ,auxPrecio
                                              ,auxCantidad
                                              ,auxCuit
                                              ,auxFecha);
            }
        }
        fclose(fp);
        return 0;
    }
    return 1;
}
