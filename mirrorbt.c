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

void inorder(struct node* root){
	if(root == NULL)
	return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

void mirror(struct node* root){
	if(root == NULL)
	return;
	else{
		mirror(root->left);
		mirror(root->right);
		
		struct node* temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}

int main(){
        struct node* root = newNode(1);
        root->left  = newNode(2);
        root->right = newNode(3);
        root->left->left = newNode(4);
        root->left->right = newNode(5);
        root->right->left = newNode(6);
        root->right->right = newNode(7);
        
	inorder(root);
	printf("\n");
	mirror(root);
	inorder(root);
        return 0;
}   
