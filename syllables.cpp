#include <stdio.h>
int main(){
	int n;
	scanf("%d ",&n);
	for(int i = 0;i<n;i++){
		int bf=0;
		int out =0;
		while(1){
			char tmp;
			scanf("%c",&tmp);
			if(tmp=='\n')break;
			if(tmp=='a'||tmp=='e'||tmp=='i'||tmp=='o'||tmp=='u')bf=1;
			else{
				if(bf==1){
					out++;
					bf=0;
				}
			}
		}
		if(bf==1)out++;
		printf("%d\n",out);
	}
	return 0;
}