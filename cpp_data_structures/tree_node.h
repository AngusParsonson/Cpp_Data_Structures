#ifndef TREE_NODE 
#define TREE_NODE

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

#endif
