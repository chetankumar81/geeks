#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
struct Node
{
    int data;
    struct Node *left, *right;
};
 
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void findMinMax(Node*root,int*min,int*max,int hd){
	if(root==NULL) return;
	if(*min > hd) *min=hd;
	else if(*max < hd) *max = hd;
	
	findMinMax(root->left, min, max,hd-1);
	findMinMax(root->right, min, max,hd+1);
}
//void printVeticalLine(Node *root,int line_no,int hd);
void printVerticalLine(Node *root,int line_no,int hd){
	if(root==NULL) return;
	
	if(hd == line_no)
	cout<<root->data<<" ";
	
	printVerticalLine((root->left),line_no,(hd-1));
	printVerticalLine((root->right),line_no,(hd+1));
}



void verticalOrder(Node* root){
	int min=0,max=0;
	findMinMax(root,&min,&max,0);
	int line_no;
	for(line_no = min;line_no <= max;line_no++){
		printVerticalLine(root,line_no,0);
		cout<<endl;
	}

}
//Using hashmap function to get the vertical order
void getVerticalOrder(Node* root,int hd, map <int ,vector<int> > &mp){
	if(root==NULL) return;
	
	mp[hd].push_back(root->data);
	
	getVerticalOrder(root->left,hd-1,mp);
	getVerticalOrder(root->right,hd+1,mp);
}

void printVerticalOrder(Node * root){
	map < int , vector <int> > mp;
	int hd =0;
	getVerticalOrder(root,hd,mp);
	
	map <int,vector<int> >::iterator it;
	int i;
	
	for(it=mp.begin();it!=mp.end();it++)
	{
		for(i=0;i<it->second.size();++i){
			cout<<it->second[i]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
    // Create binary tree shown in above figure
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
 
    cout << "Vertical order traversal is \n";
    //verticalOrder(root);
 	printVerticalOrder(root);
    return 0;
}
