#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
    int mat;
    char nome[81];
    float cr;
    struct lista *prox;
} Tlista;

Tlista* inserel(Tlista *l, int mat, char *nome, float cr){
    Tlista *novo = (Tlista *) malloc(sizeof(Tlista));
    novo->prox = l;
    novo->mat = mat;
    strcpy(novo->nome,nome);
    novo->cr = cr;
    return novo;
}

// Tlista* inicializa(void){
//     Tlista* aluno = (Tlista*) malloc(sizeof(Tlista));
//     aluno = NULL;
//     return aluno;
// }

void imprime(Tlista* l){
    while(l){
        printf("%d\n",l->mat);
        printf("    Nome: %s\n",l->nome);
        printf("    Cr: %f\n",l->cr);
        printf("\n");
        l = l->prox;
    }
}

Tlista* copy(Tlista *l){
    Tlista* aux = (Tlista*)malloc(sizeof(Tlista));
    aux = NULL; 
    while(l){
        aux = inserel(aux,l->mat,l->nome,l->cr);
        l = l->prox;
    }
    Tlista* resp = (Tlista*)malloc(sizeof(Tlista));
    resp = NULL;
    while(aux){
        resp = inserel(resp,aux->mat,aux->nome,aux->cr);
        aux = aux->prox;
    }
    return resp;
}

int contrario(Tlista* l1,Tlista* l2){
    Tlista* aux = (Tlista*)malloc(sizeof(Tlista));
    aux = NULL; 
    while(l2){
        aux = inserel(aux,l2->mat,l2->nome,l2->cr);
        l2 = l2->prox;
    }
    while(l1 || aux){
        if (!(l1&&aux)) return 0;
        if (l1->cr != aux->cr) return 0;
        if (l1->mat != aux->mat) return 0;
        if (strcmp(l1->nome,aux->nome)) return 0;
        l1 = l1->prox;
        aux = aux->prox;
    }
    return 1;
}

int alunocmp(const void *x, const void *y){
    Tlista* a = (Tlista*) x;
    Tlista* b = (Tlista*) y;
    if(a->mat<b->mat) return -1;
    if(a->mat>b->mat) return 1;
    if(a->cr>b->cr) return-1;
    if(a->cr<b->cr) return 1;
    if (strcmp(a->nome, b->nome)<0) return -1;
    if (strcmp(a->nome, b->nome)>0) return 1;
    return 0;
}

int main(){
    Tlista* alunos = (Tlista*) malloc(sizeof(Tlista));
    alunos = NULL;
    alunos = inserel(alunos,5785,"Gabriel",6.5);
    alunos = inserel(alunos,1031,"Joao",9.3);
    alunos = inserel(alunos,7853,"Julia",9.3);
    Tlista* alunos1 = (Tlista*) malloc(sizeof(Tlista));
    alunos1 = NULL;
    alunos1 = inserel(alunos1,5785,"Gabriel",6.5);
    alunos1 = inserel(alunos1,1031,"Julia",9.3);
    alunos1 = inserel(alunos1,5785,"Gabriel",6.5);
    alunos = alunos->prox;
    alunos1 = alunos1->prox;
    alunos = alunos->prox;
    alunos1 = alunos1->prox;
    
}