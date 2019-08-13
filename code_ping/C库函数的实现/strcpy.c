//
// Created by yanpan on 2018/10/8.
//

#if 0

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

char* mystrcpy(char *str,const char *src)
{
    assert((str!=NULL)&&(src!=NULL));  //检查参数的合法性
    char *addres = str;
    while(*src != '\0')
    {
        *str++ = *src++;
    }
    return addres;        //为了实现链式拷贝返回地址
}

void show(const char *src)
{
    while(*src!='\0')
    {
        printf("%c",*src);
        src++;
    }
    printf("\n");
}

int main()
{
    const char *src = "hello";
    char *str = (char*)malloc(strlen(src)+1);
    mystrcpy(str,src);
    show(str);
    return 0;
}

#endif