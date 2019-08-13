//
// Created by yanpan on 2019/6/9.
//

#if 0
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    vector<int> deque1;
    for(auto i = 0; i < 6; ++i)
    {
        deque1.push_back(i);
    }

    auto it = deque1.begin();
    for(; it != deque1.end();)
    {
        if(*it > 2)
            it = deque1.erase(it);   //会返回迭代器的下一个值
        else
            it++;
    }
    it = deque1.begin();
    for(; it != deque1.end(); ++it)
    {
        cout << *it << endl;
    }
    return 0;
}
#endif