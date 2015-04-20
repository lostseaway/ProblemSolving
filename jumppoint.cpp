#include <stdio.h>
#include <math.h>

int tree[10010][2];
int n,r;
int jump(int i,int nx,int ny,int z){
	if(i==0)return 0;
	int p=0,np=0;
	double dis = sqrt(pow((nx-tree[i][0]),2)+pow((ny-tree[i][1]),2));
	printf("%d : %d %d\n",i,nx,ny );

	if(dis<=r){
		if(i-1==0)p = jump(i-1,tree[i][0],tree[i][1],0)+1;
		else p = jump(i-1,tree[i][0],tree[i][1],1)+1;
	}
	else{
		if(i-1==0)return -1;
	}
	np = jump(i-1,nx,ny,z);
	if(p==-1&&np!=-1)return np;
	else if(p!=-1&&np==-1)return p;
	else return (n>np?np:n);

}

int main(){

	scanf("%d %d",&n,&r);
	tree[0][0]=0;
	tree[0][1]=0;
	for(int i =1;i<=n;i++){
		scanf("%d %d",&tree[i][0],&tree[i][1]);
	}
	for(int i =0;i<=n;i++){
		printf("%d : %d %d\n",i,tree[i][0],tree[i][1]);
	}
	printf("%d\n",jump(n,100,100,1));

}