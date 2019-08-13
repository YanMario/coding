//
// Created by yanpan on 2018/9/10.
//

#if 0                //************** 用函数模版实现范型冒泡排序算法 *********************/
#include <iostream>
#include <ctime>
using namespace std;

template<typename T>
void sort(T array[],int size)
{
    int i,j = 0;
    T temp = T();  //T() 0初始化 or 0构造
    for(i = 0; i < size-1; ++i)
    {
        for(j = 0; j < size-1-i; ++j)
        {
            if(array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}


int main()
{

    //内置类型
    int a = int();
    cout<<a<<endl;

    int array[10];
    for(int i = 0; i<10; ++i)
    {
        array[i] = rand()%100+1;
    }
    sort(array,10);

    for(int i = 0; i<10 ;++i)
    {
        cout<<array[i]<< " ";
    }
    cout<<endl;
    return 0;
}

#endif

#if 0           //************** 用函数模版实现范型find算法 *********************/

#include <iostream>
using namespace std;

template <typename T>
int findValIndex(T *arr,int length,const T &val)
{
    for(int i = 0;i < length; ++i)
    {
        if(arr[i] == val)
        {
            return i;
        }
    }
    return -1;
}

template<>
int findValIndex<char*>(char** arr,int length,char* const &val)
{
    for(int i = 0;i < length; ++i)
    {
        if(strcmp(arr[i],val) == 0)
            return i;
    }
    return -1;
}

int main()
{
    int arr[] = {1,2,3,78,90,31};
    char *Tarr[] = {"hello","world","success","ok","nice"};
    int length = sizeof(Tarr)/sizeof(Tarr[0]);
    int index = -1;


    index = findValIndex<char*>(Tarr,length,"ok");
    if(-1 == index)
    {
        return -1;
    }
    cout<<"find of index: "<< index <<endl;
}

#endif


#if 0                  //******************用类模版实现链表******************/

#include <iostream>
using namespace std;

//前向声明
template <typename T>
class CLink;

template <typename T>
class Node
{
public:
    Node(T data = T()): _data(data), _pnext(NULL){};
private:
    T _data;
    Node<T> *_pnext;

    //友元类

    friend class CLink<T>;
};

template <typename T>
class CLink
{
public:
    CLink()
    {
        _phead =  new Node<T>();
    }
    ~CLink()
    {
        Node<T> *pcur = _phead;
        while(pcur != NULL)
        {
            _phead = _phead->_pnext;
            delete pcur;
            pcur = _phead;
        }
    }

    void insertHead(const T &value);

    void show()
    {
        Node<T> *pcur = _phead -> _pnext;
        while(pcur != NULL)
        {
            cout<< pcur->_data << " ";
            pcur = pcur->_pnext;
        }
        cout<<endl;
    }

private:
    Node<T> *_phead;
};
template <typename T>
void CLink<T>::insertHead(const T &value)
{
    Node<T> *ptmp = new Node<T>(value);
    ptmp -> _pnext = _phead -> _pnext;
    _phead -> _pnext = ptmp;
}

int main()
{
    //类模版的选择实例化   成员方法使用的时候实例化，不使用的时候没有实例化即没有编译
    CLink<int> link1;
    link1.insertHead(10);
    link1.insertHead(20);
    link1.insertHead(30);
    link1.insertHead(40);
    link1.show();
//    CLink<> link2;
    CLink<double> link3;
//    CLink<CLink<int>> link4;   //会报错
}
#endif

/* 嵌套类 */

#if 0
#include <iostream>
#include <ctime>
using namespace std;

template<typename T>
class CLink
{
public:
    //前置声明
    class Node;


    CLink();
    ~CLink();
    void inseartHead(const T &value)
    {
        Node *pcur = new Node(value);
        pcur -> _pnext = _phead ->_pnext;
        _phead ->_pnext = pcur;
    }
    Node* queryNode(const T &value);

    void show()const
    {
        Node *pcur = _phead;
        while(pcur != NULL)
        {
            cout<<pcur -> _data <<" ";
            pcur = pcur -> _pnext;
        }
        cout<<endl;
    }
private:
    class Node
    {
    public:
        Node(const T data = T()):_data(data),_pnext(NULL){};
        T _data;
        Node *_pnext;
    };
    Node *_phead;
};
template<typename T>
CLink<T>::CLink()
{
    _phead = new Node();
}

template<typename T>
CLink<T>::~CLink()
{
    Node *pcur =  _phead;
    while(pcur != NULL)
    {
        _phead = _phead->_pnext;
        delete(pcur);
        pcur = _phead;
    }
}

template<typename T>
typename CLink<T>::Node* CLink<T>::queryNode(const T &value) //typename的第二个作用告诉编译器Node
{                                                            //是一个类型的名字，把它当作类名处理
    Node *pcur = _phead -> _pnext;
    while(pcur != NULL)
    {
        if(pcur->_data == value)
            return pcur;   //返回当前节点的地址
        pcur = pcur -> _pnext;
    }
    return NULL;
}

//提供专门的特例化
template<>
class CLink<char *>
{

public:
    //前置声明
    class Node;


    CLink()
    {
        cout<<"CLink<char *> "<<endl;
        _phead = new Node();
    }
    ~CLink()
    {

    }
    void inseartHead(const char* &value)
    {
        Node *pcur = new Node(value);
        pcur -> _pnext = _phead ->_pnext;
        _phead ->_pnext = pcur;
    }
    Node* queryNode(const char* &value);
    void show()const
    {
        Node *pcur = _phead;
        while(pcur != NULL)
        {
            cout<<pcur -> _data <<" ";
            pcur = pcur -> _pnext;
        }
        cout<<endl;
    }
private:
    class Node
    {
    public:
        Node(const char* data = " "):_pnext(NULL)
        {
            _data = new char[strlen(data)+1];
            strcpy(_data,data);
        }
        char* _data;
        Node *_pnext;
    };
    Node *_phead;
};

int main()
{
    CLink<int> link1;

    for(int i = 0; i < 10; ++i)
        link1.inseartHead(rand()%100);
    link1.show();
    if(!link1.queryNode(73))
    {
        cout<<"73 not find"<<endl;
        return -1;
    }
    else
    {
        cout<<"73 be find"<<endl;
    }
    return 0;
}
#endif

#if 0      //友元类
#include <iostream>
using namespace std;

class B;
class A
{
public:
    A(int _a):a(_a){};
private:
    int a;
    friend class B;
};

class B
{
public:
    void get();
private:
    friend class A;
    int b =20;
};
void B::get()
{
    cout<< a <<endl;
    cout<< b <<endl;
}
int main()
{
    A Aa(10);
    B Bb;
    Bb.get();
    return 0;
}
#endif