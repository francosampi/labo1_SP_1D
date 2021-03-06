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

/*
int perritos_orderByName(LinkedList* llist)
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
				perrito_getNombre(perritoB, nombrePerritoB);

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
*/

int perritos_compareName(void* perritoA, void* perritoB)
{
	if(perritoA!=NULL && perritoB!=NULL)
	{
		char auxNombreA[128], auxNombreB[128];

		Perrito *perrA = (Perrito*) perritoA;
		Perrito *perrB = (Perrito*) perritoB;

		perrito_getNombre(perrA, auxNombreA);
		perrito_getNombre(perrB, auxNombreB);

		return strcmp(auxNombreA, auxNombreB);
	}
	return -2;
}

int perritos_orderByName(LinkedList* llist)
{
	if(llist!=NULL)
	{
		ll_sort(llist, perritos_compareName, 1);
		return 0;
	}
	return 1;
}

void perrito_listOne(Perrito* perrito, int conComida)
{
	int auxId, auxEdad;
	float auxPeso, auxComida;
	char auxNombre[128], auxRaza[128];

	perrito_getId(perrito, &auxId);
	perrito_getNombre(perrito, auxNombre);
	perrito_getPeso(perrito, &auxPeso);
	perrito_getEdad(perrito, &auxEdad);
	perrito_getRaza(perrito, auxRaza);
	perrito_getCantidadComidaRacion(perrito, &auxComida);

	if(conComida==0)
	{
		printf("%-5d %-20s %-10.2f %-5d %-20s\n", auxId, auxNombre, auxPeso, auxEdad, auxRaza);
	}
	else
	{
		printf("%-5d %-20s %-10.2f %-5d %-20s %-10.2f\n", auxId, auxNombre, auxPeso, auxEdad, auxRaza, auxComida);
	}
}

int perritos_listAll(LinkedList* llist, int conComida)
{
	Perrito* pPerrito=NULL;
	int lltam;
	if(llist!=NULL)
	{
		lltam=ll_len(llist);

		printLine("LISTA DE PERRITOS");
		if(conComida==0)
		{
			printf("\n\n%-5s %-20s %-10s %-5s %-20s\n", "ID", "Nombre", "Peso", "Edad", "Raza");
		}
		else
		{
			printf("\n\n%-5s %-20s %-10s %-5s %-20s %-10s\n", "ID", "Nombre", "Peso", "Edad", "Raza", "Racion de comida");
		}
		printLine("");
		for(int i=0; i<lltam; i++)
		{
			pPerrito=(Perrito*) ll_get(llist, i);
			perrito_listOne(pPerrito, conComida);
		}
		printLine("");
		return 0;
	}
	return 1;
}

int ePerrito_laQueMapea(void* perrito)
{
	Perrito* pPerrito=NULL;

	float peso;
	float cantidadComidaRacion;

	if(perrito!=NULL)
	{
		pPerrito = (Perrito*) perrito;

		perrito_getPeso(pPerrito, &peso);

		cantidadComidaRacion=peso*23;

		perrito_setCantidadComidaRacion(pPerrito, cantidadComidaRacion);

		return 0;
	}
	return 1;
}

int perritos_calculateFood(LinkedList* llist)
{
	if(llist!=NULL)
	{
		ll_map(llist, ePerrito_laQueMapea);
		return 0;
	}
	return 1;
}

int ePerrito_laQueFiltra(void* perrito)
{
	Perrito* pPerrito=NULL;

	char auxRaza[128];
	int auxEdad;
	float auxComida;

	if(perrito!=NULL)
	{
		pPerrito = (Perrito*) perrito;
		perrito_getRaza(pPerrito, auxRaza);
		perrito_getEdad(pPerrito, &auxEdad);
		perrito_getCantidadComidaRacion(pPerrito, &auxComida);

		if(strcmp(auxRaza, "Galgo")==0 && auxEdad>9 && auxComida<200)
		{
			return 0;
		}
	}
	return 1;
}

LinkedList* perritos_filtrarGalgos(LinkedList* llist)
{
	LinkedList* filteredList=NULL;

	if(llist!=NULL)
	{
		filteredList=ll_filter(llist, ePerrito_laQueFiltra);

		return filteredList;
	}
	return NULL;
}

int perritos_saveGalgosText(char* path, LinkedList* llist)
{
	Perrito* pPerrito=NULL;
	int lltam;

	if(path!=NULL && llist!=NULL)
	{
		FILE* pFile = fopen(path, "w");

		int auxId, auxEdad;
		float auxPeso, auxComida;
		char auxNombre[128], auxRaza[128];

		lltam=ll_len(llist);

		fprintf(pFile, "%s\n", "id,nombre,peso,edad,raza,comida");
		for(int i=0; i<lltam; i++)
		{
			pPerrito=(Perrito*) ll_get(llist, i);

			perrito_getId(pPerrito, &auxId);
			perrito_getNombre(pPerrito, auxNombre);
			perrito_getPeso(pPerrito, &auxPeso);
			perrito_getEdad(pPerrito, &auxEdad);
			perrito_getRaza(pPerrito, auxRaza);
			perrito_getCantidadComidaRacion(pPerrito, &auxComida);

			fprintf(pFile, "%d,%s,%f,%d,%s,%f\n", auxId, auxNombre, auxPeso, auxEdad, auxRaza, auxComida);
		}
		fclose(pFile);
		pFile=NULL;
		return 0;
	}
	return 1;
}
