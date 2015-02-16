#include <stdio.h>
struct Node
{
	int n;
	Node* left;
	Node* right;
	Node(int v, Node* l=0, Node* r=0)
    : n(v), left(l), right(r)
    {}
};
void insert(Node*& head,int n){
	if(head == 0){
		head = new Node(n);
		return;
	}
	if(n< head->n) return insert(head->left,n);
	else return insert(head->right,n);
}
int find(Node* head,int n){
	if(head==0)return 0;
	if(n==head->n)return 1;
	else if(n>head->n) return find(head->right,n);
	else return find(head->left,n);

}
void print(Node* head,int dep){
	if(head==0)return;
	if(head->right!=0) print(head->right,dep+1);
	for(int i = 0;i<dep;i++)printf("...");
	printf("* %d\n",head->n);
	if(head->left!=0) print(head->left,dep+1);
	
}
int main(){
	int n,i,k;
	Node* head=0;
	scanf("%d",&n);
	for(i = 0 ;i<n;i++){
		scanf("%d",&k);
		insert(head,k);
	}
	print(head,0);
	return 0;

}