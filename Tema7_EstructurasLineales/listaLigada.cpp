#include <iostream>
using namespace std;

template<class T>
class Node
{
public:
    Node()
    {   next = nullptr; }
    T value;
    Node<T>* next;
};
template<class T>
void printNormal(Node<T>* node)
{
    Node<T>* temp = node;
    while(temp != nullptr)
    {
        cout<< temp->value << " ";
        temp = temp->next;
    }
}

template<class T>
void recursivePrint(Node<T>* node)
{
    if(node == nullptr)
        return; 
    else
    {
        cout << node->value;
        return recursivePrint(node->next);
    }
}

template<class T>
class LinkedList
{
protected:
    Node<T>* root;
public:
    LinkedList()
    {
        root = nullptr;
    }

    void add(Node<T>* node)
    {
        if(root == nullptr)
            root = node;
        else
        {
            Node<T>* temp = traverse(root);
            temp->next = node;
        }
    }

    Node<T>* traverse(Node<T>* node)
    {
        if(node->next == nullptr)
            return node;
        else
            return traverse(node->next);
    }

};

int main()
{
    Node<char>* node =new Node<char>();  // esto se crea en el heap
    node->value = 33;
    Node<char>* nodeEight = new Node<char>();
    nodeEight->value = 34;
    node->next = nodeEight;
    Node<char>* nodeNine = new Node<char>();
    nodeNine->value = 35;
    nodeEight->next = nodeNine;
    recursivePrint(node);
    return 0;
}