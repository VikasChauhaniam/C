#include<iostream>
using namespace std ;

struct node 
{
	int data ; 
	struct node *left ;
	struct node *right ;
	struct node *parent ;
};

struct node * create_node(int x)
{
    struct node *temp = new struct node() ;
    temp->data = x ;
    temp->left = NULL ;
    temp->right = NULL ;
    temp -> parent = NULL ;
    return temp ;
}

struct node *root = new struct node() ;

int zig = 0 ;
int zig_zig = 0 ;
int zig_zag = 0 ;

struct node* right_rotation(struct node* x)
{
    struct node* y = x->left;
    x->left = y->right;
    if (y->right != NULL)
        y->right->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->right = x;
    x->parent = y;
    return y;
}

// Left Rotation
struct node* left_rotation(struct node* x)
{
    struct node* y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
    return y;
}

struct node *splay(struct node *current)
{
 	while (current->parent != NULL)
    {
        if (current->parent == root)
        {
            if (current == current->parent->left)
                current = right_rotation(current->parent);
            else
                current = left_rotation(current->parent);
            zig++ ;
        }
        else
        {
            struct node* p = current->parent;
            struct node* g = p->parent;
            
            if (current == current->parent->left && p == p->parent->left)
            {
                right_rotation(g);
                current = right_rotation(p);
                zig_zig++ ;
            }
            else if (current == current->parent->right && p == p->parent->right)
            {
                left_rotation(g);
                current = left_rotation(p);
                zig_zig++ ;
            }
            else if (current == current->parent->right && p == p->parent->left)
            {
                left_rotation(p);
                current = right_rotation(g);
                zig_zag++ ;
            }
            else
            {
                right_rotation(p);
                current = left_rotation(g);
                zig_zag++ ;
            }
        }
    }
    root = current;
    return root;
}

struct node * insert(struct node *root , int x)
{
    struct node *current = create_node(x) ;
    struct node *temp = root ;
	struct node *y = NULL ;
	while(temp != NULL)
	{
		y = temp ;
		if(temp->data < current->data)
			temp = temp->right ;
		else
			temp = temp->left ;
	}
	current->parent = y ;
	//empty tree
	if(y == NULL)
	{
		root = current ;
		return root ;
	}
	if(current->data > y->data)
	{
		y->right = current ;
	}
	else
		y->left = current ;
	root = splay(current) ;
	return root ;
}

void print_tree(struct node *root)
{
	if(root != NULL)
    {
        //printing in inorder   
        print_tree(root->left) ;
        cout << "Data = " << root->data << "  " << endl ;
        print_tree(root->right) ;
    }
}

int main()
{
	root = NULL ;

	while(1)
	{
		cout << "Enter your option\n 1. Insertion \n 2. printing \n 3. Exit \n" ;
		int n ;
		cin >> n ;
		if(n == 1)
		{
			int x ;
            cout << "\nEnter the element to insert : " ;
            cin >> x ;
            root = insert(root , x) ;
		}
		else if(n == 2)
		{
			cout << "\nPrinting the tree : " << endl ;
			print_tree(root) ;

			
			cout << "\nNo of zig rotations : " << zig << endl ;
            cout << "\nNo of zig_zig rotations : " << zig_zig << endl ;
            cout << "\nNo of zig_zag rotations : " << zig_zag << endl ;
            
		}
		else if(n == 3)
		{
			cout << "\nEnd\n" ;
			break ;
		}
	}
	return 0 ;
}