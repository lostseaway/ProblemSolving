#include <stdio.h>

char map[31][31];
int mask[31][31];
int m,n;
int count = 0;
void makeMask(int i,int j){
	if(i>=n||j>=m||i<0||j<0)return;
	if(mask[i][j]!=0)return;
	if(map[i][j]=='#')return;
	mask[i][j]=count;
	makeMask(i+1,j);
	makeMask(i-1,j);
	makeMask(i,j+1);
	makeMask(i,j-1);
}

int main(){
	
	scanf("%d %d",&n,&m);
	for(int i = 0;i<n;i++){
		for(int j =0;j<m;j++){
			char tmp;
			scanf("%c",&tmp);
			if(tmp=='\n')j--;
			else {
				map[i][j] = tmp;
				mask[i][j]=0;
			}
		}
	}
	

	for(int i =0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(map[i][j]!='#'){
				if(mask[i][j]==0){
					count++;
					makeMask(i,j);
				}
				
			}
		}
	}

	// printf("\n");
	// for(int i =0;i<n;i++){
	// 	for(int j =0;j<m;j++){
	// 		printf("%d ",mask[i][j]);
	// 	}
	// 	printf("\n");
	// }
	int check[count+1][2];
	int cm[count+1];
	for(int i =1;i<=count;i++) {
		check[i][0]=0;
		check[i][1]=0;
		cm[i]=0;
	}

	
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			if(map[i][j]=='#')continue;
			if(map[i][j]=='*')check[mask[i][j]][0]=1;
			if(map[i][j]=='$')check[mask[i][j]][1]=1;
			cm[mask[i][j]]+=1;
		}
	}
	// for(int i =1;i<=count;i++) {
	// 	printf("%d : %d %d %d\n",i,check[i][0],check[i][1],cm[i]);
	// }

	int best = 0;
	int good = 0;
	for(int i =1;i<=count;i++){
		if(check[i][0]==1&&check[i][1]==1)best+=cm[i];
		else if(check[i][0]==1||check[i][1]==1)good+=cm[i];
	}

	printf("%d %d\n",best,good);


	
	return 0;	
}
