#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Entregas.h"
#include "informes.h"
#include "Controller.h"

int main()
{
    // Definir lista de entregas
    LinkedList* listaEntregas=ll_newLinkedList();
    //carga los datos del csv en la lista
    controller_loadFromText("data.csv",listaEntregas);
    //llama a las func de informes y genera el archivo correspondiente con los mismos
    generarArchivoInformes("informes.txt",listaEntregas);
    return 0;
}


