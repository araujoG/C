#include "TLSE.h"

TLSE* inserel(TLSE *l, int elem){
  TLSE *novo = (TLSE *) malloc(sizeof(TLSE));
  novo->prox = l;
  novo->info = elem;
  return novo;
}

void imprimel(TLSE *l){
  TLSE *p = l;
  while(p){
    printf("% d ", p->info);
    p = p->prox;
  } 
}

void liberal(TLSE *l){
  TLSE *p = l, *q;
  while(p){
    q = p;
    p = p->prox;
    free(q);
  } 
}

TLSE* retiral(TLSE *l, int elem){
  TLSE *p = l, *ant = NULL;
  while((p) && (p->info != elem)){
    ant = p;
    p = p->prox;
  }
  if(!p) return l;
  if(!ant) l = l->prox;
  else ant->prox = p->prox;
  free(p);
  return l;
}

TLSE* buscal(TLSE *l, int elem){
  TLSE *p = l;
  while((p) && (p->info != elem)) p = p->prox; 
  return p;
}

void ordenaA(TLSE* l){
	TLSE* menor;
	TLSE* atual;
	int temp;
	while(l){
		atual = l;
		menor = atual;
		while(atual){
			if (atual->info < menor->info) menor = atual;
			atual = atual->prox;
		}
		temp = menor->info;
		menor->info = l->info;
		l->info = temp;
		l = l->prox;
	}
}

TLSE* ordenaB(TLSE* l){
	TLSE* l2 = (TLSE*) malloc(sizeof(TLSE));
	l2=NULL;
	while(l){
		l2= inserel(l2, l->info);
		l=l->prox;
	}
	printf("Antes da ordenaB: \n");
	imprimel(l2);
	printf("\n");
	printf("Depois da ordenaB: \n");
	ordenaA(l2);
	imprimel(l2);
	printf("\n");
	return l2;
}

void inverteA(TLSE* l){
	TLSE* l2 = (TLSE*) malloc(sizeof(TLSE));
	l2=NULL;
	TLSE* inicio = l;
	while(inicio){
		l2= inserel(l2, inicio->info);
		inicio=inicio->prox;
	}
	while(l){
		l->info = l2->info;
		l = l->prox;
		l2 = l2->prox;
	}
}

TLSE* inverteB(TLSE* l){
	printf("\nDepois de inverter:\n");
	TLSE* l2 = (TLSE*) malloc(sizeof(TLSE));
	l2=NULL;
	TLSE* inicio = l;
	while(inicio){
		l2= inserel(l2, inicio->info);
		inicio=inicio->prox;
	}
}

void miscA(TLSE* l, int x){
	TLSE* l2 = (TLSE*) malloc(sizeof(TLSE));
	l2=NULL;
	TLSE* inicio = l;
	while(l){
		if (l->info == x){
			l2= inserel(l2, l->info - 1);
			l2= inserel(l2, l->info + 1);
		}else{
			l2= inserel(l2, l->info);
		}
		l=l->prox;	
	}
	
}

TLSE* miscB(TLSE* l, int x){
	TLSE* l2 = (TLSE*) malloc(sizeof(TLSE));
	l2=NULL;
	while(l){
		if (l->info == x){
			l2= inserel(l2, l->info - 1);
			l2= inserel(l2, l->info + 1);
		}else{
			l2= inserel(l2, l->info);
		}
		l=l->prox;	
	}
}