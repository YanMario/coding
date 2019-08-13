//
// Created by yanpan on 2019/5/9.
//


/* 智能指针的循环引用 */
#if 0
#include <iostream>
#include <memory>
using namespace std;

class B;

class A
{
public:
    A(){ cout << "A()" << endl; }
    A(int i):a(i){ cout << "A(int)" << endl;}
    ~A(){ cout << "~A()" << endl;}

    weak_ptr<B> ptr;
    int a;
};

class B
{
public:
    B(){ cout << "A()" << endl; }
    B(int i):b(i){ cout << "A(int)" << endl;}
    ~B(){cout << "~B()" << endl;}

    weak_ptr<A> ptr;
    int b;
};

int main()
{
    shared_ptr<A> aptr(new A(10));
    shared_ptr<B> bptr(new B(10));
    cout << aptr.use_count() << endl;
    aptr -> ptr = bptr;
    bptr -> ptr = aptr;
    cout << aptr.use_count() << endl;
    return 0;
}


#endif