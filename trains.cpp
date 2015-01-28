#include <iostream>
#include <cstdio>
struct Train
{
	int n;
	Train* next;
	Train(int i, Train* n=0)
    :n(i), next(n)
    {}
};

// void insert(Train* now,Train* ins){
// 	if(now->next==0){
// 		now->next = ins;
// 		return;
// 	}
// 	return insert(now->next,ins);
// }

void print(Train* now){
	if(now==0)return;
	printf("%d\n",now->n);
	return print(now->next);
}
Train* trains[100010];
Train* tail[100010];
int main(){
	int n,t2,t3,max;
	char t1;
	
	scanf("%d",&n);
	for(int i = 0 ;i<n;i++){
		std::cin >> t1 >> t2 >> t3;
		max = max>t3?max:t3;
		if(t1=='N'){

			Train* n = new Train(t2);
			if(trains[t3]==0) {
				trains[t3] = n;
				tail[t3] = n;
			}
			else{
				// insert(trains[t3],n);
				if(tail[t3]==0)tail[t3] = n;
				else{
					if(trains[t3]==tail[t3]){
						trains[t3]->next = n;
						tail[t3] = n;
					}
					else{
						// n->next = tail[t3];
						// tail[t3] = n;
						tail[t3]->next = n;
						tail[t3] = n;
					}
				} 
			}
		}
		if(t1=='M'){
			if(trains[t2]==0)continue;
			if(trains[t3]==0){
				trains[t3]=trains[t2];
				tail[t3] = tail[t2];
			}
			else{
				tail[t3]->next = trains[t2];
				tail[t3] = tail[t2];
			}
			trains[t2]=0;
			tail[t2]=0;
		}
		// printf("-----------\n");
		// for(int i = 1;i<=max;i++){
		// if(trains[i]==0)continue;
		// printf("NO : %d\n",i);
		// print(trains[i]);
		// printf("-----------\n");
	// }

	}
	// printf("max : %d\n",max);
	for(int i = 1;i<=max;i++){
		if(trains[i]==0)continue;
		print(trains[i]);
	}
	return 0;
}