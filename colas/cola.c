#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "cola.h"

/*////////////////////////////////
//                              //
//    Javier Hernández Santos   //
//          EDA I               //
//                              //
////////////////////////////////*/


int 
colaCreaVacia(Cola *c)
{
	
    if (c == NULL)
		return -1;
		
	else {
		
		c->frente = c->fondo = NULL;
		return 0;
		
	}
	
} //Fin de funcion colaCreaVacia()

int 
colaVacia (Cola *c)
{
	
    if (c == NULL)
		return -1;
		
	return (c->frente == NULL && c->fondo == NULL);

} //Fin de funcion colaVacia()

int 
colaInserta (tipoElemento elemento, Cola *c)
{
	tipoCelda *aux;
	
    if (c == NULL)
		return -1;
		
	else {
		
		aux = malloc (sizeof(tipoCelda));
		
		if (aux == NULL)
			return -2;
			
		aux->elemento = elemento;
		aux->sig = NULL;
		
		if (c->fondo == NULL)
			c->fondo = c->frente = aux;
			
		else {
			
			c->fondo = c->fondo->sig = aux;
			
		}
		
		return 0;
	}      
	
} //Fin de funcion colaInserta()

tipoElemento 
colaSuprime (Cola *c)
{
	
	tipoCelda *aBorrar;
	tipoElemento elemento;
	
    if (c == NULL)
		return -1;
		
	else if (c->frente == NULL)
		return -2;
		
	else {
		
		aBorrar = c->frente;
		elemento = aBorrar->elemento;
		
		if (c->frente == c->fondo) 
			c->fondo = c->frente = NULL;
	
		else
			c->frente=aBorrar->sig;

		free (aBorrar);
		return elemento;
	}
	
} //Fin de funcion colaSuprime()