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
char s[1010];
int rev(int f,int t){
	int n = f;
	int i;
	// printf("f=%d i=%d\n",f,t);
	for(i=t;i>=n;i--)
		printf("%c",s[i]);
	return 0;
}
int main(){	
	int i,n,tmp=0;
	scanf("%s",s);
	n = mystrlen(s);
	for(i=0;i<n;i++){
		if(s[i]=='_'||i==n-1){
			if(i==n-1)rev(tmp,i);
			else rev(tmp,i-1);

			if(i!=n-1)printf("_");
			tmp = i+1;
		}
	}
	printf("\n");
	return 0;
}