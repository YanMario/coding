// Created by yanpan on 2019/5/10.

#if 0
#include <iostream>
using namespace std;


//class也有内存对齐
class Base
{
public:
    Base(){cout << "Base()" << endl;}
    Base(int num): _bnum(num){cout << "Base(int)" << endl;}
    void show()
    {
        cout << "_bnum: " << _bnum << endl;
    }
    virtual ~Base(){cout << "~Base()" << endl;}
private:
    int c;
    int d;
    int _bnum;
};

class Derive: public Base
{
public:
    Derive(){cout << "Derive()" << endl;}
    Derive(int num): _dnum(num){cout << "Derive(int)" << endl;}
    ~Derive(){cout << "~Derive()" << endl;}
private:
    int _dnum;

    int c;
};

int main()
{
    Base A;
    cout << "base: " << sizeof(Base) << " Drev: " << sizeof(Derive) << " A: " << sizeof(A) << endl;
    Base* base = new Derive();
    delete base;
    return 0;
}
#endif