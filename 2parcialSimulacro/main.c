#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Entregas.h"

int generarArchivoInformes(char* fileName,LinkedList* listaEntregas);

int main()
{
    // Definir lista de entregas
    LinkedList* listaEntregas = ll_newLinkedList();
}

int generarArchivoInformes(char* fileName,LinkedList* listaEntregas)
{
    int retorno = -1;
    Entregas* pEntregas;
    int i;

    FILE* pFile = fopen(fileName,"w+");

    if(listaEntregas != NULL && pFile != NULL)
    {
        fprintf(pFile,"***********************"
                      "---Informe de ventas---"
                      "***********************");

        for (i=0;i<ll_len(listaEntregas);i++)
        {
            pEntregas=ll_get(listaEntregas, i);

            if(pEntregas != NULL)
            {
                //cambiar esto por los informes y tirar el for a la mierda
                fprintf (pFile,"%d\n,%s\n,%d\n,%d\n", pEntregas->id, pEntregas->tipo,
                                                      pEntregas->cantidad, pEntregas->peso);
            }
        }

        fclose(pFile);

        retorno = 1;
    }

    return retorno;
}
