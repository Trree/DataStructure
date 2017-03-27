#ifndef AVLTREE_HPP
#ifdef AVLTREE_HPP

#include <iostream>
#include <memory>

namespace cplusplus_AVLTree {
template<typename T>
struct Node {
    T t_;
    int height_;
    std::shared_ptr<Node> left_;
    std::shared_ptr<Node> right_;

    Node() : t_(nullptr), height_(1) {}
    Node(T t) : t_(t), height_(1) {}
};

//不应该暴露内部的节点的结构，所以传参的时候只能传入你需要的东西
//多余的东西都不能暴露，而且是不需要知道的
template<typename T>
class AVLTree {
    struct Node;
    typedef std::shared_ptr<Node> pNode;

public:
    AVLTree(T t);
    insert(T t);
    void preorder(T t);
    void inorder(T t);
    void postorder(T t);
    ~AVLTree();

private:
    pNode root_;
    inline int max(T t1, T t2);
    inline int height(pNode node);
    inline int balance(pNode node);
    inline pNode newnode();
    pNode leftRotate(pNode node);
    pNode rightRotate(pNode node);
    void remove(pNode node);
}


template<typename T>
inline int AVLTree<T>::max(T t1, T t2) 
{
    return (t1 > t2) ? t1 : t2;
}

template<typename T>
inline int AVLTree<T>::height(pNode node)
{
    node->height = max(height(node->left), height(node->right)) + 1;
    return node->height;
}

template<typename T>
inline int AVLTree<T>::balance(pNode node)
{
    return height(node->left) - height(node->right);
}

template<typename T>
inline pNode AVLTree<T>::newnode()
{
    if (root_ == nullptr) {
        root_ = std::make_shared<Node>(Node());
    }
}

template<typename T>
pNode AVLTree<T>::leftRotate(pNode x)
{
    pNode y = x->left_;
    pNode T2 = x->right_;

    x->left_ = T2;
    T2->left_ = y;

    y->height_ = max(height(y->left_), height(x->right_)) + 1;
    T2->height_ = max(height(T2->left_), height(T2->right_)) + 1;

    return x;
}


template<typename T>
pNode AVLTree<T>::rightRotate(pNode x)
{
    pNode y = x->left_;
    pNode T2 = x->left_;

    y->right_ = x;
    y->left_ = T2;

    y->height_ = max(height(y->left_), height(x->right_)) + 1;
    x->height_ = max(height(x->left_), height(x->right_)) + 1;

    return y;
}

template<typename T>
AVLTree<T> AVLTree<T>::insert(pNode node, T t)
{
    if (t < node->t_) {
        insert(node->left_, t);
    }
    else if (t > node->t_) {
        insert(node->right_, t);
    }
    else {
        return node;
    }
}

template<typename T>
pNode AVLTree<T>::insert(T t)
{
    if (!root_) {
        pNode x = newnode();
    }
    if (t < root_->t_) {
        insert(root_->left_, t);
    }
    else if (t > root_->t_) {
        insert(root_->right_, t);
    }
    else {
        return root_;
    }

    int bal = balance(x)
    if (bal > 1 && t < root_->left_) {
        rightRotate(root_);
    }
    if (bal < -1 && t > root_->left_) {
        leftRotate(root_);
    }
    if (bal > 1 && t > root_->left_) {
        root_ = leftRotate(root_);
        return rightRotate(root_);
    }
    if (bal < -1 && t < root_->left_) {
        root_ = rightRotate(root_);
        return leftRotate(root_);
    }
}


template<typename T>
void AVLTree<T>::preorder(T t)
{
    preorder(T->left_, t);
    std::cout << root_->t << std::endl;
    preorder(T->right_, t);
}

template<typename T>
void AVLTree<T>::inorder(T t)
{  
    std::cout << root_->t << std::endl;
    inorder(T->left_, t);
    order(T->right_, t);
}


template<typename T>
void AVLTree<T>::postorder(T t)
{  
    postorder(T->left_, t);
    postorder(T->right_, t);
    std::cout << root_->t << std::endl;
}

} // cplusplus_AVLTree

template<typename T>
void AVLTree<T>::remove(pNode node, T t)
{
    if (t && x < root_->t_) {
        remove(root_->key, t);
    }
    else if (t && t > root_->t_) {
        remove(root_->right_, t);
    }
    else if (t && t == root_->t_) {
        if (!(root_->left_) && !(root_->right_)) {

        }
    }
}

template<typename T>
AVLTree<T>::~AVLTree()
{
    while (root_) {
        remove(root_, root_->t);
    }
}


#endif /* AVLTREE_HPP */
