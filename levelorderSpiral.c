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

void printGivenLevel(struct node* root,int level,int ltr);
int height(struct node* node);
void printLevelOrderSpiral(struct node* root){
	int h = height(root);
	int i;
	int ltr = 1;
	for(i=0;i<=h;i++){
	printGivenLevel(root,i,ltr);
	ltr = !ltr;

	}

}
void printGivenLevel(struct node* root,int level,int ltr){
	if(root==NULL) return;
	if(level == 1)
	printf("%d ",root->data);
	else if(level>1){
		if(ltr){
			printGivenLevel(root->left,level-1,ltr);
			printGivenLevel(root->right,level-1,ltr);
		}else{
			printGivenLevel(root->right,level-1,ltr);
			printGivenLevel(root->left,level-1,ltr);
		}
	}
}
int height(struct node * root){
	if(root==NULL)
	return 0;
	else{
		int lheight = height(root->left);
		int rheight = height(root->right);
		if(lheight > rheight)
			return(lheight+1);
		else
			return(rheight+1);
	}
}

int main(){
        struct node* root = newNode(1);
        root->left = newNode(2);
         root->right = newNode(3);
        root->left->left = newNode(7);
        root->left->right = newNode(6);
        root->right->left = newNode(5);
        root->right->right = newNode(4);

	
	printLevelOrderSpiral(root);
        return 0;

}


