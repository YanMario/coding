//
// Created by yanpan on 2019/7/2.
//

//priority_queue

#if 0

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cmp     //比较方法    作为放函数传到容器里
{
    bool operator()(const int &left, const int &right)const
    {
        return left < right;
    }

};


int main()
{
    int arr[] = {2, 1, 4, 3, 8, 6, 10};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

//    priority_queue<int> ipq(arr, arr + sizeof(arr) / sizeof(arr[0]));
//    cout << "size = " << ipq.size() << endl;
    priority_queue<int, vector<int>, greater<int>> ipq;     //制定了从小到大的排序规则， 默认是从大到小 绑定器
    for(auto i = 0; i < vec.size(); i++)
    {
        ipq.push(vec[i]);
//        if(ipq.size() > 4)
//            ipq.pop();
    }

    for(int i = 0; i < ipq.size(); i++)
        cout << ipq.top() << " ";
    cout << endl;

    while(!ipq.empty())  //默认是大根堆
    {
        cout << ipq.top() << " ";
        ipq.pop();
    }
    cout << endl;

    return 0;
}
#endif



//使用 make_heap()  方法 使容器变成一个堆
#if 0

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cmp     //比较方法    作为放函数传到容器里
{
    bool operator()(const int &left, const int &right)const
    {
        return left < right;
    }

};


int main()
{
    int arr[] = {2, 1, 4, 3, 8, 6, 10};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

    make_heap(vec.begin(), vec.end(), greater<int>());

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}

#endif

#if 0

#include<iostream>
#include<vector>

using namespace std;

void Fun(vector<vector<int>> &arr,int row,int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<arr[i][j] ;
        }
        cout<<endl;
    }
}

int main()
{
    int row,col;
    cin>>row;
    cin>>col;

    vector<int> temp;
    vector<vector<int>> arr;
    for(int i=0;i<row;i++)
    {

        for(int j=0;j<col;j++)
        {
            int num;
            cin>>num;
            temp.push_back(num);
        }
        arr.push_back(temp);
        temp.clear();
    }
    Fun(arr,row,col);
}
#endif