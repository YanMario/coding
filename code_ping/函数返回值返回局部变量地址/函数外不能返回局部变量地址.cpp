//
// Created by yanpan on 2018/7/27.
//

#if 0
#include <stdio.h>
char *returnStr()
{
    char p[]="hello world!";
    return p;
}
int main()
{
    char *str;
    str=returnStr();
    printf("%s\n", str);
//    printf("%s\n","hello world");
    return 0;
}
#endif




#if 0
#include <iostream>
using namespace std;

int& test()
{
    int a = 20;
    cout<<"test fuction a = "<< a <<endl;
    return a;
}

int foo()
{
    int a =10;
    return a;
}
int main()
{
    int a = test();
    foo();
    cout<<"main fuction a = "<< a <<endl;
    return 0;
}
#endif




#if 0
#include <iostream>

using namespace std;

double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};

double& setValues( int i )
{
    return vals[i];   // 返回第 i 个元素的引用
}

// 要调用上面定义函数的主函数
int main ()
{

    int a = 10;
    int b = 20;
    int &c = a;
    c = b;
    cout<<" c = "<< c <<endl;
    cout<<" a = "<< a <<endl;
    cout << "改变前的值" << endl;
    for ( int i = 0; i < 5; i++ )
    {
        cout << "vals[" << i << "] = ";
        cout << vals[i] << endl;
    }
//    double a = 20.23;
//    double b = 89.2;
//    setValues(1) = a; // 改变第 2 个元素
//    setValues(3) = a;  // 改变第 4 个元素
//    setValues(3) = b;
    cout << "改变后的值" << endl;
    for ( int i = 0; i < 5; i++ )
    {
        cout << "vals[" << i << "] = ";
        cout << vals[i] << endl;
    }
    return 0;
}
#endif