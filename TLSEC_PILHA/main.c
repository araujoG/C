#include "pilha-lista.h"

void ordena_v (TPilha* p){
    TLSE* l = p->prim;
    TLSE* n = p->prim;
    int i, temp;
    while(l){
        n = l->prox;
        i = l->info;
        printf("loop\n");
        while(n){
            if (n->info < i){
                printf("Trocando %d por %d\n",n->info,i);
                temp = l->info;
                l->info = n->info;
                n->info = temp;
                i = l->info;
                printf("ninfo = %d  linfo= %d   i=%d\n",n->info,l->info,i);
            }
            n = n->prox;
        }
        l = l->prox;
    }
}

void ordena_v1 (TPilha* p){
    TPilha *lixo = inicializa_p();
    TPilha *ord = inicializa_p();
    int num;
    while(!(vazia_p(p))){
        int maior = p->prim->info;
        int aux, troca = 0;
        while(!(vazia_p(p))){
            num = pop(p);
            push(lixo, num); //pega o primeiro da pilha p e coloca no lixo
            if (num > maior) maior = num;
        }
        while(!(vazia_p(lixo))){
            aux = pop(lixo);
            if (aux == maior && !troca){
                push(ord,aux);
                troca = 1;
            } 
            else push(p,aux);
        }
    }
    while(!(vazia_p(ord))){
        push(p,pop(ord));
    }
}

TPilha* ordena_v2 (TPilha* pil){
    TPilha *p = inicializa_p();
    while(!(vazia_p(pil))){
        push(p,pop(pil));
    }
    TPilha *lixo = inicializa_p();
    TPilha *ord = inicializa_p();
    int num;
    while(!(vazia_p(p))){
        int maior = p->prim->info;
        int aux, troca = 0;
        while(!(vazia_p(p))){
            num = pop(p);
            push(lixo, num); //pega o primeiro da pilha p e coloca no lixo
            if (num > maior) maior = num;
        }
        while(!(vazia_p(lixo))){
            aux = pop(lixo);
            if (aux == maior && !troca){
                push(ord,aux);
                troca = 1;
            } 
            else push(p,aux);
        }
    }
    return ord;
}
//      Questão 9
//a- pilha invertida
TPilha* inv_p(TPilha *f){
    TPilha * resp = inicializa_p();
    while(!(vazia_p(f))){
        push(resp,pop(f));
    }
    return resp;
}

//b- Retira os pares void
void retira_pares(TPilha *p){
    TPilha *aux = inicializa_p();
    while(!(vazia_p(p))){
        int num = pop(p);
        if (num%2) push(aux,num);
    }
    while(!(vazia_p(aux))){
        push(p,pop(aux));
    }
}

//c- Separa os pares numa nova piha e a original fica só com os impares
TPilha* sep_p(TPilha *f){
    TPilha *par = inicializa_p();
    TPilha *imp = inicializa_p();
    while(!(vazia_p(f))){
        int num = pop(f);
        if(num%2) push(imp,num);
        else push(par,num);
    }
    while(!vazia_p(imp)){
        push(f,pop(imp));
    }
    while(!(vazia_p(par))){
        push(imp,pop(par));
    }
    libera_p(par);
    return imp;
}

//d- Colocar uma pilha no final da outra
TPilha* Junta_p (TPilha *f1, TPilha *f2){
    TPilha* aux = inicializa_p();
    TPilha* resp = inicializa_p();
    while(!(vazia_p(f1))){
        push(aux,pop(f1));
    }
    while(!(vazia_p(aux))){
        int num = pop(aux);
        push(resp,num);
        push(f1,num);
    }
    while(!(vazia_p(f2))){
        push(aux,pop(f2));
    }
    while(!(vazia_p(aux))){
        int num = pop(aux);
        push(resp,num);
        push(f2,num);
    }
    return resp;
}

//e- separa pares e impares de uma pilha em outras duas
void separa_pilhas(TPilha * f, TPilha *par, TPilha * impar){
    TPilha* aux = inicializa_p();
    while(!(vazia_p(f))){
        push(aux,pop(f));
    }
    while(!(vazia_p(aux))){
        int num = pop(aux);
        if (num%2) push(impar,num);
        else push(par,num);
        push(f,num);
    }
}

int main(){
    TPilha* pilha = inicializa_p();
    TPilha* par = inicializa_p();
    TPilha* impar = inicializa_p();
    push(pilha,8);
    push(pilha,3);
    push(pilha,12);
    push(pilha,1);
    push(pilha,7);
    push(pilha,14);
    push(par,4);
    push(par,8);
    push(par,10);
    push(impar,1);
    push(impar,3);
    push(impar,5);
    imprime_p(pilha);
    printf("\n");
    separa_pilhas(pilha,par,impar);
    imprime_p(par);
    printf("\n");
    imprime_p(impar);
    printf("\n");
    imprime_p(pilha);
    printf("\n");
}