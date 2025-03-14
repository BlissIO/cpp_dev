//************************************************************
// Program #5 
// Rayane EL YASTI
// due 2/20/2025
// This program implements two classes MyDLL and MyList
// Both have adding a node in the middle 
// and sorting the list using insertion sort
//************************************************************
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
    T deleteFromTail(){
        T t = tail->info;
        if(head == tail) {
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

template<class T>
class MyDLL : public DLL<T> {
    public:
        // Inserts an element at the middle of the list
        void addInMiddle(const T& element) {
            // Handle empty list case
            if (this->isEmpty()) {
                this->insertAtHead(element);
                return;
            }
            
            // Find the length of the list
            DLLNode<T>* pointer = this->head;
            int totalNodes = 0;
            
            while (pointer != nullptr) {
                totalNodes++;
                pointer = pointer->next;
            }
            
            // Find the middle position
            int middlePos = totalNodes / 2;
            
            // Special case for lists with only one node
            if (totalNodes == 1) {
                DLLNode<T>* newEntry = new DLLNode<T>(element);
                this->head->next = newEntry;
                newEntry->prev = this->head;
                this->tail = newEntry;
                return;
            }
            
            // Find the node at position before middle
            pointer = this->head;
            for (int i = 0; i < middlePos - 1; i++) {
                pointer = pointer->next;
            }
            
            // Create new node and insert at middle
            DLLNode<T>* newEntry = new DLLNode<T>(element);
            
            newEntry->next = pointer->next;
            if (pointer->next != nullptr) {
                pointer->next->prev = newEntry;
            } else {
                this->tail = newEntry;
            }
            
            newEntry->prev = pointer;
            pointer->next = newEntry;
        }

        // Sorts the list elements in ascending order using insertion sort
        void sorting(const T& element) {
            // Handle empty or single element list
            if (this->isEmpty() || this->head->next == nullptr) {
                return;
            }
            
            DLLNode<T>* sorted = nullptr;
            DLLNode<T>* current = this->head;
            
            // Insertion sort algorithm
            while (current != nullptr) {
                DLLNode<T>* nextNode = current->next;
                
                // Insert current into sorted linked list
                if (sorted == nullptr || sorted->info >= current->info) {
                    current->next = sorted;
                    current->prev = nullptr;
                    if (sorted != nullptr) {
                        sorted->prev = current;
                    }
                    sorted = current;
                } else {
                    // Find the position to insert
                    DLLNode<T>* searchPtr = sorted;
                    while (searchPtr->next != nullptr && searchPtr->next->info < current->info) {
                        searchPtr = searchPtr->next;
                    }
                    
                    // Insert between searchPtr and searchPtr->next
                    current->next = searchPtr->next;
                    if (searchPtr->next != nullptr) {
                        searchPtr->next->prev = current;
                    }
                    searchPtr->next = current;
                    current->prev = searchPtr;
                }
                
                current = nextNode;
            }
            
            // Update head and tail
            this->head = sorted;
            
            // Find the new tail
            DLLNode<T>* tailPtr = this->head;
            while (tailPtr != nullptr && tailPtr->next != nullptr) {
                tailPtr = tailPtr->next;
            }
            this->tail = tailPtr;
        }
};  

template<class T>
class MyList : public list<T> {
    public:
        // Inserts an element at the middle of the list
        void addInMiddle(const T& element) {
            if (this->empty()) {
                this->push_back(element);
                return;
            }
            
            // Calculate the middle position
            typename list<T>::iterator midIterator = this->begin();
            int listSize = 0;
            
            // Count elements
            for (typename list<T>::iterator countIter = this->begin(); 
                 countIter != this->end(); ++countIter) {
                listSize++;
            }
            
            // Advance to middle position
            int midPosition = listSize / 2;
            for (int i = 0; i < midPosition; i++) {
                ++midIterator;
            }
            
            // Insert at middle position
            this->insert(midIterator, element);
        }
        
        // Sorts the list using insertion sort
        void sorting(const T& element) {
            if (this->size() <= 1) {
                return; // Nothing to sort
            }
            
            // Create a new sorted list
            list<T> sortedList;
            
            // Insertion sort
            for (typename list<T>::iterator currentItem = this->begin(); 
                 currentItem != this->end(); ++currentItem) {
                
                bool inserted = false;
                
                // Find the right position in the sorted list
                for (typename list<T>::iterator sortedItem = sortedList.begin(); 
                     sortedItem != sortedList.end(); ++sortedItem) {
                    
                    if (*currentItem < *sortedItem) {
                        sortedList.insert(sortedItem, *currentItem);
                        inserted = true;
                        break;
                    }
                }
                
                // If not inserted, add to the end
                if (!inserted) {
                    sortedList.push_back(*currentItem);
                }
            }
            
            // Replace original list with sorted list
            this->clear();
            for (typename list<T>::iterator copyItem = sortedList.begin(); 
                 copyItem != sortedList.end(); ++copyItem) {
                this->push_back(*copyItem);
            }
        }
};

