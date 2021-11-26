#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Perritos.h"
#include "LinkedList.h"

Perrito* perrito_new(){
	Perrito* employee = NULL;
	employee = (Perrito*)malloc(sizeof(Perrito));
	return employee;
}

Perrito* perrito_newParametros(char* idStr,char* nombreStr,char* pesoStr,char* edadStr,char* razaStr)
{
	Perrito* perrito = NULL;
	perrito = perrito_new();

	if(perrito!=NULL && idStr!=NULL && nombreStr!=NULL && pesoStr!=NULL && edadStr!=NULL && razaStr!=NULL)
	{
		perrito_setId(perrito, atoi(idStr));
		perrito_setNombre(perrito, nombreStr);
		perrito_setPeso(perrito, atof(pesoStr));
		perrito_setEdad(perrito, atoi(edadStr));
		perrito_setRaza(perrito, razaStr);
	}
	return perrito;
}

void perrito_delete(Perrito* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}

int perrito_setId(Perrito* this,int id)
{
	if(this!=NULL)
	{
		this->id=id;
		return 0;
	}
	return -1;
}

int perrito_getId(Perrito* this,int* id)
{
	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		return 0;
	}
	return -1;
}

int perrito_setNombre(Perrito* this,char* nombre)
{
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre, nombre);
		return 0;
	}
	return -1;
}

int perrito_getNombre(Perrito* this,char* nombre)
{
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre, this->nombre);
		return 0;
	}
	return -1;
}

int perrito_setPeso(Perrito* this,float peso)
{
	if(this!=NULL)
	{
		this->peso=peso;
		return 0;
	}
	return -1;
}

int perrito_getPeso(Perrito* this,float* peso)
{
	if(this!=NULL && peso!=NULL)
	{
		*peso=this->peso;
		return 0;
	}
	return -1;
}

int perrito_setEdad(Perrito* this,int edad)
{
	if(this!=NULL)
	{
		this->edad=edad;
		return 0;
	}
	return -1;
}

int perrito_getEdad(Perrito* this,int* edad)
{
	if(this!=NULL && edad!=NULL)
	{
		*edad=this->edad;
		return 0;
	}
	return -1;
}

int perrito_setRaza(Perrito* this,char* raza)
{
	if(this!=NULL && raza!=NULL)
	{
		strcpy(this->raza, raza);
		return 0;
	}
	return -1;
}

int perrito_getRaza(Perrito* this,char* raza)
{
	if(this!=NULL && raza!=NULL)
	{
		strcpy(raza, this->raza);
		return 0;
	}
	return -1;
}

int perrito_setCantidadComidaRacion(Perrito* this,float cantidadComidaRacion)
{
	if(this!=NULL)
	{
		this->cantidadComidaRacion=cantidadComidaRacion;
		return 0;
	}
	return -1;
}

int perrito_getCantidadComidaRacion(Perrito* this,float* cantidadComidaRacion)
{
	if(this!=NULL && cantidadComidaRacion!=NULL)
	{
		*cantidadComidaRacion=this->peso;
		return 0;
	}
	return -1;
}
