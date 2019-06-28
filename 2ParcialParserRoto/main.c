#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Ventas.h"
#include "informes.h"
#include "Controller.h"

int main()
{
    int ret=0;
    // Definir lista de ventas
    LinkedList* listaVentas=ll_newLinkedList();
    //carga los datos del csv en la lista
    controller_loadFromText("data.csv",listaVentas);
    //llama a las func de informes y genera el archivo correspondivente con los mismos
    generarArchivoInformes("informes.txt",listaVentas);

    int i;
    Ventas* auxElem=NULL;
    for(i=0;i<ll_len(listaVentas);i++)
    {
        auxElem=ll_get(listaVentas,i);
        printf("%d,%s,%d,%d,%f,%s\n",auxElem->id,auxElem->fecha,auxElem->cantidad,auxElem->cantidad,auxElem->precio,auxElem->cuit);
    }

    return ret;
}


