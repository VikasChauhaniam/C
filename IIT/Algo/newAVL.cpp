#include <iostream>
using namespace std;

struct node 
{
    int data ; 
    int height ;
    struct node *left ;
    struct node *right ;
};

int count_insertion = 0 , count_deletion = 0 ;

struct node * create_node(int x)
{
    struct node *temp = new struct node() ;
    temp->data = x ;
    temp->left = NULL ;
    temp->right = NULL ;
    temp -> height = 1 ;
    return temp ;
}

int find_height(struct node *root)
{
    if(root == NULL)
        return 0 ;
    else
        return root->height ;
}

int find_balance_factor(struct node *root)
{
    if(root == NULL)
        return 0 ;
    return(find_height(root->left) - find_height(root->right)) ;
}


struct node * right_rotate(struct node *root1)
{
    
    struct node * temp1 = root1->left ;
    struct node * temp2 = temp1->right ;
    temp1->right = root1 ;
    root1->left = temp2 ;
    //update height
    root1->height = 1 + max(find_height(root1->left) , find_height(root1->right)) ;
    temp1->height = 1 + max(find_height(temp1->left) , find_height(temp1->right)) ; 
    root1 = temp1 ;
    return root1 ;
}

struct node * left_rotate(struct node *root2)
{
    struct node * temp1 = root2->right ;
    struct node * temp2 = temp1->left ;
    temp1->left = root2 ;
    root2->right = temp2 ;
    //update height
    root2->height = 1 + max(find_height(root2->left) , find_height(root2->right)) ;
    temp1->height = 1 + max(find_height(temp1->left) , find_height(temp1->right)) ;
    root2 = temp1 ;
    return root2 ;
}

struct node * search(struct node *root , int x)
{
    if(root == NULL)
        return NULL ;
    else
    {
        bool flag = 0 ;
        if(root->data == x)
        {
            flag = 1 ;
            return root ;
        }
        else if(root->data > x)
            flag = search(root->left , x) ;
        else
            flag = search(root->right , x) ;
    }
}

struct node * insert(struct node *root , int x)
{
    if(root == NULL)
        return(create_node(x)) ;
    if(root->data < x)
        root->right = insert(root->right , x) ;
    else if(root->data > x)
        root->left = insert(root->left , x) ;
    else
        return root ;

    root->height = 1 + max(find_height(root->left) , find_height(root->right)) ;

    int bf = find_balance_factor(root) ;

    //left left
    if(bf > 1 && x < root->left->data)
    {
        count_insertion++ ;
        return right_rotate(root) ;
    }

    //left right
    if(bf > 1 && x > root->left->data)
    {
        root->left = left_rotate(root->left) ;
        count_insertion += 2 ;
        return right_rotate(root) ;
    }

    //right right
    if(bf < -1 && x > root->right->data)
    {
        count_insertion++ ;
        return left_rotate(root) ;
    }

    //right left
    if(bf < -1 && x < root->right->data)
    {
        root->right = right_rotate(root->right) ;
        count_insertion += 2 ;
        return left_rotate(root) ;
    }

    return root ;
}

struct node * minValueNode(struct node *root)
{
    struct node *current = root;

    while (current->left != NULL)
        current = current->left;
 
    return current;
}

struct node *delete_node(struct node *root , int x)
{
    if (root == NULL)
        return root;

    if ( x < root->data )
        root->left = delete_node(root->left, x);

    else if( x > root->data )
        root->right = delete_node(root->right, x);
 
    // if key is same as root's key, then this is the node to be deleted
    else if(x == root->data)
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct node *temp = root->left ? root->left : root->right;
 
            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
            *root = *temp; // Copy the contents of the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder successor (smallest in the right subtree)
            struct node* temp = minValueNode(root->right);
 
            // Copy the inorder successor's data to this node
            root->data = temp->data;
 
            // Delete the inorder successor
            root->right = delete_node(root->right, temp->data);
        }
    }
 
    // If the tree had only one node then return
    if (root == NULL)
        return root;
 
    // UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(find_height(root->left), find_height(root->right));
 
    //GET THE BALANCE FACTOR OF THIS NODE (to check whether this node became unbalanced)
    int balance = find_balance_factor(root);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && find_balance_factor(root->left) >= 0)
    {
        count_deletion++ ;
        return right_rotate(root);
    }
 
    // Left Right Case
    if (balance > 1 && find_balance_factor(root->left) < 0)
    {
        root->left = left_rotate(root->left);
        count_deletion += 2 ;
        return right_rotate(root);
    }
 
    // Right Right Case
    if (balance < -1 && find_balance_factor(root->right) <= 0)
    {
        count_deletion ++ ;
        return left_rotate(root);
    }
 
    // Right Left Case
    if (balance < -1 && find_balance_factor(root->right) > 0)
    {
        root->right = right_rotate(root->right);
        count_deletion += 2 ;
        return left_rotate(root);
    }
    return root;
}

void print_tree(struct node *root)
{
    if(root != NULL)
    {
        //printing in inorder   
        print_tree(root->left) ;
        cout << "Data = " << root->data << "  " << "Balance factor = " << find_balance_factor(root) << endl ;
        print_tree(root->right) ;
    }
}

int main()
{
    struct node *root = new struct node() ;
    root = NULL ;

    
    while(1)
    {
        cout << "\nEnter your option : \n 1. Insertion \n 2. Search \n 3. Print \n 4. Delete \n 5. Exit\n" ;
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
            int x ;
            cout << "\nEnter the element to search : " ;
            cin >> x ;
            if(search(root,x))
                cout << "\nYES , element is present" << endl ;
            else
                cout << "\nNO , element is not present" << endl ;
        }
        else if(n == 3)
        {
            cout << "\nPrinting the tree : " << endl ;
            print_tree(root) ;
        }
        else if(n == 4)
        {
            int x ;
            cout << "\nEnter the element to delete : " ;
            cin >> x ;
            root =  delete_node(root,x) ;
        }
        else if(n == 5)
        {
            cout << "\nNo of roations required for insert : " << count_insertion << endl ;
            cout << "\nNo of roations required for delete : " << count_deletion << endl ;
            break ;
        }
    }
}