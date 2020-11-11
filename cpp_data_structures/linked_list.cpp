#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

template<class T>
struct Node {
    T value;
    Node* next;
};

template<class T>
class LinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;
        size_t length;

    public:
        LinkedList();
        LinkedList(size_t n, T values[]);
        void pushBack(T value); // O(1)
        void pushForward(T value); // O(1)

        // Inserts value before pos O(pos), returns 0 for success, 1 for fail
        int insert(T value, int pos);

        T decapitate(); // Remove head and return value
        T dock(); // Remove tail and return value
        T getFromEnd(int k);
        void removeDuplicates();
        void print();
        Node<T>* getHead();
        Node<T>* getTail();
        size_t size();
};

template<class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template<class T>
LinkedList<T>::LinkedList(size_t n, T values[]) {
    head = new Node<T>;
    tail = head;
    length = n;
    
    for (int i = 0; i < length; i++) {
        tail->value = values[i];
        if (i < length-1) {
            tail->next = new Node<T>;
            tail = tail->next;
        }
    }
}

template<class T>
void LinkedList<T>::pushBack(T value) {
    Node<T>* n = new Node<T>;
    n->value = value;

    if (!head) {
        head = n;
        tail = head;
    }
    else {
        tail->next = n;
        tail = tail->next;
    }
    length++;
}

template<class T>
void LinkedList<T>::pushForward(T value) {
    Node<T>* n = new Node<T>;
    n->value = value;

    if (!head) {
        head = n;
        tail = head;
    }
    else
        n->next = head;

    head = n;
    length++;
}

template<class T>
int LinkedList<T>::insert(T value, int index) {
    if (index == length) { pushBack(value); return 0; }
    if (index > length) return 1;

    Node<T>* curr = head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    if (curr == head) { pushForward(value); return 0; }

    Node<T>* n = new Node<T>;
    n->value = value; n->next = curr->next;
    curr->next = n;
    length++;

    return 0;
}

template<class T>
Node<T>* LinkedList<T>::getHead() {
    return head;
}

template<class T>
Node<T>* LinkedList<T>::getTail() {
    return tail;
}

template<class T>
size_t LinkedList<T>::size() {
    return length;
}

template<class T>
void LinkedList<T>::removeDuplicates() {
    unordered_set<T> set;
    Node<T> *current = head, *prev = head;

    while (current) {
        if (set.count(current->value)) 
            prev->next = current->next; 
        
        else {
            set.insert(current->value);
            prev = current;
        }

        current = current->next;
    }
}

template<class T>
T LinkedList<T>::getFromEnd(int k) {
    Node<T> *fst = head, *snd = head;

    for (int i = 0; i <= k; i++)
        fst = fst->next;

    while (fst) {
        snd = snd->next;
        fst = fst->next;
    }

    return snd->value;
}

template<class T>
void LinkedList<T>::print() {
    Node<T>* current = head;

    while (current) {
        cout << current->value << " -> ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    long arr[] = {1,2,2,3,4,5,1,1,5,1,1,2,7};
    LinkedList<long> list(13, arr);
    list.pushBack(7);
    list.pushForward(8);
    list.insert(23, 2);
    list.print();
    list.removeDuplicates();
    list.print();
    cout << list.getFromEnd(3) << endl;
    cout << list.getFromEnd(5) << endl; 
}
