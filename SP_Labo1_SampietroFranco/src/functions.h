#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "Perritos.h"
#include "LinkedList.h"

int perritos_loadFromText(char* path , LinkedList* llist);
int perritos_listByName(LinkedList* llist);
int ePerrito_laQueMapea(void* perrito);
int perritos_calculateFood(LinkedList* llist);
int perritos_orderByName(LinkedList* llist);
void perrito_listOne(Perrito* perrito, int conComida);
int perritos_listAll(LinkedList* llist, int conComida);

#endif /* FUNCTIONS_H_ */
