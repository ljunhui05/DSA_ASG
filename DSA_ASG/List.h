//------------------------------------------------------------------//
// Lim JunHui (S10242387K)                                          //
// This Linked List classes uses the template class T. The template //
// class T is used so that this List can be used by multiple class  //
// types.                                                           //
//------------------------------------------------------------------//

#pragma once
#include <iostream>
#include <string>

template <class T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    int size;

public:

    //List constructor
    List() : head(nullptr), size(0) {}

    //// Destructor to clean up memory
    //~List() {
    //    Node* current = head;
    //    while (current) {
    //        Node* next = current->next;
    //        delete current;
    //        current = next;
    //    }
    //}


    //Adds an item of class T to the end of the linked list
    bool add(T item) {
        Node* newNode = new Node(item);
        if (!newNode)
            return false;

        if (!head) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next)
                current = current->next;
            current->next = newNode;
        }

        size++;
        return true;
    }

    //Adds an item of class T at a certain index of the linked list
    bool add(int index, T item) {
        if (index < 0  || index > size)
            return false;

        Node* newNode = new Node(item);
        if (!newNode)
            return false;

        if (index == 0) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* current = head;
            for (int i = 0; i < index - 1; i++)
                current = current->next;
            newNode->next = current->next;
            current->next = newNode;
        }

        size++;
        return true;
    }

    //Traverses the linked list
    void traverse(void (*func)(T&)) const {
        Node* current = head;
        while (current) {
            func(current->data);
            current = current->next;
        }
    }

    //Returns an object of class T in a certain index, which is given by input parameter of index.
    T get(int index) const {
        if (index < 0  || index >= size) {
            throw std::out_of_range("Invalid index");
        }

        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        return current->data;
    }

    //Returns the length of the linked list
    int getLength() const {
        return size;
    }

    //Removes a item from the linked list in a certain index, which is given by the input parameter of index.
    void remove(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Invalid index");
        }

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            Node* prev = nullptr;
            Node* current = head;
            for (int i = 0; i < index; i++) {
                prev = current;
                current = current->next;
            }
            prev->next = current->next;
            delete current;
        }

        size--;
    }

    //Clears the linked list
    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        size = 0;
    }

};