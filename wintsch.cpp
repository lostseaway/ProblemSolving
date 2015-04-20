#include <stdio.h>
int arr[1001][3];
int tmp[1001];
int n;
int sov(int i,int edt){
	if(i>=n)return 0;
	// if(tmp[i]!=0)return tmp[i];

	int p=0,np=0;
	if(arr[i][0]>=edt){
		p = sov(i+1,arr[i][1])+arr[i][2];
	}
	np = sov(i+1,edt);

	printf("i:%d p:%d np:%d edt:%d\n",i,p,np,edt);
	tmp[i] = p>np?p:np;
	return tmp[i];
}


int main(){
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
		tmp[i]=0;
	}
	printf("\n");
	int ans = sov(0,0);
	printf("%d\n",ans);

	for (int i = 0; i < n; ++i)
	{
		printf("%d ",tmp[i]);
	}
	printf("\n");


}