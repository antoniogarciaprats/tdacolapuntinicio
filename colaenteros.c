
#include <stdlib.h>
#include <stdio.h>
#include "colaenteros.h"

struct c_enteros_ele {
	
	struct c_int_typo val;
	struct c_entero_ele *sig;
	
};

c_int c_int_nuevo ( ) {
	
	return NULL;
	
}

int c_int_vacia ( c_int c ) {
	
	return ( c == NULL );
	
}

void c_int_dest ( c_int *c ) {
	
	
	c_int viejo;
	
	while ( *c ) {
	
		viejo = *c;
		*c = (*c)->sig;
		free ( viejo );
		
	}
	
}


void c_int_mete ( c_int *c, struct c_int_ele e ) {
	
		c_int nuevo, ultimo;
		
		nuevo = ( struct c_enteros_ele* ) malloc ( sizeof ( struct c_int_ele ));
		
		if ( !nuevo ) {
			
			fprintf ( stderr, "c_int_mete: no hay memoria suficiente- n"  );
			exit (1);
		}
		
		nuevo->val = e;
		nuevo->sig = NULL;
		
		if ( !*c ) *c = nuevo;
		else {
			for ( ultimo=*c; ultimo->sig; ultimo=ultimo->sig );
				ultimo->sig = nuevo;
		}
		
}

void c_int_saca ( c_int *c, struct c_int_ele *e ) {

	c_int viejo;
	
	if ( !*c ) {
		fprintf ( stderr, "c_int_saca: La cola está vacía\n" );
		exit (1);
	}
	
	viejo = *c;
	*e = viejo->val;
	*c = viejo->sig;
	
	free ( viejo );

}

c_int c_int_copy ( c_int c ) {

	c_int b, corr, nuevo;
	
	b = NULL;
	
	if ( c ) {
		
		nuevo = ( struct c_int_ele* ) malloc ( sizeof struct c_int_nuevo ));
		if ( !nuevo ) {
			fprintf ( stderr, "c_int_copy: No hay memmoria suficiente\n" );
			exit(1);
		}
		
		nuevo->val = c->val;
		b = corr = nuevo;
		c = c->sig;
		
		while ( c ) {
			
			nuevo = ( struct c_int_nuevo* ) malloc ( sizeof ( struct c_int_nuevo ));
			if ( !nuevo ) {
				fprintf ( stderr, "c_int_copy: No hay memoria suficiente\n" );
				exit (1);
			}
			
			nuevo->val = c->val;
			corr = corr->sig = nuevo;
			c = c->sig;
		}
		
		corr->sig = NULL;
	}
	
	return (b);
}

