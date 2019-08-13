//
// Created by yanpan on 2019/8/2.
//

//使用虚基类

#if 0
#include <iostream>
using namespace std;


class A
{
public:
    void set_a(int m)
    {
//        a = m;
//        cout << a << endl;
    }
//
//   int a;

};

class B : virtual public A      //虚基类
{
public:
    void  set_b(int n)
    {
//        b = n;
//        cout << b << endl;
    }
//
//
//    int b;
};

class C: virtual public A          //虚基类
{
public:

    virtual void  set_c(int n)
    {
//        c = n;
//        cout << c << endl;
    }

//    int c;
};
class D :public B,public C
{
public:
    void   set_d(int n)
    {
        d = n;
        cout << d << endl;
    }

    int d;

};

int  main()
{
    cout<< "A: " << sizeof(A) << " B: " << sizeof(B) << " C: " << sizeof(C) << " D: " << sizeof(D);
    cout << endl;

//    D d;
//    d.set_a(200);          //设置虚基类类后不会报错
//    d.set_b(300);
//    d.set_c(400);
//    d.set_d(500);
//    cout << d.B::a << endl;


    return 0;
}

#endif