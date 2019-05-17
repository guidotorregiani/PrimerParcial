#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED
#define Nombre_LEN 51

typedef struct{
int idOrquesta;
int isEmpty;
char nombre [Nombre_LEN];
char lugar[Nombre_LEN];
int tipo;

}Orquesta;


int orquesta_inicializar(Orquesta *arrayOrquesta,int len);
int orquesta_lugarLibre(Orquesta *arrayOrquesta,int len,int *lugarLibre);
int orquesta_listar(Orquesta *arrayOrquesta,int len);
int orquesta_alta(Orquesta *arrayOrquesta,int len,int idOrquestaAnterior);
int orquesta_modificar(Orquesta *arrayOrquesta,int len);
int orquesta_baja(Orquesta *arrayOrquesta,int len);
int orquesta_buscarID(Orquesta *arrayOrquesta, int len, int valorBuscado, int* posicion);
int orquesta_promedioSalarios(Orquesta *arrayOrquesta,int len);
int orquesta_ordenarPorApellido(Orquesta *arrayOrquesta,int len,int orden);
void orquesta_menu(Orquesta *arrayOrquesta,int len,char* opcionesMenu, char* msgErr);

#endif // ORQUESTA_H_INCLUDED
