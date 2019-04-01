#include<iostream>

class Memory
{
public:
    void reserveByAddress(int** variable, int size);
    void reserveByReference(int*& variable, int& size);
};

void Memory::reserveByReference(int*& variable, int& size)
{
    variable = new int[size];
    size = 22;
}

void Memory::reserveByAddress(int** variable, int size)
{
    *variable = new int[size];
}

int main()
{    
    int* pointer;
    int size = 2;
    Memory m;
    m.reserveByAddress(&pointer, size);
    delete[]pointer;
    m.reserveByReference(pointer, size);
    pointer[0] = 10;
    std::cout << size;
    delete[]pointer;
}