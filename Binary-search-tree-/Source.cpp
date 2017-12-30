#include <iostream>
#include <queue>
using namespace std;

struct node
{
	int data;
	node *left = NULL;
	node * right = NULL;
};
class BST
{
public:
	void Create(node *(&), int &);//passing arguments by reference is more efficient
	void Preorder(node *(&));
	void Inorder(node *(&));
	void Postorder(node *(&));
	void Eachlevel(node *(&));
};

void BST::Create(node *(&root), int &n)
{
	if (root == NULL)
	{
		root = new node;
		root->data = n;
	}
	else//root is not null
	{
		if (n <= root->data)   Create(root->left, n);
		else    Create(root->right, n);
	}
/*
by passing the root pointer as reference, every change to it will also change the root poiter in the mian. 
Then, when passing the root pointer into other functions after the for loop, it is no longer null.

this is important. Because if this root pointer is not passed by reference, the root pointer will always remain
as null since this root pointer will be out of scope after this function.

Before realized this, i always declare the root pointer inside the class. Although I successfully made the create function work, but everything is out of scope after the for loop
in the main. Then the pointer that pass into other functions is just the same null pointer before the for loop

*/
}
void BST::Preorder(node *(&root))
{	
	if(root!=NULL)
	{
	cout << root->data << " ";
	Preorder(root->left);
	Preorder(root->right);
	}
}
void BST::Inorder(node *(&root))
{
	if (root != NULL)
	{
		Inorder(root->left);
		cout << root->data << " ";
		Inorder(root->right);
	}
}
void BST::Postorder(node *(&root))
{
	if (root != NULL)
	{
		Postorder(root->left);
		Postorder(root->right);
		cout << root->data << " ";
	}
}
void BST::Eachlevel(node *(&root))
{
	if (root == NULL) return;

	queue<node*> q;
	q.push(root);//everything in root is pushed into q

	while (!q.empty())
	{
		cout << q.front()->data << " ";//q.front() is just like root
		if (q.front()->left != NULL) q.push(q.front()->left);//push the number into the queue
		if (q.front()->right != NULL) q.push(q.front()->right);
		q.pop();//pop off the element from left side, so the next couot will output the next element
	}

}
int main()
{
	node *root = NULL;//this is where and all i need to declare this pointer
	BST bo;//binary search tree object
	int size;
	cout << " Enter the size of the tree--";
	cin >> size;
	cout << "Enter the numbers:" << endl;
	for (int x = 0; x < size; x++)
	{
		int n;
		cin >> n;
		bo.Create(root, n);
	}

	cout << "Preorder is:" << endl;
	bo.Preorder(root);//is temp still null here?
	cout << endl;

	cout << "Inorder is:" << endl;
	bo.Inorder(root);
	cout << endl;

	cout << "Postorder is:" << endl;
	bo.Postorder(root);
	cout << endl;

	cout << "numbers in each level:" << endl;
	bo.Eachlevel(root);
	cout << endl;

	system("pause");
}

/*

level order traversal
3 5 2 1 4 6=                             3
                            2                        5
		    1                         4            6
everything is pushed into queue

cout 3----------------------
push 2 5
pop 3
cout 2--------------------------
push 1
null
pop 2
cout 5-----------------------------
 push 4 6
 pop 5
 cout 1--------------------------
 pop 1
 cout 4---------------------------------
 pop 4
 cout 6-------------------
 pop 6
 empty
 exit



3 5 2 1 4 6=                             3
                                2                  5
			    1                  4       6


pre-order
a,r->d
b, r->l
c, r->r

 r->d=3---------------------------------------------------
 r->l,
 back to a
 r->l->d=2------------------------------------------------
 r->l->l, 
 back to a
 r->l->l->d=1----------------------------------------------------
 r->l->l->l=null
 down to c
 r->l->l->r=null
 retreat back to r->l and beginning
 r->l->d=already done
 r->l->l already done still r->l
 r->l->r  =null
 left branch all done
 goes to c
 r->r
 goes to a
 r->r->d=5------------------------------------------------
 goes to b
 r->r->l
 goes to c
 r->r->l->r=null
 goes to a
 r->r->l->d=4-------------------------------------------------
 goes to b
 r->r->l->l=NULL retreat to r->r
 goes to c
 r->r->r
 goes to a
 r->r->r->d=6--------------------------------------------
 goes to b
 r->r->r->l=null
 goes to c
 r->r->r->r=null
 done


 in order and post order are kind of same recurssive steps

 

*/
