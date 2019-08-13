//
// Created by yanpan on 2019/7/1.
//



//为了字节复习快速排序

#if 0
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


//每一次排序的调整
int AdjustArr(int *arr,int left, int right)
{
    //对参数进行判断，防止对空数组进行操作
    if(arr == NULL || left < 0 || right <= 0 || left > right)
        return -1;
    int i = left;
    int j = right;

    //基数 car_num
    int car_num = arr[left];
    while(i < j)
    {
        //从左边开始找，找到比基数小的元素 并将元素调整到右边的坑中
        while(i < j && arr[j] >= car_num)
            j--;
        if(i < j)
        {
            arr[i] = arr[j];
            //调整之后要将右边 i 的位置进行加一调整
            i++;
        }

        //从左边找完之后，再从右边开始找，找到比基数大的元素 并将元素调整到左边的坑中
        while(i < j && arr[i] <= car_num)
            i++;
        if(i < j)
        {
            arr[j] = arr[i];
            //调整之后将左边 j 的位置进行减一操作
            j--;
        }
    }

    //将基数填到 i 的位置
    arr[i] = car_num;
    return i;
}




//运用了栈的特性
void Quick_Sort(int *arr, int left, int right)
{
    if(arr == NULL || left < 0 || right <= 0 || right < left)
        return;
    stack<int> st;
    st.push(right);
    st.push(left);
    while(!st.empty())
    {
        int i = st.top();
        st.pop();
        int j = st.top();
        st.pop();
        if(i < j)
        {
            int k = AdjustArr(arr, i, j);
            if(i < k)
            {
                st.push(k-1);
                st.push(i);
            }
            if(j > k)
            {
                st.push(j);
                st.push(k+1);
            }
        }

    }
}


void show(int *arr,int len)
{
    if(arr == NULL || len<= 0)
        return;
    int i = 0;
    while(i < len)
    {
        printf("%d ",arr[i]);
        ++i;
    }
    printf("\n");
    return;
}




int main()
{
    int arr[10] = {72,6,57,88,60,42,83,73,48,85};
    int right = sizeof(arr)/sizeof(arr[0]);
    int left = 0;
    Quick_Sort(arr, left, right-1);
    show(arr,right);
    return 0;
}
#endif


#if 0

#include <iostream>
#include <stack>
using namespace std;

int Adjust(int *arr, int left, int right)
{
    if(arr == NULL || left > right)
        return -1;
    int cam_num = arr[left];
    while(left < right)
    {
        while (left < right && arr[right] >= cam_num)
        {
            right--;
        }
        if(right > left)
        {
            arr[left] = arr[right];
            left++;
        }

        while (left < right && arr[left] <= cam_num)
        {
            left++;
        }
        if(right > left)
        {
            arr[right] = arr[left];
            right--;
        }
    }
    arr[left] = cam_num;
    return left;
}

void Quick_Sort(int *arr, int left, int right)
{
    if(arr == NULL || left < 0 || left > right || right <= 0)
    {
        return;
    }
    stack<int> st;
    st.push(right);
    st.push(left);
    while(!st.empty())
    {
        int i = st.top();
        st.pop();
        int j = st.top();
        st.pop();
        if(i < j)
        {
            int k = Adjust(arr, i, j);
            if(i < k)
            {
                st.push(k-1);
                st.push(i);
            }
            if(j > k)
            {
                st.push(j);
                st.push(k+1);
            }

        }
    }
}


void show(int *arr,int len)
{
    if(arr == NULL || len<= 0)
        return;
    int i = 0;
    while(i < len)
    {
        printf("%d ",arr[i]);
        ++i;
    }
    printf("\n");
    return;
}

int main()
{
    int arr[10] = {72,6,57,88,60,42,83,73,48,85};
    int right = sizeof(arr)/sizeof(arr[0]);
    int left = 0;
    Quick_Sort(arr, left, right-1);
    show(arr,right);
    return 0;
}


#endif