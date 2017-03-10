/*************************************************************************
	> File Name: ptree.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  3/ 9 20:56:41 2017
 ************************************************************************/

#include<iostream>

template <typename T>
class Tree {
public:
  struct Node {
    T key;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    Node() : key(), left(), right() {}
    Node(T x) : key(x), left(), right() {}
  };
  std::shared_ptr<Node> root;

public:
  Tree() : root() {}
  ~Tree();
  Tree(Tree&&) = default;
  Tree& operator= (Tree&&) = default;
  Tree(const Tree&);
  Tree& operator= (const Tree&);
  bool insert(T);
  bool remove(T);
  shared_ptr<Node> find(T x) {
    return find(x, root);
  }
  void breath_first();
  size_t heigth() {
    return heigth(root);
  }
}

template <typename T>
bool Tree<T>::remove(T x) {
  return remove(x, root);
}

template <typename T>
bool Tree<T>::remove(T x, std::shared_ptr<Node>& p) {
  if (p && x < p->key)
    return remove(x, p->left);
  else if (p && x > p->key) 
    return remove(x, p->right);
  else if (p && p->key = x) {
    if (!p->left) 
      p = p->right;
    else if (!p->right)
      p = p->left;
    else {
      std::shared_ptr<Node> q = p->left;
      while(q->right)
      q = q->right;
      p->key = q->key;
      remove(q->key, p->left);
    }
    return true;
  }
  return false;
}

~Tree() {
  while(root)
    remove(root->key);
}

template <typename T>
bool Tree<T>::insert(T x) {
  return insert(x, root);
}
template <typename T>
Tree& Tree::insert(T x, std::shared_ptr<Node>& p) 
{
  if (x < p->key) {
    if (p->left != nullptr) {
      insert(x, p->left);
    }
    else {
      std::shared_ptr<Node> q = p->left;
      q->key= key;
      q->left = nullptr;
      q->right = nullptr;
    }
  }
  else {
    if (x > p->key) {
      if (p->right != nullptr) {
        insert(x, p->right);
      }
      else {
        std::shared_ptr<Node> q = p->right;
        q->key= key;
        q->left = nullptr;
        q->right = nullptr;
      }
    }
  }
}

template <typename T>
bool Tree<T>::find(T x, std::shared_ptr<Node>& p) {
{
  if (p) {
    if (x < p->left) {
      search(x, p->left);
    }
    else if (x > p->right) {
      search(x, p->right);
    }
    else {
      return true;
    }
  }
  else {
    return false;
  }
}

