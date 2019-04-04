#include<iostream>
#include<cstring>
using namespace std;

void ejercicio2A()
{
    int *p = new int[10]{5,9,3,8,1,4,7,6,0,2};
    const int * q = p;
    int * r = p;
    int n;

    n = *p; cout << n << endl;
    n = *(p+1); cout << n << endl;
    n = *p++;   cout << n << endl;
    n = *++p;   cout << n << endl;
    n = *(p)+1; cout << n << endl;
    n = *q;     cout << n << endl;
    n = *r;     cout << n << endl;
    
    p=p-2; //regreso al apuntador a su lugar para evitar memory leaks
    delete[]p;
}

class Example
{
public:
    int * a = new int[5]{10,20,30,40,50};
    ~Example(){delete [] a;}
};
void ejercicio2B()
{
    Example a;
    Example b = a;
    Example* c = &b;
    int n;

    n = (a.a[4]);       cout << n << endl;
    n = (b.a[3]);       cout << n << endl;
    n = *(b.a+2);       cout << n << endl;
    n = *(a.a+3);       cout << n << endl;
    *c->a = 4;          
    n=*(a.a);           cout << n << endl;
    n=*(b.a);           cout << n << endl;
    b.a[2] = 10;        
    n = *(b.a+2);       cout << n << endl;
    n = *(a.a+2);       cout << n << endl;
}

class ex2
{
public:
    int*a;
    ex2(){};
    virtual ~ex2(){}
};

class ex1
{
public:
    char*A = nullptr;
    ex1(const char*);
    void setA(const char*);
    virtual ~ex1(){if(A!=nullptr) delete [] A;}
};
ex1::ex1(const char* b)
{
    A=(char*)malloc(strlen(b)+1);
    strcpy(A,b);
}
void ex1::setA(const char* b)
{
    A=(char*)malloc(strlen(b)+1);
    strcpy(A,b);
}

class ex3
{
public:
    int*a;
    ex3(){}
    virtual ~ex3(){ delete a;}
};

class ex4 : public ex3
{
public:
    int*a;
    ex4(){}
    virtual ~ex4(){delete a;}
};

void ejercicio3()
{
    ex4*e1;
    ex3*e2;
    e1=new ex4;
    e2=new ex3;
    delete e1;
    delete e2;
}

int main()
{
    ejercicio2A();
    ejercicio2B();
    ejercicio3();
    return 0;
}