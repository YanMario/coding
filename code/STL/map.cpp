//
// Created by yanpan on 2018/12/19.
//



//map
#if 0
#include <iostream>
#include <map>
using namespace std;

/*map原型
 *template<class Key,                                      //map::key_type
        class T,                                         //map::mapped_type
        class Compare = less<Key>,                       //map::key_compare
        class Alloc = allocator<pair<const Key, T>>      //map::allocator_type
        > class map;
 */


int main()
{

    return 0;
}
#endif



#if 0
#include <iostream>
#include <map>
using namespace std;

int min(int a,int b)
{
    printf("ok");
    return a>b?a:b;
}

int main()
{
    int a = 2;
    int b = 1;
    int c = min(a,b);
    int i = 0;
    for(i = 0; i<=6; ++i)
    {
        a = 3;
    }
    printf("%d\n",i);
    return 0;
}
#endif