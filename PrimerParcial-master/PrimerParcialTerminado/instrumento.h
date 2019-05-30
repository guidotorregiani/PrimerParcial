#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED
#define Nombre_LEN 51

typedef struct{
int idInstrumento;
int isEmpty;
char nombre [Nombre_LEN];
int tipo;

}Instrumento;


int instrumento_inicializar(Instrumento *arrayInstrumento,int len);
int instrumento_lugarLibre(Instrumento *arrayInstrumento,int len,int *lugarLibre);
int instrumento_listar(Instrumento *arrayInstrumento,int len);
int instrumento_alta(Instrumento *arrayInstrumento,int len,int idInstrumentoAnterior);
int instrumento_modificar(Instrumento *arrayInstrumento,int len);
int instrumento_baja(Instrumento *arrayInstrumento,int len);
int instrumento_buscarID(Instrumento *arrayInstrumento, int len, int valorBuscado, int* posicion);
int instrumento_promedioSalarios(Instrumento *arrayInstrumento,int len);
int instrumento_ordenarPorApellido(Instrumento *arrayInstrumento,int len,int orden);
void instrumento_menu(Instrumento *arrayInstrumento,int len,char* opcionesMenu, char* msgErr);

#endif // INSTRUMENTO_H_INCLUDED
