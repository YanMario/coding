//
// Created by yanpan on 2018/9/7.
//
#if 0

#include <iostream>
using namespace std;
char *RemoveRight(char *arr, int a, int b){
    if (arr == NULL)
    {
        return NULL;
    }
    a = a % b;
    if (a == 0)
    {
        return arr;
    }
    for(int i = 0; i < b-a; i++)
    {
        int tmp = i + a;
        tmp = tmp %b;
        char j = arr[tmp];
        arr[tmp] = arr[i];
        arr[i] = j;
    }
    return arr;
}

int main()
{
    char arr[] = "abcd1234";
//    RemoveRight(arr,4,strlen(arr));
    cout<<arr<<endl;
    return 0;
}

#endif