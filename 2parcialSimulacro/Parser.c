#include "LinkedList.h"
#include "Parser.h"
#include "Entregas.h"

int parser_EntregasFromText(FILE* pFile , LinkedList* pArrayListEntregas)
{

    char bufferId[4096];
    char bufferTipo[4096];
    char bufferCantidad[4096];
    char bufferPeso[4096];
    int cantidadDatos;
    Entregas *pEntregas;


    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                  bufferTipo,
                                                  bufferCantidad,
                                                  bufferPeso);
        while(!feof(pFile))
        {
            cantidadDatos=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                  bufferTipo,
                                                  bufferCantidad,
                                                  bufferPeso);
            if(cantidadDatos==4)
            {
                pEntregas = entregas_newParametros( bufferId,
                                                    bufferTipo,
                                                    bufferCantidad,
                                                    bufferPeso);

                if(pEntregas != NULL)
                {
                    if(ll_add(pArrayListEntregas,pEntregas))
                    {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}
