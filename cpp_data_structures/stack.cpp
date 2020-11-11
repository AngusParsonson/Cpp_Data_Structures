#include <iostream>

using namespace std;

#define SIZE 100

template<class T>
class stack{
    private:
        T *data;
        int topInd;
        int capacity;
        size_t length;

    public:
        stack(int s=SIZE);
        ~stack();
        int push(T value); // 0 for success, 1 for failure
        void emplace(T value);
        T top();
        T pop();
        size_t size();
};

template<class T>
stack<T>::stack(int s) {
    data = new T[s];
    topInd = -1;
    capacity = s;
    length = 0;
}

template<class T>
stack<T>::~stack() {
    delete[] data;
}

template<class T>
int stack<T>::push(T value) {
    if (length == capacity-1) return 1;

    data[++topInd] = value;
    length++;
}

template<class T>
void stack<T>::emplace(T value) {
    data[topInd] = value;
}

template<class T>
T stack<T>::top() {
    return data[topInd];
}

template<class T>
T stack<T>::pop() {
    if (topInd < 0) { 
        throw length_error("Stack empty");
        exit(EXIT_FAILURE);
    }

    length--;
    return data[topInd--];
}

int main() {
    stack<int> st;
    st.push(5);
    st.push(32453);
    st.push(78);
    st.push(16);
    st.push(7);

    cout << st.top() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    return 0;
}
