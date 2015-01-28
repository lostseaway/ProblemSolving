#include <stdio.h>
int check(int x,int y,int r){
	return ((x * x) + (y * y)) > r*r;
}

int main(){
	int n,x,y,i,tmp,j,sum;
	int sc[7];
	sc[1] = 5;
	sc[2] = 4;
	sc[3] = 3;
	sc[4] = 2;
	sc[5] = 1;
	sc[6] = 0;
	scanf("%d",&n);
	sum=0;
	for(i=0;i<n;i++){
		scanf("%d %d",&x,&y);
		tmp=0;
		
		for(j=2;j<=12;j+=2){
			tmp=j;
			if(!check(x,y,j))break;;	
		}
		// printf("%d\n",tmp);
		tmp = sc[tmp/2];
		sum+=tmp;
		// printf("-- %d\n",tmp);
	}
	printf("%d\n",sum);
}
