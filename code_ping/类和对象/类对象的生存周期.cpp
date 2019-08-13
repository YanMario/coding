//
// Created by yanpan on 2019/4/21.
//

#if 0
#include <iostream>
using namespace std;

class Test
{
public:
    Test(int a = 10, int b = 10):_a(a),_b(b)  //带有默认值的构造函数
    {
        cout << this << endl;
        cout << "a: " << _a << " b: " << _b << endl;
        cout << "test()" << endl;
    }
    Test(const Test &src)         //拷贝构造函数
    {
        _a = src._a;
        _b = src._b;
        cout << &src << "->" << this << endl;
        cout << "a: " << _a << " b: " << _b << endl;
        cout << "test(const test &src)" << endl;
    }
    void operator=(const Test &src)   //赋值运算符重载函数
    {
        _a = src._a;
        _b = src._b;
        cout << &src << "->" << this << endl;
        cout << "a: " << _a << " b: " << _b << endl;
        cout << "operator=(const test &src))" << endl;
    }
    ~Test()              //析构函数
    {
        cout << this << endl;
        cout << "a: " << _a << " b: " << _b << endl;
        cout << "~Test()" << endl;
    }
private:
    int _a;
    int _b;
};

Test test1(20,10);
int main()
{
    Test test2(20, 20);
    Test test3 = test2;
    static Test test4 = Test(40, 40);//初始化的静态局部变量在.data段存储，程序的存活周期就是静态变量的生存周期
    test2 = Test(50, 50);
    test2 = (Test)(60, 60);
    test2 = 70;         //隐式生成临时对象
    Test *p1 = &Test(80);     //用指针指向临时对象，出了语句临时对象会析构
    Test &q1 = Test(90, 50);   //引用变量引用临时对象，临时对象的生存周期和引用变量的生存周期一样
    Test *p2 = new Test;
    delete p2;
    return 0;
}
Test test5(100, 100);
#endif