//
// Created by yanpan on 2019/7/19.
//

#if 0
#include <iostream>
#include <list>
using namespace std;

int Sum(list<int> l1, int k)
{
    int len = l1.size();
    if(len <= 0)
        return -1;
    int sum = 0;
    auto it = l1.begin();
    for(; it != l1.end(); it++)
    {
        if(*it > k)
        {
            cout << *it << " ";
            sum += *it;
        }
    }
    cout << endl;
    cout << sum << endl;
    return sum;
}

int main()
{
    list<int> list1(6);
    list1.push_back(4);
    list1.push_back(80);
    list1.push_back(20);
    list1.push_back(34);
    list1.push_back(55);
    list1.push_back(60);
    int k = 33;
    Sum(list1, k);
    return 0;
}

#endif



