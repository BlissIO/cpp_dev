#include <iostream>
#include <list>

using namespace std;

template<class T>
class DLLNode {
    public:
    T info;
    DLLNode *next, *prev;
    DLLNode(){
        next = prev = nullptr;
    }
    DLLNode(T t,DLLNode<T> *n = nullptr,DLLNode<T> *p = nullptr) {
        info = t;
        next = n;
        prev = p;
    }
};

template<class T>
class DLL {
    protected:
    DLLNode<T> *head = nullptr, *tail = nullptr;
    public:

    bool isEmpty() {
        return head == nullptr;
    }
    void insertAtHead(T t) {
        head = new DLLNode<T>(t,head);
        if (tail == nullptr)
            tail = head;
        else head->next->prev = head;
    }
    T deleteFromTail(){ // Works only for non-empty lists
        T t = tail->info;
        if(head == tail) { // There is only one node on the list
            delete tail;
            head = tail= nullptr;
        }
        else {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
        return t;
    }
    template<class TT>
    friend ostream& operator<<(ostream& out, const DLL<TT>& dll);

};



template<class T>
ostream& operator<<(ostream& out, const DLL<T>& dll){
    for (DLLNode<T> *p = dll.head; p ;p = p->next)
        out << p->info << ' ';
    out << endl;
    return out;
}

void testDLL() {
    DLL<int> dll;
    dll.insertAtHead(10);
    dll.insertAtHead(10);
    dll.insertAtHead(10);
    cout << dll;
    cout << dll.deleteFromTail() << " " << endl;
    cout << dll.deleteFromTail() << " " << endl;
    cout << dll.deleteFromTail() << " " << endl;
}
int main() {
    testDLL();

    list<int> lst;

    return 0;
}