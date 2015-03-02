#include <stdio.h>
char box[31][31];
int n,m;

int find(int i,int j,int d){
	
	if(j>m||j<0||i<0)return 0;
	// printf("i : %d j : %d d: %d c: %c\n",i,j,d,box[i][j]);
	// for(int i = 0;i<n;i++){
	// 	for(int j=0;j<m;j++)printf("%c",box[i][j]);
	// 	printf("\n");
	// }
	if(box[i][j]=='#')return 0;
	if(box[i][j]=='.'){
		char k;
		if(j+1<m){
			if(box[i][j+1]!='#'){
				if(i<n){
					if(box[i+1][j]!='#'&&box[i+1][j+1]!='#'){
						box[i][j]='x';
						if(box[i+1][j]!='x')if(find(i+1,j,d+1)==1)return 1;
						// scanf("%c",&k);
						if(box[i][j+1]!='x')if(find(i,j+1,d+1)==1)return 1;
						// scanf("%c",&k);
						if(box[i][j-1]!='x')if(find(i,j-1,d+1)==1)return 1;
						// scanf("%c",&k);
						if(box[i-1][j]!='x')if(find(i-1,j,d+1)==1)return 1;
						// scanf("%c",&k);
					}
				}
				if(i==n-1){
					if(box[i][j+1]=='.')return 1;
				}
					
			}
		}
	}
	return 0;

}

int main(){
	scanf("%d %d ",&n,&m);
	for(int i = 0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%c",&box[i][j]);
			if(box[i][j]=='\n')j--;
		}
	}
	// for(int i = 0;i<n;i++){
	// 	for(int j=0;j<m;j++)printf("%c",box[i][j]);
	// 	printf("\n");
	// }
	int c =0;
	for(int j=0;j<m;j++){
		if(box[0][j]=='.'){
			c=1;
			if(find(0,j,0)==1){
				c=2;
				printf("yes\n");
				break;
			}
		}
	}
	if(c!=2)printf("no\n");
	return 0;
}