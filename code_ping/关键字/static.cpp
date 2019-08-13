//
// Created by yanpan on 2019/8/3.
//
#if 0
#include <stdio.h>
#include <stdlib.h>


void fun()
{
    static int var1 = 0; //静态局部变量
    int var2 = 0;        //自动变量
    var1 ++;//1
    var2 ++;//1

    printf("var1 = %d ", var1);
    printf("var2 = %d\n", var2);
}

int main()
{
   int i = 0 ;
   for( ; i < 4 ;++i)
   {
	  printf("i = %d\n",i);
	 fun();
   }
    return 0;
}
#endif