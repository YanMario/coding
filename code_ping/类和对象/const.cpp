//
// Created by yanpan on 2019/4/16.
//

#if 0
#include <iostream>
using namespace std;

class Test
{
private:
    int a;
};
int main()
{
    int a =10;
    int &b = a;
    int &c = b;
    cout<< sizeof(Test) <<endl;
    cout << c <<endl;
    int *d = &c;
    cout << *d << endl;
    return 0;
}
#endif