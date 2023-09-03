//code of avl-splay combine
#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

struct avl_node 
{
    int data ; 
    int height ;
    struct avl_node *left ;
    struct avl_node *right ;
};

int count_insertion = 0 , count_deletion = 0 ;

struct avl_node * avl_create_node(int x)
{
    struct avl_node *temp = new struct avl_node() ;
    temp->data = x ;
    temp->left = NULL ;
    temp->right = NULL ;
    temp -> height = 1 ;
    return temp ;
}

int avl_find_height(struct avl_node *avl_root)
{
    if(avl_root == NULL)
        return 0 ;
    else
        return avl_root->height ;
}

int avl_find_balance_factor(struct avl_node *avl_root)
{
    if(avl_root == NULL)
        return 0 ;
    return(avl_find_height(avl_root->left) - avl_find_height(avl_root->right)) ;
}


struct avl_node * avl_right_rotate(struct avl_node *avl_root1)
{
    
    struct avl_node * temp1 = avl_root1->left ;
    struct avl_node * temp2 = temp1->right ;
    temp1->right = avl_root1 ;
    avl_root1->left = temp2 ;
    //update height
    avl_root1->height = 1 + max(avl_find_height(avl_root1->left) , avl_find_height(avl_root1->right)) ;
    temp1->height = 1 + max(avl_find_height(temp1->left) , avl_find_height(temp1->right)) ; 
    avl_root1 = temp1 ;
    return avl_root1 ;
}

struct avl_node * avl_left_rotate(struct avl_node *avl_root2)
{
    struct avl_node * temp1 = avl_root2->right ;
    struct avl_node * temp2 = temp1->left ;
    temp1->left = avl_root2 ;
    avl_root2->right = temp2 ;
    //update height
    avl_root2->height = 1 + max(avl_find_height(avl_root2->left) , avl_find_height(avl_root2->right)) ;
    temp1->height = 1 + max(avl_find_height(temp1->left) , avl_find_height(temp1->right)) ;
    avl_root2 = temp1 ;
    return avl_root2 ;
}

struct avl_node * avl_search(struct avl_node *avl_root , int x)
{
    if(avl_root == NULL)
        return NULL ;
    else
    {
        bool flag = 0 ;
        if(avl_root->data == x)
        {
            flag = 1 ;
            return avl_root ;
        }
        else if(avl_root->data > x)
            flag = avl_search(avl_root->left , x) ;
        else
            flag = avl_search(avl_root->right , x) ;
    }
}

struct avl_node * avl_insert(struct avl_node *avl_root , int x)
{
    if(avl_root == NULL)
        return(avl_create_node(x)) ;
    if(avl_root->data < x)
        avl_root->right = avl_insert(avl_root->right , x) ;
    else if(avl_root->data > x)
        avl_root->left = avl_insert(avl_root->left , x) ;
    else
        return avl_root ;

    avl_root->height = 1 + max(avl_find_height(avl_root->left) , avl_find_height(avl_root->right)) ;

    int bf = avl_find_balance_factor(avl_root) ;

    //left left
    if(bf > 1 && x < avl_root->left->data)
    {
        count_insertion++ ;
        return avl_right_rotate(avl_root) ;
    }

    //left right
    if(bf > 1 && x > avl_root->left->data)
    {
        avl_root->left = avl_left_rotate(avl_root->left) ;
        count_insertion += 2 ;
        return avl_right_rotate(avl_root) ;
    }

    //right right
    if(bf < -1 && x > avl_root->right->data)
    {
        count_insertion ++ ;
        return avl_left_rotate(avl_root) ;
    }

    //right left
    if(bf < -1 && x < avl_root->right->data)
    {
        avl_root->right = avl_right_rotate(avl_root->right) ;
        count_insertion += 2 ;
        return avl_left_rotate(avl_root) ;
    }

    return avl_root ;
}

struct avl_node * avl_minValueNode(struct avl_node *avl_root)
{
    struct avl_node *current = avl_root;

    while (current->left != NULL)
        current = current->left;
 
    return current;
}

struct avl_node *avl_delete_node(struct avl_node *avl_root , int x)
{
    if (avl_root == NULL)
        return avl_root;

    if ( x < avl_root->data )
        avl_root->left = avl_delete_node(avl_root->left, x);

    else if( x > avl_root->data )
        avl_root->right = avl_delete_node(avl_root->right, x);
 
    // if key is same as root's key, then this is the node to be deleted
    else if(x == avl_root->data)
    {
        // node with only one child or no child
        if( (avl_root->left == NULL) || (avl_root->right == NULL) )
        {
            struct avl_node *temp = avl_root->left ? avl_root->left : avl_root->right;
 
            // No child case
            if (temp == NULL)
            {
                temp = avl_root;
                avl_root = NULL;
            }
            else // One child case
            *avl_root = *temp; // Copy the contents of the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder successor (smallest in the right subtree)
            struct avl_node* temp = avl_minValueNode(avl_root->right);
 
            // Copy the inorder successor's data to this node
            avl_root->data = temp->data;
 
            // Delete the inorder successor
            avl_root->right = avl_delete_node(avl_root->right, temp->data);
        }
    }
 
    // If the tree had only one node then return
    if (avl_root == NULL)
        return avl_root;
 
    // UPDATE HEIGHT OF THE CURRENT NODE
    avl_root->height = 1 + max(avl_find_height(avl_root->left), avl_find_height(avl_root->right));
 
    //GET THE BALANCE FACTOR OF THIS NODE (to check whether this node became unbalanced)
    int balance = avl_find_balance_factor(avl_root);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && avl_find_balance_factor(avl_root->left) >= 0)
    {
        count_deletion++ ;
        return avl_right_rotate(avl_root);
    }
 
    // Left Right Case
    if (balance > 1 && avl_find_balance_factor(avl_root->left) < 0)
    {
        avl_root->left = avl_left_rotate(avl_root->left);
        count_deletion += 2 ;
        return avl_right_rotate(avl_root);
    }
 
    // Right Right Case
    if (balance < -1 && avl_find_balance_factor(avl_root->right) <= 0)
    {
        count_deletion ++ ;
        return avl_left_rotate(avl_root);
    }
 
    // Right Left Case
    if (balance < -1 && avl_find_balance_factor(avl_root->right) > 0)
    {
        avl_root->right = avl_right_rotate(avl_root->right);
        count_deletion += 2 ;
        return avl_left_rotate(avl_root);
    }
    return avl_root;
}

void avl_print_tree(struct avl_node *avl_root)
{
    if(avl_root != NULL)
    {
        //printing in inorder   
        avl_print_tree(avl_root->left) ;
        cout << "Data = " << avl_root->data << "  " << "Balance factor = " << avl_find_balance_factor(avl_root) << endl ;
        avl_print_tree(avl_root->right) ;
    }
}

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

/**********red black tree***************/
int red_black_rotation = 0 ;

struct Node {
  int data;
  Node *parent;
  Node *left;
  Node *right;
  int color;
};

typedef Node *NodePtr;

class Red_blackTree {
   private:
  NodePtr root;
  NodePtr TNULL;

   void red_black_transplantation(NodePtr u, NodePtr v) {
    if (u->parent == nullptr) {
      root = v;
    } else if (u == u->parent->left) {
      u->parent->left = v;
    } else {
      u->parent->right = v;
    }
    v->parent = u->parent;
  }

  void nullNodeInitialization(NodePtr node, NodePtr parent) {
    node->data = 0;
    node->parent = parent;
    node->left = nullptr;
    node->right = nullptr;
    node->color = 0;
  }

  // Preorder
  void pre_order_helper(NodePtr node) {
    if (node != TNULL) {
      cout << node->data << " ";
      pre_order_helper(node->left);
      pre_order_helper(node->right);
    }
  }


  // Inorder
  void in_order_helper(NodePtr node) {
    if (node != TNULL) {
      in_order_helper(node->left);
      cout << node->data << " ";
      in_order_helper(node->right);
    }
  }

  // Post order
  void post_order_helper(NodePtr node) {
    if (node != TNULL) {
      post_order_helper(node->left);
      post_order_helper(node->right);
      cout << node->data << " ";
    }
  }

  NodePtr search_tree_helper(NodePtr node, int key) {
    if (node == TNULL || key == node->data) {
      return node;
    }

    if (key < node->data) {
      return search_tree_helper(node->left, key);
    }
    return search_tree_helper(node->right, key);
  }

  // For balancing the tree after deletion
  void delete_fix(NodePtr x) {
    NodePtr s;
    while (x != root && x->color == 0) {
      if (x == x->parent->left) {
        s = x->parent->right;
        if (s->color == 1) {
          s->color = 0;
          x->parent->color = 1;
          left_rotate(x->parent);
          s = x->parent->right;
        }

        if (s->left->color == 0 && s->right->color == 0) {
          s->color = 1;
          x = x->parent;
        } else {
          if (s->right->color == 0) {
            s->left->color = 0;
            s->color = 1;
            right_rotate(s);
            s = x->parent->right;
          }
        s->color = x->parent->color;
          x->parent->color = 0;
          s->right->color = 0;
          left_rotate(x->parent);
          x = root;
        }
      } else {
        s = x->parent->left;
        if (s->color == 1) {
          s->color = 0;
          x->parent->color = 1;
          right_rotate(x->parent);
          s = x->parent->left;
        }

        if (s->right->color == 0 && s->right->color == 0) {
          s->color = 1;
          x = x->parent;
        } else {
          if (s->left->color == 0) {
            s->right->color = 0;
            s->color = 1;
            left_rotate(s);
            s = x->parent->left;
          }

          s->color = x->parent->color;
          x->parent->color = 0;
          s->left->color = 0;
          right_rotate(x->parent);
          x = root;
        }
      }
      }
    x->color = 0;
  }

  void delete_node_helper(NodePtr node, int key) {
    NodePtr z = TNULL;
    NodePtr x, y;
    while (node != TNULL) {
      if (node->data == key) {
        z = node;
      }

      if (node->data <= key) {
        node = node->right;
      } else {
        node = node->left;
      }
    }

    if (z == TNULL) {
      cout << "Key not found in the tree" << endl;
      return;
    }
    y = z;
    int y_original_color = y->color;
    if (z->left == TNULL) {
      x = z->right;
      red_black_transplantation(z, z->right);
    } else if (z->right == TNULL) {
      x = z->left;
      red_black_transplantation(z, z->left);
    } else {
      y = min_key(z->right);
      y_original_color = y->color;
      x = y->right;
      if (y->parent == z) {
        x->parent = y;
      } else {
        red_black_transplantation(y, y->right);
        y->right = z->right;
        y->right->parent = y;
      }

      red_black_transplantation(z, y);
      y->left = z->left;
      y->left->parent = y;
      y->color = z->color;
    }
    delete z;
    if (y_original_color == 0) {
      delete_fix(x);
    }
  }
  void insert_node_fix(NodePtr k) {
    NodePtr u;
    while (k->parent->color == 1) {
      if (k->parent == k->parent->parent->right) {
        u = k->parent->parent->left;
        if (u->color == 1) {
          u->color = 0;
          k->parent->color = 0;
          k->parent->parent->color = 1;
          k = k->parent->parent;
        } else {
          if (k == k->parent->left) {
            k = k->parent;
            right_rotate(k);
          }
          k->parent->color = 0;
          k->parent->parent->color = 1;
          left_rotate(k->parent->parent);
        }
      } else {
        u = k->parent->parent->right;

        if (u->color == 1) {
          u->color = 0;
          k->parent->color = 0;
          k->parent->parent->color = 1;
          k = k->parent->parent;
        } else {
          if (k == k->parent->right) {
            k = k->parent;
            left_rotate(k);
          }
          k->parent->color = 0;
          k->parent->parent->color = 1;
          right_rotate(k->parent->parent);
        }
      }
      if (k == root) {
        break;
      }
    }
    root->color = 0;
  }

  void print_tree_Helper(NodePtr root, string indent, bool last) {
    if (root != TNULL) {
      cout << indent;
      if (last) {
        cout << "R----";
        indent += "   ";
      } else {
        cout << "L----";
        indent += "|  ";
      }

      string sColor = root->color ? "RED" : "BLACK";
      cout << root->data << "(" << sColor << ")" << endl;
      print_tree_Helper(root->left, indent, false);
      print_tree_Helper(root->right, indent, true);
    }
  }
  public:
  Red_blackTree() {
    TNULL = new Node;
    TNULL->color = 0;
    TNULL->left = nullptr;
    TNULL->right = nullptr;
    root = TNULL;
  }

  void preorder() {
    pre_order_helper(this->root);
  }

  void inorder() {
    in_order_helper(this->root);
  }

  void postorder() {
    post_order_helper(this->root);
  }

  int searchTree(int k) {
    return search_tree_helper(this->root, k)->data;
  }

  NodePtr min_key(NodePtr node) {
    while (node->left != TNULL) {
      node = node->left;
    }
    return node;
  }

  NodePtr max_key(NodePtr node) {
    while (node->right != TNULL) {
      node = node->right;
    }
    return node;
  }

  NodePtr rootSuccessor(NodePtr x) {
    if (x->right != TNULL) {
      return min_key(x->right);
    }

    NodePtr y = x->parent;
    while (y != TNULL && x == y->right) {
      x = y;
      y = y->parent;
    }
    return y;
  }

  NodePtr rootPredecessor(NodePtr x) {
    if (x->left != TNULL) {
      return max_key(x->left);
    }

    NodePtr y = x->parent;
    while (y != TNULL && x == y->left) {
      x = y;
      y = y->parent;
    }
    return y;
  }

  void left_rotate(NodePtr x) {
    red_black_rotation++ ;
    NodePtr y = x->right;
    x->right = y->left;
    if (y->left != TNULL) {
      y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
      this->root = y;
    } else if (x == x->parent->left) {
      x->parent->left = y;
    } else {
      x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
    
  }

  void right_rotate(NodePtr x) {
    red_black_rotation++ ;
    NodePtr y = x->left;
    x->left = y->right;
    if (y->right != TNULL) {
      y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
      this->root = y;
    } else if (x == x->parent->right) {
      x->parent->right = y;
    } else {
      x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
    
  }

  // Inserting a node
  void insert(int key) {
    NodePtr node = new Node;
    node->parent = nullptr;
    node->data = key;
    node->left = TNULL;
    node->right = TNULL;
    node->color = 1;

    NodePtr y = nullptr;
    NodePtr x = this->root;

    while (x != TNULL) {
      y = x;
      if (node->data < x->data) {
        x = x->left;
      } else {
        x = x->right;
      }
    }
    node->parent = y;
    if (y == nullptr) {
      root = node;
    } else if (node->data < y->data) {
      y->left = node;
    } else {
      y->right = node;
    }

    if (node->parent == nullptr) {
      node->color = 0;
      return;
    }

    if (node->parent->parent == nullptr) {
      return;
    }

    insert_node_fix(node);
  }

  NodePtr getRoot() {
    return this->root;
  }

  void deleteNode(int data) {
    delete_node_helper(this->root, data);
  }
  void printTree() {
    if (root) {
      //rotation = 10;
      //cout << "value of rotation : "<<rotation<<endl;
      print_tree_Helper(this->root, "", true);
    }
  }


};




int main()
{
    struct avl_node *avl_root = new struct avl_node() ;
    avl_root = NULL ;
    splay_root = NULL ;
    Red_blackTree bst;

    int sequence_size[10] = {0} ;
    int avl_rotation[10] = {0} ;
    int splay_rotaion[10] = {0} ;
    int red_black_rot[10] = {0} ;
    
    srand(time(0));
    int random_int = (rand() % 10)+1;

    for(int k = 0 ; k < 10 ; k++)
    {
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
        int s = 0 , in = 0 , d = 0  ;
        for (int i = 0; i < random_int; ++i) 
        {
            if (operationArray[i]  == 0) 
            {
                //SearchFUNCTION(searchArray[i])
                //for AVL tree
                if(avl_search(avl_root , searchArray[s])) 
                    cout << "\nElement " << searchArray[s] << " is present in avl tree " << endl;
                else
                    cout << "\nElement " << searchArray[s] << " is not present in avl tree " << endl;
                //for SPLAY tree
                if(splay_search(searchArray[s])) 
                    cout << "\nElement " << searchArray[s] << " is present in splay tree " << endl;
                else
                    cout << "\nElement " << searchArray[s] << " is not present in splay tree " << endl;
                //for red black
                if(bst.searchTree(searchArray[s]))
                    cout << "\nElement " << searchArray[s] << " is present in RED_BLACK tree " << endl;
                else
                    cout << "\nElement " << searchArray[s] << " is not present in RED_BLACK tree " << endl;
                s++ ;
            } 
            else if (operationArray[i]  == 1) 
            {
                //InsertFUNCTION(insertArray[i])
                //for AVL tree
                avl_root = avl_insert(avl_root , insertArray[in]) ;
                //for SPLAY tree
                splay_root = splay_insert(splay_root , insertArray[in]) ;
                //for red black
                bst.insert(insertArray[in]) ;
                in++ ;
            } 
            else if (operationArray[i]  == 2) 
            {
                //DeletionFUNCTION(deletionArray[i])
                //for AVL tree
                avl_root = avl_delete_node(avl_root , deleteArray[d]) ;
                //for SPLAY tree
                splay_root = splay_delete_node(deleteArray[d]) ;
                //for red black
                bst.deleteNode(deleteArray[d]) ;
                d++ ;
            }
        }

        // Don't forget to delete the dynamically allocated array
        delete[] operationArray;

        avl_print_tree(avl_root) ;
        splay_print_tree(splay_root) ;
        bst.printTree();
        cout << "\nNo of rotations  required for insert : " << count_insertion << endl ;
        cout << "\nNo of rotations  required for delete : " << count_deletion << endl << "\n\n" ;
        cout << "\nNo of zig rotations : " << zig << endl ;
        cout << "\nNo of zig_zig rotations : " << zig_zig << endl ;
        cout << "\nNo of zig_zag rotations : " << zig_zag << endl ;
        cout << "\nNo of rotations in red_black : " << red_black_rotation << endl ;

        int total_avl_rotation = count_insertion + count_deletion ;
        int total_splay_rotation = zig + zig_zig + zig_zag ;

        cout << "\nTotal avl rotations : " << total_avl_rotation << endl ;
        avl_rotation[k] = total_avl_rotation ;
        cout << "\nTotal splay rotations : " << total_splay_rotation << endl ;
        splay_rotaion[k] = total_splay_rotation ;
        cout << "\nTotal no of rotations in red_black : " << red_black_rotation << endl ;
        red_black_rot[k] = red_black_rotation ; 

        random_int += 100 ;

    } 
    ofstream myfile ("example2.txt");
    if (myfile.is_open())
    {
        for(int count = 0; count < 10; count ++)
        {
            myfile << sequence_size[count] << " " ;
        }
        myfile << "\n" ;
        for(int count = 0; count < 10; count ++)
        {
            myfile << avl_rotation[count] << " " ;
        }
        myfile << "\n" ;
        for(int count = 0; count < 10; count ++)
        {
            myfile << splay_rotaion[count] << " " ;
        }
        myfile << "\n" ;
        for(int count = 0; count < 10; count ++)
        {
            myfile << red_black_rot[count] << " " ;
        }
        myfile << "\n" ;

        myfile.close();
    }
    else cout << "Unable to open file";
}