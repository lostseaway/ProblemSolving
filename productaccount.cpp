#include <stdio.h>
#include <map>

using namespace std;
int main(){
	map<int,int> mmap;
	int n,op,item,amout;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d %d",&op,&item);
		map<int,int>::iterator got = mmap.find(item);
		if(op==1){
			scanf("%d",&amout);
			if(got==mmap.end())mmap[item]=amout;
			else mmap[item]+=amout;
		}
		else if(op==2){
			if(got==mmap.end()) printf("0\n");
			else printf("%d\n",mmap[item]);
		}
		else{
			scanf("%d",&amout);
			if(got==mmap.end()) printf("0\n");
			else{
				int k = mmap[item];
				if(amout>k){
					printf("%d\n",mmap[item]);
					mmap[item]=0;
				}
				else{
					printf("%d\n",amout);
					mmap[item]-=amout;
				}
			}
		}
	}
}