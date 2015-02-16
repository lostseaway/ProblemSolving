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
// void insert(Node*& head,int n){
// 	if(head == 0){
// 		head = new Node(n);
// 		return;
// 	}
// 	if(n< head->n) return insert(head->left,n);
// 	else return insert(head->right,n);
// }
void insert(Node*& head,Node* tn){
	if(head == 0){
		head = tn;
		return;
	}
	if(tn->n<head->n) return insert(head->left,tn);
	else return insert(head->right,tn);
}
int find(Node* head,int n){
	if(head==0)return 0;
	if(n==head->n)return 1;
	else if(n>head->n) return find(head->right,n);
	else return find(head->left,n);

}
void deleteBST(Node* head,int n){
	if(n==head->n){
		if(head->right==0&&head->left==0)head =0 ;
		else if(head->right!=0 && head->left==0)head = head->right;
		else if(head->right==0 && head->left!=0)head = head->left;
		else{
			Node* tmp = head->left;
			head = head->right;
			insert(head,tmp);
		}
	}
	else if(n==(head->right)->n){
		Node* tr = head->right;
		if(tr->right==0&&tr->left==0)tr =0 ;
		else if(tr->right!=0 && tr->left==0)tr = tr->right;
		else if(tr->right==0 && tr->left!=0)tr = tr->left;
		else{
			Node* tmp = tr->left;
			tr = tr->right;
			insert(tr,tmp);
		}
		head->right = tr;
	}
	else if(n==(head->left)->n){
		Node* tr = head->left;
		if(tr->right==0&&tr->left==0)tr =0 ;
		else if(tr->right!=0 && tr->left==0)tr = tr->right;
		else if(tr->right==0 && tr->left!=0)tr = tr->left;
		else{
			Node* tmp = tr->left;
			tr = tr->right;
			insert(tr,tmp);
		}
		head->left = tr;
	}
	else if(n>head->n) return deleteBST(head->right,n);
	else return deleteBST(head->left,n);
}

void print(Node* head,int dep){
	if(head==0)return;
	if(head->right!=0) print(head->right,dep+1);
	for(int i = 0;i<dep;i++)printf("...");
	printf("* %d\n",head->n);
	if(head->left!=0) print(head->left,dep+1);
	
}
int main(){
	int n,i,k,x;
	Node* head=0;
	scanf("%d",&n);
	for(i = 0 ;i<n;i++){
		scanf("%d %d",&k,&x);
		if(k==1){
			Node* xx = new Node(x);
			insert(head,xx);
		}
		else if(k==2)printf("%d\n",find(head,x));
		else{
			if(find(head,x)){
				// printf("in\n");
				deleteBST(head,x);
			}
		}
		// printf("xxxxxxxxxxxxxxxx\n");
		// print(head,0);
	}
	return 0;

}