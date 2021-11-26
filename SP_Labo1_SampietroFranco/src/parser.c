#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Perritos.h"

int parser_PerritoFromText(FILE* pFile , LinkedList* llist)
{
	if(pFile!=NULL && llist!=NULL)
	{
		char id[10];
		char nombre[128];
		char peso[10];
		char edad[10];
		char raza[128];

		Perrito* pPerrito;

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]", id, nombre, peso, edad, raza);
		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]", id, nombre, peso, edad, raza);
			if(feof(pFile))
			{
				break;
			}
			pPerrito = perrito_newParametros(id, nombre, peso, edad, raza);
			ll_add(llist, pPerrito);
		}
		fclose(pFile);
		pFile=NULL;
		return 0;
	}
    return 1;
}
