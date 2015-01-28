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
	char st[100000];
	char s[100000];
	int n,i,p,l,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		p = 0;
		scanf("%s",s);
		l = mystrlen(s);
		for(j=0;j<l;j++){
			if(s[j]=='{'||s[j]=='('||s[j]=='['){
				st[p] = s[j];
				p++;
			}
			else{
				if(s[j]=='}' && st[p-1]=='{') p--;
				else if(s[j]==')' && st[p-1]=='(') p--;
				else if(s[j]==']' && st[p-1]=='[') p--;
				else {
					p = -1;
					break;
				}
			}
		}
		// printf("%d\n",p);
		if(p==-1||p!=0)printf("no\n");
		else printf("yes\n");
	}
}