//
// Created by yanpan on 2018/10/11.
//


//unordered_map的用法
#if 0
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
//using namespace std;


typedef std::unordered_map<std::string, std::string> stringmap;

stringmap Merge(stringmap a, stringmap b)
{
    //unordered_map 拷贝构造函数
    stringmap temp(a);
    //进行范围插入，将b 全部插入到 a中
    temp.insert(b.cbegin(), b.cend());
    return temp;
}

//class Solution {
//public:
//    vector<vector<string>> groupAnagrams(vector<string>& strs)
//    {
//        vector< vector<string> > res;
//        unordered_map< string, vector<string> > map1;
//        for(auto str :strs)
//        {
//            string t = str;
//            sort(t.begin(), t.end());
//            map1[t].push_back(str);
//        }
//        for(auto &pair :map1)
//        {
//            res.push_back(move(pair.second));
//        }
//        return res;
//    }
//};

//unorder_map中能不能对同一个健不同值作为存储

int main()
{
    //unorder_map 元素计算与基础遍历， 定义一个unordered_map
    std::unordered_map<std::string, int> my_unordered_map = {{"yang", 330}, {"yan", 460}, {"jia", 550}};
    //对元素进行计算   for循环auto遍历
    std::cout<< my_unordered_map.at("yan") <<std::endl;
//    my_unordered_map.at("yang") += 60;
    my_unordered_map.at("jia") = my_unordered_map.at("yan") + 30;
    for(auto& x : my_unordered_map)
    {
        std::cout<< x.first << ": " << x.second <<std::endl;
    }

    std::cout << "my_unordered_map.size is" << ": "<< my_unordered_map.size() << std::endl;


//    iterator 迭代器遍历
//    std::unordered_map<std::string, int>::iterator it = my_unordered_map.begin();
    for(auto it = my_unordered_map.begin(); it != my_unordered_map.end(); it++)
    {
        std::cout << it -> first << ": " << it -> second << std::endl;
    }

    //将vector放入到unordered_map 的value中    leetcode49
    /*std::unordered_map<std::string, std::vector<std::string>> my_unordered_map1;
    std::string t = "yan";
    std::string value = "hello";
    my_unordered_map1[t].push_back(value);
    value = "world";
    my_unordered_map1[t].push_back(value);
    for(auto it = my_unordered_map1.begin(); it != my_unordered_map1.end(); it++)
    {
        std::cout << it -> first << ": " << it -> second[0] << std::endl;
    }*/

    std::pair<std::string, int> pair1("yan", 500);
    my_unordered_map.insert(pair1);

    //分配的各桶中的元素
    std::cout << "my_unordered_map's buckets contain:\n" << my_unordered_map.bucket_count() << std::endl;
    for(unsigned i = 0; i < my_unordered_map.bucket_count(); ++i)
    {
        std::cout << "bucket #" << i << "coutains" << std::endl;
        for(auto local_it = my_unordered_map.begin(i); local_it != my_unordered_map.end(i); ++local_it)
            std::cout << " " << local_it -> first << ": " << local_it -> second;
        std::cout<< std::endl;
    }


    //bucker, 桶操作
    std::unordered_map<std::string, std::string> mymap3 = {{ "us", "United States" },
                                                           { "uk", "United Kingdom" },
                                                           { "fr", "France" },
                                                           { "de", "Germany" }};
    //遍历mymap3
   /* for(auto &x : mymap3)
    {
        std::cout << "Element[" << x.first << ": " << x.second << "]";
        //返回元素所在的桶号
        std::cout << "is in bucket #" << mymap3.bucket(x.first) << std::endl;
    }*/

    for(unsigned i = 0; i < mymap3.bucket_count(); ++i) {
        std::cout << "bucket #" << i << "coutains" << std::endl;
        for (auto local_it = mymap3.begin(i); local_it != mymap3.end(i); ++local_it)
            std::cout << " " << local_it->first << ": " << local_it->second;
        std::cout << std::endl;
    }


    //============================
    //   4. count ，判断元素是否在容器中
    //============================
    // 定义第四个 unordered_map
    std::unordered_map<std::string, double> mymap4 = {
            { "Burger", 2.99 },
            { "Fries", 1.99 },
            { "Soda", 1.50 } };

    // 遍历 mymap4
    for (auto& x : { "Burger", "Pizza", "Salad", "Soda" })
    {
        // 判断 x 是否在容器中
        if (mymap4.count(x)>0)
            std::cout << "mymap4 has " << x << std::endl;
        else
            std::cout << "mymap4 has no " << x << std::endl;
    }
    std::cout << "mymap4.buck_count(): " << mymap4.bucket_count() << std::endl;

    /*============================
    5. erase ，删除操作
    ============================*/
    std::unordered_map<std::string, std::string> mymap5;
    mymap5["U.S."] = "1";
    mymap5["U.K."] = "2";
    mymap5["France"] = "3";
    mymap5["Russia"] = "4";
    mymap5["China"] = "5";
    mymap5["Germany"] = "6";
    mymap5["Japan"] = "7";

    mymap5.erase(mymap5.begin());
    mymap5.erase("France");
    mymap5.erase(mymap5.find("U.S."), mymap5.end());

    for(auto &x : mymap5)
    {
        std::cout << x.first << ": " << x.second << std::endl;
    }

    /*============================
    6. find ，搜索操作
    ============================
    定义第六个 unordered_map*/

    std::unordered_map<std::string, double> mymap6 = {
            { "mom", 5.4 },
            { "dad", 6.1 },
            { "bro", 5.9 } };

    std::string input;
    std::cout << "who? ";
    // 输入 mom, dad, bro 中的一个，否则搜索失败返回 Not Found
    getline(std::cin, input);

    // 根据输入参数 Key 值进行搜索，返回一个迭代器
    std::unordered_map<std::string, double>::const_iterator got = mymap6.find(input);

    // find 返回值若为 unordered_map 的尾部，则没有在容器中找到
    if (got == mymap6.end())
        std::cout << "not found";
    else
        std::cout << got->first << " is " << got->second;
    std::cout << std::endl;


    /*============================
    7. insert ，插入操作
    ============================
    定义第七、八个 unordered_map*/

    std::unordered_map<std::string, double>
            myrecipe,
            mypantry = { { "milk", 2.0 }, { "flour", 1.5 } };

    // 定义插入元素，类型为 pair 的对象
    std::pair<std::string, double> myshopping("baking powder", 0.3);

    // 复制插入
    myrecipe.insert(myshopping);
    // 移动插入
    myrecipe.insert(std::make_pair<std::string, double>("eggs", 6.0));
    // 范围插入
    myrecipe.insert(mypantry.begin(), mypantry.end());  // range insertion
    // 初始化列表插入
    myrecipe.insert({ { "sugar", 0.8 }, { "salt", 0.1 } });    // initializer list insertion

    std::cout << "myrecipe contains:" << std::endl;
    for (auto& x : myrecipe)
        std::cout << x.first << ": " << x.second << std::endl;

    std::cout << std::endl;


    /*============================
    7. 等于运算符 = 操作
    ============================*/
    // 初始化列表
    stringmap first = { { "AAPL", "Apple" }, { "MSFT", "Microsoft" } };
    stringmap second = { { "GOOG", "Google" }, { "ORCL", "Oracle" } };
    // 移动
    stringmap third = Merge(first, second);
    // 复制
    first = third;

    std::cout << "first contains:";
    for (auto& elem : first) std::cout << " " << elem.first << ":" << elem.second;
    std::cout << std::endl;

    /*unordered_map<string,int> mymap = { { "Mars", 3000}, { "Saturn", 60000 }, { "Jupiter", 70000 } };
    cout<<mymap.at("Mars")<<endl;
    cout<<mymap.count("Mars")<<endl;
    unordered_map<string,int>::iterator got = mymap.find("Mars");
    cout<<got->second<<endl;
    cout<<"success"<<endl;*/

    return 0;
}

#endif





//move方法
#if 0
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> vec1;
    vector<string> vec = {"hello", "world", "yanyan"};
    for(auto it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it <<endl;
    }
    cout << "==========" <<endl;
    vec1.push_back(move(*(vec.begin())));

    for(auto it = vec1.begin(); it != vec1.end(); it++)
    {
        cout << *it <<endl;
    }
    return 0;
}

#endif