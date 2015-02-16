#include <stdio.h>
int c[100000];
int find(int i,int j,int n){
	if(i==j)return i;
	if(i+1==j){
		if(c[j]<n)return j+1;
		return i+1;
	}
	int med = (i+j)/2;
	// printf("i = %d med = %d j = %d n = %d\n",i,med,j,n);
	if(n==c[med])return med+1;
	if(n>c[med])return find(med,j,n);
	else return find(i,med,n);
}
int main(){
	int n ,k;
	
	int m[100000];
	int max=1;
	scanf("%d %d",&n,&k);
	for(int i = 0;i<n;i++){
		int tmp;
		scanf("%d",&tmp);
		if(i==0) c[i] = tmp;
		else c[i] = c[i-1]+tmp;
	}
	for(int i = 0;i<k;i++){
		scanf("%d",&m[i]);
		if(m[i]<c[0])printf("0\n");
		else if(m[i]>=c[n-1])printf("%d\n",n);
		else {
			int x = find(0,n,m[i]);
			if (c[x-1]>m[i]) printf("%d\n",x-1);
			else printf("%d\n",x);
		}
	}


}