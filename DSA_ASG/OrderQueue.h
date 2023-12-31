#pragma once
#include<string>
#include<iostream>
#include "Food.h"
#include "Order.h"
using namespace std;

typedef Order OrderItem;

class Queue
{
private:
 

public:   
    struct Node
    {
        OrderItem item;	// item
        Node* next;	// pointer pointing to next item
        Node() 
        {
        }
    };

    Node* frontNode;	// point to the first item
    Node* backNode;	// point to the first item

    // constructor
    Queue();

    ~Queue();

    // enqueue (add) item at the back of queue
    bool enqueue(OrderItem item);

    // dequeue (remove) item from front of queue
    bool dequeue();

    // dequeue (remove) and retrieve item from front of queue
    bool dequeue(OrderItem& item);

    // retrieve (get) item from front of queue
    void getFront(OrderItem& item);

    List<Order> getMemberOrder(Member member);

    // check if the queue is empty
    bool isEmpty();

    int getLength();

    Node* getFrontNode();

};