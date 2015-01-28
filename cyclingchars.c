#include <stdio.h>
int main(){
	char s[110];
	int i=0;
	int tmp;
	scanf("%s",s);
	while(1){
		if(s[i]==0)break;
		tmp = s[i]+4;
		tmp = tmp%97;
		tmp = tmp%26;
		// printf("%d",tmp);
		tmp += 97;
		
		printf("%c",tmp);
		i++;
	}
	printf("\n");
}