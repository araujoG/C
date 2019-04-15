#include "TABB.h"

TAB* inicializa(){
    return NULL;
}

TAB* cria(int info, TAB* sae, TAB *sad){
    TAB* novo = (TAB *) malloc(sizeof(TAB));
    novo->info = info;
    novo->esq = sae;
    novo->dir = sad;
    return novo;
}

void imp_sim(TAB* a){
    // esq , raiz , dir
    if(a){
        imp_sim(a->esq);
        printf("%d ",a->info);
        imp_sim(a->dir);
    }
}

void imp_pos(TAB* a){
    // esq , dir , raiz
    if(a){
        imp_pos(a->esq);
        imp_pos(a->dir);
        printf("%d ",a->info);
    }
}

void imp_pre(TAB* a){
    // raiz , esq , dir
    if(a){
        printf("%d ",a->info);
        imp_pre(a->esq);
        imp_pre(a->dir);
    }
}

// void imp_larg(TAB* a){
//     TFILA* f =criaf();
//     inseref(f,a);
//     while(!vaziaf(f)){
//         TAB* x = retiraf(f);
//         printf("%d ",x->info);
//         if (x->esq) inseref(f,x->esq);
//         if (x->dir) inseref(f, x->dir);
//     }
//     liberaf(f);
// }

void libera(TAB* a){
    if(a){
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
}

TAB* busca_abb(TAB* a, int elem){
    if ((!a) || (a->info == elem)){
        return a;
    }
    if (a->info > elem){
        return busca_abb(a->esq, elem);
    }
    return busca_abb(a->dir, elem);   
}

TAB* busca(TAB* a, int elem){
    if ((!a) || (a->info == elem)) return a;
    TAB *resp = busca(a->esq, elem);
    if (resp) return resp;
    return(busca(a->dir, elem));
}

void retira(TAB* a, int elem){
    TAB* resp = busca(a, elem);
    if (resp){ //se achar o elem
        if (!resp->dir && !resp->esq){//se o elem não tiver filhos
            free(resp);
            return;
        } 
        if (resp->dir && !resp->esq){ //se só tiver 1 filho na direita
            resp->info = resp->dir->info;
            resp->dir = resp->dir->dir;
            resp->esq = resp->dir->esq;
            free(resp->dir);
            return;

        }
        if (resp->esq && !resp->dir){ //se só tiver 1 filho na esquerda
            resp->info = resp->esq->info;
            resp->dir = resp->esq->dir;
            resp->esq = resp->esq->esq;
            free(resp->esq);
            return;
        }
        TAB* m = maior(resp->esq);
        resp->info = m->info;
        retira(m,m->info);
    }      
}

TAB* maior(TAB *a) {
    TAB* m; 
    TAB* atual;
    TAB* esquerda;
    TAB* direita;

    //o maior começa sendo o atual
    m = a; 
    if (a->esq) {
        esquerda = maior(a->esq);
        if (esquerda->info > m->info) {
            m = esquerda;
        }
    }
    if (a->dir) {
        direita = maior(a->dir);
        if (direita->info > m->info) {
            m = direita;
        }
    }
    return m;
}