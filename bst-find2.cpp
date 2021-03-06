#include <stdio.h>
struct Node
{
	int n;
	Node* left;
	Node* right;
	int nl;
	int nr;
	Node(int v, Node* l=0, Node* r=0)
    : n(v), left(l), right(r),nl(0),nr(0)
    {}
};
int insert(Node*& head,int n){
	if(head == 0){
		head = new Node(n);
		return 0;
	}
	if(n< head->n) {
		head->nl+=1;
		if(insert(head->left,n))head->nl-=1;
	}
	else {
		head->nr+=1;
		if(insert(head->right,n))head->nr-=1;
	}
	int r = head->nr;
	int l = head->nl;
	int dif = r>l?r-l:l-r;

}
int find(Node* head,int n){
	if(head==0)return 0;
	if(n==head->n)return 1;
	else if(n>head->n) return find(head->right,n);
	else return find(head->left,n);

}
int findC(Node* head,int n){
	if(head==0)return 0;
	int sum = 0;
	if(head->n>n)sum++;
	if(head->n>=n&&head->right!=0)sum+=head->nr;
	else if(head->right!=0)sum+=findC(head->right,n);
	if(head->left!=0 && head->n > n)sum+=findC(head->left,n);
	return sum;
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
		// printf("------------------\n");
		// print(head,0);
	}
	return 0;

}