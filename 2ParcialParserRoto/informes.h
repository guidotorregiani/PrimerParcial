#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int generarArchivoInformes(char* fileName,LinkedList* listaVentas);
int informe_cantidadVentasPorMonto2(LinkedList* ListaVentas);
int informe_cantidadVentasPorMonto(LinkedList* ListaVentas);
int informe_cantidadFotosReveladas(LinkedList* ListaVentas);
int informe_cantidadFotosPolaroid(LinkedList* Listaventas);

#endif // INFORMES_H_INCLUDED
