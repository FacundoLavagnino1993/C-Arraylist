#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#define T 10
#include"ArrayList.h"

void printPersona(ePersona* p)
{
	printf("Nombre:%s\nEdad:%d\n",p->nombre,p->edad);
}

ArrayList* al_newArrayList(void)
{
	ArrayList* p;
	p=(ArrayList*)malloc(sizeof(ArrayList));
	if(p==NULL)
	{
		printf("Error...\n");
		exit(1);
	}
	
	p->size=0;
	p->reservedSize=T;
	p->pElements=(void*)malloc(sizeof(void*)*T);
	if(p->pElements==NULL)
	{
		printf("Error...\n");
		exit(1);
	}
	
	//Le asignamos a los punteros la direccion de memoria de las funciones correspondientes.
	
	p->len=al_len;
	p->isEmpty=al_isEmpty;
	p->add=al_add;
	p->contains=al_contains;
	p->indexof=al_indexOf;
	p->set=al_set;
	p->get=al_get;
	p->remove = al_remove;
	p->push = al_push;
	p->pop = al_pop;
	p->clear = al_clear;
	p->deleteArrayList = al_deleteArrayList;
	p->clone = al_clone;
	
	return p;
	
}

int al_len(ArrayList* self)
{
	int tam;
	tam = self->size;
	return tam;	
}



int al_isEmpty(ArrayList* self)
{
	if(self->size == 0)
	{
		return 1;
	}else{
				return 0;
		 }
}



void al_add(ArrayList* self, void* element)
{
	if(self->size == self->reservedSize)
	{
		reziseup(self);		
	}
	
	self->pElements[self->size] = element;
	self->size++;
}



void reziseup(ArrayList* self)
{
	self->pElements = (void*)realloc(self->pElements, sizeof(void*)* (self->reservedSize + T));
	
	if(self->pElements == NULL)
	{
		printf("No se pudo asignar memoria \n\n");
		exit(1);
	}
	self->reservedSize = self->reservedSize + T;
}



int al_contains(ArrayList* self, void* element)
{
	int i;
	ePersona* p8;
	p8 = (ePersona*)malloc(sizeof(ePersona));
	
	if(p8 == NULL)
	{
		printf("Error \n\n\n");
		exit(1);
	}
	
	for(i = 0 ; i < self->size ; i++)
	{
		p8 = self->pElements[i];
		if(p8 == element)
		{
			return 1;
		}
	}
	return 0;
}



int al_indexOf(ArrayList* self, void* element)
{
	int i;
	

	for(i = 0 ; i < self->size ; i++)
	{
		if(self->pElements[i] == element)
		{
			return i;
		}
	}
	return -1;
}



void al_set(ArrayList* self, int index, void* element)
{
	if(index < self->size)
	{
		strcpy(self->pElements[index], element);
		
	}else{
				printf("No se existe el indice %d \n\n\n", index);
		 }
}



void* al_get(ArrayList* self, int index)
{
		
	if(index < self->size)
	{
		return  self->pElements[index];
		 		
	}else{
				return NULL;
		 }
}



void al_remove(ArrayList* self, int index)
{
	int i, tam = self->size - 1;
	for(i = index ; i < tam ; i++)
	{
		self->pElements[i] = self->pElements[i + 1];
	}
	
	self->pElements[self->size - 1] = NULL;
	self->size = self->size - 1;
}



void al_push(ArrayList* self, int index, void* element)
{
	expand(self, index);
	self->pElements[index] = element;
	self->size = self->size + 1;
}



void expand(ArrayList* self, int index)
{
	int i;
	if(self->size == self->reservedSize)
	{
		reziseup(self);
	}
	
	for(i = self->size - 1 ; i >= index ; i--)
	{
		self->pElements[i+1] = self->pElements[i];
	}
	self->pElements[index] = NULL;
}



void* al_pop(ArrayList* self, int index)
{
	void* k;
	if(index < self->size)
	{
		k = self->pElements[index];
		contract(self, index);
		self->size = self->size - 1;
		return k;
	}
	return NULL;
}



void contract(ArrayList* self, int index)
{
	int i;
	for(i = index ; i < self->size - 1; i++)
	{
		self->pElements[i] = self->pElements[i + 1];
	}
	self->pElements[self->size - 1] = NULL;
}



void al_clear(ArrayList* self)
{
	int i;
	for(i = 0 ; i < self->size ; i++)
	{
			self->pElements[i] = NULL;	
	}
	self->size = 0;
}

void al_deleteArrayList(ArrayList* self)
{
	free(self->pElements);
	free(self);
}

void printArrayListPersonas(ArrayList* lista)
{
  int i=0;
  for(i=0;i<lista->len(lista);i++)
  {
      ePersona* pAux = lista->get(lista,i);
      printf("%d)\n",i+1);
      printPersona(pAux);                                
  }    
}

ArrayList* al_clone(ArrayList* self)
{
	int i;
	ArrayList* cloneArray;
	cloneArray = al_newArrayList();
	
	cloneArray->size = self->size;
	cloneArray->reservedSize = self->reservedSize;
	
	cloneArray->pElements = (void*)malloc(sizeof(void*) * self->reservedSize);
	
	for(i = 0 ; i < cloneArray->size ; i++)
	{
		cloneArray->pElements[i] = self->pElements[i];
	}
	
	return cloneArray;
}
