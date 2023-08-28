//code of avl-splay combine
#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

/************************ SPLAY START *******************************/

struct splay_node 
{
    int data ; 
    struct splay_node *left ;
    struct splay_node *right ;
    struct splay_node *parent ;
};

struct splay_node * splay_create_node(int x)
{
    struct splay_node *temp = new struct splay_node() ;
    temp->data = x ;
    temp->left = NULL ;
    temp->right = NULL ;
    temp->parent = NULL ;
    return temp ;
}

struct splay_node *splay_root = new struct splay_node() ;

int zig = 0 ;
int zig_zig = 0 ;
int zig_zag = 0 ;

struct splay_node* splay_right_rotation(struct splay_node* x)
{
    struct splay_node* y = x->left;
    x->left = y->right;
    if (y->right != NULL)
        y->right->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        splay_root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->right = x;
    x->parent = y;
    return y;
}

// Left Rotation
struct splay_node* splay_left_rotation(struct splay_node* x)
{
    struct splay_node* y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        splay_root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
    return y;
}

struct splay_node *splay(struct splay_node *current)
{
    while (current->parent != NULL)
    {
        if (current->parent == splay_root)
        {
            if (current == current->parent->left)
                current = splay_right_rotation(current->parent);
            else
                current = splay_left_rotation(current->parent);
            zig++ ;
        }
        else
        {
            struct splay_node* p = current->parent;
            struct splay_node* g = p->parent;
            
            if (current == current->parent->left && p == p->parent->left)
            {
                splay_right_rotation(g);
                current = splay_right_rotation(p);
                zig_zig++ ;
            }
            else if (current == current->parent->right && p == p->parent->right)
            {
                splay_left_rotation(g);
                current = splay_left_rotation(p);
                zig_zig++ ;
            }
            else if (current == current->parent->right && p == p->parent->left)
            {
                splay_left_rotation(p);
                current = splay_right_rotation(g);
                zig_zag++ ;
            }
            else
            {
                splay_right_rotation(p);
                current = splay_left_rotation(g);
                zig_zag++ ;
            }
        }
    }
    splay_root = current;
    return splay_root;
}

struct splay_node * splay_insert(struct splay_node *splay_root , int x)
{
    struct splay_node *current = splay_create_node(x) ;
    struct splay_node *temp = splay_root ;
    struct splay_node *y = NULL ;
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
        splay_root = current ;
        return splay_root ;
    }
    if(current->data > y->data)
    {
        y->right = current ;
    }
    else
        y->left = current ;
    splay_root = splay(current) ;
    return splay_root ;
}

struct splay_node * splay_delete_node(int x)
{
    struct splay_node *temp = splay_root ;
    struct splay_node *y = NULL ;
    while(temp != NULL && temp->data != x)
    {
        y = temp ;
        if(temp->data < x)
            temp = temp->right ;
        else
            temp = temp->left ;
    }
    //value to be deleted not found
    if(temp == NULL)
    {
        if(y != NULL)
            return splay(y) ;
        else
            return splay_root ;
    }
    //Check if the node to be deleted has 0 or 1 child
    struct splay_node *t = NULL ;
    if(temp->left == NULL || temp->right == NULL)
    {
        if(temp->left == NULL)
            t = temp->right ;
        else
            t = temp->left ;
    
        //check if root to be deleted
        if(y == NULL)
        {
            t->parent == NULL ;
            return t ;
        }
        //check if temp if left child or right child of y(i.e. temp's parent)
        if(temp == y->left)
        {
            y->left = t ;
            if(t != NULL)
                t->parent = y ;
            delete temp ;
            if(y != NULL)
                return splay(y) ;
            else
                return splay_root ;
        }
        else
        {
            y->right = t ;
            if(t != NULL)
                t->parent = y ;
            delete temp ;
            if(y != NULL)
                return splay(y) ;
            else
                return splay_root ;
        }
    }
    //if node to be deleted has 2 child
    else
    {
        struct splay_node *prev = NULL ;
        struct splay_node *successor = temp->right ;
        //find successor
        while(successor->left != NULL)
        {
            prev = successor ; 
            successor = successor->left ;
        }
        //before replacing the value check if the parent node of the inorder successor
        // is the current node or not if it is not then make the left child of the parent
        // equal to the inorder successor of the right child else if inorder successor was
        // itself  the current then make the right child of the node to be deleted equal
        // To the right child of inorder successor
        prev != NULL ? prev->left = successor->right : temp->right = successor->left ;
        temp->data = successor->data ;
        if(successor->right != NULL)
            successor->right->parent = prev ;
        delete successor ;
        if(y != NULL)
            return(splay(y)) ;
        else
        {
            splay_root = temp ;
            return splay_root ;
        }
    }
    return splay_root ;
}

struct splay_node *splay_search(int x) 
{
    struct splay_node *temp = splay_root ;
    struct splay_node *y = NULL ;
    while(temp != NULL)
    {
        y = temp ;
        if(temp->data == x)
        {
            cout << x << " found" << endl ;
            return splay(temp) ;
        }
        else if(temp->data < x)
            temp = temp->right ;
        else
            temp = temp->left ;
    }
    cout << x << " not found" << endl ;
    if(y != NULL)
        return splay(y) ; 
    else
        return splay_root ;
}

void splay_print_tree(struct splay_node *splay_root)
{
    if(splay_root != NULL)
    {
        //printing in preorder   
        cout << "Data = " << splay_root->data << "  " << endl ;
        splay_print_tree(splay_root->left) ;
        splay_print_tree(splay_root->right) ;
    }
}

int main()
{
    splay_root = NULL ;

    int sequence_size[19] = {0} ;
    int splay_rotaion[19] = {0} ;
    
    for(int k = 0 ; k < 19 ; k++)
    {
        // // Generate and print random integer
        srand(time(0));
        int random_int = (rand() % 2000);

        sequence_size[k] = random_int ;

        cout << "random int is : " << random_int<<endl;

        int* operationArray = new int[random_int]; 

        srand(time(0));
        // Fill the array with random values of 0, 1, and 2
        for (int i = 0; i < random_int; ++i) 
        {
            operationArray[i] = rand() % 3; // Generate a random value between 0 and 2
        }

        int count0 = 0, count1 = 0, count2 = 0;

        for (int i = 0; i < random_int; ++i) 
        {
            cout << operationArray[i] << " ";
            if (operationArray[i]  == 0) 
            {
                count0++;
            } else if (operationArray[i]  == 1) 
            {
                count1++;
            } else if (operationArray[i]  == 2) 
            {
                count2++;
            }
        }  

        int* searchArray = new int[count0];
        int* insertArray = new int[count1];
        int* deleteArray = new int[count2]; 

        for (int i = 0; i < count0; ++i) 
        {
            searchArray[i] = rand() % 100; // Generate a random value between 0 and 99
        }

        cout << "--------------------------SearchArray-----------------"<<endl;
        for (int i = 0; i < count0; ++i) 
        {
            cout << searchArray[i] << " ";  
        }

        for (int i = 0; i < count1; ++i) 
        {
            insertArray[i] = rand() % 100; // Generate a random value between 0 and 99
        }
        cout<<endl;

        cout << "--------------------------InsertArray-----------------"<<endl;
        for (int i = 0; i < count1; ++i) 
        {
            cout << insertArray[i] << " ";  
        }

        for (int i = 0; i < count2; ++i) 
        {
            deleteArray[i] = rand() % 100; // Generate a random value between 0 and 99
        }
        cout<<endl;

        cout << "--------------------------DeleteArray-----------------"<<endl;
        for (int i = 0; i < count2; ++i) 
        {
            cout << deleteArray[i] << " ";  
        }
        cout<<endl;



//---------------------------------------------------------------HERE WE CAN ADD OUR CALLING FXNS-------------------------
        int s = 0 , in = 0 , d = 0 , temp = 0 ;
        for (int i = 0; i < random_int; ++i) 
        {
            if (operationArray[i]  == 0) 
            {
                //SearchFUNCTION(searchArray[i])
                //for SPLAY tree
                if(splay_search(searchArray[s])) 
                    cout << "\nElement " << searchArray[s] << " is present in splay tree " << endl;
                else
                    cout << "\nElement " << searchArray[s] << " is not present in splay tree " << endl;
                s++ ;
            } 
            else if (operationArray[i]  == 1) 
            {
                //InsertFUNCTION(insertArray[i])
                //for SPLAY tree
                splay_root = splay_insert(splay_root , insertArray[in]) ;
                in++ ;
            } 
            else if (operationArray[i]  == 2) 
            {
                //DeletionFUNCTION(deletionArray[i])
                //for SPLAY tree
                splay_root = splay_delete_node(deleteArray[d]) ;
                d++ ;
            }
        }

        // Don't forget to delete the dynamically allocated array
        delete[] operationArray;
        splay_print_tree(splay_root) ;
        cout << "\nNo of zig rotations : " << zig << endl ;
        cout << "\nNo of zig_zig rotations : " << zig_zig << endl ;
        cout << "\nNo of zig_zag rotations : " << zig_zag << endl ;

        int total_splay_rotation = zig + zig_zig + zig_zag ;
        cout << "\nTotal splay rotations : " << total_splay_rotation << endl ;
        splay_rotaion[k] = total_splay_rotation ;
    } 
    ofstream myfile ("example1.txt");
    if (myfile.is_open())
    {
        for(int count = 0; count < 19; count ++)
        {
            myfile << sequence_size[count] << " " ;
        }
        myfile << "\n" ;
        myfile << "\n" ;
        for(int count = 0; count < 19; count ++)
        {
            myfile << splay_rotaion[count] << " " ;
        }
        myfile << "\n" ;

        myfile.close();
    }
    else cout << "Unable to open file";
}