//
// Created by yanpan on 2019/5/6.
//

//leetcode---41
#if 0

#include <iostream>
#include <vector>
using namespace std;

/*
class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        if(nums.size() <= 0)
        {
            return 1;
        }
        //sort(nums.begin(), nums.end());
        auto it = nums.begin();
        int num = nums.size();
        vector<int> vec(num, 0);
        while(it != nums.end())
        {
            if(*it >= 1 && *it <= num)
                vec[*it-1] = *it;
            it++;

        }
        for(int i = 0; i < num; i++)
        {
            if(vec[i] != i+1)
                return i+1;
        }
        return num+1;
    }
};
*/

class Solution {
public:
    void swap(int &num1, int &num2)
    {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    int firstMissingPositive(vector<int>& nums)
    {
        int num = nums.size();
        if(num <= 0)
            return 1;

        for(int i = 0; i < num; i++)
        {
            while(nums[i] >= 1 && nums[i] < num && nums[i] != nums[nums[i]] && nums[i] != i)
                swap(nums[i], nums[nums[i]]);
        }
        for(int i = 1; i < num; i++)
        {
            if(nums[i] != i)
                return i;
        }
        return num;
    }
};

int main()
{
    Solution te;
    vector<int> vec;
    /*vec.push_back(3);
    vec.push_back(4);
    vec.push_back(-1);
    vec.push_back(1);*/

    vec.push_back(2);
    vec.push_back(1);

    cout<< te.firstMissingPositive(vec) <<endl;
}
#endif