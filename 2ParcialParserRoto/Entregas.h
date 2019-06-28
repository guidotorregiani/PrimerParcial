#ifndef ENTREGAS_H_INCLUDED
#define ENTREGAS_H_INCLUDED
typedef struct
{
    int id;
    char tipo[128];
    int cantidad;
    int peso;
}Ventas;

Ventas* ventas_new();
Ventas* ventas_newParametros(char* id,char* tipo,char* cantidad,char* peso);
int ventas_delete(Ventas* this);

int ventas_setId(Ventas* this,char* id);
int ventas_getId(Ventas* this,int* id);

int ventas_setTipo(Ventas* this,char* tipo);
int ventas_getTipo(Ventas* this,char* tipo);

int ventas_setCantidad(Ventas* this,char* cantidad);
int ventas_getCantidad(Ventas* this,int* cantidad);

int ventas_setPeso(Ventas* this,char* peso);
int ventas_getPeso(Ventas* this,int* peso);

int ventas_sortByName(void* pFirstVentas,void* pSecondVentas);
int ventrega_contarByTipoSTD(void* pEntrega);
int ventrega_contarByTipoEXP(void* pFirstEntrega);
int ventrega_contarByTipoECO(void* pFirstEntrega);
int ventrega_contarCantidad(void* pFirstEntrega);
int ventrega_contarPeso(void* pFirstEntrega);
#endif // ENTREGAS_H_INCLUDED
