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
	int flagRacionesCargadas=0;
	int flagFiltroCargado=0;

	LinkedList* listaPerritos = ll_newLinkedList();
	LinkedList* listaFiltrada = NULL;

	do{
		printLine("MENU");
		printf("1. Cargar los datos de los perritos desde el archivo perritos.csv (modo texto)\n"
			  "2. Listar los perritos de manera ascendente\n"
			  "3. Calcular cantidad de comida\n"
			  "4. Listar los perritos con raciones de comida\n"
			  "5. Filtrar Galgos flaquitos\n"
			  "6. Guardar Galgos flaquitos en galgosFlaquitos.csv\n"
			  "7. Salir");
		printLine("");

		opcion=getInt("\nIngrese una opcion (1-7): ", "\nError. Ingrese una opcion (1-7): ", 1, 7);

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
				}
				system("pause");
				break;
			case 2:
				if(flagListaCargada==1)
				{
					if(listaPerritos!=NULL)
					{
						printf("\nEspere mientras se ordena la lista...\n");
						if(perritos_orderByName(listaPerritos)==0)
						{
							perritos_listAll(listaPerritos, 0);
						}
					}
					else
					{
						printf("\nError al listar los datos...\n");
					}
				}
				else
				{
					printf("La lista no fue cargada previamente...\n");
				}
				system("pause");
				break;
			case 3:
				if(flagListaCargada==1)
				{
					if(listaPerritos!=NULL && perritos_calculateFood(listaPerritos)==0)
					{
						flagRacionesCargadas=1;
						printf("\nRaciones calculadas exitosamente...\n");
					}
				}
				else
				{
					printf("La lista no fue cargada previamente...\n");
				}
				system("pause");
				break;
			case 4:
				if(flagListaCargada==1)
				{
					if(flagRacionesCargadas==1)
					{
						if(listaPerritos==NULL || perritos_listAll(listaPerritos, 1)==1)
						{
							printf("\nError al listar los datos...\n");
						}
					}
					else
					{
						printf("\nLas raciones de comida no fueron calculadas previamente...\n");
						if(verify("\nDesea calcularlas? ('s'): ")==0)
						{
							if (perritos_calculateFood(listaPerritos)==0)
							{
								flagRacionesCargadas=1;
								printf("\nRaciones calculadas exitosamente...\n");
							}
						}
						else
						{
							printf("\nVolviendo al menu...\n");
						}
					}
				}
				else
				{
					printf("La lista no fue cargada previamente...\n");
				}
				system("pause");
				break;
			case 5:
				if(flagListaCargada==1)
				{
					if(flagRacionesCargadas==1)
					{
						if(flagFiltroCargado==0)
						{
							if(listaPerritos!=NULL)
							{
								listaFiltrada=perritos_filtrarGalgos(listaPerritos);
								flagFiltroCargado=1;
								printf("\nGalgos filtrados exitosamente...\n");
							}
						}
					}
					else
					{
						printf("\nLas raciones de comida no fueron calculadas previamente...\n");
						if(verify("\nDesea calcularlas? ('s'): ")==0)
						{
							if (perritos_calculateFood(listaPerritos)==0)
							{
								flagRacionesCargadas=1;
								printf("\nRaciones calculadas exitosamente...\n");
							}
						}
						else
						{
							printf("\nVolviendo al menu...\n");
						}
					}
				}
				else
				{
					printf("La lista no fue cargada previamente...\n");
				}
				system("pause");
				break;
			case 6:
				if(flagListaCargada==1)
				{
					if(flagRacionesCargadas==1)
					{
						if(flagFiltroCargado==1)
						{
							if(listaPerritos!=NULL && perritos_saveGalgosText("src//galgosFlaquitos.csv", listaFiltrada)==0)
							{
								printf("\nGalgos guardados exitosamente...\n");
							}
						}
						else
						{
							printf("\nLos filtros no fueron aplicados previamente...\n");
							if(verify("\nDesea filtrar la lista? ('s'): ")==0)
							{
								listaFiltrada=perritos_filtrarGalgos(listaPerritos);
								flagFiltroCargado=1;
								printf("\nGalgos filtrados exitosamente...\n");
							}
							else
							{
								printf("\nVolviendo al menu...\n");
							}
						}
					}
					else
					{
						printf("\nLas raciones de comida no fueron calculadas previamente...\n");
						if(verify("\nDesea calcularlas? ('s'): ")==0)
						{
							if (perritos_calculateFood(listaPerritos)==0)
							{
								flagRacionesCargadas=1;
								printf("\nRaciones calculadas exitosamente...\n");
							}
						}
						else
						{
							printf("\nVolviendo al menu...\n");
						}
					}
				}
				else
				{
					printf("La lista no fue cargada previamente...\n");
				}
				system("pause");
				break;
			case 7:
				if(verify("\nDesea salir del programa? ('s'): ")==0)
				{
					if(listaPerritos!=NULL)
					{
						ll_deleteLinkedList(listaPerritos);
					}
					printf("\nSaliendo del programa...\n");
				}
				break;
		}
	}while(opcion!=7);

	return EXIT_SUCCESS;
}
