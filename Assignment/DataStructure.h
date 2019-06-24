#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//-----------------------------************* NODE *************-----------------------------//

template <class T>
struct Node
{
    T data;
    Node<T> * pNext;
};

//-----------------------------************* LINKED LIST *************-----------------------------//

template <class T>
class LinkedList
{
    Node<T> * pHead;
    int count;

    public: 
        LinkedList ();
        ~LinkedList ();

        //int InsertNode (Node<T> * pPre, T data);
        void InsertFirst (T data);
        void InsertLast (T data);
        int Insert2Position (T data, int position);

        void DeleteFirst ();
        void DeleteLast ();
        int DeletePosition (int position);
        int GetItem (int position, T & DataOut);

        void Traverse ();
        void Traverse2 (T * & visit);
        LinkedList<T> * Clone ();
        void Print2Console ();
        void Clear ();
        void Reverse ();

    protected:    
        int InsertNode (Node<T> * pPre, T data);
        T DeleteNode (Node<T> * pPre, Node<T> * pDel);
        int Search (T data, Node<T> * & pPre, Node<T> * & pLoc);
};

template <class T>
LinkedList<T> :: LinkedList()
{
    this -> pHead = NULL;
    this -> count = 0;
}

/*
template <class T>
int LinkedList<T> :: InsertNode (Node<T> * pPre, T data) {
    Node<T> * pNew = new Node<T> ();
    if (pNew == NULL) {
        return 0;
    }
    pNew -> data = data;
    if (pPre == NULL) {
        pNew -> pNext = this -> pHead;
        this -> pHead = pNew;
    } else {
        pNew -> pNext = pPre -> pNext;
        pPre -> pNext = pNew;
    }
    this -> count ++;
    return 1;
}
*/

template <class T>
T LinkedList<T> :: DeleteNode (Node<T> * pPre, Node<T> * pDel)
{
    T result = pDel -> data;
    if (pPre == NULL)
    {
        this -> pHead = pDel -> pNext;
    }
    else
    {
        pPre -> pNext = pDel -> pNext;
    }
    this -> count --;
    delete pDel;
    return result;
}

template <class T>
int LinkedList<T> :: Search (T data, Node<T> * & pPre, Node<T> * & pLoc)
{
    pPre = NULL;
    pLoc = this -> pHead; 

    while (pLoc != NULL && pLoc -> data != data)
    {
        pPre = pLoc;
        pLoc = pLoc -> pNext;    
    }

    return (pLoc != NULL);
}

template <class T>
void LinkedList<T> :: Traverse ()
{
    Node<T> * p = this -> pHead;
    while (p != NULL)
    {
        p -> data ++;
        p = p -> pNext;
    }
}

template <class T> 
void LinkedList<T> :: Traverse2 (T * & visit)
{
    Node<T> * p = this -> pHead;
    int i = 0;
    while (p != NULL && i < this -> count)
    {
        visit[i] = p -> data;
        p = p -> pNext;
        i ++;
    }
}

template <class T>
void LinkedList<T> :: Clear ()
{
    Node<T> * pTemp;
    while ( this -> pHead != NULL)
    {
        pTemp = this -> pHead;
        this -> pHead = this -> pHead -> pNext;
        delete pTemp;
    }
    this -> count = 0;
}

template <class T>
LinkedList<T> :: ~LinkedList() {
    this -> Clear ();
}

template <class T>
int LinkedList<T> :: Insert2Position (T data, int position)
{
    if (position < 0 || position > this -> count)
        return 0;

    Node<T> * pNew, * pPre;
    pNew = new Node<T> ();

    if (pNew == NULL)
        return 0;
    
    pNew -> data = data;

    if (pHead == NULL)
    {
        pHead = pNew;
        pNew -> pNext = NULL;
    }
    else if (position == 0)
    {
        pNew -> pNext = pHead;
        pHead = pNew;
    }
    else
    {
        pPre = this -> pHead;
        for (int i = 0; i < position - 1; i ++)
            pPre = pPre -> pNext;
        pNew -> pNext = pPre -> pNext;
        pPre -> pNext = pNew;
    }
    this -> count ++;
    return 1;
}

template <class T>
int LinkedList<T> :: DeletePosition (int position)
{
    if (position < 0 || position > this -> count)
        return 0;

    Node<T> * pDel, * pPre;

    if (position == 0)
    {
        pDel = pHead;
        pHead = pHead -> pNext;
    }
    else
    {
        pPre = this -> pHead;
        for (int i = 0; i < position -1; i ++)
            pPre = pPre -> pNext;
        pDel = pPre -> pNext;
        pPre -> pNext = pDel -> pNext;
    }
    delete pDel;
    this -> count --;
    return 1;
}

template <class T>
LinkedList<T> * LinkedList<T> :: Clone ()
{
    LinkedList<T> * result = new LinkedList<T> ();
    Node<T> * p = this -> pHead;

    while (p != NULL)
    {
        result -> InsertLast (p -> data);
        p = p -> pNext;
    }

    result -> count = this -> count;
    return result;
}

//-----------------------------************* STACK *************-----------------------------//

template <class T>
class Stack
{
    public:
        Stack ();
        ~Stack ();

        void Push (T DataIn);
        T Peek ();
        int Pop (T & DataOut);
        int GetStackTop (T & DataOut);
        void Clear ();
        int isEmpty ();
        int isFull ();
        int GetSize ();
        Stack<T> * Clone ();
        void Print2Console ();

    private:
        Node<T> * top;
        int count;
};

template <class T>
Stack<T> :: Stack ()
{
    this -> top = NULL;
    this -> count = 0;
}

template <class T>
Stack<T> :: ~Stack ()
{
    this -> Clear ();
}

template <class T>
void Stack<T> :: Push (T DataIn)
{
    Node<T> * pNew = new Node<T> ();
    pNew -> data = DataIn;
    pNew -> pNext = this -> top;
    this -> top = pNew;
    this -> count ++;
}

template <class T>
T Stack<T> :: Peek ()
{
    return this -> top -> data;
}

template <class T>
int Stack<T> :: Pop (T & DataOut)
{
    if (this -> GetSize () == 0)
        return 0;
    
    Node<T> * pDel = this -> top;
    DataOut = pDel -> data;
    this -> top = pDel -> pNext;
    this -> count --;
    delete pDel;
    return 1;
}

template <class T>
int Stack<T> :: GetStackTop (T & DataOut)
{
    if (this -> GetSize () == 0)
        return 0;

    DataOut = this -> top -> data;
    return 1;
}

template <class T>
void Stack<T> :: Clear ()
{
    Node<T> * pTemp;
    while (this -> top != NULL)
    {
        pTemp = this -> top;
        this -> top  = this -> top -> pNext;
        delete pTemp;
    }
}

template <class T>
int Stack<T> :: isEmpty ()
{
    return (this -> count == 0);
}

template <class T>
int Stack<T> :: GetSize ()
{
    return this -> count;
}

template <class T>
int Stack<T> :: isFull ()
{
    Node<T> * pNew = new Node<T> ();

    if (pNew != NULL)
    {
        delete pNew;
        return 0;
    }
    else
    {
        return 1;
    }
}

template <class T>
void Stack<T> :: Print2Console ()
{
    Node<T> * p;
    p = this -> top;

    while (p != NULL) {
        cout << p -> data << " ";
        p = p -> pNext;
    }

    cout << endl;
}

//-----------------------------************* Binary Search Tree *************-----------------------------//

template <class T>
struct BinTreeNode
{
    T Data;
    BinTreeNode<T> * pLeft;
    BinTreeNode<T> * pRight;

    BinTreeNode<T> (T DataIn) 
    {
        this -> Data = DataIn;
        this -> pLeft = NULL;
        this -> pRight = NULL;
    }
};

template <class T>
class BST
{
    BinTreeNode<T> * pRoot; 
    int count;
    
    public:
        void Insert (BinTreeNode<T> * & pRoot, T Data);
};

template <class T>
void BST<T> :: Insert (BinTreeNode<T> * & pRoot, T Data)
{
    if (pRoot == NULL) 
        pRoot = new BinTreeNode<T> (Data);
    else 
    {
        if (Data < pRoot -> Data) Insert (pRoot -> pLeft, Data);
        else Insert (pRoot -> pRight, Data);
    }
}

/*
template <class T>
void BST<T> :: PrintPreOrder (BinTreeNode<T> * pRoot) { 
    if (pRoot == NULL) return;
    
    cout << pRoot -> Data << ' ';
    PrintPreOrder (pRoot -> pLeft);
    PrintPreOrder (pRoot -> pRight);
    return;
}


template <class T>
int BST<T> :: isBST (BinTreeNode<T> * root) {
    if (root == NULL) return 1;
    if (root -> pLeft != NULL && root -> pLeft > root -> Data) return 0;
    if (root -> pRight != NULL && root -> pRight < root -> Data) return 0;
    if (!isBST (root -> pLeft) || !isBST (root -> pRight)) return 0;
    return 1;
}

//template <class T>
bool isArrayAnBST (int pre[], int n) {
    Stack<int> s;
    int root = INT_MIN;

    for (int i = 0; i < n; i ++) {
        if (pre[i] < root) return false;

        int out;
        s.GetStackTop (out);
        while (!s.isEmpty () && out < pre[i]) {
        root = s.GetStackTop (out);
        int ignore;
        s.Pop (ignore);
        }
        s.GetStackTop (out);
        s.Push (pre[i]);
    }
    return true;
}

int ArraySearch (int Array[], int x, int n) {
    for (int i = 0; i < n; i ++) {
        if (Array[i] == x) return i;
        return -1;
    }
}


//template <class T>
void printPostFromInAndPreOrder (int in[], int pre[], int n) {
    int root = ArraySearch (in, pre[0], n);

    if (root != 0) printPostFromInAndPreOrder (in, pre + 1, root);
    if (root != n - 1) printPostFromInAndPreOrder (in + root +1, pre + root + 1, n - root - 1);

    cout << pre[0] << " "; 
}
*/

//-----------------------------************* AVL Tree *************-----------------------------//

enum BallanceFactor
{
    LH = -1,
    EH,
    RH
};

template <class T>
struct AVLNode {
    T Data;
    AVLNode<T> * pLeft;
    AVLNode<T> * pRight;
    BallanceFactor BF; 

    AVLNode (T DataIn)
    {
        this -> Data = DataIn;
        this -> pLeft = NULL;
        this -> pRight = NULL;
        this -> BF = EH;
    }
};

template <class T>
class AVL 
{
    public:
        AVLNode<T> * pRoot; 
        int count;
    
        void RotateRight (AVLNode<T> * & pRoot);
        void RotateLeft (AVLNode<T> * & pRoot);
        void RotateLeftRight (AVL<T> * & pRoot);
        void RotateRightLeft (AVL<T> * & pRoot);
        bool Insert (AVLNode<T> * &pRoot, T Data);
        void PrintPreOrder (AVLNode<T> * pRoot);
        bool BallanceLeft (AVLNode<T> * & pRoot);
};

template <class T>
void AVL<T> :: RotateRight (AVLNode<T> * & pRoot)
{
    AVLNode<T> * pTemp = pRoot -> pLeft;
    pRoot -> pLeft = pTemp -> pRight;
    pTemp -> pRight = pRoot;
    pRoot = pTemp;
}

template <class T>
void AVL<T> :: RotateLeft (AVLNode<T> * & pRoot)
{
    AVLNode<T> * pTemp = pRoot -> pRight;
    pRoot -> pRight = pTemp -> pLeft;
    pTemp -> pLeft = pRoot;
    pRoot = pTemp;
}

template <class T>
void AVL<T> :: RotateRightLeft (AVL<T> * & pRoot)
{
    RotateRight (pRoot -> pRight);
    RotateLeft (pRoot);
}

template <class T>
void AVL<T> :: RotateLeftRight (AVL<T> * & pRoot)
{
    RotateLeft (pRoot -> pLeft);
    RotateRight (pRoot);
}

template <class T>
bool AVL<T> :: Insert (AVLNode<T> * & pRoot, T Data)
{
    if (pRoot == NULL)
    {
        pRoot = new AVLNode<T> (Data);
        return true;
    }
    else
    {
        if (Data < pRoot -> Data)
        {
            if (Insert (pRoot -> pLeft, Data))
                {
                    if (pRoot -> BF == EH) 
                    {
                        pRoot = LH;
                        return true;
                    }
                    if (pRoot -> BF == RH)
                    {
                        pRoot -> BF = EH;
                        return false;
                    }
                }
        }
        else Insert (pRoot -> pRight, Data);
    }
}

template <class T>
bool AVL<T> :: BallanceLeft (AVLNode<T> * & pRoot) 
{
    if (pRoot -> pLeft -> BF == LH)
    {
        RotateRight (pRoot);
        pRoot -> BF = pRoot -> pRight -> BF = EH;
        return false;
    }
    if (pRoot -> pLeft -> BF == RH)
    {
        RotateLeftRight (pRoot);
        if (pRoot -> BF == EH)
        {
            pRoot == NULL;
        }
    }
}

template <class T>
void PrintPreOrder (AVLNode<T> * pRoot) {
    if (pRoot == NULL ) return;
    cout << pRoot -> Data << ' ';
    return PrintPreOrder (pRoot -> pLeft) && PrintPreOrder (pRoot -> pRight); 
}