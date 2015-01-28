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

int main(){
	char s[102];
	int x=0,y=0;
	int sp=0,n;
	int i;
	scanf("%s",s);
	n=mystrlen(s);
	for(i=n-1;i>=0;i--){
		if(s[i]=='Z'){
			sp=i+1;
			break;
		}
	}
	for(i=sp;i<n;i++){
		if(s[i]=='N')y++;
		else if(s[i] == 'S')y--;
		else if(s[i] == 'E')x++;
		else x--;
	}

	printf("%d %d\n",x,y );

}