#include <iostream>
#include <queue>

using namespace std;

struct node{
	int data;
	struct node *left,*right;	
};

node* newNode(int data){
	node* temp = new node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return (temp);
}
void printLevelOrder(node *root)
{
    // Base Case
    if (root == NULL)  return;
 
    // Create an empty queue for level order tarversal
    queue<node *> q;
 
    // Enqueue Root and initialize height
    q.push(root);
 
    while (1)
    {
        // nodeCount (queue size) indicates number of nodes
        // at current lelvel.
        int nodeCount = q.size();
        if (nodeCount == 0)
            break;
 
        // Dequeue all nodes of current level and Enqueue all
        // nodes of next level
        while (nodeCount > 0)
        {
            node *node1 = q.front();
            cout << node1->data << " ";
            q.pop();
            if (node1->left != NULL)
                q.push(node1->left);
            if (node1->right != NULL)
                q.push(node1->right);
            nodeCount--;
        }
        cout << endl;
    }
}

int main(){
	node* root = newNode(1);
	root->left  = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	
	printLevelOrder(root);
	
	return 0;
}
