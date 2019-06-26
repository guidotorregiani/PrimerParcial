#ifndef ENTREGAS_H_INCLUDED
#define ENTREGAS_H_INCLUDED
typedef struct
{
    int id;
    char tipo[128];
    int cantidad;
    int peso;
}Entregas;

Entregas* entregas_new();
Entregas* entregas_newParametros(char* id,char* tipo,char* cantidad,char* peso);
int entregas_delete(Entregas* this);

int entregas_setId(Entregas* this,char* id);
int entregas_getId(Entregas* this,int* id);

int entregas_setTipo(Entregas* this,char* tipo);
int entregas_getTipo(Entregas* this,char* tipo);

int entregas_setCantidad(Entregas* this,char* cantidad);
int entregas_getCantidad(Entregas* this,int* cantidad);

int entregas_setPeso(Entregas* this,char* peso);
int entregas_getPeso(Entregas* this,int* peso);

int entregas_sortByName(void* pFirstEntregas,void* pSecondEntregas);

#endif // ENTREGAS_H_INCLUDED
