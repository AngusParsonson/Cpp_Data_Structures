#include <iostream>
#include <vector>

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
        LinkedList(size_t n, T *values);
        void pushBack(T value); // O(1)
        void pushForward(T value); // O(1)

        // Inserts value before pos O(pos), returns 0 for success, 1 for fail
        int insert(T value, int pos);

        T decapitate(); // Remove head and return value
        T dock(); // Remove tail and return value
        Node<T>* getHead();
        Node<T>* getTail();
        size_t size();
};

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

    tail->next = n;
    tail = tail->next;
    length++;
}

template<class T>
void LinkedList<T>::pushForward(T value) {
    Node<T>* n = new Node<T>;
    n->value = value;
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

int main() {
    long arr[] = {1,2,3,4};
    LinkedList<long> list(4, arr);
    list.pushBack(7);
    list.pushForward(8);
    list.insert(23, 2);
    int *q = new int(5);
    int *swap = p;
    p = q;
    q = swap;
    cout << "q: "<< *q << endl;
    cout << "p: " << *p << endl;

    cout << list.getHead()->value << endl;
    cout << list.getHead()->next->value << endl;
    cout << list.getHead()->next->next->value << endl;
    cout << list.getTail()->value << endl;
    cout << list.size() << endl;
}
