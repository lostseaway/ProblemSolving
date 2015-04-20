// #include <stdio.h>
// int n;
// int arr[1000010];
// int tmp[1000010];

// int sov(int i ,int bef,int st){

// 	printf("i:%d arr:%d bef:%d st:%d\n",i,arr[i],bef,st);
// 	for (int k = 0; k < n; ++k)
// 	{
// 		printf("%d ",tmp[k]);
// 	}
// 	printf("\n");

// 	if(i==0)return 1;
// 	// if(tmp[i]!=-1)return tmp[i];

// 	int p=0,np=0;
// 	if(bef>arr[i]){
// 		p = sov(i-1,arr[i],0)+1;
// 	}
// 	np = sov(i-1,bef,1);

// 	tmp[i] = p>np?p:np;
// 	return tmp[i];

// }


// int main(){
// 	scanf("%d",&n);
// 	for(int i = 0;i<n;i++){
// 		scanf("%d",&arr[i]);
// 		tmp[i] = -1;
// 		// mask[i] = -1;
// 	}
// 	int ans =sov(n-1,10000001,-1);
// 	printf(">%d\n",ans);
// 	int tmp1 = 1;
// 	for (int i = 0; i < n; ++i)
// 	{
// 		printf("%d ",arr[i]);
// 	}
// 	printf("\n");
// 	for (int i = 0; i < n; ++i)
// 	{
// 		printf("%d ",tmp[i]);
// 	}
// 	printf("\n");
// 	int bf = -10000001;
// 	for(int i = 0;i<n;i++){
// 		if(tmp1==ans+1)break;
// 		if(tmp[i]==tmp1){
// 			if(arr[i]>bf){
// 				printf("%d ",arr[i]);
// 				tmp1++;
// 				bf = arr[i];
// 			}
// 		}
// 	}




// }

#include <vector>
using namespace std;
 
/* Finds longest strictly increasing subsequence. O(n log k) algorithm. */
void find_lis(vector<int> &a, vector<int> &b)
{
	vector<int> p(a.size());
	int u, v;
 
	if (a.empty()) return;
 
	b.push_back(0);
 
	for (size_t i = 1; i < a.size(); i++) 
        {
                // If next element a[i] is greater than last element of
                // current longest subsequence a[b.back()], just push it at back of "b" and continue
		if (a[b.back()] < a[i]) 
                {
			p[i] = b.back();
			b.push_back(i);
			continue;
		}
 
                // Binary search to find the smallest element referenced by b which is just bigger than a[i]
                // Note : Binary search is performed on b (and not a).
                // Size of b is always <=k and hence contributes O(log k) to complexity.    
		for (u = 0, v = b.size()-1; u < v;) 
                {
			int c = (u + v) / 2;
			if (a[b[c]] < a[i]) u=c+1; else v=c;
		}
 
                // Update b if new value is smaller then previously referenced value 
		if (a[i] < a[b[u]]) 
                {
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
		}	
	}
 
	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
}
 
#include <cstdio>
int main()
{

	int n;
	scanf("%d",&n);
	int a[n];
	for(int i = 0;i<n;i++){
		scanf("%d",&a[i]);

	}
	vector<int> seq(a, a+sizeof(a)/sizeof(a[0])); 
	vector<int> lis;                              
        find_lis(seq, lis);
 
 	printf("%lu\n",lis.size());
	for (size_t i = 0; i < lis.size(); i++)
		printf("%d ", seq[lis[i]]);
        printf("\n");    
 
	return 0;
}