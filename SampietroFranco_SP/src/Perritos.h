#ifndef perritos_H_INCLUDED
#define perritos_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int edad;
    char raza[128];
}Perrito;

Perrito* perrito_new();
Perrito* perrito_newParametros(char* idStr,char* nombreStr,char* edadStr,char* razaStr);

void perrito_delete(Perrito* this);

int perrito_setId(Perrito* this,int id);
int perrito_getId(Perrito* this,int* id);
int perrito_setNombre(Perrito* this,char* nombre);
int perrito_getNombre(Perrito* this,char* nombre);
int perrito_setEdad(Perrito* this,int edad);
int perrito_getEdad(Perrito* this,int* edad);
int perrito_setRaza(Perrito* this,char* raza);
int perrito_getRaza(Perrito* this,char* raza);

#endif
