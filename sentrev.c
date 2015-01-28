#include <stdio.h>
int mystrlen(char* st)
{
  int l = 0;
  char* p = st;
  while(*p != '\0') {
    p++;
    l++;
  }
  return l;
}
char an[1000][1000];
char s[1010];

int main(){
	int n,i,c,cn;
	scanf("%s",s);
	n = mystrlen(s);
	c = 0;
	cn = 0;
	for(i=0;i<n;i++){
		// printf("s = %c c= %d cn = %d\n",s[i],c,cn);
		if(s[i]=='_'){
			c++;
			cn=0;
			continue;
		}
		an[c][cn] = s[i];
		cn++;

	}
	for(i=c;i>=0;i--){
		printf("%s",an[i]);
		if(i!=0)printf("_");
	}
	printf("\n");
}