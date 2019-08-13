//
// Created by yanpan on 2018/9/12.
//

#if 0
#include <iostream>
using namespace std;

class Counter
{
public:
    Counter():_counter(1)
    {
        _number++;
    }

    void Show()    //Counter *const this
    {
        shownumber();
        show();
        cout<<"_counter:" <<_counter << endl;
    }

    void show()const   //const Counter *const this
    {                  //不能调用普通成员方法 this指向被const修饰  const Counter *const this不能赋值到 Counter *const this

        shownumber();
        cout<<"const _counter: "<<_counter <<endl;
    }
    static void shownumber()  //调用静态成员方法不需要对象因为静态成员方法没有this指针
    {
        cout<<"_nmber: " <<_number << endl;
//        cout<<"_counter " <<_counter << endl;
    }

private:
    int _counter;
    static int _number;      //静态成员内存在数据段  //这不是定义，是类型的抽象说明
};

int Counter::_number = 0;

int main()
{
    Counter *p = new Counter();
    p -> Show();
    delete p;
    Counter counter1;
    Counter counter2;
    Counter counter3;              //Counter*
    counter3.show();
    const Counter counter4;       //const Counter*
    counter4.show();              // const Counter*     成员方法里有this指针 this指针指向对象的内存
    Counter::shownumber();        //静态的成员函数调用不需要一个对象

    return 0;
}

#endif

/*************const修饰this指针指向的代码*************/
#if 0
#include <iostream>
using namespace std;



int main()
{
    int a = 10;
    int b = 20;
    const int *p = &a;
//    int *q = p;
//    const char *w = "hello world";
//    char *r = w;
    p = &b;
    cout<<"*p: "<<*p<<endl;
    return 0;
}

#endif