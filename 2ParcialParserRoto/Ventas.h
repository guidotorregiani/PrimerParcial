#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

typedef struct
{
    int id;
    char* fecha;
    char tipo[128];
    int cantidad;
    float precio;
    char* cuit;
}Ventas;



Ventas* ventas_new();
Ventas* ventas_newParametros(char* idStr,char* fechaStr,char* tipoStr,char* cantidadStr,char* precioStr,char* cuitStr);
int ventas_delete(Ventas* this);

int ventas_setId(Ventas* this,char* id);
int ventas_getId(Ventas* this,int* id);

int ventas_setTipo(Ventas* this,char* tipo);
int ventas_getTipo(Ventas* this,char* tipo);

int ventas_setCantidad(Ventas* this,char* cantidad);
int ventas_getCantidad(Ventas* this,int* cantidad);

int ventas_setPrecio(Ventas* this,char* precio);
int ventas_getPrecio(Ventas* this,float* precio);

int ventas_setCuit(Ventas* this,char* cuit);
int ventas_getCuit(Ventas* this, char* cuit);

int ventas_setFecha(Ventas* this,char* fecha);
int ventas_getFecha(Ventas* this,char* fecha);

int ventas_sortByName(void* pFirstVentas,void* pSecondVentas);
int venta_contarByTipoSTD(void* pEntrega);
int venta_contarByTipoEXP(void* pFirstEntrega);
int venta_contarByTipoECO(void* pFirstEntrega);
int venta_contarCantidad(void* pFirstEntrega);
int venta_contarPrecio(void* pFirstEntrega);

int venta_contarVentaPorMonto(void* pFirstEntrega);
int venta_contarVentaPorMonto2(void* pFirstEntrega);
int venta_contarPrecio(void* pFirstEntrega);

#endif // VENTAS_H_INCLUDED
