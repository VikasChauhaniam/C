// Implementing Red-Black Tree in C++

#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;


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

  // For balancing the tree after insertion
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
    while (y != TNULL && x == y->right) {Dell XPS 13 (9315)
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



int main() {
    Red_blackTree bst;
    //bst.insert(55);
     
    //bst.printTree();
   // bst.deleteNode(40);

   // int x = bst.searchTree(40);
   // int y = bst.searchTree(5);
     
  //=========================================================

    unsigned int seed1;

    cout<< "Enter Seed1 for range : ";
    cin>>seed1;

    std::mt19937 rng(seed1);

    int random_int = 5 ;

    cout << "random int is : " << random_int<<endl;

    int* operationArray = new int[random_int]; 

    int seed2;
    cout << "Enter a seed2 value for 012: ";
    cin >> seed2;

    srand(seed2); // Set the seed for the random number generator

    // Fill the array with random values of 0, 1, and 2
    for (int i = 0; i < random_int; ++i) 
    {
        operationArray[i] = rand() % 3; // Generate a random value between 0 and 2
    }

    // Display the array elements
    cout << "Array elements: ";

    int count0 = 0, count1 = 0, count2 = 0;

    for (int i = 0; i < random_int; ++i) {
        cout << operationArray[i] << " ";
        if (operationArray[i]  == 0) {
            count0++;
        } else if (operationArray[i]  == 1) {
            count1++;
        } else if (operationArray[i]  == 2) {
            count2++;
        }
    }
    cout << endl;

    std::cout << "Count of 0s: " << count0 << std::endl;
    std::cout << "Count of 1s: " << count1 << std::endl;
    std::cout << "Count of 2s: " << count2 << std::endl;

    int* searchArray = new int[count0];
    int* insertArray = new int[count1];
    int* deleteArray = new int[count2]; 

    for (int i = 0; i < count0; ++i) {
        searchArray[i] = rand() % 100; // Generate a random value between 0 and 99
        
    }

    cout << "--------------------------SearchArray-----------------"<<endl;
    for (int i = 0; i < count0; ++i) {
        cout << searchArray[i] << " ";  
    }

     for (int i = 0; i < count1; ++i) {
        insertArray[i] = rand() % 100; // Generate a random value between 0 and 99
    }cout<<endl;

    cout << "--------------------------InsertArray-----------------"<<endl;
    for (int i = 0; i < count1; ++i) {
        cout << insertArray[i] << " ";  
    }

     for (int i = 0; i < count2; ++i) {
        deleteArray[i] = rand() % 100; // Generate a random value between 0 and 99
    }cout<<endl;

    cout << "--------------------------DeleteArray-----------------"<<endl;
    for (int i = 0; i < count2; ++i) {
        cout << deleteArray[i] << " ";  
    }cout<<endl;



//---------------------------------------------------------------HERE WE CAN ADD OUR CALLING FXNS-------------------------
    int s = 0 , in = 0 , d = 0 , temp = 0 ;
    for (int i = 0; i < random_int; ++i) 
    {
        if (operationArray[i]  == 0) 
        {
        	//SearchFUNCTION(searchArray[i])
            //for RED BLACK tree
        	if(bst.searchTree(searchArray[s]))
        		cout << "\nElement " << searchArray[s] << " is present in RED_BLACK tree " << endl;
        	else
        		cout << "\nElement " << searchArray[s] << " is not present in RED_BLACK tree " << endl;
            
        	s++ ;
        } 
        else if (operationArray[i]  == 1) 
        {
            //InsertFUNCTION(insertArray[i])
            //for RED BLACK tree
        	bst.insert(insertArray[in]) ;
        	in++ ;
        } 
        else if (operationArray[i]  == 2) 
        {
            //DeletionFUNCTION(deletionArray[i])
            //for AVL tree
            bst.deleteNode(deleteArray[d]) ;
            d++ ;
        }
    }

    // Don't forget to delete the dynamically allocated array
    delete[] operationArray;

    bst.printTree();

   // cout << "\nTotal splay rotations : " << rotation << endl ; 
    
}