#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Perritos.h"
#include "functions.h"
#include "LinkedList.h"
#include "parser.h"
#include "inputs.h"

int perritos_loadFromText(char* path , LinkedList* llist)
{
	FILE* pFile = fopen(path, "r");

	if(pFile!=NULL && llist!=NULL)
	{
		parser_PerritoFromText(pFile, llist);
		return 0;
	}
	return 1;
}

int perritos_listByName(LinkedList* llist)
{
	int len=ll_len(llist);
	Perrito* perritoA=NULL;
	Perrito* perritoB=NULL;
	Perrito* perritoAux=NULL;
	char nombrePerritoA[128];
	char nombrePerritoB[128];

	if(llist!=NULL && len>-1)
	{
		for(int i=0; i<len-1; i++)
		{
			Perrito* perritoA=ll_get(llist, i);
			perrito_getNombre(perritoA, nombrePerritoA);

			for(int j=i+1; j<len; j++)
			{
				Perrito* perritoB=ll_get(llist, j);
				perrito_getNombre(perritoA, nombrePerritoB);

				if(strcmp(nombrePerritoA, nombrePerritoB)==1)
				{
					perritoAux=perritoA;
					perritoA=perritoB;
					perritoB=perritoAux;
				}
			}
		}
		printf("Lista ordenada por apellido de manera ascendente...\n");
		return 0;
	}
	return 1;
}
