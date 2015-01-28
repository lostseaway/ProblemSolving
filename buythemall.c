#include <stdio.h>
int main(){
	int a,b,c;
	int aa=0,bb=0,cc=0;
	int n,min=0;
	int i;
	int tmp;
	scanf("%d %d %d",&a,&b,&c);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&tmp);
		if(tmp==1)aa++;
		else if(tmp==2)bb++;
		else cc++;
	}
	aa*=a;
	bb*=b;
	cc*=c;
	min = aa<bb?aa:bb;
	min = min<cc?min:cc;
	// printf("%d %d %d\n",aa,bb,cc );
	printf("%d\n",min);
}