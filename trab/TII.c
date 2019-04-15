#include "TII.h"

tdesc* inicializa(){
    // Aloca espaço para um novo número int int
    tdesc* numero = (tdesc*)malloc(sizeof(tdesc));
    numero->prim = (tii*)malloc(sizeof(tii));
    numero->prim = NULL;
    numero->ult = (tii*)malloc(sizeof(tii));//////
    numero->ult = NULL;
    return numero;
}

tdesc* leituranum(){
    // Lê um número como string e retorna o descritor da lista com aql número
    char* str = (char*)malloc(sizeof(char)*10000);
    printf("\n");
    scanf("%s",str);
    int j, i = 0;
    int sin = 0;
    while (str[i]!='\0'){
        i++;
    }
    tdesc *desc = inicializa();
    desc->sinal = '+';
    desc->ncarac = i;
    for(j=i-1;j>-1;j--){
        if ((str[j] == '-' || str[j] == '+') && !sin) {
          desc->sinal = str[j];
          desc->ncarac--;
          sin = 1;
        }else{
          if (!(str[j]>='0' && str[j]<='9')){
            liblista(desc);
            return NULL;
          }
          str[j] = atoi(&str[j]);
          insere(desc,str[j]);
        }
    }
    free(str);
    retira_zero(desc);
    return desc;
}

tii* insere(tdesc *desc, int elem){
    // Insere um algarismo no inicio da lista tipo tii apontada pelo descritor desc
    tii *novo = (tii *) malloc(sizeof(tii));
    novo->ant = NULL;
    novo->prox = desc->prim;
    novo->num = elem;
    // printf("%d",novo->num); teste
    if(desc->prim) desc->prim->ant = novo;
    if(!desc->prim) desc->ult = novo;
    desc->prim = novo;
    return novo;
}

tii* insere_fim(tdesc *desc, int elem){
    // Insere um algarismo no inicio da lista tipo tii apontada pelo descritor desc
    tii *novo = (tii *) malloc(sizeof(tii));
    novo->prox = NULL;
    novo->ant = desc->ult;
    novo->num = elem;
    // printf("%d",novo->num); teste
    if(desc->ult) desc->ult->prox = novo;
    if(!desc->ult) desc->prim = novo;
    desc->ult = novo;
    return novo;
}

void retira_zero(tdesc *desc){
  tii* temp;
  while ((desc->prim->num == 0) && (desc->prim->prox)){
    temp = desc->prim;
    desc->prim = desc->prim->prox;
    desc->prim->ant = NULL;
    free(temp);
  }

}

int ehzero(tdesc *desc){
    //detecta se um número é zero
    tii *p = desc->prim;
    while(p){
        if(p->num != 0) return 0;
        p = p->prox;
    }
    return 1;
}

tdesc* operacao(tdesc* numa, char *op, tdesc* numb){
    //Seleciona a operação que será realizada entre os números passados como parâmetro pelos descritores
    //Chama novamente a função se resp for igual a NULL(operação inválida)
    tdesc *resp = NULL;
    switch(*op){
			case('+'):
        //printf("Mais\n");
        if(numa->sinal == numb->sinal){ //sinais iguais
          resp = soma(numa,numb);
          resp->sinal = numa->sinal;
        }else { //sinais diferentes
          if (numa->sinal == '+') resp = subtracao(numa,numb); //se numa é + e numb -(numa-numb)
          else resp = subtracao(numb,numa); //se numb é positivo e numa negativo(numb-numa)
        }
				break;
			case('-'):
        // printf("Menos\n"); teste
        if(numa->sinal != numb->sinal){
          resp = soma(numa,numb);
          resp->sinal = numa->sinal;
        }else{
          if(numa->sinal == '+') resp = subtracao(numa,numb);
          else resp = subtracao(numb,numa);
        }
        break;
			case('*'):
        // printf("Mult\n"); teste
        resp = multiplicacao(numa,numb);
        if(numa->sinal == numb->sinal) resp->sinal = '+';
        else resp->sinal = '-';
				break;
			case('/'):
        // printf("Divisão\n"); teste
				if(ehzero(numb)){
          //printf("eh zero\n"); teste
          numb->sinal = '0';
					break;
				}else{
          // pr/intf("ok\n"); teste
          resp = divisao(numa,numb);
          if(numa->sinal == numb->sinal) resp->sinal = '+';
          else resp->sinal = '-';
					break;
				}
			default:
        // printf("Sinal errado\n"); teste
				break;
    }
    return resp;
}

void imprime(tdesc *desc){
  tii *p = desc->prim;
  printf("%c",desc->sinal);
  while(p){
    printf("%d", p->num);
    p = p->prox;
  }
}

int intintcmp(tii *numa, tii *numb){
  // Compara uma lista intint recursivamente
  if (numa->num > numb->num) return -1;
  if (numa->num < numb->num) return 1;
  if (numa->num == numb->num){
    if (numa->prox){
      intintcmp(numa->prox, numb->prox);
    }else return 0;
  }
}

int comparacao(tdesc *numa, tdesc *numb){
  /*
  Retorna -1 se o primeiro for maio
  0 se eles são iguais
  1 se o segundo é maior
 */
  // printf("comparação entre: ");
  // imprime(numa);
  // printf(" e ");
  // imprime(numb);
  // printf("\n");
  if (numa->ncarac > numb->ncarac) return -1;
  if (numa->ncarac < numb->ncarac) return 1;
  if (numa->ncarac == numb->ncarac) intintcmp(numa->prim, numb->prim);
}

tdesc* intintcpy(tdesc *numb){
  //cria uma copia de numb em numa
  int i = 0;
  tdesc* numa = inicializa();
  tii *l = numb->ult;
  while(l){
    insere(numa,l->num);
    i++;
    l = l->ant;
  }
  numa->ncarac = i;
  return numa;
}

void liblista(tdesc *l){
  //libera a lista mas mantem o descritor
  tii *p = l->prim, *q;
  while(p){
    q = p;
    p = p->prox;
    free(q);
  }
  l->prim = NULL;
  l->ult = NULL;

}

void libtudo(tdesc *l){
  //libera a estrutura toda
  tii *p = l->prim, *q;
  while(p){
    q = p;
    p = p->prox;
    free(q);
  }
  free(l->prim);
  free(l->ult);
  free(l);
}

void somador(tdesc *numa){
  // equivalente a i++
  tii *p1 = numa->ult;
  int cont = 1;
  int sum;
  while(p1){
    sum = p1->num + cont;
    p1->num = sum%10;
    if (sum>9) cont = 1;
    else cont = 0;
    p1 = p1->ant;
  }
  if(cont){
    insere(numa,cont);
  }
}

tdesc* soma(tdesc *numa,tdesc *numb){
  tdesc *resp = inicializa();
  tii *p1 = numa->ult;
  tii *p2 = numb->ult;
  int cont = 0;
  int sum;
  // CASO EM QUE O TAMANHO DE NUMA E O MESMO DE NUMB
  if(numa->ncarac == numb->ncarac){
    while(p1){
      //SOMA DOS RESPECTIVOS NUMEROS DE CADA "CASA" DA LISTA
      sum = p1->num + p2->num;
      //CASO A SOMA DE MAIOR QUE 10 DAS CASAS DE MAIOR QUE 10
      if(sum>=10){
        if(!cont){
          insere(resp,(sum%10));
          cont = 1;
        }
        else{
          insere(resp,(sum%10+cont));
          cont = 1;
        }
      }
      // INSERE SOMANDO O CONTADOR E RESETA ELE
      else{
        // "VAI-UM" NO CASO SUM+CONT = 10
        if((sum+cont)==10){
          insere(resp,0);
          cont = 1;
        }
        else{
          insere(resp,(sum+cont));
          cont = 0;
        }
      }
      p1 = p1->ant;
      p2 = p2->ant;
      //CASO PARA ADICIONAR O NUMERO 1 AO COMECO DA LISTA SE A SOMA DER UM NUMERO MAIOR QUE AS CASAS
      if(!p1 && cont)insere(resp,1);
    }
  }
  // CASO EM QUE TAMANHO DE NUMA E MAIOR QUE DE NUMB
  if(numa->ncarac > numb->ncarac){
    while(p1){
      if(p2){
        sum = p1->num + p2->num;
        if(sum>=10){
          if(!cont){
            insere(resp,(sum%10));
            cont = 1;
          }
          else{
            insere(resp,(sum%10+cont));
            cont = 1;
          }
        }
        else{
          if((sum+cont)==10){
            insere(resp,0);
            cont = 1;
          }
          else{
            insere(resp,(sum+cont));
            cont = 0;
          }
        }
        p1 = p1->ant;
        p2 = p2->ant;
      }
      // SE NUMB JA TIVER "TERMINADO"
      else{
        sum = p1->num;
        if((sum+cont)==10){
          insere(resp,0);
          cont = 1;
        }
        else{
          insere(resp,(sum+cont));
          cont = 0;
        }
        p1 = p1->ant;
        if(!p1 && cont)insere(resp,1);
      }
    }
  }
  // CASO EM QUE TAMANHO DE NUMA E MAIOR QUE DE NUMB
  if(numa->ncarac < numb->ncarac){
    while(p2){
      if(p1){
        sum = p1->num + p2->num;
        if(sum>=10){
          if(!cont){
            insere(resp,(sum%10));
            cont = 1;
          }
          else{
            insere(resp,(sum%10+cont));
            cont = 1;
          }
        }
        else{
          if((sum+cont)==10){
            insere(resp,0);
          }
          else{
            insere(resp,(sum+cont));
            cont = 0;
          }
        }
        p1 = p1->ant;
        p2 = p2->ant;
      }
      //SE NUMA JA TIVER "TERMINADO"
      else{
        sum = p2->num;
        if((sum+cont)==10){
          insere(resp,0);
          cont = 1;
        }
        else{
          insere(resp,(sum+cont));
          cont = 0;
        }
        p2 = p2->ant;
        if(!p2 && cont)insere(resp,1);
      }
    }
  }
  return resp;
}

tdesc* subtracao(tdesc *numa,tdesc *numb){
  int sub, carry = 0, temp;
  char sinal;
  tii *n1, *n2;
  tdesc* resp = inicializa();

  if(comparacao(numa, numb) == 1){
    n1 = numb->ult;
    n2 = numa->ult;
    //resp->sinal = '+';
  }
  else{
    n1 = numa->ult;
    n2 = numb->ult;
    resp->sinal = '-';
  }

  while(n2){
    temp = n1->num;
    temp += carry;
    carry = 0;

    if (temp < n2->num){
      temp += 10;
      carry = -1;
    }
    sub = temp - n2->num;
    insere(resp, sub);
    n2 = n2->ant;
    if (n2)
      n1 = n1->ant;
  }
  n1 = n1->ant;

  while(n1){
    temp = n1->num;
    if((temp == 0) && (carry == -1)){
      temp += 9;
      carry = -1;
    }
    else if (temp < 0){
      temp += 10;
      carry = -1;
    }
    else{
      temp += carry;
      carry = 0;
    }
    insere(resp, temp);
    n1 = n1->ant;
  }

  // resp->sinal = sinal;  Teste
  // printf("%c", resp->sinal);
  // imprime(resp);
  // printf("\n");
  retira_zero(resp);
  return resp;
}
tdesc* multiplicacao(tdesc *numa,tdesc *numb){
  tdesc* resp = inicializa();
  insere(resp, 0);
  int expoente = 0;
  tii *n1, *n2;
  tdesc* temp = inicializa();
  insere(temp, 0);
  n2 = numb->ult;
  tdesc* aux = inicializa();
  // char sinal;
  // sinal = numa->sinal;
  // numa->sinal = '+';
  printf("n2 = %d , resp= %d, temp = %d\n",n2->num,resp->prim->num,temp->prim->num);

  while (n2){
    tdesc* mult = inicializa();
    insere(mult, 0);
    for (int i=0; i<n2->num; i++){
      printf("Temp = ");
      imprime(temp);
      liblista(temp);
      printf("liblista Temp = ");
      temp->sinal = '+';
      imprime(temp);
      temp = soma(mult, numa);
      imprime(mult);
      printf("+");
      imprime(numa);
      printf("=");
      imprime(temp);
      liblista(mult);
      mult = intintcpy(temp);
      printf("\n");
    }

    for (int j=0; j<expoente; j++){
      insere_fim(mult, 0);
      printf("t2:");
      imprime(mult);
      printf("\n");
    }
    tii *t;
    t = mult->prim;
    while(t){
      printf("%d ",t->num);
      t = t->prox;
    }

    liblista(aux);
    printf("aux =");
    imprime(aux);
    resp->ncarac = tamanho(resp);
    mult->ncarac = tamanho(mult);
    aux = soma(resp, mult);
    imprime(resp);
    printf("+");
    imprime(mult);
    printf(" = ");
    imprime(aux);
    printf("\nAux: \n");
    printf("ncarac %d e %d",numa->ncarac,mult->ncarac);
    t = aux->prim;
    while(t){
      printf("%d ",t->num);
      t = t->prox;
    }
    liblista(resp);
    resp = intintcpy(aux);

    printf("\n");
    expoente++;
    n2 = n2->ant;
  }
  return resp;

  // tii *p1 = numa->ult;
  // tii *p2 = numb->ult;
  // tdesc *resp = numa;
  // int i = 0;
  // int pot = 1;
  // int counter = p2->num;
  // p2 = p2->ant;
  // insere(resp,0);
  // insere(resp,0);
  // insere(resp,0);
  //
  // while(i<(numb->ncarac-1)){
  //   pot *= 10;
  //   counter += p2->num*pot;
  //   p2 = p2->ant;
  //   i++;
  // }
  // for(i = 0;i<counter-1;i++){
  //   printf("\n");
  //   resp = soma(resp,numa);
  //   imprime(resp);
  // }

}

tdesc* divisao(tdesc *numa,tdesc *numb){
  // numa dividido por numb
  tdesc *total = intintcpy(numb); //soma de numb resp vezes
  tdesc *temp = intintcpy(total); //temporario para o total
  tdesc *resp = inicializa();
  int comp;
  insere(resp,0);
  resp->ncarac = tamanho(resp);
  total->ncarac = tamanho(total);
  comp = comparacao(total,numa);
  while(comp > -1){
    somador(resp);
    liblista(temp);
    total->ncarac = tamanho(total);
    temp = soma(total,numb);
    temp->ncarac = tamanho(temp);
    liblista(total);
    total = intintcpy(temp);
    total->ncarac = tamanho(total);
    comp = comparacao(total,numa);
  }
  return resp;
}

int tamanho(tdesc *desc){
  tii *t = desc->prim;
  int cont = 0;
  while (t){
    t = t->prox;
    cont += 1;
  }
  return cont;
}
