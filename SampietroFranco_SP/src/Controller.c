#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Perritos.h"
#include "parser.h"
#include "functions.h"
#include "inputs.h"

int controller_loadFromText(char* path , LinkedList* llist)
{
	FILE* pFile = fopen(path, "r");

	if(pFile!=NULL && llist!=NULL)
	{
		parser_PerritoFromText(pFile, llist);
		return 0;
	}
	return 1;
}

int controller_loadFromBinary(char* path , LinkedList* llist)
{
	FILE* pFile = fopen(path, "rb");

	if(pFile!=NULL && llist!=NULL)
	{
		parser_PerritoFromBinary(pFile, llist);
		return 0;
	}
	return 1;
}

/*
int controller_addPerrito(LinkedList* llist, int* ultimoId)
{
	if(llist!=NULL)
	{
		Perrito* pPerrito=NULL;

		int auxId=*ultimoId+1;
		char auxIdParse[10];
		char auxNombre[128];
		int auxEdad;
		char auxEdadParse[10];
		char auxRaza[128];

		printLine("NUEVO PERRITO");

		sprintf(auxIdParse, "%d", auxId);

		getName(auxNombre, "Ingrese nombre de perrito: ",
			"El nombre es muy largo...\n",
			"El nombre no puede contener caracteres especiales...\n",
			"El nombre no puede estar en blanco...\n",
			128);

		auxEdad=getInt("Ingrese edad: ", "Error. Ingrese edad: ", 0, 9999);
		sprintf(auxEdadParse, "%d", auxEdad);

		getName(auxRaza, "Ingrese raza de perrito: ",
					"El nombre es muy largo...\n",
					"El nombre no puede contener caracteres especiales...\n",
					"El nombre no puede estar en blanco...\n",
					128);

		printf("\nEmpleado a agregar:\n\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Horas trabajadas", "Salario");
		printf("%-5s %-20s %-20s %-20s\n", auxIdParse, auxNombre, auxEdadParse, auxRaza);
		printLine("");
		if(verify("Agregar empleado? ('s'): ")==0)
		{
			pPerrito=perrito_newParametros(auxIdParse, auxNombre, auxEdadParse, auxRaza);
			ll_add(llist, pPerrito);
			*ultimoId+=1;

			if(pPerrito!=NULL)
			{
				free(pPerrito);
				pPerrito=NULL;
			}
			return 0;
		}
		if(pPerrito!=NULL)
		{
			free(pPerrito);
			pPerrito=NULL;
		}
	}
    return 1;
}

int controller_editPerrito(LinkedList* llist, int ultimoId)
{
	if(llist!=NULL)
	{
		int opcion=getInt("Ingrese ID del empleado a modificar: ", "Error. Ingrese ID del perrito a modificar: ", 0, ultimoId);

		Perrito* pPerritoAModificar=NULL;
		pPerritoAModificar=perrito_getById(llist, opcion);

		Perrito* pAuxPerrito=NULL;
		pAuxPerrito=perrito_new();

		if(pPerritoAModificar!=NULL && pAuxPerrito!=NULL)
		{
			pAuxPerrito=pPerritoAModificar;

			int auxId, auxEdad;
			char auxNombre[128], auxRaza[128];

			perrito_getId(pAuxPerrito, &auxId);
			perrito_getNombre(pAuxPerrito, auxNombre);
			perrito_getEdad(pAuxPerrito, &auxEdad);
			perrito_getRaza(pAuxPerrito, &auxRaza);

			printf("\nPerrito a modificar:\n\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Edad", "Raza");
			perrito_listOne(pAuxPerrito);
			printLine("");

			do
			{
				printf("\nPerrito a modificar:\n\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Edad", "Raza");
				perrito_listOne(pAuxPerrito);
				printLine("");
				printf("1. Modificar nombre\n2. Modificar edad\n3. Modificar raza\n4. Salir");
				printLine("");
				opcion=getInt("\nIngrese una opcion (1-4): ", "\nError. Ingrese una opcion (1-4): ", 1, 4);
				switch(opcion)
				{
					case 1:
						getName(auxNombre, "Ingrese nombre de perrito: ",
							"El nombre es muy largo...\n",
							"El nombre no puede contener caracteres especiales...\n",
							"El nombre no puede estar en blanco...\n",
							128);
						printf("\Perrito luego de la modificacion:\n\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Edad", "Raza");
						printf("%-5d %-20s %-20d %-20d\n", auxEmpleadoId, auxEmpleadoNombre, auxEmpleadoHoras, auxEmpleadoSueldo);
						printLine("");

						if(verify("Confirmar cambios? ('s'): ")==0)
						{
							perrito_setNombre(pAuxPerrito, auxEmpleadoNombre);
							pPerritoAModificar=pAuxPerrito;
						}
					break;
					case 2:
						auxEdad=getInt("Ingrese edad: ", "Error. Ingrese edad: ", 0, 9999);
						printf("\Perrito luego de la modificacion:\n\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Edad", "Raza");
						printf("%-5d %-20s %-20d %-20d\n", auxEmpleadoId, auxEmpleadoNombre, auxEmpleadoHoras, auxEmpleadoSueldo);
						printLine("");
						if(verify("Confirmar cambios? ('s'): ")==0)
						{
							perrito_setHorasTrabajadas(pAuxPerrito, auxEmpleadoHoras);
							pPerritoAModificar=pAuxPerrito;
						}
					break;
					case 3:
						getName(auxRaza, "Ingrese nombre de perrito: ",
											"El nombre es muy largo...\n",
											"El nombre no puede contener caracteres especiales...\n",
											"El nombre no puede estar en blanco...\n",
											128);
						printf("\Perrito luego de la modificacion:\n\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Edad", "Raza");
						printf("%-5d %-20s %-20d %-20d\n", auxEmpleadoId, auxEmpleadoNombre, auxEmpleadoHoras, auxEmpleadoSueldo);
						printLine("");
						if(verify("Confirmar cambios? ('s'): ")==0)
						{
							perrito_setSueldo(pAuxPerrito, auxEmpleadoSueldo);
							pPerritoAModificar=pAuxPerrito;
						}
					break;
					case 4:
						printLine("");
						if(verify("Salir al menu principal? ('s'): ")==0)
						{
							printf("\nRegresando al menu principal...\n");
						}
						else
						{
							opcion=0;
						}
					break;
				}
			}while(opcion!=4);

			if(pAuxPerrito!=NULL)
			{
				free(pAuxPerrito);
				pAuxPerrito=NULL;
			}
			return 0;
		}
	}
    return 1;
}

int controller_removeperrito(LinkedList* pArrayListperrito, int ultimoId)
{
	if(pArrayListperrito!=NULL)
	{
		perrito *empleadoABorrar=NULL;

		int opcion=getInt("Ingrese ID del empleado a remover: ", "Error. Ingrese ID del empleado a remover: ", 0, ultimoId);
		int index;

		empleadoABorrar=perrito_getById(pArrayListperrito, opcion);
		index=ll_indexOf(pArrayListperrito, empleadoABorrar);

		if(empleadoABorrar!=NULL)
		{
			printf("\nEmpleado a remover:\n\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Horas trabajadas", "Salario");
			perrito_listOne(empleadoABorrar);
			printLine("");
			if(verify("Confirmar baja? ('s'): ")==0)
			{
				ll_remove(pArrayListperrito, index);
				return 0;
			}
		}
	}
    return 1;
}
*/

int controller_ListPerritos(LinkedList* llist)
{
	if(llist!=NULL)
	{
		Perrito* pPerrito=NULL;
		int lltam=ll_len(llist);

		printLine("LISTA DE PERRITOS");
		printf("\n\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Edad", "Raza");
		printLine("");
		for(int i=0; i<lltam; i++)
		{
			pPerrito=(Perrito*) ll_get(llist, i);
			perrito_listOne(pPerrito);
		}
		printLine("");

		if(pPerrito!=NULL)
		{
			free(pPerrito);
			pPerrito=NULL;
		}
		return 0;
	}
    return 1;
}

int controller_sortPerritos(LinkedList* llist)
{
	if(llist!=NULL)
	{
		int option;
		int (*compareFunction)(void*, void*) = NULL;

		do{
			printLine("ORDENAR PERRITOS");
			printf("1. Por ID (ascendente)\n2. Por ID (descendente)\n3. Por nombre (ascendente)\n4. Por nombre (descendente)\n5. Por edad (ascendente)\n6. Por edad (descendente)\n7. Atras");
			printLine("");
			option=getInt("\nIngrese una opcion (1-9): ", "Error. Ingrese una opcion valida (1-9): ", 1, 7);

			switch(option)
			{
				case 1:
					compareFunction=perrito_orderById;
					printLine("");
					printf("\nEspere un momento mientras se realiza el ordenamiento...\n...\n");
					if(ll_sort(llist, compareFunction, 1)==0)
					{
						printf("\nLa lista fue ordenada de manera exitosa...\n");
					}
					else
					{
						printf("\nError. La lista no pudo ser ordenada...\n");
					}
					break;
				case 2:
					compareFunction=perrito_orderById;
					printLine("");
					printf("\nEspere un momento mientras se realiza el ordenamiento...\n...\n");
					if(ll_sort(llist, compareFunction, 0)==0)
					{
						printf("\nLa lista fue ordenada de manera exitosa...\n");
					}
					else
					{
						printf("\nError. La lista no pudo ser ordenada...\n");
					}
					break;
				case 3:
					compareFunction=perrito_orderByName;
					printLine("");
					printf("\nEspere un momento mientras se realiza el ordenamiento...\n...\n");
					if(ll_sort(llist, compareFunction, 1)==0)
					{
						printf("\nLa lista fue ordenada de manera exitosa...\n");
					}
					else
					{
						printf("\nError. La lista no pudo ser ordenada...\n");
					}
					break;
				case 4:
					compareFunction=perrito_orderByName;
					printLine("");
					printf("\nEspere un momento mientras se realiza el ordenamiento...\n...\n");
					if(ll_sort(llist, compareFunction, 0)==0)
					{
						printf("\nLa lista fue ordenada de manera exitosa...\n");
					}
					else
					{
						printf("\nError. La lista no pudo ser ordenada...\n");
					}
					break;
				case 5:
					compareFunction=perrito_orderByEdad;
					printLine("");
					printf("\nEspere un momento mientras se realiza el ordenamiento...\n...\n");
					if(ll_sort(llist, compareFunction, 1)==0)
					{
						printf("\nLa lista fue ordenada de manera exitosa...\n");
					}
					else
					{
						printf("\nError. La lista no pudo ser ordenada...\n");
					}
					break;
				case 6:
					compareFunction=perrito_orderByEdad;
					printLine("");
					printf("\nEspere un momento mientras se realiza el ordenamiento...\n...\n");
					if(ll_sort(llist, compareFunction, 0)==0)
					{
						printf("\nLa lista fue ordenada de manera exitosa...\n");
					}
					else
					{
						printf("\nError. La lista no pudo ser ordenada...\n");
					}
					break;
				case 7:
					if(verify("\nDesea salir al menu principal? ('s'): ")==0)
					{
						printf("\nVolviendo al menu principal...\n");
						return 0;
					}
					else
					{
						option=0;
					}
					break;
			}
		}while(option!=7);
	}
    return 1;
}

int controller_saveAsText(char* path , LinkedList* llist)
{
	if(path!=NULL && llist!=NULL)
	{
		FILE* pFile = fopen(path, "w");
		Perrito* pPerrito=NULL;

		int auxId, auxEdad;
		char auxNombre[128], auxRaza[128];

		int lltam=ll_len(llist);

		fprintf(pFile, "%s\n", "id,nombre,edad,raza");
		for(int i=0; i<lltam; i++)
		{
			pPerrito=(Perrito*) ll_get(llist, i);

			perrito_getId(pPerrito, &auxId);
			perrito_getNombre(pPerrito, auxNombre);
			perrito_getEdad(pPerrito, &auxEdad);
			perrito_getRaza(pPerrito, auxRaza);

			fprintf(pFile, "%d,%s,%d,%s\n", auxId, auxNombre, auxEdad, auxRaza);
		}
		fclose(pFile);
		pFile=NULL;
		return 0;
	}
    return 1;
}

int controller_saveAsBinary(char* path , LinkedList* llist)
{
	if(path!=NULL && llist!=NULL)
	{
		FILE* pFile = fopen(path, "wb");
		Perrito* pPerrito=NULL;

		int lltam=ll_len(llist);

		for(int i=0; i<lltam; i++)
		{
			pPerrito=(Perrito*) ll_get(llist, i);
			fwrite(pPerrito, sizeof(Perrito), 1, pFile);
		}
		fclose(pFile);
		pFile=NULL;
		return 0;
	}
    return 1;
}

int controller_filterBy(LinkedList* llist)
{
	int option;
	void (*pFilterFunc)(LinkedList*) = NULL;

	if(llist!=NULL)
	{
		do{
			pFilterFunc=NULL;

			printLine("FILTRAR PERRITOS");
			printf("1. Por Edad\n2. Por Raza\n3. Atras");
			printLine("");
			option=getInt("\nIngrese una opcion (1-3): ", "\nError. Ingrese una opcion valida (1-3): ", 1, 3);

			switch(option)
			{
				case 1:
					pFilterFunc=perrito_filterEdad;
					break;
				case 2:
					pFilterFunc=perrito_filterRaza;
					break;
				case 3:
					if(verify("\nDesea salir al menu? ('s'): ")==0)
					{
						printf("\nSaliendo al menu principal...");
						system("pause");
					}
					break;
			}

			if(pFilterFunc!=NULL)
			{
				pFilterFunc(llist);
				printLine("");
				system("pause");
			}
		}
		while(option!=3);

		return 0;
	}
    return 1;
}
