#include "LinkedList.h"
#include "Parser.h"
#include "Ventas.h"

int parser_VentasFromText(FILE* pFile , LinkedList* listaVentas)
{

    char bufferId[4096];
    char bufferTipo[4096];
    char bufferCantidad[4096];
    char bufferPrecio[4096];
    char bufferFecha[4096];
    char bufferCuit[4096];
    int cantidadDatos;
    Ventas *pVentas;


    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId
                                                             ,bufferFecha
                                                             ,bufferTipo
                                                             ,bufferCantidad
                                                             ,bufferPrecio
                                                             ,bufferCuit);

        while(!feof(pFile))
        {
            cantidadDatos=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId
                                                                               ,bufferFecha
                                                                               ,bufferTipo
                                                                               ,bufferCantidad
                                                                               ,bufferPrecio
                                                                               ,bufferCuit);

            printf("%s: ,%s :,%s :,%s, :%s :%s : \n",bufferId,bufferFecha,bufferTipo,bufferCantidad,bufferPrecio,bufferCuit);

            if(cantidadDatos==6)
            {
                pVentas = ventas_newParametros(bufferId
                                               ,bufferFecha
                                               ,bufferTipo
                                               ,bufferCantidad
                                               ,bufferPrecio
                                               ,bufferCuit);

                if(pVentas != NULL)
                {
                    if(ll_add(listaVentas,pVentas))
                    {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}
