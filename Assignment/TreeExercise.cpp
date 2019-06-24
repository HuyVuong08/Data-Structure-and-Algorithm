#include <iostream>

using namespace std;

struct Node { 
    int data; 
    struct Node* left; 
    struct Node* right; 
};

class BinaryTree {
    Node * root = new Node();
    root -> data = 0;
    root -> left = NULL;
    root -> right = NULL;
}

/*--------------------------------------------------------------------------*/

/*Question: 32*/

unsigned int NodeCount (const Node *root)
{
    unsigned int count = 1;
    if (root->left != NULL) {
        count += NodeCount (root->left);
    }
    if (root->right != NULL) {
        count += NodeCount (root->right);
    }
    return count;
}
 
unsigned int TreeNodeCount (const BinaryTree * Tree)
{
    unsigned int count = 0;
    if (Tree->root != NULL) {
        count += NodeCount (Tree->root);
    }
    return count;
}

/*--------------------------------------------------------------------------*/

/*Question: 33*/

unsigned int LeafCount (struct Node * Node) {
    if (Node == NULL) 
        return 0;
    if (Node -> left == NULL && Node -> right == NULL)
        return 1;
    else {
        return  LeafCount (Node -> left) + 
                LeafCount (Node -> right);
    }
}

unsigned int TreeLeafCount (const BinaryTree * Tree) {
    unsigned int count = 0;
    if (Tree->root != NULL) {
        count += NodeCount (Tree->root);
    }
    return count;
}

/*--------------------------------------------------------------------------*/

/*Question: 34*/

unsigned int LeafDelete (struct Node * Node) {
    if (Node == NULL) 
        return 0;
    if (Node -> left == NULL && Node -> right == NULL)
        return delete Node;
    else {
        return  LeafDelete (Node -> left) + 
                LeafDelete (Node -> right);
    }
} 

/*--------------------------------------------------------------------------*/

/*Question: 35*/

unsigned int maxDepth(struct Node* Node) { 
    if (Node==NULL)  
       return 0; 
    else { 
        int lDepth = maxDepth(Node->left); 
        int rDepth = maxDepth(Node->right); 
  
       
        if (lDepth > rDepth)  
            return(lDepth+1); 
        else 
            return(rDepth+1); 
    } 
}  

/*--------------------------------------------------------------------------*/

/*Question: 36*/

unsigned int IsTreeComplete (const Node * Node) {
    if (Node == NULL) 
        return 0;
    if (Node -> left == NULL && Node -> right == NULL)
        return 1;
    else {
        return  LeafDelete (Node -> left) + 
                LeafDelete (Node -> right);
    }
    return 0;
}

/*--------------------------------------------------------------------------*/

/*Question: 37*/

unsigned int IsTreeNearlyComplete (const Node * Node) {
    return !IsTreeComplete(Node);
}

/*--------------------------------------------------------------------------*/

/*  
Helper function that allocates a new Node with the 
   given data and NULL left and right pointers.
struct Node* newNode(int data)  
{ 
    struct Node* Node = (struct Node*) 
                                malloc(sizeof(struct Node)); 
    Node->data = data; 
    Node->left = NULL; 
    Node->right = NULL; 
    
    return(Node); 
} 
    
int main() 
{ 
    struct Node *root = newNode(1); 
  
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5);  
    
    printf("Hight of tree is %d", maxDepth(root)); 
    
    getchar(); 
    return 0; 
} 
*/