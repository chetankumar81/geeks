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
int sumProperty(struct node* root){
	int left_data = 0, right_data = 0;
	if(root==NULL||root->left==NULL && root->right==NULL)
	return 1;
	else{
	
		if(root->left!=NULL)
			left_data = root->left->data;
		
		if(root->right!=NULL)
			right_data = root->right->data;
		
		if((root->data == left_data + right_data) && sumProperty(root->left) && sumProperty(root->right))
		return 1;
		else
		return 0;
	}
}

int main(){
	struct node* root = newNode(10);
	root->left = newNode(8);
	 root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(5);
	root->right->left = newNode(2);
	
	if(sumProperty(root))
	printf("YES");
	else
	printf("NO");

	return 0;

}
