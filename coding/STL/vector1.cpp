//
// Created by yanpan on 2018/9/12.
//

#if 0

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <exception>
#include <functional>
#include <iterator>
#include <algorithm>    //泛型算法
#include <memory>
#include <ctime>
using namespace std;

//范型算法   函数对象  绑定器

/*
 * 插入型迭代器     back_insert_iterator  -> back_inserter
 *                front_insert_iterator  ->front_inserter
 *                insert_iterator  ->   inserter
 */



template<typename Container>
void showBase(const Container &con)
{
    if(con.empty())
    {
        cout<<"vec is empty"<<endl;
    }
    cout<<con.size()<<endl;
    cout<<con.max_size()<<endl;
}

template<typename Container>
void showContainer(const Container &con)
{
    vector<int>::const_iterator it = con.begin();
    while(it != con.end())
    {
        cout<< *it <<" ";
        ++it;
    }
    cout<<endl;
}

int main()
{
    vector<int> vec1(0);
    showContainer(vec1);
    showBase(vec1);
    vector<int> vec2(vec1);

    int array[10] = {0};
    for(int i = 0; i < 10; ++i)
    {
        array[i] = rand()%100;
    }
    vec1.insert(vec1.begin(),27);
    vec1.insert(vec1.end(),26);
    showBase(vec1);
    showContainer(vec1);

    vector<int> vec3(array,array+10);
    vector<int> vec4(vec3.begin(),vec3.end());

    showContainer(vec4);
    sort(vec4.begin(),vec4.end(),greater<int>());
    showContainer(vec4);

    vector<int>::iterator it1 = find_if(vec4.begin(),vec4.end(),bind1st(greater_equal<int>(),74));
    if(*it1 !=74)
    {
        vec4.insert(it1,74);
    }
    showContainer(vec4);

    //删除  clear()  vec4.clear()   erase(it)   erase(itf,itl)
    //vector  pop_back
    //deque list  pop_back pop_front
    //72元素如果有则删掉
    vector<int>::iterator it2 = find(vec4.begin(),vec1.end(),72);
    if(it2 == vec4.end())
    {
        cout<<"not found"<<endl;
    }
    vec4.erase(it2);
    showContainer(vec4);

    //删除 >= 20 <= 60的数据全部删除
    vector<int>::iterator it3 = find_if(vec4.begin(),vec4.end(),bind1st(greater_equal<int>(),73));
    if(it3 == vec4.end())
    {
        return -1;
    }
    vector<int>::iterator it4 = find_if(vec4.begin(),vec4.end(),bind1st(greater<int>(),23));
    if(it4 == vec4.end())
    {
        return -1;
    }
    vec4.erase(it3,it4);
    showContainer(vec4);

    /*
    //逆向迭代器
    vector<int>::const_reverse_iterator rit = vec4.rbegin();
    for(;rit !=  vec4.rend();++rit)
    {
        cout<<*rit<<endl;
    }
     */

    /*
    //插入型迭代器     back_insert_iterator  -> back_inserter
    vector<int>::const_reverse_iterator rit = vec4.rbegin();
    for(;rit !=  vec4.rend();++rit)
    {
        cout<<*rit<<endl;
    }
     */

    vector<int> vec5;
    /*


    int length = vec4.size();
    for(int i = 0;i<length;++i)
    {
        vec5.push_back(vec4[i]);
    }
    showContainer(vec5);

     vector<int>::iterator it5 = vec4.begin();
     for(;it5 != vec4.end();++it)
     {
        vec5.insert(vec5.begin(),*it5);
     }
    */

    //泛型算法
  //  copy(vec4.begin(),vec4.end(),back_inserter(vec5.begin()));
//    showContainer(vec5);



//    vector<int>::iterator it = find_if(vec1.begin(),vec1.end(),bind1st(greater<int>(),20));

    return 0;
}


#endif


#if 0
#include <iostream>
using namespace std;

bool Test(int num_a,int num_b)
{
    while(num_b != 0)
    {
        int temp = num_b;
        num_b = num_a%num_b;
        num_a = temp;
    }
    if(num_a == 1)
        return true;
    else
        return false;
}

int main()
{
    int n = 0;
    cin>>n;
    int count = 0;
    int i = 1;
    while(i<=n)
    {
        for(int j=1; j<=n; ++j)
        {
            for(int h=1; h<=n; ++h)
            {
                if(i*i+j*j == h*h && i<=j&&j<=h)
                {
                    if(Test(i,j) && Test(j,h))
                    {
                        ++count;
                    }
                }
            }
        }
        ++i;
    }
    cout<< count <<endl;
}
#endif

#if 0
#include <stdio.h>

int Max_count(int c,int d)
{
    int temp=(d/c)*(-1);        //倍数，肯定是个负数故乘以-1

    int b_num=17/(temp+1);  //周期,也就是B的个数
    int a_num=17-b_num;    //A的个数

    int count=a_num*c+b_num*d;
    return count;
}

int main()
{
    long long a;
    long long b;
    scanf("%d",&a);
    scanf("%d",&b);
    int ret= Max_count(a,b);
    printf("%d\n",ret);
    return 0;
}
#endif