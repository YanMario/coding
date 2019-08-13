//
// Created by yanpan on 2018/6/23.
//
#if 0
#include <stdio.h>

int Getsize(int *data)
{
    return sizeof(data);
}

int main()
{
    int data1[] = {1,2,3,4,5};
    int size1 = sizeof(data1);

    int *data2 = data1;
    int *p;
    int size2 = sizeof(p);
    int size3 = Getsize(data1);

    printf("%d,%d,%d",size1,size2,size3);
}
#endif


#if 0
#include <stdio.h>
#include <stdlib.h>
//二维数组中的查找
typedef int BOOL;
#define ture 1
#define false 0

BOOL Find(int *matrix, int rows, int columns, int number)
{
    BOOL found = false;

    if(matrix != NULL && rows > 0 && columns > 0)
    {
        int row =0;
        int column = columns - 1;
        while(row<rows && column >=0) {
            if(matrix[ row * columns + column] == number)      //看最后
            {
                found = ture;
                break;
            }
            else if(matrix[row * columns + column] > number)
            {
                --column;
            }
            else
            {
                ++row;
            }
        }
    }
    return found;
}

int main()
{
    int arr[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    printf("%d\n",Find(*arr,4,4,7));

    return 0;

}
#endif

