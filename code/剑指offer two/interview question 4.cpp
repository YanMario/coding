//
// Created by yanpan on 2018/7/27.
//

#if 0
#include <iostream>
using namespace std;

char* Rplaceblank(char *arr,int len)
{
    if(arr != NULL && len > 0)
    {
        int numberblank = 0;
        int orginlen = 0;
        int i = 0;
        while(arr[i] != '\0')
        {
            if(arr[i] == ' ')
            {
                ++numberblank;
            }
            ++orginlen;
            ++i;
        }
        int newlen = orginlen + numberblank*2;
        if(newlen > len)
            return 0;
        int indexlen = orginlen;
        int indexofnew = newlen;
        while(indexlen >= 0 && indexofnew > indexlen)
        {
            if(arr[indexlen] == ' ')
            {
                arr[indexofnew--] = '0';
                arr[indexofnew--] = '2';
                arr[indexofnew--] = '%';
            }
            else
            {
                arr[indexofnew--] = arr[indexlen];
            }
            --indexlen;
        }
    }
    return arr;
}

int main()
{
    cout<<"1"<<endl;
    char p[20] = "we are happy";
    cout<<2<<endl;
    char* q = Rplaceblank(p,sizeof(p)/sizeof(p[0]));
    cout<<"%s\n"<<q<<endl;
    cout<<"s"<<endl;
    return 0;
}
#endif

#if 0

#include <stdio.h>

int climbStairs(int n)
{
    int temp = 0;
    int a =n;
    int arr[a];
    if(n==1 || n==2)
        return n;
    if(arr[a] != 0)
        return arr[n];
    else
    {
        arr[n] = climbStairs(n-1) + climbStairs(n-2);
    }
    printf("%d\n",arr[a]);
    return arr[n];
}


int main()
{
    int n = 4;
    climbStairs(n);
    return 0;
}

#endif