#include<iostream>

struct node
{
    int key_value;
    node *left;
    node *right;
};

class btree {
public:
    btree ();
    ~btree (){
        destory_tree();
    }

    void insert(int key);
    node* search(int key);
    void destory_tree();

private:
    void destory_tree(node* leaf);
    void insert(int key, node* leaf);
    node* search(int key, node* leaf);

    node* root;
};

btree::btree()
{
    root = nullptr;
}

void btree::destory_tree(node* leaf)
{
    if (leaf != nullptr) {
        destory_tree(leaf->left);
        destory_tree(leaf->right);
        delete leaf;
    }
}

void btree::insert(int key, node* leaf)
{
    if (key < leaf->key_value) {
        if (leaf->left != nullptr) {
            insert(key, leaf->left);
        }
        else {
            leaf->left = new node;
            leaf->left->key_value = key;
            leaf->left->left = nullptr;
            leaf->left->right = nullptr;
        }
    }
    else if (key >= leaf->key_value) {
        if (leaf->right != nullptr) {
            insert(key, leaf->right);
        }
        else {
            leaf->right = new node;
            leaf->right->key_value = key;
            leaf->right->left = nullptr;
            leaf->right->right = nullptr;
        }
    }
}

node* btree::search(int key, node* leaf)
{
    if (leaf != nullptr) {
        if (key == leaf->key_value) {
            return leaf;
        }
        if (key < leaf->key_value) {
            return search(key, leaf->left);
        }
        else {
            return search(key, leaf->right);
        }
    }
    else {
        return nullptr;
    }
}

void btree::insert(int key)
{
    if (root != NULL) {
        insert(key, root);
    }
    else {
        root = new node;
        root->key_value = key;
        root->left = nullptr;
        root->right = nullptr;
    }
}

node* btree::search(int key)
{
    return search(key, root);
}

void btree::destory_tree()
{
    destory_tree(root);
}

int main(int argc, const char *argv[])
{
    btree node;
    node.insert(1);
    node.insert(8);
    node.insert(4);
    node.insert(10);
    node.insert(9);
    node.insert(7);
    node.search(10);
    return 0;
}
