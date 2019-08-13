//
// Created by yanpan on 2018/9/12.
//



//虚函数能否被内联
#if 0
#include <iostream>
using namespace std;
class Base
{
public:
    inline virtual void who()
    {
        cout << "I am Base\n";
    }
    virtual ~Base() {}
};
class Derived : public Base
{
public:
    inline void who()  // 不写inline时隐式内联
    {
        cout << "I am Derived\n";
    }
};

int main()
{
    // 此处的虚函数 who()，是通过类（Base）的具体对象（b）来调用的，编译期间就能确定了，所以它可以是内联的，但最终是否内联取决于编译器。
    Base b;
    b.who();

    // 此处的虚函数是通过指针调用的，呈现多态性，需要在运行时期间才能确定，所以不能为内联。
    Base *ptr = new Derived();
    ptr->who();

    // 因为Base有虚析构函数（virtual ~Base() {}），所以 delete 时，会先调用派生类（Derived）析构函数，再调用基类（Base）析构函数，防止内存泄漏。
    delete ptr;
    ptr = nullptr;

//    system("pause");
    return 0;
}
#endif



//参数列表初始化
#if 0

#include <iostream>
#include <vector>
#include <initializer_list>

template <class T>
struct S {
    std::vector<T> v;
    S(std::initializer_list<T> l) : v(l) {
        std::cout << "constructed with a " << l.size() << "-element list\n";
    }
    void append(std::initializer_list<T> l) {
        v.insert(v.end(), l.begin(), l.end());
    }
    std::pair<const T*, std::size_t> c_arr() const {
        return {&v[0], v.size()};  // 在 return 语句中复制列表初始化
        // 这不使用 std::initializer_list
    }
};

template <typename T>
void templated_fn(T) {}

int main()
{
    S<int> s = {1, 2, 3, 4, 5}; // 复制初始化
    s.append({6, 7, 8});      // 函数调用中的列表初始化

    std::cout << "The vector size is now " << s.c_arr().second << " ints:\n";

    for (auto n : s.v)
        std::cout << n << ' ';
    std::cout << '\n';

    std::cout << "Range-for over brace-init-list: \n";

    for (int x : {-1, -2, -3}) // auto 的规则令此带范围 for 工作
        std::cout << x << ' ';
    std::cout << '\n';

    auto al = {10, 11, 12};   // auto 的特殊规则

    std::cout << "The list bound to auto has size() = " << al.size() << '\n';

//    templated_fn({1, 2, 3}); // 编译错误！“ {1, 2, 3} ”不是表达式，
    // 它无类型，故 T 无法推导
    templated_fn<std::initializer_list<int>>({1, 2, 3}); // OK
    templated_fn<std::vector<int>>({1, 2, 3});           // 也 OK
}
#endif




/*
 * 写出高效c++代码，函数返回值的优化
 */
#if 0
#include <iostream>
using namespace std;

class Test
{
public:
    Test(int a = 10):_a(a)  //带有默认值的构造函数
    {
        cout << "test()" << endl;
    };
    Test(const Test &src)         //拷贝构造函数
    {
        _a = src._a;
        cout << "test(const test &src)" << endl;
    }
    void operator=(const Test &src)   //赋值运算符重载函数
    {
        _a = src._a;
        cout << "operator=(const test &src))" << endl;
    }
    int GetValue()
    {
        return _a;
    }
    ~Test()              //析构函数
    {
        cout << "~Test()" << endl;
    }
private:
    int _a;
};

Test GetObject(Test t)
{
    int value = t.GetValue();
    Test temp(value);
    return temp;
}

int main()
{
    Test t1(10);
    Test t2;
    t2 = GetObject(t1);
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
bool isNum(char c){
    return c >= '0' && c <= '9';
}

int string2int(string str)
{
    //空字符串
    if(str.size() == 0){
        return 0;
    }
    int head = 0;
    long result = 0;
    bool isNag = false;

    while(!isNum(str[head])){
        //排除空字符串
        if(str[head] != ' '){
            //如果不是空字符串的话就判一下正负号
            if(head+1 < str.size() && isNum(str[head+1])){
                if(str[head] == '-'){
                    isNag = true;
                }
                else if(str[head] != '+'){
                    return 0;
                }
            }else{
                return 0;
            }
        }

        head ++;
        if(head >= str.size()){
            return 0;
        }
    }

    while(isNum(str[head])){
        //先算出结果然后和Int进行比较
        result = result * 10;
        result += str[head] - '0';

        if(result > INT32_MAX && !isNag){
            return INT32_MAX;
        }else if(result * -1 < INT32_MIN && isNag){
            return INT32_MIN;
        }

        // cout << INT32_MAX << endl;
        // cout << result << endl;

        head ++;
        //如果结束就break
        if(head >= str.size()){
            break;
        }
    }

    if(isNag){
        result = -1 * result;
    }
    return result;

}
/******************************结束写代码******************************/


int main()
{
    int res;

    string _str;
    getline(cin, _str);

    res = string2int(_str);
    cout << res << endl;

    return 0;

}
#endif



//360的面试题，数组类型   彩球放在篮子里
#if 0
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>


using namespace std;

int Fun(vector<int>& vec,int n)
{
    vector<int> res(n, 0);
    int j=0;
    int k =0;
    int count = 0;
    for(int i=0;i<n;i++)
    {
        res[ vec[i] ]++;
    }
    sort(res.begin(),res.end(), greater<int>());
    auto it = res.cbegin();
    while(it != res.cend())
    {
        if(*it > 0)
        {
            count++;
        }
        it++;
    }
    vector<int> temp(count, 0);
    for(int i = 0; i < count; i++)
    {
        j = res[0] % res[i];

    }
    if(j != 0)
        return


//    auto
//    else if()//
//    {
//        return
//    }
//    else
//    {
//        return n/(res[0]);
//    }
return 0;
}

int main()
{
    int num;
    cin>>num;
    vector<int> vec1;
    int n;
    for(int i=0;i<num;i++)
    {
        cin>>n;
        vec1.push_back(n);
    }

    cout<<Fun(vec1,num)<<endl;

}
#endif