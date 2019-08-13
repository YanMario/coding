//
// Created by yanpan on 2019/7/1.
//


#if 0
#include <iostream>
#include <vector>
using namespace std;

//建立堆，堆调整    堆排序呐呐呐    建立堆很重要呐

void MaxHeap_Adjust(int *arr, int start, int len)
{
    int temp;
    int left;
    while((left = start * 2 + 1) <= len)
    {
        int right = left + 1;
        int j = left;
        if(right <= len && arr[right] > arr[left])
            ++j;
        if(arr[start] < arr[j])
        {
            int temp = arr[start];
            arr[start] = arr[j];
            arr[j] = temp;
        }

        else
            break;
        start = j;
    }
}



void MaxHeap_Sort(int *arr, int len)
{
    for(int start = (len-1)/2; start >= 0; start--)
        MaxHeap_Adjust(arr, start, len);
    int temp;
    while(len >= 0)
    {
        temp = arr[0];
        arr[0] = arr[len];
        arr[len] = temp;
        len--;
        MaxHeap_Adjust(arr, 0, len);
    }
}
void Show(int *arr, int len)
{
    int i = 0;
    while(i < len)
    {
        printf("%d ", arr[i]);
        ++i;
    }
    printf("\n");
}


int main()
{
    int arr[] = {10, 40, 22, 2, 66, 3, 45, 56, 390, 453, 223, 99};
    int len = sizeof(arr)/sizeof(arr[0]);
    //程序的总时间复杂度为o(nlogn)
    MaxHeap_Sort(arr, len-1);
    Show(arr,len);
    return 0;
}
#endif