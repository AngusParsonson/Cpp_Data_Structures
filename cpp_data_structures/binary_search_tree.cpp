#include <iostream>
#include "tree_node.h"

template<class T>
class binary_search_tree {
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
        TreeNode<T>* get_root();

        binary_search_tree() {
            root = nullptr;
        }
};

template<class T>
void binary_search_tree<T>::insert(T value) {
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
bool binary_search_tree<T>::search(T value, TreeNode<T>** node) {
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
T binary_search_tree<T>::min() {
    TreeNode<T>* current = root;

    while(current->left)
        current = current->left;

    return current->key;
}

template<class T>
T binary_search_tree<T>::max() {
    TreeNode<T>* current = root;

    while(current->right)
        current = current->right;

    return current->key;
}

template<class T>
int binary_search_tree<T>::remove(T value) {
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

template<class T>
TreeNode<T>* binary_search_tree<T>::get_root() {
    return root;
}

int main() {
    binary_search_tree<int> tree;
    tree.insert(5);
    tree.insert(6);
    tree.insert(4);
    tree.insert(24);
    tree.insert(16);
    tree.insert(15);
    tree.insert(17);
    tree.insert(2);
    tree.insert(3);
    tree.insert(1);
    tree.remove(2);
    std::cout << tree.min() << std::endl;
    tree.remove(16);
    tree.remove(6);
    std::cout << tree.search(16) << std::endl;
    std::cout << tree.search(6) << std::endl;
    std::cout << tree.search(5) << std::endl;
    std::cout << tree.search(4) << std::endl;
    std::cout << tree.search(24) << std::endl;
    std::cout << tree.search(15) << std::endl;
    std::cout << tree.search(17) << std::endl;
    std::cout << tree.max() << std::endl;
    std::cout << tree.min() << std::endl;
}

