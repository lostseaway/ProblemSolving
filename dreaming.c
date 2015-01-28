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
	char d1[310];
	char d2[310];
	char ans[400];
	int de=-1;
	int tmp;	
	int p1,p2,p3,max,i;
	scanf("%s",d1);
	scanf("%s",d2);
	p1=mystrlen(d1);
	p2=mystrlen(d2);
	p3=0;
	max = p1>p2?p1:p2;

	while(1){
		// printf("p1 : %d p2 : %d\n",p1,p2);
		// printf("d1 : %d  d2 : %d\n",d1[p1-1]-'0',d2[p2-1]-'0');
		// printf("de : %d\n",de);
		
		if(p1==0&&p2==0){
			if(de!=-1){
				ans[p3]='1';
				p3++;
			}
			break;
		}
		if(p1==0||p2==0){
			tmp = p1==0?(d2[p2-1]-'0'):(d1[p1-1]-'0');
			if(de!=-1){
				tmp+=1;
				de=-1;
			}
			if(tmp>=10){
				tmp=tmp%10;
				de=1;
			}
			ans[p3] = tmp+'0';
			p3++;
			// printf("p3 : %c\n",ans[p3-1]);
		}
		else{
			tmp = (d1[p1-1]-'0')+(d2[p2-1]-'0');
			if(de!=-1)tmp+=de;
			if(tmp>=10){
				tmp= tmp%10;
				de=1;
			}
			else de=-1;
			ans[p3] = tmp+'0';
			p3++;
		}
		if(p1!=0)p1--;
		if(p2!=0)p2--;
		// printf("p3 : %c\n",ans[p3-1]);
		// printf("----------------------\n");
	}

	for(i=p3-1;i>=0;i--){
		printf("%c", ans[i]);
	}
	printf("\n");

}	