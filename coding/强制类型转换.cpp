//
// Created by yanpan on 2019/4/29.
//

#if 0
#include <iostream>
using namespace std;

int main()
{
    int *ptr = NULL;
    char *qtr = NULL;
    qtr = static_cast<char*>(ptr);   //no
    qtr = reinterpret_cast<char*>(ptr);     //ok

    return 0;
}

#endif