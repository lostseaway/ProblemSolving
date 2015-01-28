#include <iostream>
#include <cstdio>
struct ListNode
{
	int val;
	ListNode* next;

	 ListNode(int v, ListNode* n=0)
    :val(v), next(n)
  {}
};
void print(ListNode* head){
	ListNode* list = head->next;
	while(list!=0){
		printf("%d\n",list->val);
		list=list->next;
	}
}

// void del(ListNode* pre,ListNode* now,int n){
// 	if(now==0)return ;
// 	if(now->val==n){
// 		pre->next = now->next;
// 		return;
// 	}
// 	return del(now,now->next,n);
// }

void del(ListNode* pre,ListNode* now,int n,int i){
	
	if(now==0)return ;
	// printf("%d %d %d\n",n,i,now->val);
	if(i==n){
		pre->next = now->next;
		delete now;
		return;
	}
	return del(now,now->next,n,i+1);
}

void app(ListNode* now,ListNode* ap){
	if(now->next==0){
		now->next = ap;
		return;
	}
	return app(now->next,ap);
}

int main(){
 	int n,t2;
 	char t1;
 	ListNode* head = new ListNode(0);
 	scanf("%d",&n);
 	for(int i = 0;i<n;i++){
 		std::cin >> t1 >> t2;
 		// scanf("%c %d ",&t1,&t2);
 		// printf("%c\n",t1);
 		if(t1=='I'){
 			ListNode* nn = new ListNode(t2);
 			nn->next = head->next;
 			head->next = nn;
 		}
 		if(t1=='D'){
 			del(head,head->next,t2,1);
 		}
 		if(t1=='A'){
 			ListNode* nn = new ListNode(t2);
 			app(head,nn);
 		}
 	}
 	print(head);
 	return 0;
}