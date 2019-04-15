#include <stdio.h>

int main(){
	do{
		int n,m,div=1;
		int i = 1;
		scanf("%d%d",&n,&m);
		if(n<1 || m<1) return 0;
		while(i<=n && i<=m){
			i++;
			if (!(n%i) && !(m%i)) div = i;
		}
		printf("%d\n",div);
	}while(1);
}