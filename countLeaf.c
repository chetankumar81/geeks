#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left,*right;
};

struct node* newNode(int data){
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

int countLeaf(struct node* root){
	if(root==NULL)
	return 0;
	if(root->left==NULL && root->right==NULL)
	return 1;
	else
	return(countLeaf(root->left)+countLeaf(root->right));
	
}

int main(){
	struct node* root = newNode(1);
	root->left = newNode(2);
	 root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->left->left->left = newNode(8);
	root->left->left->right = newNode(9);
	printf("%d",countLeaf(root));
	return 0;

}

