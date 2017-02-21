/*************************************************************************
	> File Name: List.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon Feb 20 20:15:37 2017
 ************************************************************************/

#include<iostream>
#include<initializer_list>

template<typename T>
class List {
    struct Node {
        T t;
        Node *next;
        Node *pre;
    };
    List *list_;

public:
    List();
    List(std::initializer_list<T> l);
    List(T& t);
    insert(T& t);
    find(T& t);
    del(T& t);
    ~List();
}

List::List()
{
    struct Node fisrt =  new Node;
    first->t = nullptr;
    first->next = nullptr;
    first->pre = nullptr;
}

List::List()








