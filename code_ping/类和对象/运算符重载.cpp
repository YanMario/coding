//
// Created by yanpan on 2019/4/18.
//



//运算符重载函数 new 和 delete
#if 0
#include <iostream>
using namespace std;//为 using 指示符，其中 namespace 为名字空间作用域
//建议不用这个指示符，可在需要的地方加 std 的作用域

void* operator new(size_t size) //size 代表总字节个数
{
    void* ptr = malloc(size);
    cout << "operator new: " << ptr << endl;
    return ptr;
}

void operator delete(void* ptr)
{
    cout << "operator delete: " << ptr << endl;
    free(ptr);
}

int main()
{
    int *p = new int;
    delete p;         //直接调用我们写好的 operator new（开辟空间） 和
                      // （释放空间），没有初始化和释放资源
    return 0;
}
#endif




//赋值运算符重载函数
#if 0
#include <iostream>
using namespace std;

class person{
public:
    person(int);
    inline bool operator == (const person &ps) const;
private:
    int _age;
};

person::person(int a)
{
    _age = a;
}
inline bool person::operator==(const person &ps) const
{
    if(_age == ps._age)
        return true;
    return false;
}

int main()
{
    person p1(10);
    person p2(10);
    if(p1 == p2)
        cout<< "these age is equal" <<endl;
    return 0;
}
#endif

//操作符重载之全局函数
#if 0
#include <iostream>
using namespace std;

class person{
public:
    person(int age = 0):_age(age)
    {
        cout << "person(int age )"<< endl;
    }
    person(person& ps)
    {
        *this = ps;
        cout << "person(pesrson &ps)"<< endl;
    }
    ~person()
    {
        cout<< "~person()" <<endl;
    }
public:
    int _age;
};

bool operator==(person &p1, person &p2)   //全局重载==操作符
{
    if(p1._age == p2._age)
        return true;
    return false;
}

int main()
{
    person person1(10);
    person1._age;
    person person2(person1);
    if (person1 == person2)
    {
        cout << " is equal " << endl;
    }
    else
    cout << "not equal " << endl;

    return 0;
}



#endif


#if 0
#include <iostream>
using namespace std;


int main()
{
    return 0;
}
#endif

#if 0
#include <iostream>
#include "CGoods.h"
using namespace std;

CGoods::CGoods()
{
    cout<<"CGoods"<<endl;
    _pname = new char[1];
    _pname[0] = '\0';
}

CGoods::CGoods(char *name,double price,int mount)
{
    cout<<"CGoods(char *, double, int)"<<endl;
    _pname = new char[strlen(name)];
    strcpy(_pname,name);
    _price = price;
    _mount = mount;
}
CGoods::CGoods(const CGoods& src)
{
    cout<<&src << "---->" << this <<endl;
    cout<<"拷贝构造函数"<<endl;
    _pname = new char[strlen(src._pname)+1];
    strcpy(_pname,src._pname);
    _mount = src._mount;
    _price = src._price;
}

/*没有考虑异常安全的赋值重载函数*/
#if 0
CGoods& CGoods::operator=(const CGoods &src)
{
    cout<<&src << "---->" << this <<endl;
    cout<<"CGoods operator="<<endl;
    if(this == &src)
        return *this;
    delete []_pname;
    _pname = NULL;
    _pname = new char[strlen(src._pname)+1];
    strcpy(_pname,src._pname);
    _mount = src._mount;
    _price = src._price;
    return *this;
}
#endif
/*考虑异常安全的赋值重载函数*/
//写法一：先申请内存，new成功后在释放_pname指向堆上的资源
//写法二：创造一个临时对象，在交换临时对象和原来的类(会多调用一次拷贝构造函数)
#if 1
CGoods& CGoods::operator=(const CGoods &src)
{
    cout<<&src << "---->" << this <<endl;
    cout<<"CGoods operator="<<endl;
    if(this != &src)
    {
        CGoods goodsTemp(src);
        char *pTemp = goodsTemp._pname;
        goodsTemp._pname = _pname;
        _pname = pTemp;
        _mount = src._mount;
        _price = src._price;
    }
    return *this;
}
#endif
CGoods::~CGoods()
{
    cout<<"~CGoods"<<endl;
    delete []_pname;
    _pname = NULL;
}


int main()
{
    CGoods goods1;
    CGoods goods2("apple",3.5,6);
    CGoods goods3;
    goods3 = goods1;
//    goods3 = goods2;
//    CGoods goods4;
//    goods4 = goods3 = goods2;
    return 0;
}
#endif
















