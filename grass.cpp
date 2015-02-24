#include <stdio.h>
char fl[110][110];
void eat(int i,int j,char dir,int n){
	// printf("i:%d j:%d dir:%c n:%d\n",i,j,dir,n);
	if(dir=='L'&&j==n)return;
	if(dir=='R'&&j==-1)return;
	if(dir=='U'&&i==n)return;
	if(dir=='D'&&i==-1)return;
	if(fl[i][j]=='#'||fl[i][j]=='.')return;
	fl[i][j]='.';
	if(dir=='L')eat(i,j+1,dir,n);
	if(dir=='R')eat(i,j-1,dir,n);
	if(dir=='U')eat(i+1,j,dir,n);
	if(dir=='D')eat(i-1,j,dir,n);
}
void plan(int i,int j,char dir){
	// printf("i:%d j:%d dir:%c\n",i,j,dir);
	if(dir=='A'&&j==-1)return;
	if(dir=='B'&&i==-1)return;
	if(fl[i][j]=='#'){
		if(dir=='A')return plan(i,j-1,dir);
		else return plan(i-1,j,dir);
	}
	fl[i][j]='x';
	if(dir=='A')return plan(i,j-1,dir);
	else return plan(i-1,j,dir);
}
int main(){
	int n,k;
	scanf("%d %d ",&n,&k);
	
	for(int i = 0;i<n;i++){
		for(int j = 0;i<n;j++){
			char tmp;
			scanf("%c",&tmp);
			if(tmp=='\n')break;
			fl[i][j]=tmp;
		}
	}

	for(int i = 0;i<k;i++){
		char op;
		int j;
		scanf(" %c %d",&op,&j);
		// printf("%c\n",op );
		if(op=='A'){
			plan(j-1,n-1,op);
		}
		else if(op=='B') plan(n-1,j-1,op);
		else{
			if(op=='L')eat(j-1,0,op,n);
			else if(op=='R')eat(n-1,j-1,op,n);
			else if(op=='U')eat(0,j-1,op,n);
			else eat(n-1,j-1,op,n);
		} 
			for(int i =0;i<n;i++){
			for(int j =0;j<n;j++){
				printf("%c",fl[i][j]);
			}
			printf("\n");
		}
		
	}




}