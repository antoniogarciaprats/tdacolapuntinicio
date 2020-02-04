#ifndef C1CP_tip_TYPO
#define C1CP_tip_TYPO

struct c_int_typo {
	int x;
};

typedef struct c_int_ele *c_int;

c_int c_int_nuevo ( );
int c_int_vacia ( c_int c );
void c_int_mete ( c_int *c, struct c_int_ele e );
void c_int_saca ( c_int *c, struct c_int_ele *e );
void c_int_dest ( c_int *c );
c_int c_int_copy ( c_int c );

#endif
