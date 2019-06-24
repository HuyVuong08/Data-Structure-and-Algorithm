#include <iostream>

using namespace std;

//-----------------------------************* NODE *************-----------------------------//

template <class T>
struct Node {
    T * data;
    Node<T> * pNext;
};

template <class T>
class Stack {
    public:
        Stack ();
        ~Stack ();

        void Push (T DataIn);
        int Pop (T & DataOut);
        int GetStackTop (T & DataOut);
        void Clear ();
        int IsEmpty ();
        int IsFull ();
        int GetSize ();
        Stack<T> * Clone ();
        void Print2Console ();

    private:
        Node<T> * top;
        int count;
};

template <class T>
Stack<T> :: Stack () {
    this -> top = NULL;
    this -> count = 0;
}

template <class T>
Stack<T> :: ~Stack () {
    this -> Clear ();
}

template <class T>
void Stack<T> :: Push (T DataIn) {
    Node<T> * pNew = new Node<T> ();
    pNew -> data = DataIn;
    pNew -> pNext = this -> top;
    this -> top = pNew;
    this -> count ++;
}

template <class T>
int Stack<T> :: Pop (T & DataOut) {
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
int Stack<T> :: GetStackTop (T & DataOut) {
    if (this -> GetSize () == 0)
        return 0;

    DataOut = this -> top -> data;
    return 1;
}

template <class T>
void Stack<T> :: Clear () {
    Node<T> * pTemp;
    while (this -> top != NULL) {
        pTemp = this -> top;
        this -> top  = this -> top -> pNext;
        delete pTemp;
    }
}

template <class T>
int Stack<T> :: IsEmpty () {
    return (this -> count == 0);
}

template <class T>
int Stack<T> :: GetSize () {
    return this -> count;
}

template <class T>
int Stack<T> :: IsFull () {
    Node<T> * pNew = new Node<T> ();

    if (pNew != NULL) {
        delete pNew;
        return 0;
    } else {
        return 1;
    }
}

template <class T>
void Stack<T> :: Print2Console () {
    Node<T> * p;
    p = this -> top;

    while (p != NULL) {
        cout << p -> data << " ";
        p = p -> pNext;
    }

    cout << endl;
}

