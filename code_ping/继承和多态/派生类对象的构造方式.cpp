//
// Created by yanpan on 2019/4/29.
//

/****************派生类对象的构造方式****************/
#if 0
#include <iostream>
#include <typeinfo>
using namespace std;


class Base
{
public:
    //提供了构造函数，编译器就不会提供默认的构造函数了
    Base(int a):ma(a){
        cout << "Base()" << endl;
    }
    ~Base(){
        cout << "~Base()" << endl;
    }
protected:
    int ma;
};

class Derive : public Base
{
public:
    //在初始化列表没有调用基类的构造函数则编译器会自动调用默认的构造函数，如果编译器没有提供基类的构造函数则会报错
    Derive(int data):Base(data), mb(data){
        cout << "Derive()" << endl;
    }
    ~Derive(){cout << "~Derive()" << endl;}
private:
    int mb;
};



int main()
{
    //派生类对象的构造方式
    /*先构造基类成员对象,在构造基类自己,构造派生类的成员对象,
    构造派生类自己,析构则反之
    (根据初始化列表的理解,调用构造函数先执行初始化列表再执行函数体)*/
    Derive derive(10);
    return 0;
}

#endif