#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"
#include "functions.h"
#include "inputs.h"

int main(void) {
		setbuf(stdout, NULL);

	    int opcion = 0;
	    int flagListaCargada=0;
	    int ultimoIdIngresado;

	    LinkedList* listaPerritos = ll_newLinkedList();

	    do{
	        printLine("MENU");
	        printf("1. Cargar los datos de los perritos desde el archivo data.csv (modo texto)\n"
				  "2. Cargar los datos de los perritos desde el archivo datab.csv (modo binario)\n"
				  "3. Listar perritos\n"
				  "4. Ordenar perritos\n"
	        	  "5. Filtrar perritos\n"
				  "6. Guardar los datos de los perritos en el archivo data.csv (modo texto)\n"
				  "7. Guardar los datos de los perritos en el archivo datab.csv (modo binario)\n"
				  "8. Salir");
			printLine("");

			opcion=getInt("\nIngrese una opcion (1-8): ", "\nError. Ingrese una opcion (1-8): ", 1, 8);

	        switch(opcion)
	        {
	            case 1:
	            	if(flagListaCargada==0)
	            	{
	                    if(listaPerritos!=NULL && controller_loadFromText("src//data.csv",listaPerritos)==0)
	                    {
	                    	printf("\nSe han cargado los datos exitosamente...\n");
	                    	ultimoIdIngresado=ll_getLastId(listaPerritos);
	                    	flagListaCargada=1;
	                    }
	                    else
	                    {
	                    	printf("\nError al cargar los datos...\n");
	                    }
	            	}
	            	else
	            	{
	            		printf("\nLa lista ya ha sido cargada...\n");
	            	}
	            	system("pause");
	                break;
	            case 2:
	            	if(flagListaCargada==0)
					{
						if(listaPerritos!=NULL && controller_loadFromBinary("src//datab.csv",listaPerritos)==0)
						{
							printf("\nSe han cargado los datos exitosamente...\n");
							ultimoIdIngresado=ll_getLastId(listaPerritos);
							flagListaCargada=1;
						}
						else
						{
							printf("\nError al cargar los datos...\n");
						}
					}
					else
					{
						printf("\nLa lista ya ha sido cargada...\n");
					}
	                system("pause");
	                break;
	            case 3:
	            	if(flagListaCargada==1)
					{
						if(listaPerritos!=NULL && controller_ListPerritos(listaPerritos)==1)
						{
							printf("\nError al cargar la lista...\n");
						}
					}
					else
					{
						printf("\nLa lista de empleados no fue cargada previamente...\n");
					}
					system("pause");
					break;
	            case 4:
					system("pause");
					break;
	            case 5:
	            	if(flagListaCargada==1)
					{
						if(listaPerritos!=NULL && controller_filterBy(listaPerritos)==1)
						{
							printf("\nError al cargar la lista...\n");
						}
					}
					else
					{
						printf("\nLa lista de empleados no fue cargada previamente...\n");
					}
					system("pause");
					break;
	            case 6:
	            	if(flagListaCargada==1)
					{
						if(listaPerritos!=NULL && controller_saveAsText("C:\\Users\\franc\\OneDrive\\Escritorio\\data.csv", listaPerritos)==0)
						{
							printf("\nLa lista fue guardada en texto exitosamente...\n");
						}
						else
						{
							printf("\nError al guardar la lista en texto...\n");
						}
					}
					else
					{
						printf("\nLa lista de empleados no fue cargada previamente...\n");
					}
					system("pause");
					break;
	            case 7:
	            	if(flagListaCargada==1)
					{
						if(listaPerritos!=NULL && controller_saveAsBinary("src//datab.csv", listaPerritos)==0)
						{
							printf("\nLa lista fue guardada en binario exitosamente...\n");
						}
						else
						{
							printf("\nError al guardar la lista en binario...\n");
						}
					}
					else
					{
						printf("\nLa lista de empleados no fue cargada previamente...\n");
					}
					system("pause");
					break;
	            case 8:
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
	    }while(opcion != 8);
	    return 0;

	return EXIT_SUCCESS;
}
