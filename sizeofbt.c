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

int size(struct node* root){
	if(root==NULL)
	return 0;
	else
	return((size(root->left))+1+(size(root->right)));
}

int main(){
	struct node* root = newNode(1);
	root->left  = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	int si = size(root);
	printf("%d",si);
	return 0;
}
