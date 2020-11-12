#include <iostream>

#define DEFAULT_SIZE 100

using namespace std;

template <class T>
class graph_node {
    public:
        T key;
        graph_node<T>* adjacent;

        graph_node() {}
        graph_node(T val) {
            key = val;
        }
};

template <class T>
class graph {
    public:
        graph_node<T>** nodes;

        graph(int size=DEFAULT_SIZE) {
            nodes = new graph_node<T>*[size];
        }

        ~graph() {
            delete[] nodes;
        }
};

template <class T>
void depth_first_search(graph_node<T>** head) {
}

int main() {
    graph<int> g;
    g.nodes[0] = new graph_node<int>(1);
    g.nodes[0]->adjacent = new graph_node<int>(10);
    g.nodes[1] = new graph_node<int>(2);
    g.nodes[2] = new graph_node<int>(3);
    depth_first_search(g.nodes);
    cout << g.nodes[0]->key << endl;
    cout << g.nodes[1]->key << endl;
    cout << g.nodes[2]->key << endl;
}
