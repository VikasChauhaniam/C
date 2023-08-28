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
    temp->parent = NULL ;

    return temp ;
}

struct node *right_rotation(struct node *root ,struct node *temp)
{
	struct node *y = temp->left ;
	temp->left = y->right ;
	y->right->parent = temp;
	y->right = temp ;
	temp->parent=y;

	return y;
}

struct node *left_rotation(struct node *root ,struct node *temp)
{
	struct node *y = temp->right ;
	temp->right = y->left ;
	y->left->parent = temp;
	y->left = temp ;
	temp->parent=y;

	return y;
}

struct node *splay(struct node *root , struct node *current)
{
	while(current->parent != NULL)
	{
		//if parent of current node is root
		if(current->parent == root)
		{
			if(current == current->parent->left)
				root = right_rotation(root , current->parent) ;
			else
				root = left_rotation(root , current->parent) ;

			return root;	
		}

		//if parent and grandparent both are present
		struct node *p = current->parent ;
		struct node *g = p->parent ;
		//4 cases are possible
		//if both are left child
		if(current == current->parent->left && p == p->parent->left)
		{
			right_rotation(root , g) ;
			right_rotation(root , p) ;
		}
		//if both are right child
		else if(current == current->parent->right && p == p->parent->right)
		{
			left_rotation(root , g) ;
			left_rotation(root , p) ;
		}
		//if current is right child of P and P is left child of g
		else if(current == current->parent->right && p == p->parent->left)
		{
			left_rotation(root , p) ;
			right_rotation(root , g) ;
		}
		//if current is left child of P and P is right child of g
		else if(current == current->parent->left && p == p->parent->right)
		{
			right_rotation(root , p) ;
			left_rotation(root , g) ;
		}
	}
	return root;
}

struct node *insert(struct node *root , int x)
{
	struct node *current = create_node(x); 
	struct node *y = root ;
	struct node *z = y ;
  

	while(y != NULL)
	{
		if(y->data < current->data){
			*z = *y;
			y = y->right ;
		}
			
		else{
			*z = *y;
			y = y->left ;
		}
	}

	current->parent = z ;
	
	if(z == NULL)
	{
		root = current ;
		return root ;
	}

	if(z->data > current->data){
		z->left = current;
	}
	else{
		y->left = current;
	}


	root = splay(root , current) ;
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
	struct node *root = new struct node() ;
    root = NULL ;
    
    root = insert(root , 12) ;
    root = insert(root , 13) ;

    print_tree(root) ;

	return 0 ;
}