#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Perritos.h"
#include "functions.h"
#include "LinkedList.h"
#include "inputs.h"

Perrito* perrito_getById(LinkedList* llist, int id)
{
	if(llist!=NULL)
	{
		Perrito *pPerrito=NULL;

		int tam=ll_len(llist);
		int auxId;

		for(int i=0; i<tam; i++)
		{
			pPerrito=(Perrito*) ll_get(llist, i);
			perrito_getId(pPerrito, &auxId);

			if(pPerrito!=NULL && auxId==id)
			{
				return pPerrito;
			}
		}
	}
	return NULL;
}

int perrito_orderById(void* perritoA, void* perritoB)
{
	if(perritoA!=NULL && perritoB!=NULL)
	{
		int auxIdA, auxIdB;

		Perrito* pPerritoA = (Perrito*) perritoA;
		Perrito* pPerritoB = (Perrito*) perritoB;

		perrito_getId(pPerritoA, &auxIdA);
		perrito_getId(pPerritoB, &auxIdB);

		if(auxIdA>auxIdB)
		{
			return 1;
		}
		else
		{
			if (auxIdB>auxIdA)
			{
				return -1;
			}
		}
	}
	return -2;
}

int perrito_orderByName(void* perritoA, void* perritoB)
{
	if(perritoA!=NULL && perritoB!=NULL)
	{
		char auxNombreA[128], auxNombreB[128];

		Perrito* pPerritoA = (Perrito*) perritoA;
		Perrito* pPerritoB = (Perrito*) perritoB;

		perrito_getNombre(pPerritoA, auxNombreA);
		perrito_getNombre(pPerritoB, auxNombreB);

		return strcmp(auxNombreA, auxNombreB);
	}
	return -2;
}

int perrito_orderByEdad(void* perritoA, void* perritoB)
{
	if(perritoA!=NULL && perritoB!=NULL)
	{
		int auxEdadA, auxEdadB;

		Perrito* pPerritoA = (Perrito*) perritoA;
		Perrito* pPerritoB = (Perrito*) perritoB;

		perrito_getId(pPerritoA, &auxEdadA);
		perrito_getId(pPerritoB, &auxEdadB);

		if(auxEdadA>auxEdadB)
		{
			return 1;
		}
		else
		{
			if (auxEdadB>auxEdadA)
			{
				return -1;
			}
		}
	}
	return -2;
}

int perrito_orderByRaza(void* perritoA, void* perritoB)
{
	if(perritoA!=NULL && perritoB!=NULL)
	{
		char auxRazaA[128], auxRazaB[128];

		Perrito *pPerritoA = (Perrito*) perritoA;
		Perrito *pPerritoB = (Perrito*) perritoB;

		perrito_getRaza(pPerritoA, auxRazaA);
		perrito_getRaza(pPerritoB, auxRazaB);

		return strcmp(auxRazaA, auxRazaB);
	}
	return -2;
}

void perrito_listOne(Perrito* perrito)
{
	int auxId, auxEdad;
	char auxNombre[128], auxRaza[128];

	perrito_getId(perrito, &auxId);
	perrito_getNombre(perrito, auxNombre);
	perrito_getEdad(perrito, &auxEdad);
	perrito_getRaza(perrito, auxRaza);

	printf("%-5d %-20s %-20d %-20s\n", auxId, auxNombre, auxEdad, auxRaza);
}

void perrito_filterRaza(LinkedList* llist)
{
	Perrito* pPerrito=NULL;
	char auxRaza[128];
	char getRaza[128];
	int lltam=ll_len(llist);

	getName(auxRaza, "Ingrese raza de perrito: ",
					"El nombre es muy largo...\n",
					"El nombre no puede contener caracteres especiales...\n",
					"El nombre no puede estar en blanco...\n",
					128);

	printLine("LISTA DE PERRITOS");
	printf("\nOrdenado por: %s", auxRaza);
	printf("\n\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Edad", "Raza");
	printLine("");

	for(int i=0; i<lltam; i++)
	{
		pPerrito=(Perrito*) ll_get(llist, i);

		if(perrito_getRaza(pPerrito, getRaza)==0)
		{
			if (*auxRaza==*getRaza)
			{
				perrito_listOne(pPerrito);
			}
		}
	}
}

void perrito_filterEdad(LinkedList* llist)
{
	Perrito* pPerrito=NULL;
	int auxEdad;
	int getEdad;
	int lltam=ll_len(llist);

	auxEdad=getInt("Ingrese la edad del perrito: ", "Error. Ingrese una edad valida: ", 0, 99);

	printLine("LISTA DE PERRITOS");
	printf("\nOrdenado por: %d años de edad.", auxEdad);
	printf("\n\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Edad", "Raza");
	printLine("");

	for(int i=0; i<lltam; i++)
	{
		pPerrito=(Perrito*) ll_get(llist, i);

		if(perrito_getEdad(pPerrito, &getEdad)==0)
		{
			if (auxEdad==getEdad)
			{
				perrito_listOne(pPerrito);
			}
		}
	}
}

int ll_getLastId(LinkedList* llist)
{
	int lltam;
	int lastId;

	if(llist!=NULL)
	{
		lltam=ll_len(llist);
		lastId=-1;

		for(int i=0; i<lltam; i++)
		{
			Perrito* perrito=ll_get(llist, i);

			if(perrito!=NULL)
			{
				int auxId;
				perrito_getId(perrito, &auxId);

				if(auxId>lastId)
				{
					lastId=auxId;
				}
			}
		}
		return lastId;
	}
	return 1;
}

