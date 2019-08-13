//
// Created by yanpan on 2018/9/30.
//
#if 0
#include <iostream>
using namespace std;

class CMyString
{
public:
    CMyString()
    {
        m_pdata = new char[1];
    }
    CMyString(char *name)
    {
        m_pdata = new char[strlen(name)+1];
        strcpy(m_pdata,name);
    }
    CMyString(const CMyString& str);
    CMyString& operator = (const CMyString& str)  //需要连续赋值所以要返回引用
    {
        cout<<"CMyString& operator =(const CMyString& str)"<<endl;
        if (this == &str)    //判断是不是自赋值
            return *this;
        delete[]m_pdata;
        m_pdata = nullptr;
        m_pdata = new char[strlen(str.m_pdata)+1]; //分配空间
        strcpy(m_pdata,str.m_pdata);
        return *this;
    }
    ~CMyString()
    {
        delete[]m_pdata;
        m_pdata = NULL;
    }
    void show()
    {
        if(this == NULL)
            return;
        cout<<m_pdata<<endl;
    }
private:
    char* m_pdata;
};

int main()
{
    CMyString str1;
    CMyString str2("world");
    CMyString str3;
    str3 = str1 = str2;  //要连续赋值   连续赋值是调用两次赋值函数
    str1.show();
    str3.show();
    cout<<"hello"<<endl;
    return 0;
}
#endif


#if 0
#include <iostream>
using namespace std;

class CMyString
{
public:
    CMyString()
    {
        m_pdata = new char[1];
    }
    CMyString(char *name)
    {
        m_pdata = new char[strlen(name)+1];
        strcpy(m_pdata,name);
    }
    CMyString(const CMyString& str)
    {
        cout<<"CMyString(const CMyString& str)"<<endl;
        m_pdata = new char[strlen(str.m_pdata)+1];
        strcpy(m_pdata,str.m_pdata);

    }

    //防止申请内存时没有申请成功，对原有实例的状态还没有修改 保证异常安全性
    CMyString& operator = (const CMyString& str)  //需要连续赋值所以要返回引用
    {
        cout<<"CMyString& operator =(const CMyString& str)"<<endl;
        if (this != &str)
        {
            CMyString strTemp(str);
            char *pTemp = strTemp.m_pdata;
            strTemp.m_pdata = m_pdata;
            m_pdata = pTemp;
        }
        return *this;
    }
    void Print();
    ~CMyString()
    {
        cout<<"~CMyString()"<<endl;
        delete[]m_pdata;
        m_pdata = NULL;
    }
    void show()
    {
        if(this == NULL)
            return;
        cout<<m_pdata<<endl;
    }
private:
    char* m_pdata;
};

int main()
{
    CMyString str1;
    CMyString str2("world");
    CMyString str3;
    str3 = str1 = str2;  //要连续赋值   连续赋值是调用两次赋值函数
    str1.show();
    str3.show();
    cout<<"hello"<<endl;
    return 0;
}

//void CMyString::Print()
//{
//    printf("%s", m_pdata);
//}
//
//void Test1()
//{
//    printf("Test1 begins:\n");
//
//    char* text = "Hello world";
//
//    CMyString str1(text);
//    CMyString str2;
//    str2 = str1;
//
//    printf("The expected result is: %s.\n", text);
//
//    printf("The actual result is: ");
//    str2.Print();
//    printf(".\n");
//}
//
//// 赋值给自己
//void Test2()
//{
//    printf("Test2 begins:\n");
//
//    char* text = "Hello world";
//
//    CMyString str1(text);
//    str1 = str1;
//
//    printf("The expected result is: %s.\n", text);
//
//    printf("The actual result is: ");
//    str1.Print();
//    printf(".\n");
//}
//
//// 连续赋值
//void Test3()
//{
//    printf("Test3 begins:\n");
//
//    char* text = "Hello world";
//
//    CMyString str1(text);
//    CMyString str2, str3;
//    str3 = str2 = str1;
//
//    printf("The expected result is: %s.\n", text);
//
//    printf("The actual result is: ");
//    str2.Print();
//    printf(".\n");
//
//    printf("The expected result is: %s.\n", text);
//
//    printf("The actual result is: ");
//    str3.Print();
//    printf(".\n");
//}

//int main(int argc, char* argv[])
//{
//    Test1();
//    Test2();
//    Test3();
//
//    return 0;
//}
#endif

#if 0
#include <iostream>
using namespace std;

int main()
{
    char *p = new char[1];
    delete p;



    cout<<"ok"<<endl;
//    delete p;
//    p =NULL;
}
#endif