int controller_loadFromText(char* path , LinkedList* llist);
int controller_loadFromBinary(char* path , LinkedList* llist);
/*
int controller_addPerrito(LinkedList* llist, int *ultimoId);
int controller_editPerrito(LinkedList* llist, int ultimoId);
int controller_removePerrito(LinkedList* llist, int ultimoId);
*/
int controller_ListPerritos(LinkedList* llist);
int controller_sortPerritos(LinkedList* llist);
int controller_saveAsText(char* path , LinkedList* llist);
int controller_saveAsBinary(char* path , LinkedList* llist);

int controller_filterBy(LinkedList* llist);
