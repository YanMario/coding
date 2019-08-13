//
// Created by yanpan on 2018/6/23.
//

#if 0
#include <stdio.h>

//面试题4


char* ReplaceBlank(char *str,int length)
{
    if(str == NULL || length <= 0)
        return 0;
    int originallength = 0;
    int numberofBlack = 0;
    int i = 0;
    while(str[i] != '\0')
    {
        ++originallength;
        if(str[i] = ' ')
        {
            ++numberofBlack;
        }
        ++i;
    }
    int newlength = originallength + numberofBlack*2;
    if(newlength > length)
        return 0;
    int indexoriginallength = originallength;
    int indexofnew = newlength;

    while(indexoriginallength >= 0 && indexofnew > indexoriginallength)
    {
        if(str[indexoriginallength] == ' ')
        {
            str[indexofnew--] = '0';
            str[indexofnew--] = '2';
            str[indexofnew--] = '%';
        }
        else
        {
            str[indexofnew--] = str[indexoriginallength];
        }
        --indexoriginallength;

    }
    return str;

}

int test()
{
    printf("%d\n",2);
    return 1;
}

int main()
{
    char str[] = "we are happy";
    char *p = ReplaceBlank(str,sizeof(str)/ sizeof(str[0]));
    while(*p != '\0')
    {
        printf("%s\n",*p);
        *p++;
    }
    int h = test();
    printf("%d\n",h);
    return 0;

}
#endif

//
// Created by yanpan on 2018/6/23.
//

#if 0
#include <stdio.h>

//面试题4


char* ReplaceBlank(char *str,int length)
{
    if(str == NULL || length <= 0)
        return 0;
    int originallength = 0;
    int numberofBlack = 0;
    int i = 0;
    while(str[i] != '\0')
    {
        ++originallength;
        if(str[i] == ' ')
        {
            ++numberofBlack;
        }
        ++i;
    }
    int newlength = originallength + numberofBlack*2;
    if(newlength > length)
        return 0;
    int indexoriginallength = originallength;
    int indexofnew = newlength;

    while(indexoriginallength >= 0 && indexofnew > indexoriginallength)
    {
        if(str[indexoriginallength] == ' ')
        {
            str[indexofnew--] = '0';
            str[indexofnew--] = '2';
            str[indexofnew--] = '%';
        }
        else
        {
            str[indexofnew--] = str[indexoriginallength];
        }
        --indexoriginallength;

    }
    return str;

}

int test()
{
//    printf("%d\n",1);
    return 1;
}

int main()
{
    char str[20] = "we are happy";
    char *p = ReplaceBlank(str,sizeof(str)/ sizeof(str[0]));
    printf("%s\n",p);
    /*while(*p != '\0')
    {
        printf("%s\n",*p);
        p++;
    }*/
    printf("%d\n",test());
    return 0;

}
#endif





#if 0
#include <iostream>
#include <vector>
using namespace std;

vector<int> Find(vector<int>& vec, int k)
{
    int len = vec.size();
    if(len <= 0)
        return {};
    vector<int> res;
    int l = 0;
    int r = len - 1;

    while(l < r)
    {
        if(vec[l] + vec[r] == k)
        {
            res.push_back(vec[l]);
            res.push_back(vec[r]);
            break;
        }
        else if(vec[l] + vec[r] < k)
            l++;
        else
            r--;
    }
    return res;
}

int main()
{
    vector<int> vec;
    int k;
    int n;
    while(cin>>n)
    {
        vec.push_back(n);
        char c = cin.get();
        if(c == '\n')
            break;
    }
    cin>>k;
    vector<int> res = Find(vec, k);
    cout<< res[0] <<" " << res[1] << endl;
    return 0;
}


#endif
