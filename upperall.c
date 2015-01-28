#include <stdio.h>
int main(){
	char s[110];
	int i=0;
	int tmp;
	scanf("%s",s);
	while(1){
		if(s[i]==0)break;
		tmp = s[i];
		if(tmp>=97&&tmp<=122){
			tmp-=32;
		}
		
		printf("%c",tmp);
		i++;
	}
	printf("\n");
}