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
	if(head==0){
		head = ins;
		return;
	}
	if(head->next==0){
		head->next = ins;
		ins->pre = head;
		return;
	}
	return insert(head->next,ins);
}

void print(Node* now){
	if(now==0)return;
	if(now->next==0) printf("Pre : %d n : %d Next : %d\n",(now->pre)->n,now->n,0);
	else printf("Pre : %d n : %d Next : %d\n",(now->pre)->n,now->n,(now->next)->n);
	print(now->next);
}

void invInsert(Node* head,Node* ins){
	if(ins==0)return;
	// printf("%d\n",ins->n);
	Node* tmp = ins->pre;
	head->next = ins;
	ins->pre = head;
	ins->next = 0;
	return invInsert(head->next,tmp);
}
int main(){
	int n,c,s;
	int nn=0;
	int tmp;
	char cm;
	scanf("%d %d",&n,&c);
	Node* head = new Node(-1);
	Node* tail;
	Node* rem[100000];
	Node* rTail[10000];
	int ri=0;
	Node* nodes[100000];
	Node* nTail[100000];
	for(int i = 0;i<n;i++){
		scanf("%d ",&tmp);
		s = nn+1;
		nn+=tmp;
		if(i==0){
			for(int j = 1;j<=nn;j++){
				Node* x = new Node(j);
				insert(head,x);
				tail = x;
			}
		}
		else{
			for(int j = s;j<=nn;j++){
				// printf("i : %d j : %d\n",i,j);
				Node* x = new Node(j);
				if(nodes[i-1]==0) nodes[i-1] = x;
				else {
					// printf("in\n");
					insert(nodes[i-1],x);
					nTail[i-1] = x;
				}
			}
		}
	}
	for(int i = 0;i<n-1;i++) printf("i : %d H:%d T:%d\n",i,nodes[i]->n,nTail[i]->n);
	Node* now = head->next;
	for(int i = 0 ;i<c;i++){
		// printf("%d\n",i);
		scanf(" %c",&cm);
		if(cm=='B'){
			if(now->pre==head){
				printf("NOW : %d\n",now->n);
				continue;
			}
			now = now->pre;
		}
		else if(cm=='F'){
			if(now->next==0){
				printf("NOW : %d\n",now->n);
				continue;
			}
			now = now->next;
		}
		else if(cm=='C'){
			scanf("%d",&tmp);
			printf("C : %c D:%d\n",cm,tmp );
			Node* t;
			for(int j = 0 ;j<n-1;j++){
				if(nodes[j]->n==tmp){
					printf("FRONT\n");
					t = nodes[j];
					
					if(now->next!=0){
						rem[ri] = now->next;
						rTail[ri] = tail;
						ri++;
					}
					now->next = t;
					t->pre = now;
					now = t;
					tail = nTail[j];
					break;
				}
			}
			if(t==0){
				for(int j = 0 ;j<n-1;j++){
					if(nTail[j]->n==tmp){
						printf("BACK\n");
						rem[ri] = now->next;
						rTail[ri] = tail;
						ri++;
						t = nTail[j];
						tail = nodes[j];
						invInsert(now,t);
						now = now->next;
						break;
					}
				}
				if(t==0){
					
					printf("REM\n");	
				}

			}

		}
		else{
			printf("??? %c\n",cm);
		}
		printf("NOW : %d\n",now->n);
		print(head->next);
		printf("H H:%d T:%d\n",(head->next)->n,tail->n);
		for(int j = 0;j<n-1;j++) printf("j : %d H:%d T:%d\n",j,nodes[j]->n,nTail[j]->n);
		for(int j = 0;j<ri;j++) printf("REM j : %d H:%d T:%d\n",j,rem[j]->n,rTail[j]->n);
		printf("---------------\n");
	}

	printf("H H:%d T:%d\n",(head->next)->n,tail->n);
	// for(int i = 0;i<n-1;i++) printf("i : %d H:%d T:%d\n",i,nodes[i]->n,nTail[i]->n);
	return 0;
}