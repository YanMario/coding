//
// Created by yanpan on 2019/5/19.
//

#if 0

List FindK(List plist, unsigned int k)
{
    if(plist == NULL || k == 0)
        return NULL;
    Node *pnode = plist;
    Node *phead = plist;
    Node *prest = plist;
    int len = 0;
    while(pnode)
    {
        len++;
        pnode= pnode -> _pnext;
    }
    if(k > len)
        return NULL;
    for(auto i = 0; i < k-1; ++i)
    {
        if(phead -> _pnext != NULL)
            phead = phead -> _pnext;
    }
    while(phead -> _pnext)
    {
        phead = phead -> _pnext;
        prest = prest -> _pnext;
    }
    return prest;
}

#endif

#if 0
#include <vector>
#include <iostream>
using namespace std;



vector<int>& resver(vector<int> &vec)
{
    int len = vec.size();
    int num_end = vec[len - 1];

    auto i = len - 2;
    int count = 0;
    for(; i >= 0; --i)
    {
        count++;
        if(vec[i] < num_end)
        {
            int temp = vec[i];
            vec[i] = num_end;
            vec[len - 1] = temp;
            break;
        }
    }
    auto it = vec.begin();
    for(int j = 0; j < len - count; ++j)
        it++;
    sort(it, vec.end());
    return vec;
}


int main()
{
    int arr[] = {1, 7, 8, 5, 4};
    vector<int> vec(arr, arr+5);
    resver(vec);
    for(auto it = vec.begin(); it != vec.end(); ++it)
        cout<< *it;
    cout << endl;
    return 0;
}

#endif

#if 0
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int brr[5] ={0};
    memcpy(brr, arr, 20);
    for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        cout << brr[i] << endl;
    return 0;
}
#endif



#if 0     //有元函数的测试
#include <iostream>
using namespace std;

class A{
    int _a = 5;
public:
    A(){}
    void printf()
    {
        cout<< _a << endl;
    }
};

class B{
    int _b;
    A te();
    void hh();

public:
    B(int b): _b(b){}
    void printf()
    {
        cout<< _b << endl;
    }
    friend void test();
};

void test()
{
    _b = 10;
}

int main()
{
    B b(10);

    return 0;
}
#endif


#if 0   //string的字符串的切割
#include <iostream>
using namespace std;

int main()
{
    string str = "hello world ni hao quan shijie";
    string p = strtok((char*)str.c_str(), " ");
    string q = strtok(NULL, " ");
    cout << p << endl;
    cout << q << endl;
    cout << str << endl;
    char *z = strtok((char*)str.c_str(), " ");
    cout << z << endl;
    char *test = "1";
    int select = atoi(test);
    cout << select << endl;
    return 0;
}
#endif



