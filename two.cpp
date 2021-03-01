#include<iostream>
using namespace std;

struct Node 
{
	int data; 
	Node* left;
	Node* right;
};

Node* GetNewNode(int data) 
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root,int data) 
{
	if(root == NULL)                                      // empty tree
    {                                           
		root = GetNewNode(data);
	}
	
	else if(data <= root->data)                         // if data to be inserted is lesser, insert in left subtree. 
    {
		root->left = Insert(root->left,data);
	}
	
	else                                                // else, insert in right subtree. 
    {
		root->right = Insert(root->right,data);
	}
	return root;
}

void inorder_traversal(Node * root)
{
    if(root==NULL)
    return;
    else
    {
        inorder_traversal(root->left);
        cout<<root->data<<" ";
        inorder_traversal(root->right);
    }
    
}

void preorder_traversal(Node * root)
{
    if(root==NULL)
    return;
    else
    {
        cout<<root->data<<" ";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
    
}

void postorder_traversal(Node * root)
{
    if(root==NULL)
    return;
    else
    {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        cout<<root->data<<" ";
    }
    
}


int main() 
{
	Node* root = NULL;  // Creating an empty tree

	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);

    cout<<"Inorder traversal: "<<endl;
    inorder_traversal(root);
    cout<<endl;

    cout<<"Preorder traversal: "<<endl;
    preorder_traversal(root);
    cout<<endl;

    cout<<"Postorder traversal: "<<endl;
    postorder_traversal(root);
    cout<<endl;
}
