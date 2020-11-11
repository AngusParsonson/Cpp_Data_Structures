#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

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

#include "binary_search_tree.tpp"
#endif
