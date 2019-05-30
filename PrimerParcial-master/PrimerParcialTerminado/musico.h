#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED
#define Nombre_LEN 51

typedef struct{
int idMusico;
int isEmpty;
char nombre [Nombre_LEN];
char apellido[Nombre_LEN];
int edad;
int idOrquesta;
int idInstrumento;

}Musico;


int musico_inicializar(Musico *arrayMusico,int len);
int musico_lugarLibre(Musico *arrayMusico,int len,int *lugarLibre);
int musico_listar(Musico *arrayMusico,int len);
int musico_alta(Musico *arrayMusico,int len,int idMusicoAnterior);
int musico_modificar(Musico *arrayMusico,int len);
int musico_baja(Musico *arrayMusico,int len);
int musico_buscarID(Musico *arrayMusico, int len, int valorBuscado, int* posicion);
int musico_promedioSalarios(Musico *arrayMusico,int len);
int musico_ordenarPorApellido(Musico *arrayMusico,int len,int orden);
void musico_menu(Musico *arrayMusico,int len,char* opcionesMenu, char* msgErr);
int musico_sortMusicoApellido(Musico *arrayMusico,int lenMusico,int order);

#endif // MUSICO_H_INCLUDED
