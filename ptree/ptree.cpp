/*************************************************************************
	> File Name: ptree.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  3/ 9 20:56:41 2017
 ************************************************************************/

#include<iostream>

struct Node {
  Node() : data_(0), left(nullptr), right(nullprt) {}
  Node(int data) : data_(data), left(nullptr), right(nullptr) {}
  ~Node() {}

  int data_;
  Node *left;
  Node *right;
};

class Tree {
public:
  Tree() : node_(std::vector<Node()>) {}
  Tree(const Node& leaf) node_(leaf) {}
  Tree& insert(int key, const Node& leaf);
  Node* search(int key, const Node& leaf);


private:
  std::vector<Node*> node_;
}

Tree& Tree::insert(int key, const Node& leaf)
{
  if (key < leaf.data_) {
    if (leaf.left != nullptr) {
      insert(key, leaf.left);
    }
    else {
      leaf.left = Node();
      leaf.left.data_ = key;
      leaf.left.left = nullptr;
      leaf.left.right = nullptr;
    }
  }
  else {
    if (leaf > leaf.data_) {
      if (leaf.right != nullptr) {
        insert(key, leaf.right);
      }
      else {
        leaf.right = Node();
        leaf.right.data_ = key;
        leaf.right.left = nullptr;
        leaf.right.right = nullptr;
      }
    }
  }
}

Node* Tree::search(int key, const Node& leaf)
{
  if (leaf != nullptr) {
    if (key < leaf.left) {
      search(key, leaf.left);
    }
    else if (key > leaf.right) {
      search(key, leaf.right);
    }
    else {
      return leaf;
    }
  }
  else {
    return nullptr;
  }
}

Tree& Tree::insert(int key)
{
  if (node_ != nullptr) {
    insert(key, node_);
  }
  else {
    node_ = new Node;
    node_.data_ = key;
    node_.left = nullptr;
    node_.right = nullptr;
    return node_;
  }
}

Node* Tree::search(int key)
{
  if (node_ != nullptr) {
    search(key, node_);
  }
  else {
    return nullptr;
  }
}
