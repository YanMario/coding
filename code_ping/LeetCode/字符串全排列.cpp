//
// Created by yanpan on 2019/5/7.
//

/************** 字符串的连续子串 **************/
#if 0
#include <iostream>
using namespace std;



//时间复杂度  O(n三次方)
void AllSubString(char *str, int len)
{
    int i = 0;
    for(; i < len; i++)
    {
        for(int j = i; j < len; j++)
        {
            for(int k = i; k < j; k++)
                cout << str[k];
            cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    char str[] = {"abcd"};
    int len = sizeof(str) / sizeof(str[0]);
    AllSubString(str, len);
    return 0;
}
#endif