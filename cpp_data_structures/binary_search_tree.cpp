#include <iostream>

using namespace std;

template<class T>
struct TreeNode {
    T key;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode(T value) {
        key = value;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

template<class T>
class BinarySearchTree {
    private:
        TreeNode<T>* root;

    public:
        void insert(T value);

        // Search takes an optional pointer which (if not null when passed)
        // will be pointing to the found node, alternative is to pass a pointer
        // by reference using *& but this doesn't allow for an optional
        // nullptr so the function would have to be overloaded and written
        // again
        bool search(T value, TreeNode<T>** node=nullptr);

        T min();
        T max();
        int remove(T value); // Returns 1 if value found and removed, 0 if not

        BinarySearchTree() {
            root = nullptr;
        }
};

template<class T>
void BinarySearchTree<T>::insert(T value) {
    if (!root) {
        root = new TreeNode<T>(value);
        return;
    }

    TreeNode<T>* current = root;
    while(true) {
        if (value <= current->key) {
            if (!current->left) {
                current->left = new TreeNode<T>(value);
                current->left->parent = current;
                break;
            }
            current = current->left;
        }
        else {
            if (!current->right) {
                current->right = new TreeNode<T>(value);
                current->right->parent = current;
                break;
            }
            current = current->right;
        }
    }
}

template<class T>
bool BinarySearchTree<T>::search(T value, TreeNode<T>** node) {
    TreeNode<T>* current = root;

    while(current) {
        if (value == (current)->key) {
            if (node) *node = current; 
            return true;
        }

        else if (value < (current)->key)
            current = (current)->left;

        else 
            current = (current)->right;
    }

    return false;
}

template<class T>
T BinarySearchTree<T>::min() {
    TreeNode<T>* current = root;

    while(current->left)
        current = current->left;

    return current->key;
}

template<class T>
T BinarySearchTree<T>::max() {
    TreeNode<T>* current = root;

    while(current->right)
        current = current->right;

    return current->key;
}

template<class T>
int BinarySearchTree<T>::remove(T value) {
    TreeNode<T>* current = root;
    if (!(this->search(value, &current))) return 0;

    if (!current->left && !current->right) // node is leaf
        (value <= current->parent->key) ? current->parent->left = nullptr : current->parent->right = nullptr;

    else if (!current->left != !current->right) { // node has one child
        TreeNode<T>* newChild = (current->left) ? current->left : current->right;
        (value <= current->parent->key) ? current->parent->left = newChild : current->parent->right = newChild;
    }

    else { // node has two children
        TreeNode<T>* dummy = current;
        current = current->right;
        
        while (current->left)
            current = current->left;
        dummy->key = current->key;

        if (current->right) current->parent->left = current->right;
    }

    delete current;
    return 1;
}

int main() {
    BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(6);
    tree.insert(4);
    tree.insert(24);
    tree.insert(16);
    tree.insert(15);
    tree.insert(17);
    tree.insert(2);

    tree.remove(2);
    cout << tree.min() << endl;
    tree.remove(16);
    tree.remove(6);
    cout << tree.search(16) << endl;
    cout << tree.search(6) << endl;
    cout << tree.search(5) << endl;
    cout << tree.search(4) << endl;
    cout << tree.search(24) << endl;
    cout << tree.search(15) << endl;
    cout << tree.search(17) << endl;
    cout << tree.max() << endl;
    cout << tree.min() << endl;
}

