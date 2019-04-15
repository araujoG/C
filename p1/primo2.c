#include <stdio.h>

int main(){
	do{
		int n,m,div,cont;
		printf("Digite o numero inicial e final: ");
		scanf("%d %d",&n,&m);
		if (n<2 || m<2) return 0;
		if (n==2) printf("2\n");
		if(!(n%2)) n++;
		cont = 0;
		while(n<=m){
			int parou=0;
			div = 3;
			while(div<n && !(parou)){
				if(!(n%div)){
					parou = 1;
				}else div += 2;
			}
			if(!(parou)){
				printf("%d\n",n);
				cont++;
			}
			n+=2;
		}
	}while(1);
}