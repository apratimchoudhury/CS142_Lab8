//Binary Search Tree

#include <iostream>
using namespace std;

/*

BINARY TREE:

Each node has one data and a maximum of two pointers to connect to its children
The node that does not have any parent is called the root
When the tree is empty the root becomes NULL
A node that does not have any children is called a leaf
Only one directional connection
A tree whose each node has a maximum of two pointers is called a binary tree
path, edge, length of a path, height
A tree is said to be balanced if it has the least possible height. Equivalently, only the last and the penutimate levels are allowed to have less than two children.

BINARY SEARCH TREE:

Everything that is on the left hand side has to be less than the ones on the right hand side

1. Check if current is NULL
2. If NULL, insert there
3. Else move right or left according to the values
4. And the recursion goes on

*/

class Node
{
	public:	
		int data;
		Node *left;
		Node *right;
		Node *parent;
		Node(int value)
		{
			data=value;
			left=NULL;
			right=NULL;	
			parent=NULL;
		}	
};

class BST
{
	public:
	Node *root;
	int count=0;
	BST()
	{
		root=NULL;
	}
	void insert(int value)
	{
		insertHelper(root, value);
		count++;
	}
	void insertHelper( Node *current,int value)
	{
		
		if(current==NULL) 
		{
			current = new Node(value);
			if(root==NULL)
			{
				root=current;
			}
			
			
			return;
		}
		else if(current->data>value)
		{
			if(current->left==NULL) 
			{
			    current->left=new Node(value);
			    current->left->parent=current;
			}
			else insertHelper(current->left,value);
		}
		else 
		{
			if(current->right==NULL) 
			{
			    current->right= new Node(value);
			    current->right->parent=current;
			}
		
			else insertHelper(current->right,value);
		}
	}
	
	
	
	void display()
	{
		display2(root);
		cout<<endl;
	}
	void display2(Node *current)
	{
		//base condition
		if(current==NULL) return;
		//display left
		display2(current->left);
		//display current
		cout<<current->data;
		//display right
		display2(current->right);
	}
	Node * search(int value)
	{
		return search2(root,value);
	}
	
	Node *search2(Node *current,int value)
	{
		if(current!=NULL)
		{
    		if(current->data>value)
    		{
    			return search2(current->left, value);
    		}
    		else if(current->data<value)
    		{
    			return search2(current->right, value);
    		}
    		else return current;
		}
		else return NULL;
	}

	Node * findMin(Node *current)
	{
	    if(current==NULL) return current;
	    else if(current->left!=NULL) findMin(current->left);
	    else  return current;
	}
	
	Node *findMax(Node *current)
	{
	    if(current==NULL) return current;
	    else if(current->right!=NULL) findMax(current->right);
	    else return current;
	}
	
	/*int count(Node *current)
	{
	    return count2(current,0);
	}
	
	int count2(Node *current,int counter)
	{
	    if(current==NULL)  return counter;
	    count2(current->left,counter++);
	    count2(current->right,counter++);
	}*/
	
	void replace_with_parent(Node *current,Node *temp)
	{
	    if(current==current->parent->left) current->parent->left=temp;
	    if(current==current->parent->right) current->parent->right=temp;
	}
	
	void deleteNode(int value)
	{
	    Node *current=search(value);
	    if(current->left!=NULL&&current->right!=NULL)
	    {
	        Node *temp=findMin(current->right);
	        current->data=temp->data;
	        current->right=temp->right;
	        delete temp;
	        count--;
	    }
	    
	    else if(current->left==NULL&&current->right==NULL)
	    {
	        if(current->parent->left==current) current->parent->left=NULL;
	        else if(current->parent->right==current) current->parent->right=NULL;
	        delete current;
	        count--;
	    }
	    
	    else
	    {
	        if(current->right!=NULL)
	        {
	            Node *temp=current->right;
	            current->parent->right=temp;
	            delete current;
	            count--;
	        }
	        
	        else if(current->left!=NULL)
	        {
	            Node *temp=current->left;
	            current->parent->left=temp;
	            delete current;
	            count--;
	        }
	    }    
	   
	}
	
	int countNode(Node *current)
	{
	    return count;
	}
	
	/*int rangeSearch(int p1,int p2)
	{
	    int counter=0;
	    int rangeSearch2(root,p1,p2); 
	    return counter;
	}
	
	int rangeSearch2(Node *current,int k1,int k2)
	{
	    if(current==NULL) return 0;
	    if(current->data>k1) rangeSearch2(current->left,k1,k2);
	    if(current->data>=k1&&current->data<=k2)
	    {
	        cout<<current->data<<" ";
	        counter++;
	        
	    }
	    if(current->data<k2) rangeSearch2(current->rught,k1,k2);
	}*/
	
	int height(Node *current)
	{
	    if(current==NULL) return 0;
	    else
	    {
	        int lheight=height(current->left);
	        int rheight=height(current->left);
	        
	        if(lheight>rheight) return (lheight+1);
	        else return (rheight+1);
	    }
	}
	
	int rangeSearch(int k1,int k2)
	{
	    int counter=0;
	    for(int i=k1;i<=k2;i++)
	    {
	        if(search(i)!=NULL)
	        {
	            cout<<i;
	            counter++;
	        }
	    }
	    cout<<endl;
	    return counter;
	}
	
};

int main()
{
	BST t1;
	t1.insert(3);
	t1.insert(4);
	t1.insert(7);
	t1.insert(2);
	t1.insert(6);
	t1.insert(8);
	t1.display();
	if(t1.search(3)->data==3) cout<<"Present!"<<endl;
	else cout<<"Absent!"<<endl;
	cout<<t1.findMin(t1.root)->data<<endl;
	
	t1.deleteNode(3);
	t1.display();
	
	cout<<t1.countNode(t1.root)<<endl;
	
	t1.rangeSearch(3,6);
	

	

	return 0;
}

















