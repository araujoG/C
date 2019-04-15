#include <stdio.h>

int main(){
	do{
		int anterior,n,atual,i,cont=1;
		int maior=1;
		scanf("%d",&n);
		if(n<1) return 0;
		scanf("%d",&anterior);
		for(i=0;i<n-1;i++){
			scanf("%d",&atual);
			if(atual>anterior){
				cont++;
			}else if(maior<cont){
				maior = cont; 
				cont = 1;
			}
			anterior = atual;
		}
		if(maior<cont) maior = cont;
		printf("Nessa sequência o comprimento do maior seguimento crescente é %d\n",maior);
	}while(1);
}