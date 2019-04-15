#include "TAB_TABB.h"


void libera_ab(TAB* t){
  if(t){
  libera_ab(t->esq);
  libera_ab(t->dir);
  free(t);
  }
}

TAB* busca_abb(int e, TAB* t){
  if(!t) return NULL;
  if(e < t->info) return busca_abb(e, t->esq);
  if(e > t->info) return busca_abb(e, t->dir);
  return t;
}

TAB* busca_ab(int e, TAB* t){
  if((!t) || (t->info == e)) return t;
  TAB *resp = busca_ab(e, t->esq);
  if(resp) return resp;
  return busca_ab(e, t->dir);
}

void imprime_aux(TAB* a, int andar){
  if(a){
    int j;
    imprime_aux(a->esq, andar + 1);
    for(j = 0; j <= andar; j++) printf("   ");
    printf("%d\n", a->info);
    imprime_aux(a->dir, andar + 1);
  }
}

void imprime_ab(TAB* a){
  imprime_aux(a, 1);
}

TAB* cria_ab(int x, TAB* e, TAB* d){
  TAB* a = (TAB*) malloc(sizeof(TAB));
  a->info = x;
  a->esq = e;
  a->dir = d;
  return a;
}

TAB* insere_abb(int e, TAB* t){
  if(!t) t = cria_ab(e, NULL, NULL);
  else if(e < t->info) t->esq = insere_abb(e, t->esq);
  else if(e > t->info) t->dir = insere_abb(e, t->dir);
  return t;
}

TAB* retira_abb(int e, TAB *t){
  if(!t) return t;
  else if(e < t->info) t->esq = retira_abb(e, t->esq);
  else if(e > t->info) t->dir = retira_abb(e, t->dir);
  else{
    if((!t->esq) && (!t->dir)){
      free(t);
      t = NULL;
    }
    else if((!t->esq) || (!t->dir)){
      TAB *q = t;
      if(!t->dir) t = t->esq;
      else t = t->dir;
      free(q); 
    }
    else{
      TAB *f = t->esq;
      while(f->dir) f = f->dir;
      t->info = f->info;
      f->info = e;
      t->esq = retira_abb(e, t->esq);
    }
  }
  return t;  
}

int zz_rec(TAB *a){
  if (a->esq && !a->dir){
    return zz_rec(a->esq);
  } else if (!a->esq && a->dir){
    return zz_rec(a->dir);
  } else if (a->esq && a->dir){
    return 0;
  } else {
    return 1;
  }
}

int zz(TAB *a){
  while(a){
    if (a->esq && !a->dir){ // 1 filho na esq
      a = a->esq;
    } else if (!a->esq && a->dir){ // 1 filho na dir
        a = a->dir;
    } else if (a->esq && a->dir){ // Dois filhos
        return 0;
    } else { // Final da árvore
        return 1;
    }
  }
}

int estbin(TAB *a){
  if (a->esq && a->dir){ // Se tiver 2 filhos
    if (estbin(a->dir) && estbin(a->esq)) return 1; // Se um dos filhos tiver 1 filho 
    else return 0; //Se nenhum dos filhos tiver 1 filho
  } else if (!a->esq && !a->dir){ // Se não tiver nenhum filho
    return 1;
  } else { // Se tiver 1 filho
    return 0;
  }
}

int mn(TAB *a1, TAB *a2){
	if (!a1 && !a2) return 1;
	if (!a1 || !a2) return 0;
	if (a1->info == a2->info)
		if (mn(a1->esq,a2->esq) && mn(a1->dir, a2->dir)) return 1;
	return 0;

}

int mn_rec(TAB* a1, TAB* a2){
  if (a1 && a2){
    if (a1->info == a2->info){
      if (a1->dir || a2->dir){
        if (mn_rec(a1->dir, a2->dir)){
          if (a1->esq || a2->esq){
            if (mn_rec(a1->esq, a2->esq)){
              return 1;
            } else return 0;
          } else return 1;
        } else return 0;
      } else {
        if (a1->esq || a2->esq){
            if (mn_rec(a1->esq, a2->esq)){
              return 1;
            } else return 0;
          } else return 1;
      }
    } else return 0;
  } else if (a1 || a2) return 0;
  else {
    return 1;
  }
}

TLSE* ancestrais(TAB *a, int elem){
  TLSE* l = (TLSE*) malloc(sizeof(TLSE));
	l = NULL;
  while(a){
    if (elem > a->info){
      l = inseref(l, a->info);
      a = a->dir;  
    } else if (elem < a->info){
      l = inseref(l, a->info);
      a = a->esq;
    } else if (elem == a->info) return l;
    else{
      liberal(l);
      return NULL;
    }
    //printf("%d ",l->info);
  }
}