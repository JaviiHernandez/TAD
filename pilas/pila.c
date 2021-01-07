#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pila.h"

/*////////////////////////////////
//                              //
//    Javier Hernández Santos   //
//          EDA I               //
//                              //
////////////////////////////////*/


int 
pilaCreaVacia(Pila *p)
{
	
    if (p == NULL)
    	return -1;

    else {

    	*p = NULL;
    	return 0;
	}
	
} //Fin de funcion pilaCreaVacia()

int 
pilaVacia(Pila *p)
{
	
    if (p == NULL)
    	return -1;

    else if (*p == NULL)
    	return 1;

    else
    	return 0; 
    	
} //Fin de funcion pilaVacia()

int 
pilaInserta(Pila *p, tipoElemento elemento)
{
	
	tipoCelda *aux;
	
    if (p == NULL)
    	return -1;

    else {
    	
    	aux = malloc (sizeof(tipoCelda));
    	
    	if (aux == NULL)
    		return -2;
    	
    	aux->elemento = elemento;
    	
    	if (*p == NULL)

    		aux->sig = NULL;

		else

			aux->sig = *p;
			
		*p = aux;
		
		return 0;
	}
    
    
} //Fin de funcion pilaInserta()

tipoElemento 
pilaSuprime(Pila *p)
{
	
	tipoCelda *aBorrar;
	tipoElemento elemento;
	
    if (p == NULL)
    	return -1;
    	
    else if (*p == NULL)
		return -2;
		
	else {
		
    	aBorrar = *p;
    	elemento = aBorrar->elemento;
    	*p = aBorrar->sig;
    	
    	free (aBorrar);
    	return elemento;
	}
    
} //Fin de funcion pilaSuprime()

