#include <stdio.h>
int find(int p,int s,int t,int c){
	if(c==1&&p<=s+1)return 1;
	// if(c==0&&p==t)return 1;
	if(c==0&&p<=t)return 0;
	if(c==1&&p>s) return find(p-s,s,t,0);
	else return find(p-t,s,t,1);
}

int main(){
	int r,s,t;
	scanf("%d %d %d",&r,&s,&t);
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		int k;
		scanf("%d",&k);
		if(k<r)printf("no\n");
		else if(k==r)printf("yes\n");
		else{
			k-=r;
			if(find(k,s,t,1)==1)printf("yes\n");
			else printf("no\n");
		}
	}
}
