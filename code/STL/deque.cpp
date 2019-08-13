//
// Created by yanpan on 2019/5/4.
//

#if 0
#include <iostream>
#include <list>
#include <deque>
#include <algorithm>
using namespace std;

template<typename Container>
void show(Container &con)
{
    copy(con.begin(), con.end(), ostream_iterator<typename Container::value_type>(cout, " "));
    cout<<endl;
}

int main()
{
    deque<int> dq1;
    int arr[] = {2, 1, 3, 6, 4, 5, 8, 7, 9};
    int len = sizeof(arr) / sizeof(arr[0]);
    list<int> list1(arr, arr+len);
    deque<int> dq2(list1.begin(), list1.end());

    dq2.push_back(20);
    dq2.push_front(30);
    dq2.insert(dq2.end(), 40);
    dq2.insert(dq2.begin(), 50);
    show(dq2);

    deque<int>::iterator it = find(dq2.begin(), dq2.end(), 20);
    if(it != dq2.end())
    {
        dq2.erase(it);
    }
    show(dq2);
    dq1.clear();
    show(dq1);
    sort(dq2.begin(), dq2.end());
    show(dq2);
    return 0;
}
#endif