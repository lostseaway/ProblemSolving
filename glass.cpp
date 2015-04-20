#include <stdio.h>

int field[102][102];
int mask[102][102];
void clear(){
	for(int i =0;i<102;i++)
		for(int j = 0;j<102;j++)
			field[i][j]=0;
}

int check(int i ,int j,int dir,int n,int m,int str){
	if(dir == 0 && i==n) return 1;
	if(dir == 1 && i==-1) return 1;
	if(dir == 2 && j==m) return 1;
	if(dir == 3 && j==-1) return 1;

	mask[i][j] = 1;
	if(field[i][j]!=str) return 0;

	if(dir==0)return check(i+1,j,dir,n,m,str);
	if(dir==1)return check(i-1,j,dir,n,m,str);
	if(dir==2)return check(i,j+1,dir,n,m,str);
	return check(i,j-1,dir,n,m,str);
}

int main(){
	int t;
	scanf("%d",&t);
	for(int i =0 ;i<t;i++){
		clear();
		int m,n;
		int min=100;
		scanf("%d %d",&n,&m);
		for(int j = 0;j<n;j++){
			for(int k =0;k<m;k++){
				scanf("%d",&field[j][k]);
				min = min<field[j][k]?min:field[j][k];
			}
		}

		int check = 0;
		for(int j = 1 ; j<m-1;j++){
			if(field[0][j]!=min)continue;
			if(field[n-1][j]!=min)continue;
			if(check(0,j,0,n,m,min)==0){
				check = 1;
				break;
			}
			if(check(n-1,j,1,n,m,min)==0){
				check = 1;
				break;
			}
		}

		if(check!=1){
			for(int j = 1 ; j<n-1;j++){
				if(field[j][0]!=min)continue;
				if(field[j][m-1]!=min)continue;
				if(check(j,0,2,n,m,min)==0){
					check = 1;
					break;
				}
				if(check(j,m-1,3,n,m,min)==0){
					check = 1;
					break;
				}
			}
			if(check!=1){
				if(field[0][0]==min){
					if(check(0,0,1,n,m,min)==0&&check(0,0,2,n,m,min)==0) check = 1;
				}
				if(check!=1){
					if(field[0][m-1]==min){
						if(check(0,m-1,1,n,m,min)==0&&check(0,m-1,3,n,m,min)==0) check = 1;
					}
				}
				if(check!=1){
					if(field[n-1][0]==min){
						if(check(n-1,0,2,n,m,min)==0&&check(n-1,0,2,n,m,min)==0) check = 1;
					}
				}
				if(check!=1){
					if(field[n-1][m-1]==min){
						if(check(n-1,m-1,2,n,m,min)==0&&check(n-1,m-1,3,n,m,min)==0) check = 1;
					}
				}

				if(check!=1){
					max = -1;
					for(int j = 0 ;j<)
				}
			}


		}




	}
}