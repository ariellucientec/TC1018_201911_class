#pragma once
template<class T>
class Node
{
public: 
    Node(T value);
    Node* left;
    Node* right;
    T value;
};

template<class T>
Node<T>::Node(T value)
{
    this->value = value;
    left = nullptr;
    right = nullptr;
}