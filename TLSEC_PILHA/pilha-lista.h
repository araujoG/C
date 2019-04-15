#include "lista.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct pilha{
	TLSE *prim;
}TPilha;	


void push(TPilha *p, int elem);
int pop(TPilha *p);
int vazia_p(TPilha *p);
TPilha *inicializa_p(void);
void libera_p(TPilha *p);
void imprime_p(TPilha *p);

