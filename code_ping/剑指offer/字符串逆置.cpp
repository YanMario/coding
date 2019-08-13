//
// Created by yanpan on 2019/7/16.
//

#if 0

#include<iostream>
#include <string.h>
using namespace std;


void reserver(char *str, int len)
{
    char* start;
    cout << "start:" << start << endl;
    cout << "str:" << str << endl;
    char* end = str + len - 1;
    char temp;
    while(start <= end)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    return;
}



int main()
{
    char str[] = "hello world";
    cout << "hello" <<endl;
    reserver(str, strlen(str));
//    cout << s << endl;
    cout << "hello" <<endl;
    printf("%s\n", str);
    return 0;
}

#endif

#if 0
#include <stdio.h>
#include <string.h>

void Reserver(char *start, char *end)
{
//    if(NULL == str)
//        return;
    while(start < end)
    {
        char tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
    return;
}

void Res(char *str, int len)
{
    //先反转整个句子
    char *start = str;
    char *end = str + len -1;
    Reserver(start, end);
    //在反转句子中的单词    怎么找到句子中的单词呢
    end = start;
    while(*str != '\0')
    {
        if(*end == '\0' || *end == ' ')
        {
            Reserver(start, end-1);
            if(*end == '\0')
                break;
            end++;
            start = end;
        }
        else
            end++;
    }







//    end = start;
//    while(*str != '\0')
//    {
//        if(*end == ' ' || *end == '\0')
//        {
//            Reserver(start, end-1);
//            if(*end == '\0')
//            {
//                break;
//            }
//            end++;
//            start = end;
//        }
//        else
//            end++;
//    }
}

int main()
{
    char str[] = "hello wooo jjjd v  j";
    int len = strlen(str);
    Res(str, len);
    printf("%s\n", str);
    return 0;
}

#endif

//0 1 背包
#if 0
#include <iostream>
#include <vector>
using namespace std;


void Find(vector<vector<int>>vec, int len, int v)
{
    vector<vector<int>> dp(len, vector<int>(v+1));

    for(int i = 1; i <= v; i++)
    {
        if(i < vec[0][1])
            dp[0][i] = 0;
        else
            dp[0][i] = vec[0][0];
    }
    for(int i = 1; i < len; i++)
    {
        for(int j = 1; j <= v; j++)
        {
            if(j < vec[i][1])
            {
                dp[i][j] = dp[i-1][j];
            }
            else
                dp[i][j] = max(dp[i - 1][j - vec[i][1]] + vec[i][0], dp[i][j] = dp[i - 1][j]);
        }
    }

    cout << dp[len - 1][v] << endl;

    return;


}

int main()
{
    vector<vector<int>> vec;
    int n,v;
    cin >> n;
    cin >> v;
    vector<int> temp;
    int val, wei;
    for(int i = 0; i < n; i++)
    {
        cin >> val >> wei;
        temp.push_back(val);
        temp.push_back(wei);
        vec.push_back(temp);
        temp.clear();
    }
    Find(vec, n, v);


    return 0;
}
#endif



#if 0
#include <iostream>
#include <vector>
using namespace std;


void Find(vector<int>vec, vector<int>res, int len, int v)
{
    vector<vector<int>> dp(len, vector<int>(v+1, 0));

//    dp[0][0] = 0;
    for(int i = 1; i <= v; i++)
    {
        if(res[0] <= i)
            dp[0][i] = vec[0];
        else
            dp[0][i] = 0;
    }

    for(int i = 1; i < len; i++)
    {
        for(int j = 1; j <= v; j++)
        {
            if(j < res[i])
            {
                dp[i][j] = dp[i-1][j];
            }
            else
                dp[i][j] = max(dp[i - 1][j - res[i]] + vec[i], dp[i - 1][j]);
        }
    }

    cout << dp[len - 1][v] << endl;

    return;


}

int main()
{
    vector<int> vec;
    vector<int> res;
    int n,v;
    cin >> n;
    cin >> v;
    vector<int> temp;
    int val;
    for(int i = 0; i < n; i++)
    {
        cin >> val;
        vec.push_back(val);
    }
    for(int i = 0; i < n; i++)
    {
        cin >> val;
        res.push_back(val);
    }

    Find(vec, res, n, v);


    return 0;
}
#endif



#if 0
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;



class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        int len = candidates.size();
        combinationSumCore(res, candidates, target, tmp, 0, 0);
        return res;
    }

    void combinationSumCore(vector<vector<int>> &res, vector<int>& candidates, int target, vector<int>& tmp, int sum, int begin){
        if(sum == target){
            res.push_back(tmp);
        }
        else
        {
            for(int i=begin; i<candidates.size(); ++i)
            {
                if(sum+candidates[i]<=target)
                {
                    if(i != begin && candidates[i] == candidates[i-1])  //去重复
                        continue;
                    tmp.push_back(candidates[i]);
                    combinationSumCore(res, candidates, target, tmp, sum+candidates[i], i + 1);
                    tmp.pop_back();     //一层一层返回，一直到第一层 i = begin + 1;
                }
                else
                    break;
            }
        }
    }
};

int Find(vector<int>& vec, int sum)
{
//    vector<vector<int>> dp(7, vector<int>(sum));

    vector<int> dp(sum+1);
    int money[] = {1,5,10,20,50,100};
    dp[0] = 1;
    for(int i = 0; i < 6; i++)
    {
        for(int j = money[i]; j <= sum; j++)
        {
            dp[j] = dp[j] + dp[j - money[i]];
        }
    }
    cout << dp[sum] << endl;
    return 0;
}
int main()
{
    int arr[] = {10,1,2,7,6,1,5};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    Solution A;
    A.combinationSum2(vec, 8);
//    int val;
//    for(int i = 0; i < 6; i++)
//    {
//        cin >> val;
//        vec.push_back(val);
//    }
//    int sum;
//    cin >> sum;
//    Find(vec, sum);
    return 0;
}


#endif


#if 0
#include <iostream>
#include <vector>
using namespace std;


void Found(vector<int> vec)
{
    if(vec[0] == 0 || vec[1] == 0 || vec[0] % 10 == 4 || vec[1] % 10 == 4 || vec[0] % 10 == -4 || vec[1] % 10 == -4)
    {
        cout << "illegal input" << endl;
        return;
    }
    int sum = 0;

    if(vec[0] == vec[1])
    {
        cout << 0 << endl;
        return;
    }

    if(vec[0] > vec[1])
    {
        for(int i = vec[0]; i > vec[1]; i--)
        {
            if(i == 0 || i % 10 == 4 || i % 10 == -4)
                continue;
            sum++;
        }
    }
    if(vec[0] < vec[1])
    {
        for(int i = vec[0]; i < vec[1]; i++)
        {
            if(i == 0 || i % 10 == 4 || i % 10 == -4)
                continue;
            sum++;
        }

    }
    cout << sum << endl;
    return;
}

int main()
{
    vector<int> res(2);
    int temp1;
    for(int i= 0; i < 2; i++)
    {
        cin >> temp1;
        res[i] = temp1;
    }

    Found(res);
    return 0;
}
#endif


#if 0

#include <iostream>
#include <string>
using namespace std;

int longestSeq(string& seq, int longest)
{
    int count_0 = 0,count_1 = 0;
    int max_0 = 0, max_1 = 0;

    int n = seq.size();
    for(int i = 0; i < n; ++i)
    {
        if(seq[i] == 'Y')
        {
            count_0++;
            count_1 = 0;
        }
        else if(seq[i] == 'T')
        {
            count_1++;
            count_0 = 0;
        }
        if(count_0 >= max_0)
            max_0 = count_0;
        if(count_1 >= max_1)
            max_1 = count_1;
    }
    //the continue occurs longest seq is '1'
    if(max_1 > max_0)
    {
        longest = max_1;
        return 1;
    }
        //the continue occurs longest seq is '0'
    else if(max_1 < max_0)
    {
        longest = max_0;
        return -1;
    }
        // both '0' and '1' have the longest continue occur times
    else
    {
        longest = max_0;
        return 0;
    }

}

int main()
{
    string str;
    cin >> str;
    int longestSequence = 0;
    int bin = longestSeq(str, longestSequence);
    if(bin == 1)
    {
        for(int i = 0; i < longestSequence; ++i)
            cout << 1;
    }
    else if(bin == -1)
    {
        for(int i = 0; i < longestSequence; ++i)
            cout << 0;
    }
    else
    {
        for(int i = 0; i < longestSequence; ++i)
            cout << 1;
        cout << " ";
        for(int i = 0; i < longestSequence; ++i)
            cout << 0;
    }

    return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
#endif

#if 0
int findMaxLength(vector<int>& nums) {
    int n = nums.size(),ans=0;

    unordered_map<int,int>hash;
    hash[0]=0;
    int x=0;//子数组的和
    for(int i=0;i<n;i++)
    {
        if(!nums[i])
            x--;
        else
            x++;
        if(hash.find(x)!=hash.end())
            ans=max(ans,i-hash[x] + 1);
        else
            hash[x]=i + 1;
    }
    return ans;
}
#endif

#if 0
int findMaxLength(vector<int>& nums)
{
    int len = nums.size(),ans=0;

    unordered_map<int,int>hash;
    vector<int> vec(len + 1);
    vec[0] = 0;

    for(int i = 0; i < len; i++)
        vec[i+1] = vec[i] + nums[i];

    for(int i = 1; i < vec.size(); i++)
    {
        vec[i] = 2*vec[i] - i;

    }

    for(int i = 1; i < vec.size(); i++)
    {
        if(hash.find(vec[i]) != hash.end())
        {
            ans = max(ans, i - hash[vec[i]] + 1);
        }
        else
        {
            hash[vec[i]] = i;
        }
    }

    return ans;
}
#endif


#if 0
int findMaxLength(vector<int>& nums)
{
    int len = nums.size(),ans=0;

    unordered_map<int,int>hash;
    vector<int> vec(len + 1);
    vec[0] = 0;

    for(int i = 0; i < len; i++)
        vec[i+1] = vec[i] + nums[i];

    for(int i = 0; i < vec.size(); i++)
    {
        vec[i] = 2*vec[i] - i;

    }

    for(int i = 0; i < vec.size(); i++)
    {
        if(hash.find(vec[i]) != hash.end())
        {
            ans = max(ans, i - hash[vec[i]]);
        }
        else
        {
            hash[vec[i]] = i;
        }
    }

    return ans;
}
#endif

#if 0
#include <map>
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)nums[i] = -1;
        }
        map<int, int>hash;//用来保存不为0时的长度
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == 0)
                res = i + 1;
            else
                {
                if (hash.find(sum) == hash.end())
                    hash[sum] = i;
                else
                    {
                    res = max(res, i - hash[sum]);
                }
            }
        }
        return res;
    }
};
//YTYTYTYTYTTTYY
int main()
{
    string str;
    cin >> str;
//    int val;
    vector<int> vec;
//    while(cin >> val)
//    {
//        vec.push_back(val);
//        char c = getchar();   //cin.get();
//        if(c == '\n')
//        {
//            cout << "hello" << endl;
//            break;
//        }
//
//
//    }

//    findMaxLength(vec);
    for(int i =0; i < str.size(); i++)
    {
        if(str[i] == 'Y')
            vec.push_back(0);
        else
            vec.push_back(1);
    }
    Solution A;
    cout << A.findMaxLength(vec) << endl;
    return 0;
}
#endif








