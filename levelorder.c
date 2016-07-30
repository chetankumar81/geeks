#include <stdio.h>
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

void printGivenLevel(struct node* root,int level);
int height(struct node* root);
void printLevelOrder(struct node* root){
	int h = height(root);
	int i;
	for(i=0;i<=h;i++){
		printGivenLevel(root,i);
		printf("\n");
	}
}
void printGivenLevel(struct node* root,int level){
	if(root == NULL)
	return;
	if(level ==1){
		printf("%d ",root->data);
	}
	if(level>1){
		printGivenLevel(root->left,level-1);
		printGivenLevel(root->right,level-1);
	}	
}
int height(struct node* root){
	if(root==NULL)
		return 0;
	else{
		int lheight = height(root->left);
		int rheight = height(root->right);
		
		if(lheight>rheight)
			return(lheight+1);
		else
			return(rheight+1);
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
	printLevelOrder(root);

	return 0;
}

