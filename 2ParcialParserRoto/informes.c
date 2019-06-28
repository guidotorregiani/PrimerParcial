#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Ventas.h"
#include "informes.h"
#include "Controller.h"

//aca las funciones que van a utilizar los ll_map, ll_informex, etc





//aca las funciones nuevas tipo ll_informes

int generarArchivoInformes(char* fileName,LinkedList* listaVentas)
{
    int retorno = -1;

    int ventas150;
    int ventas300;
    int cantTotal;
    int cantPolaroid;

    FILE* fp = fopen(fileName,"w+");
    if(fp != NULL && listaVentas!= NULL)
    {
        ventas150=informe_cantidadVentasPorMonto(listaVentas);
        ventas300=informe_cantidadVentasPorMonto2(listaVentas);
        cantTotal=informe_cantidadFotosReveladas(listaVentas);
        cantPolaroid=informe_cantidadFotosPolaroid(listaVentas);

        fprintf(fp,"*******************\n");
        fprintf(fp,"Informe de ventas\n");
        fprintf(fp,"*******************\n");
        fprintf(fp,"- Cantidad de fotos reveladas totales: %d\n",cantTotal);
        fprintf(fp,"- Cantidad de ventas por unmonto mayor a $150: %d\n",ventas150);
        fprintf(fp,"- Cantidad de ventas por un monto mayor a $300: %d\n",ventas300);
        fprintf(fp,"- Cantidad de fotos polaroids reveladas: %d\n",cantPolaroid);
        fprintf(fp,"*******************");

        printf("%d\n,%d\n,%d\n,%d\n",cantTotal,ventas150,ventas300,cantPolaroid);

        fclose(fp);
        retorno = 1;
    }
    return retorno;
}

int informe_cantidadFotosReveladas(LinkedList* ListaVentas)
{
    int ret=-1;
    int aux;
    if(ListaVentas!=NULL)
    {
        ret=0;

        aux=ll_contador(ListaVentas,venta_contarCantidad);

        if(aux!=NULL)
            {
                ret=aux;
            }
    }
    return ret;
}

int informe_cantidadVentasPorMonto(LinkedList* ListaVentas)
{
    int ret=-1;
    int aux;
    if(ListaVentas!=NULL)
    {
        ret=0;

        aux=ll_contador(ListaVentas,venta_contarVentaPorMonto);

        if(aux!=NULL)
            {
                ret=aux;
            }
    }

    return ret;
}

int informe_cantidadVentasPorMonto2(LinkedList* ListaVentas)
{
    int ret=-1;
    int aux;
    if(ListaVentas!=NULL)
    {
        ret=0;

        aux=ll_contador(ListaVentas,venta_contarVentaPorMonto2);

        if(aux!=NULL)
            {
                ret=aux;
            }
    }

    return ret;
}

int informe_cantidadFotosPolaroid(LinkedList* ListaVentas)
{
    int aux=-1;
    int i;
    int size;
    Ventas* auxElement;

    if(ListaVentas != NULL)
    {
        size = ll_len(ListaVentas);
        aux=0;
        for(i=0;i<size;i++)
        {
            auxElement=ll_get(ListaVentas,i);
            if(auxElement->tipo == "POLAROID_11x9" || auxElement->tipo == "POLAROID_10x10")
            {
                aux=ll_contador(ListaVentas,venta_contarCantidad);
            }
        }
    }
    return aux;
}


