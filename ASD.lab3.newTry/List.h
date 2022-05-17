#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;
template<typename T>
class List
{
public:
    List();
    int find(T value);
    void pushBack(T newvalue);
    bool contains(T value);
    T getElem(int index);
    int get_size();
private:
    class Node
    {
    public:
        T value;
        class Node* next;
        Node(T newvalue = 0, Node* next = nullptr)
        {
            this->next = next;
            this->value = newvalue;
        }
        ~Node() {};
    };
    Node* head;
    Node* tail;
    int size;
};

template<typename T>
List<T>::List()
{
    size = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
inline int List<T>::find(T value)
{
    Node* current = head;
    for (int i = 0; i < size; i++) {
        if (current->value == value)
            return i;
        current = current->next;
    }
    return -1;
}

template<typename T>
void List<T>::pushBack(T newvalue)
{
    if (!head)
    {
        head = new Node(newvalue);
        tail = head;
    }
    else {
        tail->next = new Node(newvalue);
        tail = tail->next;
    }
    size++;
}

template<typename T>
bool List<T>::contains(T value)
{
    Node* current = head;
    while (current) {
        if (current->value == value)
            return true;
        current = current->next;
    }
    return false;
}

template<typename T>
T List<T>::getElem(int index)
{
    if (size >= index + 1)
    {
        Node* current = head;
        for (int i = 0; i < index; i++, current = current->next); //Move list
        return current->value; //Return index number
    }
    else
        throw out_of_range("Wrong index");
}

template<typename T>
int List<T>::get_size()
{
    return size;
}
