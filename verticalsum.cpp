#include<bits/stdc++.h>
using namespace std;

struct Node{
	Node *left,*right;
	int data;
	Node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

map<int,int> m ;
void verticalsum(Node *root ,int d)
{
	if(root == NULL)
		return;
	
	m[d] = m[d]+root->data;
	
	verticalsum(root->left,d-1);
	verticalsum(root->right,d+1);
	
}

int main()
{
	Node *root = new Node(1); 
    root->left        = new Node(2); 
    root->right       = new Node(3); 
    root->left->left  = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left  = new Node(6); 
    root->right->right = new Node(7); 
    
   	verticalsum(root,0);
   	
   	map<int,int>::iterator it;
	    
		for(it = m.begin();it!=m.end();it++)
		{
			cout<<(it->first)<<" "<<(it->second)<<"\n";
		}   
			
   	return 0;
}
