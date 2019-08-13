//
// Created by yanpan on 2018/7/23.
//

#if 0
#include <stdio.h>

bool find(int *brr, int rows, int columns, int number)
{
    bool found = false;
    if(brr != NULL && rows > 0 && columns > 0)
    {
        int row = 0;
        int columnt = columns - 1;
        while(row < rows && columnt >= 0)
        {
            if(brr[row * columns + columnt] == number)
            {
                found = true;
//                return found;
                break;
            }
            else if(brr[row * columns + columnt] < number)
            {
                ++row;
            }
            else
            {
                --columnt;
            }
        }
    }
    return found;
}


int main()
{
    int arr[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    printf("%d\n",find(*arr,4,4,11));
    return 0;
}
#endif