#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "inputs.h"
#include "functions.h"

int main(void) {

	setbuf(stdout, NULL);

	int opcion = 0;
	int flagListaCargada=0;

	LinkedList* listaPerritos = ll_newLinkedList();

	do{
		printLine("MENU");
		printf("1. Cargar los datos de los perritos desde el archivo data.csv (modo texto)\n"
			  "2. Listar los perritos de manera ascendente\n"
			  "3. Calcular cantidad de comida\n"
			  "3. Salir");
		printLine("");

		opcion=getInt("\nIngrese una opcion (1-8): ", "\nError. Ingrese una opcion (1-8): ", 1, 8);

		switch(opcion)
		{
			case 1:
				if(flagListaCargada==0)
				{
					if(listaPerritos!=NULL && perritos_loadFromText("src//perritos.csv",listaPerritos)==0)
					{
						printf("\nSe han cargado los datos exitosamente...\n");
						flagListaCargada=1;
					}
					else
					{
						printf("\nError al cargar los datos...\n");
					}
					system("pause");
				}
				break;
			case 2:
				if(flagListaCargada==1)
				{
					if(listaPerritos!=NULL || perritos_listAll(listaPerritos, 0)==1)
					{
						printf("\nError al listar los datos...\n");
					}
					system("pause");
				}
				else
				{
					printf("La lista no fue cargada previamente...");
				}
				break;
			case 3:
				if(flagListaCargada==1)
				{
					if(listaPerritos!=NULL || perritos_calculateFood(listaPerritos)==1 || perritos_listAll(listaPerritos, 1)==1)
					{
						printf("\nError al listar los datos...\n");
					}
					system("pause");
				}
				break;
		}
	}while(opcion!=6);

	return EXIT_SUCCESS;
}
