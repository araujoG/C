#include <stdio.h>

int main(){
	do{
		int n,m,pot = 1;
		scanf("%d%d",&n,&m);
		if (m<2 && m>-2) return 0;
		printf("As potências de %d menores que %d são:\n",m,n);
		while(1){
			printf("%d\n",pot);
			pot = pot*m;
			if(pot>=n) break;
		}
	}while(1);
}