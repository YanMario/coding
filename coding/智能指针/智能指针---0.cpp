//
// Created by yanpan on 2019/5/10.
//

#if 0
#include <iostream>
using namespace std;

class test
{
public:
    test(){cout << "test()" << endl;}
    ~test(){cout << "~test()" << endl;}
};


template <class T>
class smart_ptr
{
public:
    smart_ptr(T *ptr): _ptr(ptr){cout << "smart_ptr" << endl;}
    ~smart_ptr()
    {
        cout << "~smart_ptr" << endl;
        delete _ptr;
    }

    T *_ptr;

};

int main()
{
    smart_ptr<test> aptr(new test());

    for(int i = 0; i < 20; ++i)
    {
        if( i == 10)
            return i;
    }
}
#endif