#include <iostream>

#include "DataStructure.h"

using namespace std;

int main () 
{

    AVL<int> AVL;
    AVL.Insert (AVL.pRoot, 5);
    AVL.Insert (AVL.pRoot,7);
    AVL.Insert (AVL.pRoot,4);

    AVL.PrintPreOrder (AVL.pRoot);
    
    cout << "abc";
    return 0;
}
