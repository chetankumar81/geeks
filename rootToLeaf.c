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
void printPathRecur(struct node*,int,int[]);
void printArray(int path[],int pathlen){
	int i;
	for(i=0;i<pathlen;i++)
	printf("%d ",path[i]);
	printf("\n");
}
void printPath(struct node* root){
	int path[1000];
	printPathRecur(root,0,path);
}
void printPathRecur(struct node* root,int pathlen,int path[]){
	if(root==NULL) return;
	
	path[pathlen++] = root->data;
	if(root->left==NULL && root->right==NULL)
	printArray(path,pathlen);
	else{
		printPathRecur(root->left,pathlen,path);
		printPathRecur(root->right,pathlen,path);
	}
}



int main(){
	struct node* root = newNode(1);
	root->left = newNode(2);
	 root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	printPath(root);

	return 0;

}
