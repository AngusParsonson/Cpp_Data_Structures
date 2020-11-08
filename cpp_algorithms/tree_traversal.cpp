#include <iostream>
#include <stack>
#include <queue>
#include "../cpp_data_structures/tree_node.h"
#include "../cpp_data_structures/binary_search_tree.h"

using namespace std;

template<class T>
void breadth_first_search(TreeNode<T>* root) {
    queue<TreeNode<T>*> q;
    TreeNode<T>* current = root;

    while (current) {
        cout << current->key << endl;
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
        (q.empty()) ? current = nullptr : current = q.front();
        q.pop();
    }
}

template<class T>
void depth_first_search(TreeNode<T>* root) {
    stack<TreeNode<T>*> s;
    TreeNode<T>* current = root;

    while (current) {
        cout << current->key << endl;
        if (current->right) s.push(current->right);
        if (current->left) s.push(current->left);
        current = (s.empty()) ? nullptr : current = s.top();
        s.pop();
    }
}

template<class T>
void in_order_traversal(TreeNode<T>* root) {
    if (root) {
        in_order_traversal(root->left);
        cout << root->key << endl;
        in_order_traversal(root->right);
    }
}

template<class T>
void pre_order_traversal(TreeNode<T>* root) {
    if (root) {
        cout << root->key << endl;
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
}

template<class T>
void post_order_traversal(TreeNode<T>* root) {
    if (root) {
        post_order_traversal(root->left);
        post_order_traversal(root->right);
        cout << root->key << endl;
    }
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
    //breadth_first_search(tree.get_root());
    //depth_first_search(tree.get_root());
    in_order_traversal(tree.get_root());
    pre_order_traversal(tree.get_root());
    post_order_traversal(tree.get_root());
}
