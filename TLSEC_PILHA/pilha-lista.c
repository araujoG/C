#include "pilha-lista.h"

TPilha *inicializa_p(void){
	TPilha *p = (TPilha *)malloc(sizeof(TPilha));
	p->prim = NULL;
	return p;
}
	
int vazia_p(TPilha *p){
	return (p->prim == NULL);
}
	
void push(TPilha *p,int elem){
	TLSE *novo = (TLSE *)malloc(sizeof(TLSE));
	novo->info = elem;
	novo->prox = p->prim;
	p->prim = novo;
}

int pop(TPilha *p){
	if (!vazia_p(p)){
		TLSE *aux = p->prim;
		int x = aux->info;
		p->prim = aux->prox;
		free(aux);
		return x;
	}
	else{ // pilha vazia
		exit(1);
	}
}

void libera_p(TPilha *p){
	TLSE *q = p->prim,*r ;
	while(q){
		r = q;
		q=q->prox;
		free(r);
	}
	free(p);
}

void imprime_p(TPilha *p){
 	TPilha *aux = inicializa_p();
	while (!vazia_p(p)){
		int x = pop(p);
		printf("%d ",x);
		push(aux,x);
	}
	while(!vazia_p(aux)){
		push(p,pop(aux));
	}
	
	libera_p(aux);
}
