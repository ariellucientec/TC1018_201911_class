class ex2
{
public:
    int *a;
    ex2(){}
    ~ex2(){delete a;}
};
int main()
{
    ex2 e;
    return 0;
}