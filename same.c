#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *left,*right;
};
struct node* newNode(int data){
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = node->right = NULL;
}

int same(struct node* root1,struct node*root2){
	if(root1==NULL && root2==NULL)
		return 1;
	if(root1!=NULL && root2!=NULL)
	{
		return(root1->data==root2->data && same(root1->left,root2->left)&&same(root1->right,root2->right));
	}
	return 0;
}

int main(){
	struct node* root = newNode(1);
	root->left  = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	
	struct node * root2 = newNode(8);
	if(same(root,root2))
		printf("Tree is same");
	else
		printf("Not same");	

	return 0;
}
