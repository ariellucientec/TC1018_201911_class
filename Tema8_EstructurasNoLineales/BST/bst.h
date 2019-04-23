#include<iostream>
#include"node.h"

using namespace std;

template<class T>
class Bst
{
protected:
    void inOrder(Node<T>*);
    Node<T>* root;
public:
    Bst();
    void insert(T value);
    void inOrder();
};

template<class T>
Bst<T>::Bst()
{
    root = nullptr;
}
template<class T>
void Bst<T>::insert(T value)
{
    if(root == nullptr)
        root = new Node<T>(value);
    else
    {
        Node<T>* temp = root;
        while(true)
        {
            if(value < temp->value)
            {
                if(temp->left == nullptr)
                {
                    temp->left = new Node<T>(value);
                    return;
                }
                else
                {
                    temp = temp->left;
                    continue;
                }            
            }
            if(value > temp->value)
            {
                if(temp->right == nullptr)
                {
                    temp->right = new Node<T>(value);
                    return;
                }
                else
                {
                    temp = temp->right;
                    continue;
                }            
            }
        }
    }
}

template<class T>
void Bst<T>::inOrder()
{
    inOrder(root);
}

template<class T>
void Bst<T>::inOrder(Node<T>* node)
{

}