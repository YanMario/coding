//
// Created by yanpan on 2019/4/17.
//


/****************动多态的代码示范****************/
#if 0
#include <iostream>
#include <typeinfo>
using namespace std;


class Base
{
public:
    //提供了构造函数，编译器就不会提供默认的构造函数了
    Base(int a):ma(a){ cout << "Base()" << endl; }
    ~Base(){ cout << "~Base()" << endl; }
    virtual void show(){cout << "Base::show()" << endl;}   //基类中加上虚函数
    virtual void show(int i){cout << "Base::show(int)" << endl;}
protected:
    int ma;
};

class Derive : public Base
{
public:
    //在初始化列表没有调用基类的构造函数则编译器会自动调用默认的构造函数，如果编译器没有提供基类的构造函数则会报错
    Derive(int data):Base(data), mb(data){ cout << "Derive()" << endl; }
    ~Derive(){cout << "~Derive()" << endl;}
    void show(){cout << "Derive::show()" << endl;}  //虚函数
private:
    int mb;
};



int main()
{
    Derive derive(10);
    Base *p = &derive;
    p -> show();       //没有虚函数的时候   call  Base::show  =====> 编译时的绑定
    /*
      mov eax, dword ptr[p]
      mov ecx, dword ptr[eax]
      call ecx   ===============>   运行时的绑定   运行时的多态
    */
    cout<< sizeof(Base) <<endl;
    cout<< sizeof(Derive) <<endl;
    cout<< typeid(p).name() <<endl;
    cout<< typeid(*p).name() <<endl;    //访问的是对象RTTI类型信息
    return 0;
}

#endif







#if 0
#include <iostream>
using namespace std;
class A
{
public:
    void foo()
    {
        printf("1\n");
    }
    virtual void fun()
    {
        printf("2\n");
    }
};

class B: public A
{
public:
    void foo()
    {
        printf("3\n");
    }

    void fun()
    {
        printf("4\n");
    }
};

int main()
{
    A a;
    B b;
    A *p = &a;
    p -> foo();
    p -> fun();

    p = &b;
    p -> foo();
    p -> fun();

    B* ptr = (B*)&a;
    ptr -> foo();
    ptr -> fun();

    return 0;
}

/*
class Shape
{
public:
    Shape();                    // 构造函数不能是虚函数
    virtual double calcArea();
    virtual ~Shape();           // 虚析构函数
};
class Circle : public Shape     // 圆形类
{
public:
    Circle();
    virtual double calcArea();
};
int main()
{
    Shape * shape1 = new Circle();
    shape1->calcArea();
    delete shape1;  // 因为Shape有虚析构函数，所以delete释放内存时，先调用子类析构函数，再调用基类析构函数，防止内存泄漏。
    shape1 = NULL;
    return 0;
}*/




/*class Shape                     // 形状类
{
public:
    virtual double calcArea()
    {
    }
    virtual ~Shape();
};
class Circle : public Shape     // 圆形类
{
public:
    virtual double calcArea();
};
class Rect : public Shape       // 矩形类
{
public:
    virtual double calcArea();
};
int main()
{
    Shape * shape1 = new Circle();
    Shape * shape2 = new Rect();
    shape1->calcArea();         // 调用圆形类里面的方法
    shape2->calcArea();         // 调用矩形类里面的方法
    delete shape1;
    shape1 = nullptr;
    delete shape2;
    shape2 = nullptr;
    cout<< "hello" <<endl;
    return 0;
}*/
#endif