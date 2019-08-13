//
// Created by yanpan on 2019/6/23.
//


//西北工业大学助攻cpp的代码  找数组中出现频次多的数字，进行排序
#if 0

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector<int> b(int num, int* slalay) {
//    vector<int> res;
//    if(num <= 0 || slalay == NULL)
//    {
//        return res;
//    }
    int i, j, k;
    int temp_frequency;
    int temp_slalay;
    int frequency[num]; // 频次
    for (i = 0; i < num; i++) // 给频次赋初值
    {
        frequency[i] = 0;
    }

    for (i = 0; i < num; i++) // 对已排序的数据统计频次
    {
        for (j = 0; j < num; j++) {
            if (slalay[i] == slalay[j])
            {
                frequency[i]++;
            }
        }
    }

    for (i = 1; i < num; i++) // 对频次进行插入排序，同时根据频数交换的顺序排列原数据
    {
        temp_frequency = frequency[i];
        temp_slalay = slalay[i];
        j = i - 1;
        while (j >= 0 && temp_frequency > frequency[j]) //频次递减排序
        {
            frequency[j + 1] = frequency[j];
            slalay[j + 1] = slalay[j]; // 变换原数据
            j--;
        }
        frequency[j + 1] = temp_frequency;
        slalay[j + 1] = temp_slalay;
    }

    for (i = 1; i < num; i++) // 再进行一次插入排序
    {
        temp_slalay = slalay[i];
        j = i - 1;
        k = i - 1;
        while (k >= 0)
        {
            if (temp_slalay == slalay[k]) // 判断前半部分子序列是否存在当前当前数据
            {
                while (j >= 0 && temp_slalay != slalay[j]) // 插入到相同的数的后面
                {
                    slalay[j + 1] = slalay[j];
                    j--;
                }
                slalay[j + 1] = temp_slalay;
                break; // 退出循环判断下个数
            }
            k--;
        }

    }
    vector<int> vec(slalay, slalay+num);
    return vec;
}


int main()
{
    int num = 6;
    int slalay[19] = {1, 2, 4, 3, 4, 5};// 测试数据
    vector<int> slalayResult;
    slalayResult = b(num, slalay); // 保存结果
    int i;
    printf("输出结果为：");

    for (i = 0; i < num; i++)// 输出结果
    {
        cout<< slalayResult[i] <<" ";
    }
    cout << endl;
}

#endif


//牛课网合并区间的问题
#if 0
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main()
{
    vector<pair<int, int>> vec;
    int num1;
    int num2;
    char str;
    while(cin >> num1 >> str >> num2)
    {
        vec.push_back(make_pair(num1, num2));
    }
    sort(vec.begin(), vec.end());



    vector<pair<int, int>> vec1;
    vec1.push_back(vec[0]);
    auto len = vec.size();    //vec的长度
    auto i = 1;
    while(i < len)
    {
        if(vec1.back().second < vec[i].first)
        {
            vec1.push_back(vec[i]);
        }
        else
        {
            vec1.back().second = max(vec1.back().second, vec[i].second);
        }
        i++;
    }

    for(auto &i: vec1)
    {
        cout << i.first << "," << i.second << " ";
    }

    return 0;
//    int a, b;
//    while(cin >> a >> b)
//    {
//        cout << a << " " << b << endl;
//    }
//    cout << "hello" << endl;
}
#endif


//西北工业大学助攻cpp的代码
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 求排列组合算法: C(n, m): 从n个数中任选m个数组成一个新的数, 求有多少种组合, 分别是什么
// 从v[]里任选m个元素组成一个组合, 与顺序无关
template<class T>
vector<vector<T>> fun(vector<T> v, int m)
{
    if (v.size() < m)
        return{};               // 找不到这样的组合

    vector<vector<T>> ret;
    if (v.size() == m)          // v[]中任选m个数
    {
        ret.push_back(v);       // 唯一的一个组合

        return ret;
    }
    else if (m == 1)                // v[]中任选1个数
    {
        for (auto& it : v)
        {
            ret.push_back(vector<T> {it});
        }

        return ret;
    }

    while (v.size() >= m)
    {
        auto first = v.front();
        v.erase(v.begin());

        // 在剩下的v[1~]中任选m-1个数
        auto res = fun(v, m - 1);
        for (auto& it : res)
        {
            it.insert(it.begin(), first);
            ret.push_back(it);
        }
    }

    return ret;
}


int maxEnergyGenerate(int reactorCap, int numberOfRadLiquid, int criticalMass,
         int volumes[], int masses[],int energies[])
{
    int sum_energies = 0;

    std::vector<int> v = {};//每个瓶子编号
    for (int i = 0; i < numberOfRadLiquid; i++)
        v.push_back(i + 1);

    for (int i = numberOfRadLiquid; i >= 1; i--)
    {
        auto res = fun(v, i);
        int sum_energies_i = 0;
        int sum_masses = 0;
        int sum_volumes = 0;

        for (auto& it : res)
        {
            sum_volumes = 0;
            sum_masses = 0;
            sum_energies_i = 0;
            for (auto& it2 : it)
            {//printf("%d ", it2);
                sum_volumes = volumes[it2 - 1] + sum_volumes;
                sum_masses = masses[it2 - 1] + sum_masses;
                sum_energies_i = energies[it2 - 1] + sum_energies_i;
            }
            if (sum_volumes <= reactorCap && sum_masses <= criticalMass && sum_energies_i > sum_energies)
            {
                sum_energies = sum_energies_i;
            }
            //printf("\n");
        }

    }
    return sum_energies;
}




int main()
{
    int reactorCap = 100;//容量50
    int numberOfRadLiquid = 5;//个数
    int criticalMass = 15;//临界质量

    int volumes[5] = { 50, 40, 30, 20, 10 };//体积
    int masses[5] = { 1, 2, 3, 9, 5 };//质量
    int energies[5] = { 300, 480, 270, 200, 180 };//能量


    int sum_energies = find(reactorCap, numberOfRadLiquid, criticalMass,
                            volumes, masses, energies);

    cout << sum_energies << endl;
    return 0;
}
#endif