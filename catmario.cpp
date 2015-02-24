#include <stdio.h>
int st[101];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i =0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		a--;
		if(st[a]==0)st[a]=b;
		else if(st[a]>b)st[a]=b;
	}
	int sum=0;
	for (int i = 0; i < n; ++i)
	{
		sum+=st[i];
	}
	printf("%d\n",sum);
	for (int i = 0; i < n; ++i)
	{
		printf("%d %d\n",i+1,st[i]);
	}

}