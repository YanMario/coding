//
// Created by yanpan on 2019/5/7.
//



/********************智能指针的使用********************/
//auto_ptr unique_ptr  shared_ptr  weak_ptr
#if 0
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class A
{
public:
    A(){cout << "A()" << endl;};
    A(int i):a(i){cout << "A(int)" << endl;}
    ~A()
    {
        cout << "~A()" << endl;
    }
    int a;
};


void Fun(auto_ptr<A> &ptr)
{
    cout << ptr -> a << endl;
    cout << "Fun faction end" << endl;
}

//auto_ptr
void Test()
{
    auto_ptr<A> aptr(new A(5));
    auto_ptr<A> bptr;
    bptr = aptr;                //赋值运算符重载函数
    auto_ptr<A> cptr(bptr);     //拷贝构造函数
    Fun(cptr);       //会导致aptr失效,将aptr对资源的拥有权转向了ptr智能指针
    cout << cptr -> a << endl;
}

void Fun(unique_ptr<A>& ptr)   //必须写成引用
{
    cout<< ptr -> a << endl;
}

//unique_ptr
void Test1()
{
    unique_ptr<A> aptr(new A(10));
    unique_ptr<A> bptr;
//    bptr = aptr;                //error
//    unique_ptr<A> cptr(aptr);   //error
    bptr = move(aptr);
    cout<< bptr -> a << endl;
    aptr.reset(new A(20));      //重新指向一个堆上的资源
    cout<< aptr -> a << endl;
    Fun(aptr);
    aptr.release();             //释放资源
    cout<< aptr -> a << endl;  //error
    cout<< "Test1() end" <<endl;
}


//weak_ptr
void Test2()
{
    shared_ptr<A> aptr(new A(10));
    shared_ptr<A> bptr(aptr);
    weak_ptr<A> wptr(aptr);
    cout << wptr.use_count() << endl;
    shared_ptr<A> cptr = wptr.lock();    //获得shared_ptr对象
    cout << cptr -> a << endl;
    cout << wptr.use_count() << endl;    //获得引用计数

    aptr.reset(new A(20));               //重新指向一个新的资源
    cout << aptr -> a << endl;


    aptr.reset();                        //指向一个空的资源
    bptr.reset();
    cptr.reset();
    cout << wptr.use_count() << endl;
    shared_ptr<A> dptr = wptr.lock();   //当堆上的对象引用计数为0，被释放的时候，weak_ptr调用lock()返回一个指针空值(nullptr)
    cout << dptr.use_count() << endl;

}

int main()
{
    //只能用构造函数初始化  不能用 =
    /*shared_ptr<A> aptr(new A(10));
    vector<auto_ptr<A>> vec;   //容器的元素是一个auto_ptr 指向整形数组内存的智能指针
//    vec.push_back(auto_ptr<A>(new A[10]));

    cout << aptr.unique() << endl;   //返回1，证明aptr是资源的唯一持有者
    shared_ptr<A> bptr = aptr;       //有第二个指针指向了资源后 unique()就返回 0
    cout<< bptr.unique() << endl;
    cout<< bptr.use_count() << endl;  //返回当前资源的引用个数
    aptr.reset();                     //不再持有该资源
    cout<< bptr.use_count() << endl;
    bptr.reset();
    cout<< "main end" << endl;*/

    /*A *a = new A();
    shared_ptr<A> aptr(a);
    shared_ptr<A> bptr = aptr;*/


    /*shared_ptr<A> aptr(new A());
    shared_ptr<A> bptr = aptr;

    cout << aptr.use_count() << endl;*/

    /*shared_ptr<A> aptr(new A[5]);
    shared_ptr<A> bptr = aptr;

    cout << aptr.use_count() << endl;*/

    /*Test();*/

    /*Test1();*/

    Test2();
    return 0;
}

#endif




