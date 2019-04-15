#include <stdio.h>
int main (void){
	do{
		int inicio,fim,div,cont;
		scanf("%d",&inicio);
		scanf("%d",&fim);
		if (inicio<=1 || fim<=1) return 0;
		if (inicio==2) printf("2\n");
		if ((inicio%2)==0) inicio++;
		while(inicio<=fim){
			div = 3;
			int parou = 0;
			while(div<inicio && parou==0){
				if(inicio%div==0){
					parou=1;
				}else div +=2;
			}
			if (parou==0){
				printf("%d\n",inicio);
				cont+=1;
			}
			inicio+=2;
		}
	}while(1);
	
}