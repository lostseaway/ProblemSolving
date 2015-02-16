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

int main(){
	int n,i,k,x;
	Node* head=0;
	scanf("%d",&n);
	for(i = 0 ;i<n;i++){
		scanf("%d %d",&k,&x);
		if(k==1){
			insert(head,x);
		}
		else {
			printf("%d\n",find(head,x));
		}
	}
	return 0;

}