#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "Perritos.h"
#include "LinkedList.h"

int perritos_loadFromText(char* path , LinkedList* llist);
int perritos_listByName(LinkedList* llist);

#endif /* FUNCTIONS_H_ */
