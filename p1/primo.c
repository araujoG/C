#include <stdio.h>
int main(){
	do{
		int n, primo = 3;
		printf("Escreva n:");
		scanf("%d",&n);
		if (n<=0) break;
		int cont = 1;
		printf("Os %d primeiros primos são: 2",n);
		while(cont<n){
			int parou = 0;
			int div = 3;
			while(div<primo && !(parou)){
				if(!(primo%div)){
					parou = 1;
				}else div += 2;
			}
			if(!(parou)){
				printf(" %d",primo);
				cont++;
			}
			primo+=2;
		}
		printf("\n");
	}while(1);
}
