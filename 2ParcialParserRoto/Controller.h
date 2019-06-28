#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path , LinkedList* pArrayListVentas);
int controller_saveAsText(char* path , LinkedList* pArrayListVentas);

#endif // CONTROLLER_H_INCLUDED
