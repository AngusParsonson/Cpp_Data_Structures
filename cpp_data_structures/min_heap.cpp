#include <iostream>

#define DEFAULT_SIZE 100

template <class T>
class min_heap {
    private:
        T *data;
        int heap_size;
        int capacity;

        int parent(int index) {
            return (index - 1) / 2;
        }

        int left(int index) {
            return (index * 2) + 1;
        }

        int right(int index) {
            return (index * 2) + 2;
        }

    public:
        min_heap(int size=DEFAULT_SIZE) {
            data = new T[size];
            capacity = size;
            heap_size = 0;
        }

        ~min_heap() {
            delete[] data;
        }

        void insert(T val);
        T extract_min();
        void print();
        void bubble_up();
        void bubble_down();
};

template <class T>
void min_heap<T>::insert(T val) {
    data[heap_size++] = val;
    bubble_up();
}

template <class T>
T min_heap<T>::extract_min() {
    int res = data[0];
    std::swap(data[0], data[--heap_size]);
    bubble_down();
    return res;
}

template <class T>
void min_heap<T>::bubble_up(){
    int bubble = heap_size - 1;
    while (bubble > 0 && data[bubble] < data[parent(bubble)]) {
        std::swap(data[bubble], data[parent(bubble)]);
        bubble = parent(bubble);
    }
}

template <class T>
void min_heap<T>::bubble_down() {
    int bubble = 0;
    int next = data[left(bubble)] < data[right(bubble)] ? left(bubble) : right(bubble);
    while (next != 0 && next < heap_size) {
        std::swap(data[bubble], data[next]);
        bubble = next;
        next = data[left(bubble)] < data[right(bubble)] ? left(bubble) : right(bubble);
    }
}

template <class T>
void min_heap<T>::print() {
    for (int i = 0; i < heap_size; i++) 
        std::cout << data[i] << " ";
    std::cout << std::endl;
}

int main() {
    min_heap<int> heap;
    heap.insert(5);
    heap.insert(7);
    heap.insert(15);
    heap.insert(11);
    heap.insert(1);
    heap.insert(16);
    heap.insert(13);
    heap.print();
    std::cout << heap.extract_min() << std::endl;
    heap.print();
    std::cout << heap.extract_min() << std::endl;
    heap.print();
    std::cout << heap.extract_min() << std::endl;
    heap.print();
}
