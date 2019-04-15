#include <stdio.h>
int main(void){
	do{
		int stop,primo=3;
		printf("Digite a quantidade de números primos que deseja obter:\n");
		scanf("%d",&stop);
		if(stop<1) break;
		printf("2\n");
		int div,cont = 1;
		while(cont<stop){
			int parou=0;
			div = 3;
			while(div<primo && parou==0){
				if((primo%div)==0){
					parou=1;
				}else div+=2; 	
			}		
			if(parou==0){
				printf("%d\n",primo);
				cont+=1;
			} 
			primo+=2;			
		}		
	}while(1);
}