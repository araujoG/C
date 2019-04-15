#include "TII.h"

int main(){
    do{
        char op[1];
        printf("Digite o primeiro número:");
        tdesc *numa = leituranum();
        printf("\n");

        printf("Digite o sinal da operação correspondente\n\t+ => Adicao\n\t- => Subtracao\n\t* => Multiplicao\n\t/ => Divisao\n\t x => Sair\n");
        scanf("%s", op);
        printf("\n");
        if(op[0]=='x') break;

        printf("Digite o segundo número:");
        tdesc *numb = leituranum();
        printf("\n");

        tdesc *resp = NULL;
        if(numa && numb) resp = operacao(numa, op, numb);

        if(!resp ){
            //printf("%c\n",numb->sinal);
            if(numa && numb){
                //Se a resposta for nula indica por que a operação deu errado
                printf("A operação inválida é: \n");
                imprime(numa);
                printf(" %s ",op);
                imprime(numb);
                printf("\n");
                if (op[0]!= '+' && op[0]!= '-' && op[0]!= '*' && op[0]!= '/'){
                    printf("O sinal da operação é inválido...\n");
                }
                if (numb->sinal == '0') printf("Divisão por zero!!!\n");
                
            }else printf("Um dos números é inválido\n"); 
        }else{
            imprime(numa);
            printf(" %s ",op);
            imprime(numb);
            printf(" = ");        
            imprime(resp);
            printf("\n");
        }

    }while(1);
}