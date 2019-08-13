//
// Created by yanpan on 2019/7/14.
//
#if 0
#include <iostream>
#include <exception>
using namespace std;


int Min(int *arr,int low,int high)
{
    int result = arr[low];
    for(int i = low+1;i < high;++i)
    {
        if(result > arr[i])
        {
            result = arr[i];
        }
    }
    return result;
}

int Find_MIN_Num(int *arr, int len)
{
    if(arr == NULL || len <= 0)
        throw new exception("invalid parameters");
    int low = 0;
    int mid = 0;
    int high = len - 1;
    while(arr[low] >= arr[high])
    {
        if((high - low) == 1)
        {
            mid = high;
            break;
        }
        mid = (low + high) / 2;
        if(arr[low] == arr[mid] && arr[mid] == arr[high])
            return Min(arr, low, high);
        if(arr[low] <= arr[mid])
            low = mid;
        if(arr[mid] <= arr[high])
            high = mid;
    }
    return arr[mid];

}

int main()
{
    int arr[]={11,12,13,14,15,7,8,9,10};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout << Find_MIN_Num(arr, len) << endl;
}
#endif