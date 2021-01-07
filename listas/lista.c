#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "lista.h"

/*////////////////////////////////
//                              //
//    Javier Hernández Santos   //
//          EDA I               //
//                              //
////////////////////////////////*/


int
creaVacia(Lista *l)
{
    if (l == NULL)
        return -2;

    else if (NULL == (l->raiz = l->ultimo = (tipoCelda *) malloc(sizeof(tipoCelda))))
        return -1;

    else {

        l->raiz->sig = NULL;
        return 0;

    }

} //Fin de funcion crearVacia()


int
vacia(Lista *l)
{
    if (l == NULL || l->raiz == NULL) 
        return -1;

    else if (l->raiz->sig == NULL)
        return 1;

    else
        return 0;

} //Fin de funcion vacia()


int
destruye(Lista *l)
{
    if (l == NULL || l->raiz == NULL) 
        return -1;

    else if (l->raiz->sig != NULL) 
        return -2;
    
    else {

        free(l->raiz);
        l->raiz = l->ultimo = NULL;
        return 0;

    }

} //Fin de funcion destruye()


void
imprime(Lista *l)
{
    tipoCelda *aImprimir;
    int posicion;
    
    if (l == NULL || l->raiz == NULL) 
        return;

    else {

        posicion = 1;
        aImprimir = l->raiz->sig;

        while (aImprimir != NULL) {

            printf("El valor -> %d está en la posición -> %d \n", aImprimir->elemento, posicion++);
            aImprimir = aImprimir->sig;

        }

        printf("%d valores en la lista\n",posicion-1);

    }

} //Fin de funcion imprime()


tipoPosicion
anterior(tipoPosicion p, Lista *l)
{
    tipoCelda *anterior;
    
    if (l == NULL || l->raiz == NULL || p == NULL) {

        return NULL;

    }
    else if (p == l->raiz) {

        return l->raiz;
        
    }
    else {

        anterior = l->raiz;
        while (anterior->sig != p)
            anterior = anterior->sig;

        return anterior;

    }

} //Fin de funcion anterior()


tipoPosicion
primero(Lista *l)
{

    if (l == NULL) {

        fprintf(stderr,"Fallo precondición lista no existente!\n");
        return NULL;

    }
    else if (l->raiz == NULL) {

        fprintf(stderr,"Fallo precondición lista no inicializada!\n");
        return NULL;

    } else
        return l->raiz;

} //Fin de funcion primero()


tipoPosicion
fin(Lista *l)
{

    if (l == NULL) {

        fprintf(stderr,"Fallo precondición lista no existente!\n");
        return NULL;
    }
    else if (l->ultimo == NULL) {

        fprintf(stderr,"Fallo precondición lista no existente!\n");
        return NULL;
    }
    else
        return l->ultimo;
    
} //Fin de funcion fin()


int
inserta(tipoElemento x, tipoPosicion p, Lista *l)
{

    tipoCelda *nuevo;
    
    if (l == NULL || l->raiz == NULL || p == NULL)  
		return -1;
		
    else {

        if (NULL == (nuevo = (tipoCelda*)malloc(sizeof(tipoCelda)))) 
            return -2;

        else {

            nuevo->elemento = x;
            nuevo->sig = p->sig;
            p->sig = nuevo;

            if (p == l->ultimo)
                l->ultimo = nuevo;

            return 0;

        }

        

    } 

} //Fin de funcion inserta()


int
suprime (tipoPosicion p, Lista *l)
{
    tipoCelda *aBorrar;
    
    if (l == NULL || l->raiz == NULL || p == NULL)  
		return -1;
		
	else {

        aBorrar = p->sig;
        p->sig = aBorrar->sig;
        free(aBorrar);

        if (p->sig == NULL)
            l->ultimo = p;
		
		return 0;
	} 
	
} //Fin de funcion suprime()


tipoPosicion
siguiente(tipoPosicion p,Lista *l)
{
    
    if (l == NULL || l->raiz == NULL || p == NULL) {

        return NULL;

    }   

    return p->sig; 
    
} //Fin de funcion siguiente()


tipoPosicion 
localiza (tipoElemento x, Lista *l)
{
    tipoPosicion aux;
    
    if (l == NULL || l->raiz == NULL)
    
    	return NULL;
    	
    else {
    	
    	aux = l->raiz;
    	
    	while (aux->sig != NULL) {
    		
			if (aux->sig->elemento == x)
				return aux;
				
			aux = aux->sig;
		}
    	
    	return fin(l);
	}
	
} //Fin de funcion localiza()


tipoElemento 
recupera (tipoPosicion p, Lista *l)
{
	
    if (l == NULL || l->raiz == NULL || p == NULL)
    	return -1;
    	
    else if (p == fin(l))
    	return -2;
    	
	else
		return p->sig->elemento;
		
} //Fin de funcion recupera()


int 
anula (Lista *l)
{
	
	tipoCelda *aux;
	tipoCelda *aBorrar;
	
    if (l == NULL || l->raiz == NULL)
    	return -1;
    	
    else {
		
    	aux = l->raiz->sig;
    	l->raiz->sig == NULL;

    	while (aux != NULL) {
    		
    		aBorrar = aux;
    		aux = aux->sig;
    		free(aBorrar);

		}
		
		l->ultimo->sig = NULL;
		return 0;
		
	}
	
} //Fin de funcion anula()

int
concatena(Lista *la, Lista *lb)
{

    if (la == NULL || lb == NULL) {

        fprintf(stderr, "Fallo precondición. Lista no existe.\n");
        return -1;

    } else if (la->raiz == NULL || lb->raiz == NULL) {

        fprintf(stderr, "Fallo precondición. Lista no existe.\n");
        return -2;

    } else {

        if (lb->raiz->sig != NULL) {

            la->ultimo->sig = lb->raiz->sig;
            la->ultimo = lb->ultimo;
            lb->raiz->sig = NULL;
            lb->ultimo = lb->raiz;
        }

        return 0; 
        
    }

} //Fin de funcion concatena()



