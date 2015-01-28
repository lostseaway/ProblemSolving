#include <stdio.h>
int ar[1001];
int sol(int n){
	int max = 0,a,b;
	if(n<0)return 0;
	a = sol(n-1);
	b = ar[n]+sol(n-1);
	return max = a>b?a:b;

}
int main(){
	int n,i;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&ar[i]);
	}
	printf("%d\n",sol(n-1));
}