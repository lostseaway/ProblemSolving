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
void print(Node* head){
	if(head==0) return;
	printf("%d\n",head->n);
	return print(head->next);
}
int main(){
	int n,tmp;
	char cm[3];
	Node* head = new Node(0);
	Node* tail = new Node(-1);
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		// std::cin >> cm >> tmp;
		scanf("%s",cm);
		// printf("%s\n",cm);

		if(strcmp(cm,"ri")==0){
			scanf("%d",&tmp);
			Node* n = new Node(tmp);
			if(head->next==0){
				head->next = n;
				n->pre = head;
				tail = n;
			}
			else{
				n->pre = tail;
				tail->next = n;
				tail = n;
			}
		}
		else if(strcmp(cm,"li")==0){
			scanf("%d",&tmp);
			Node* n = new Node(tmp);
			if(head->next==0){
				head->next = n;
				n->pre = head;
				tail = n;
			}
			else{
                (head->next)->pre = n;
				n->next = head->next;
				n->pre = head;
				head->next = n;
				if(tail->pre == head) tail->pre = n;
			}
		}
		else if(strcmp(cm,"lr")==0){
			if(head->next==0)continue;
			else{
				Node* tmp = head->next;
				if(tmp->next==0)continue;
				head->next = tmp->next;
				(head->next)->pre = head;

				tmp->pre = tail;
				tail->next = tmp;
				tail = tmp;
				tmp->next = 0;
			}
			// printf("------------\n");
			// print(head->next);

		}
		else if(strcmp(cm,"rr")==0){
			if(head->next==0)continue;
			else{
				// printf("in\n");
				Node* tmp = tail;
				if(tmp->pre==head)continue;
				tail = tail->pre;
				tail->next = 0;
				(head->next)->pre = tmp;
				tmp->next = head->next;
				tmp->pre = head;
				head->next = tmp;
			}
			
			// printf("------------\n");
			//print(head->next);
		}
		// printf("------------\n");
		//print(head->next);
	}
	print(head->next);
	return 0;
}
