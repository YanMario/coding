//
// Created by yanpan on 2019/8/11.
//

#if 0
#include <iostream>
#include <vector>
using namespace std;

int FindNumSum(vector<int>& vec) {
    int len = vec.size();
    if (len <= 1)
        return 0;
    for (int i = 0; i < len; i++)
    {

    }
}


int main()
{


    return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int len;
    cin >> len;
    vector<float> vec;
    int num = 0;
    float val;
    for(int i = 0; i < len; i++)
    {
        cin >> val;
        vec.push_back(val);
    }
    int i = 0;
    while(i < len)
    {
        for(int j = i+1; j < len; j++)
        {
            if(vec[i] >= vec[j] && vec[i] * 0.9 <= vec[j])
                num++;
            else if(vec[i] <= vec[j] && vec[j] * 0.9 <= vec[i])
                num++;
        }
        i++;
    }
    cout << num << endl;
    return 0;
}
#endif


#if 0
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int len;
    cin >> len;
    vector<long long int> vec;
    for(int i = 0; i < len; ++i)
    {
        long long int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    vector<long long int> dp;
    for(int i = 1; i < len; ++i)
    {
        long long int val = abs(vec[i]- vec[i-1]);
        dp.push_back(val);
    }
    long long int min = dp[0];
    int pos = 0;
    int i = 1;
    for(i; i < dp.size(); ++i)
    {
        if(dp[i] < min)
        {
            min = dp[i];
            pos = i;
        }
    }
    cout << vec[pos] << " " << vec[pos + 1] << endl;
    return 0;
}
#endif





//
//class Solution {
//public:
//    int Length(vector<int>& nums)
//    {
//        int len = nums.size();
//        if(len <= 0)
//            return 0;
//        vector<int> dp(len);
//        dp[0] = 1;
//        int temp;
//        int res = 1;
//        for(int i = 1; i < len; ++i)
//        {
//            temp = 0;
//            for(int j = 0; j < i; j++)
//                if(nums[i] > nums[j])
//                {
//                    if(temp < dp[j])
//                        temp = dp[j];
//                }
//            dp[i] = temp + 1;
//            if(dp[i] > res)
//                res = dp[i];
//        }
//        return res;
//    }
//};
//
//int main()
//{
//    int n;
//    cin >> n;
//    int val;
//    vector<int> vec;
//    for(int i = 0; i < n; i++)
//    {
//        cin >> val;
//        vec.push_back(val);
//    }
//    Solution sing;
//
//    cout << sing.Length(vec) << endl;
//
//    return 0;
//}


#if 0
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int Length(vector<int>& res, int n)
    {
        vector<int> vec;
        for(int i = 0;i < n;++i)
        {
            int index = vec.size()-1;
            while(index >= 0 && vec[index]>=res[i])
                --index;
            if(index + 1 == vec.size())
            {
                vec.push_back(res[i]);
                continue;
            }
            vec[index + 1] = res[i];
        }
        return vec.size();
    }
};

int main() {
    int n;
    cin >> n;
    int val;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        cin >> val;
        res.push_back(val);
    }


    Solution sing;

    cout << sing.Length(res, n) << endl;

    return 0;

}
#endif


#if 0
#include <iostream>
#include <vector>
using namespace std;


int Fun(vector<int>& res, int len)
{
    int k=0;
    int j=len-1;
    int sum, temp1 = 0, temp2 = 0;
    while(k+1 < j)
    {
        temp1 = abs(res[k]-res[k+1]);
        temp2 = abs(res[j]-res[j-1]);
        sum += temp1;
        sum += temp2;
    }
    return sum;
}

int main()
{
    int len;
    cin>>len;
    vector<int> res;
    for(int i=0; i<len; i++)
    {
        int tmp;
        cin>>tmp;
        res.push_back(tmp);
    }
    cout<<Fun(res, len);
}
#endif