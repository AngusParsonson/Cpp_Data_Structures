#include <iostream>
#include <string>

using namespace std;

#define DEFAULT_SIZE 100

template <class T> // T can be of any type
class queue {
    private:
        T *arr;
        int front;
        int back;
        int capacity;
        int count;

    public:
        queue(int size=DEFAULT_SIZE);
        ~queue();
        void enqueue(T item);
        void dequeue();
        T pop();
        T peek();
        int size();
        bool isEmpty();
        bool isFull();
};

// Since we are out of class definition, we must redefine the template 
template <class T> 
queue<T>::queue(int size) {
    arr = new T[size]; // Dynamically allocates memory for the array
    capacity = size;
    front = 0;
    count = 0;
    back = -1;
}

template <class T>
queue<T>::~queue() {
    // Dynamically allocated memory must be freed in destructor to avoid 
    // memory leak an std::allocator could be used to dynamically allocate
    // more memory on the fly (dynamically dynamically allocate)
    delete[] arr;
}

template <class T>
void queue<T>::enqueue(T item) {
    if (isFull()) {
        throw length_error("ERROR: Queue is full");
        exit(EXIT_FAILURE);
    }
    
    back = (back + 1) % capacity;
    arr[back] = item;
    count++;
}

template <class T>
void queue<T>::dequeue() {
    if (isEmpty()) {
        throw length_error("ERROR: Queue is empty");
        exit(EXIT_FAILURE);
    }

    front = (front + 1) % capacity;
    count--;
}

template <class T>
T queue<T>::pop() {
    T value = arr[front];
    dequeue();

    return value;
}

template <class T>
T queue<T>::peek() {
    if (isEmpty()) {
        throw length_error("ERROR: Queue is empty");
        exit(EXIT_FAILURE);
    }

    return arr[front];
}

template <class T>
int queue<T>::size() {
    return count;
}

template <class T>
bool queue<T>::isEmpty() {
    return (size() == 0);
}

template <class T>
bool queue<T>::isFull() {
    return (size() == capacity);
}

int main() {
    int capacity = 15;
    queue<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout << q.size() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.size() << endl;
    cout << q.peek() << endl;
    q.dequeue();

    queue<string> strQ(capacity);
    strQ.enqueue("Hello");
    strQ.enqueue("world!");
    cout << strQ.pop() << endl;
    cout << strQ.pop() << endl;

    return 0;
}
