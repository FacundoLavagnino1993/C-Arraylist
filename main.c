#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#define T 10
#include"ArrayList.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
	// Generamos personas para cargarlas en el Arraylist.
	ePersona* PersonaUno=(ePersona*)malloc(sizeof(ePersona));
	sprintf(PersonaUno->nombre,"Jose");
	PersonaUno->edad=20;
	
	ePersona* PersonaDos=(ePersona*)malloc(sizeof(ePersona));
	sprintf(PersonaDos->nombre,"Julio");
	PersonaDos->edad=21;
	
	ePersona* PersonaTres=(ePersona*)malloc(sizeof(ePersona));
	sprintf(PersonaTres->nombre,"Matias");
	PersonaTres->edad=22;
	
	ePersona* PersonaCuatro=(ePersona*)malloc(sizeof(ePersona));
	sprintf(PersonaCuatro->nombre,"Damian");
	PersonaCuatro->edad=23;
	
	printf("Nombre y edad de personas:\n\n");
	printPersona(PersonaUno);
	printPersona(PersonaDos);
	printPersona(PersonaTres);
	printPersona(PersonaCuatro);
	printf("________________________________________\n\n");
	
	//------------------------------------------------------------
	
	printf("Cargamos el ArrayList...\n");
	ArrayList* lista=al_newArrayList();
	lista->add(lista,PersonaUno);
	lista->add(lista,PersonaDos);
	lista->add(lista,PersonaTres);
	lista->add(lista,PersonaCuatro);
	printArrayListPersonas(lista);
	ArrayList* listaDos=al_clone(lista);
	printf("________________________________________\n\n");
	
	//-----------------------------------------------------------
	
	printf("Removemos el nombre del indice 3:\n");
	lista->remove(lista,2);
	printArrayListPersonas(lista);
	printf("________________________________________\n\n");
	
	//-----------------------------------------------------------
	
	printf("Contiene algun dato de la Persona del indice 1?\n");
	if(lista->contains(lista,PersonaUno))
	{
		printf("Si.\n");
		printPersona(PersonaUno);
	}
	else
	{
		printf("No contiene datos.\n");
	}
	
	printf("Contiene algun dato de la persona del indice 3?\n");
	if(lista->contains(lista,PersonaTres))
	{
		printf("Si.\n");
		printPersona(PersonaUno);
	}
	else
	{
		printf("No contiene datos.\n");
	}	
	printf("________________________________________\n\n");
	
	//-------------------------------------------------------------
	
	printf("Agregamos los datos de la Persona del indice 3 en la posicion 2.\n");
	lista->set(lista,1,PersonaTres);
	printArrayListPersonas(lista);
	printf("________________________________________\n\n");
	
	//--------------------------------------------------------------
	
	printf("Clonamos el ArrayList.\n");
	
	printf("Mostramos la lista original:\n");
	printArrayListPersonas(lista);
	printf("Mostramos la lista clonada:\n");
	printArrayListPersonas(listaDos);
	printf("________________________________________\n\n");
	
	//---------------------------------------------------------------
	
	printf("Hacemos push de la Persona 2 en la posicion 1\n");
  	lista->push(lista,1,PersonaDos);
  	printArrayListPersonas(lista);
	printf("________________________________________\n\n");
	
	//--------------------------------------------------------------
	
	printf("Hacemos pop de Persona 2 en la posicion 1\n");
    ePersona* p1Aux = lista->pop(lista,1);
    printArrayListPersonas(lista);
    printf("________________________________________\n\n");
    
    //---------------------------------------------------------------
	
	printf("Clear array\n");
    lista->clear(lista);
    printArrayListPersonas(lista);
 	printf("________________________________________\n\n");
 	
 	//---------------------------------------------------------------
 	
  	printf("\r\nEsta vacio?\r\n");
  	if(lista->isEmpty(lista))
     	 printf("SI\n");
  	else
     	 printf("NO\n");
	printf("________________________________________\n\n");
	
	//---------------------------------------------------------------
	//printf("Libero memoria y termino\n");
  	free(PersonaUno);
  	free(PersonaDos);
  	free(PersonaTres);
  	free(PersonaCuatro);      
  	lista->deleteArrayList(lista);
  	listaDos->deleteArrayList(listaDos);
  	
  	system("pause");
	return 0;
}
