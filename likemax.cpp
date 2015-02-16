#include <stdio.h>
#include <map>
#include <iostream>

using namespace std;
map<int,int> mmap;
map<int,int>::iterator got;
int main(){
	int n,lk;
	int max=0,bm;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d",&lk);
		got = mmap.find(lk);
		if(got==mmap.end()){
			mmap[lk]=1;
			max = max>1?max:1;
			bm = max==1?lk:bm;
		}else{
			mmap[lk]+=1;
			bm = mmap[lk]>=max?lk:bm;
			max = bm==lk?mmap[lk]:max;
		}
		printf("%d\n",bm);
	}
	return 0;
}