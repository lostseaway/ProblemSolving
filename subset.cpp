#include <stdio.h>
#include <math.h>
int main(){
	int count=0;
	int el=0;
	while(1){
		char a;
		scanf("%c",&a);
		if(a=='}')break;
		else if(a==',')count++;
		else if(a!='{')el=1;
	}
	if(count!=0||el==1)count++;
	printf("%.0f\n",pow(2,count));
	return 0;
}