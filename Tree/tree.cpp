#include<iostream>

struct node
{
    int key_value;
    node *left;
    node *right;
}

class btree {
public:
    btree ();
    ~btree ();

    void insert(int key);
    node* search(int key);
    node* destory_tree();

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

