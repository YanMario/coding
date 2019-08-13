//
// Created by yanpan on 2019/5/6.
//

#if 0
#include <iostream>
using namespace std;

static int binary(int *arr, int len, int data)
{
    int min = 0;
    int max = len - 1;
    int mid = 0;
    while(min <= max)
    {
        mid = (min + max) / 2;   //这句代码有bug，可能导致int溢出
        if(arr[mid] > data)
            max = mid - 1;
        else if(arr[mid] < data)
            min = mid + 1;
        else
            return mid;
    }
    return -1;
}

static int binary1(int *arr, int len, int data)
{
    int min = 0;
    int max = len - 1;
    int mid = 0;
    while(min <= max)
    {
//        mid = min + (max - min) / 2;
        mid = min + ((max - min) >> 1);
        if(arr[mid] > data)
            max = mid - 1;
        else if(arr[mid] < data)
            min = mid + 1;
        else
            return mid;
    }
    return -1;
}


int main()
{
    int arr[6] = {1, 2, 6, 7, 8, 10};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << binary1(arr, len, 2) << endl;
    return 0;
}

#endif