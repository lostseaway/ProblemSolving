#include <stdio.h>
int arr[100005];
int tmp[100005];
int n;

int sov(int i){
	if(i>=n-1)return 0;
	if (tmp[i]!=-1) return tmp[i];
	int p = arr[i+2]+sov(i+3);
	int np = sov(i+1);
	tmp[i] =  p>np?p:np;
	return tmp[i];
}
int main(){


	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d",&arr[i]);
		tmp[i] = -1;
	}
	printf("%d\n",sov(0));

}