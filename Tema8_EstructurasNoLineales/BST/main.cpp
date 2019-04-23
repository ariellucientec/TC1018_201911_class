#include"Bst.h"

int main()
{
    Bst<int> tree;
    tree.insert(6);
    tree.insert(5);
    tree.insert(7);
    tree.insert(8);
    tree.insert(3);
    tree.insert(4);

    tree.inOrder();
}