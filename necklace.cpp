#include <iostream>
#include <cstdio>
#include <string.h>
#include <stdio.h>
struct Node
{
	int n;
	Node* pre;
	Node* next;
	Node(int i, Node* n=0)
    :n(i), next(n)
    {}
};
void insert(Node* head,Node* ins){
	if(head->next==0){
		head->next = ins;
		ins->pre = head;
	}
	else{
		Node* tmp = head->next;
		head->next = ins;
		ins->pre = head;
		while(true){
			if(ins->next==0){
				ins->next = tmp;
				tmp->pre = ins;
				break;
			}
			ins = ins->next;
		}
	}
}
void print(Node* now){
	if(now==0)return;
	// printf("Val : %d Next : %d Pre : %d\n",now->n,(now->next)->n,(now->pre)->n);
	printf("%d\n",now->n);
	print(now->next);
}
int main(){
	int n,m,k;
	scanf("%d",&n);
	Node* nodes[n+1];
	for(int i = 1;i<=n;i++){
		nodes[i] = new Node(i);
	}
	for(int i = 0;i<n-1;i++){
		scanf("%d %d",&m,&k);
		insert(nodes[k],nodes[m]);

		// print(nodes[k]);
	}
	for(int i = 1;i<=n;i++){
		if(nodes[i]->pre==0){
			print(nodes[i]);
		}
	}
	return 0;
}