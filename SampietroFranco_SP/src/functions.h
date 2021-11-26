#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "Perritos.h"
#include "LinkedList.h"

Perrito* perrito_getById(LinkedList* llist, int id);
int perrito_orderById(void* perritoA, void* perritoB);
int perrito_orderByName(void* perritoA, void* perritoB);
int perrito_orderByEdad(void* perritoA, void* perritoB);
int perrito_orderByRaza(void* perritoA, void* perritoB);
void perrito_listOne(Perrito* perrito);
//FILTROS
void perrito_filterRaza(LinkedList* llist);
void perrito_filterEdad(LinkedList* llist);

int ll_getLastId(LinkedList* llist);

#endif /* FUNCTIONS_H_ */
