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
