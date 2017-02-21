/*************************************************************************
	> File Name: slist.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue Feb 21 11:02:58 2017
 ************************************************************************/

#include<iostream>
#include<memory>

template<typename T>
class DoubleLinkedList {
    struct Node;
    typedef std::shared_ptr<Node> node_pointer_type;
    struct Node {
        T t;
        std::shared_ptr<Node> next_;
        std::shared_ptr<Node> pre_;
        Node() : t(nullptr) {}
        Node(T v) : t(v) {}
    };
    node_pointer_type head;
    node_pointer_type tail;

public:
    DoubleLinkedList() {}
    void appendNodehead(T t);
    void appendNodeTail(T t);
    void dispNodesForward();
    void dispNodeReverse();
    void destroyList();
};

template<typename T>
void DoubleLinkedList<T>::appendNodehead(T t)
{
    std::shared_ptr<Node> n = std::make_shared<Node>(Node(t));
    if (!head) {
        head = n;
        tail = n;
    }
    else {
        head->pre_ = n;
        n->next_ = head;
        head = n;
    }
}

template<typename T>
void DoubleLinkedList<T>::appendNodeTail(T t)
{
    std::shared_ptr<Node> n = std::make_shared<Node>(Node(t));
    if (!head) {
        head = n;
        tail = n;
    }
    else {
        tail->next_ = n;
        n->pre_ = tail;
        tail = n;
    }
}

template<typename T>
void DoubleLinkedList<T>::dispNodesForward()
{
    std::shared_ptr<Node> n = head;
    while (n) {
        std::cout << n->t << std::endl;
        n = n->next_;
    }
}

template<typename T>
void DoubleLinkedList<T>::dispNodeReverse()
{
    std::shared_ptr<Node> n = tail;
    while (n != nullptr) {
        std::cout << n->t << std::endl;
        n = n->pre_;
    }
}

template<typename T>
void DoubleLinkedList<T>::destroyList()
{
}

int main()
{
    DoubleLinkedList<int> list;
    for (int i=1; i<4; i++) {
        list.appendNodehead(i);
    }
    list.dispNodesForward();
    list.dispNodeReverse();

    for(int i=10; i<14; i++) {
        list.appendNodeTail(i*10);
    }
    std::cout<<std::endl;
    list.dispNodesForward();
    list.dispNodeReverse();

    std::cout << std::endl;

    return 0;

}
