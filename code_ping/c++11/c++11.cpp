//
// Created by yanpan on 2019/4/17.
//



//auto 关键字
#if 0

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    vector<int> vec(3,10);
//    auto it = vec.iterator();

    for(auto iter = vec.cbegin(); iter != vec.cend(); iter++)
    {
        cout<< *iter <<endl;
    }

    return 0;
}

#endif



