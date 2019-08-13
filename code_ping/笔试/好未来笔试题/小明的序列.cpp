//
// Created by yanpan on 2018/10/9.
//

#if 0
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n = 1;
    cin>>n;
    int x;
    vector<int> vec1;
    for(int i=0;i<n;++i)
    {
        cin>>x;
        vec1.push_back(x);
    }
    vector<int>::iterator it = vec1.begin();
    for(;it!=vec1.end();++it)
    {
        cout<<*it;
    }
    cout<<endl;
    cout<<vec1[vec1.size()-1]<<endl;
    cout<<vec1.size()<<endl;

    return 0;
}
#endif
