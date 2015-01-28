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
	char w[301][10];
	int n,i,j,sum=0,k,tmp,max,l;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",w[i]);
		max=0;
		l = mystrlen(w[i]);
		for(j=0;j<i;j++){
			tmp = 0;
			for(k=0;k<l;k++){
				if(w[i][k]==w[j][k])tmp++;
				else break;
			}
			if(k==l)tmp--;
			max = max>tmp?max:tmp;
		}
		// printf("%d\n",max);
		// if(max==l) max--;
		sum+=max+1;

	}
	printf("%d\n",sum);
}