#include <stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *left,*right;
};
struct node* newNode(int data){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return(temp);
}
void inorder(struct node* root){
	if(root==NULL) return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

void del(struct node* node){
	if(node == NULL)
	return;
	del(node->left);
	del(node->right);
	
	printf("\n Deleting node %d",node->data);
	free(node);
}

int main(){
	struct node* root = newNode(1);
	root->left  = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
	inorder(root);
	del(root);
	root = NULL;
	
	printf("\nTree Deleted");
	return 0;
}
