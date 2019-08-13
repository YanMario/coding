//
// Created by yanpan on 2018/9/8.
//

#if 0

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    vector<int> vector1;
//    vector1.reserve(100);
//    vector1.resize(100);
    cout<<"vector1 beagin size: "<<vector1.size()<<endl;

    for(int i = 0; i < 10; ++i)
    {
        vector1.push_back(i);
    }
    cout<<"vector1 end size: "<<vector1.size()<<endl;

    vector<int>::iterator v = vector1.begin();
    while(v != vector1.end())
    {
        cout<<"vector1 of v: "<< *v <<endl;
        v++;
    }

    auto it = find_if(vector1.begin(), vector1.end(), bind2nd(greater_equal<int>(), 5));
    cout << *it << endl;
    return 0;
}
#endif

//???offer
#if 0

#include <iostream>
#include <stack>
using namespace std;

int MoreThanHalfNum(int *nums, int len)
{
    stack<int> st;
    if(NULL == nums || len <= 0)
        return -1;
    int rest = nums[0];
    int count = 1;

    for(int i = 1; i < len; i++)
    {
        if(nums[i] == rest)
            count++;
        else {
            count--;
            if (count == 0) {
                rest = nums[i];
                count = 1;
            }
        }
    }

    count = 0;
    for(int i = 0; i < len; ++i)
        if(nums[i] == rest)
            count++;
    if(count * 2 <= len)
        rest = -1;
    cout << rest << endl;
    return rest;
}

int main()
{
    int arr[] = {1};
    MoreThanHalfNum(arr, sizeof(arr) / sizeof(arr[0]));
}

#endif


//dp
#if 0
#include <iostream>
#include <vector>
using namespace std;


int Dp(int *arr, int len)
{
    if(!arr || len <= 0)
        return -1;
    vector<int> dp(1);

    dp[0] = 0;
    dp[1] = arr[0];
    for(int i = 1; i < len; ++i)
    {
        if(arr[i] + dp[i-1] > dp[i])
            dp[i+1] = arr[i] + dp[i-1];
        else
            dp[i+1] = dp[i];
    }
    cout << dp[len] << endl;
    return dp[len];
}

int main()
{
    int arr[] = {2, 1, 3, 5, 6, 7, 15};
    int res = Dp(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}
#endif



//???  vector
#if 0
#include <iostream>
#include <vector>
using namespace std;

int main()
{
//    vector<vector<int>> vec(2, vector<int>(2));
//    vec[0][0] = 1;
//    vec[0][1] = 2;
//    vec[1][0] = 3;
//    vec[1][1] = 4;
//
//    cout << vec[1][1] << endl;
//    auto it = vec.begin();
//    while(it != vec.end())
//    {
//        cout << (*it) << endl;
//        it++;
//    }



    vector<vector<vector<int>>> vec(2, vector<vector<int>>(2, vector<int>(2)));
//    vector<vector<vector<int>>> vec(len + 1, vector<vector<int>>(2, vector<int>(2)));
    vec[0][0][0] = 1;
    vec[0][1][1] = 2;
    vec[1][0][2] = 3;
    vec[1][1][2] = 4;
//    vec[-1][1][2] = 0;

    cout << vec[0][1][1] << endl;
    return 0;
}
#endif


//??? III
#if 0
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
//    Solution(int a){};
    int maxProfit(vector<int>& prices)
    {
        int k;
        int len = prices.size();
        if(len <= 1)
            return 0;
        vector<vector<vector<int>>> vec(len+1, vector<vector<int>>(3, vector<int>(2)));

        vec[0][0][0] = 0;
        vec[0][0][1] = -prices[0];
        vec[0][1][0] = INT_MIN + prices[0];
        vec[0][1][1] = INT_MIN + prices[0];
        // if(len == 2)
        //     k = 1;
        // else
        //     k = 2;
        // cout << k << endl;
        for(int i = 1; i < len; ++i)
        {
            for(int j = 1; j <= 2; ++j)  //????????
            {
                vec[i][j][0] = max(vec[i-1][j-1][1] + prices[i], vec[i-1][j][0]);
                vec[i][j][1] = max(vec[i-1][j-1][0] - prices[i], vec[i-1][j][1]);
            }
        }
        cout << vec[len-1][1][0] << endl;
        return max(vec[len-1][1][0], vec[len-1][2][0]);
    }
};


int main()
{
    Solution A;
    int arr[] = {3,3,5,0,4};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    A.maxProfit(vec);
    return 0;
}
#endif

//??????·??
#if 0
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int len = triangle.size();
        if(len <= 0)
            return 0;
        vector<vector<int>> dp(len);

        dp[len-1] = triangle[len-1];
        for(int i = triangle.size() - 2; i >= 0; i++)
        {
            for(int j = 0; j < triangle[i].size(); ++j)
            {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};


int main()
{
    Solution A;

}

#endif


//????????????

#if 0
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int len = nums.size();
        if(len <= 0)
            return 0;
        vector<int> dp(len);
        dp[0] = 1;
        int temp;
        for(int i = 0; i < len; ++i)
        {
            temp = 0;
            for(int j = 0; j < i; j++)
                if(nums[i] > nums[j])
                {
                    if(temp < dp[j])
                        temp = dp[j];
                }
            dp[i] = temp + 1;
        }


        return dp[len-1];
    }
};

int main()
{
    Solution A;
    int arr[] = {1,3,6,7,9,4,10,5,6};
    vector<int> vec(arr, arr +sizeof(arr)/sizeof(arr[0]));
    cout << A.lengthOfLIS(vec) << endl;
}

#endif




//????滮  //?????????????
#if 0
class Solution {
public:
    int climbStairs(int n)
    {
        if(n <= 1)
            return n;

        vector<int> dp(n);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i < n; ++i)
        {
            dp[i] = min(dp[i-2], dp[i-1]) + 1;
        }
        return dp[n-1];
    }
};
#endif




/*class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> vec1;
        for(int i=0;i<nums.size()-1;++i)
        {
            for(int j=i+1;j<nums.size();++j)
            {
                if(nums[i]+nums[j] == target)
                {
                    vec1.push_back(i);
                    vec1.push_back(j);
                    return vec1;
                }
            }
        }
        return vec1;
    }
};*/

#if 0

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> hash;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int numberToFind = target - nums[i];

            //if numberToFind is found in map, return them
            if (hash.find(numberToFind) != hash.end()) {
                result.push_back(hash[numberToFind]);
                result.push_back(i);
                return result;
            }

            //number was not found. Put it in the map.
            hash[nums[i]] = i;
        }
        return result;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input)
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        vector<int> ret = Solution().twoSum(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
#endif


#if 0
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <queue>
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//???????????
class Solution {
public:
    void help(TreeNode* root, vector<int>& res)
    {
        if(root)
        {
            if(root -> left)
                help(root -> left, res);
            res.push_back(root -> val);
            if(root -> right)
                help(root -> right, res);
        }
    }

    vector<int> inorderTraversal(TreeNode* root)
    {
        if(root == NULL)
            return {};
        vector<int> res;
        help(root, res);
        return res;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main()
{
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);

        vector<int> ret = Solution().inorderTraversal(root);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
#endif








#if 0
#include <iostream>
#include <vector>
using namespace std;

int getsumnum(vector<int>& vec,int num, int index, int sum)
{
    int count = 0;
    if(num == 0)
    {
        return sum==0?1:0;
    }
    for(int i = index; i <= vec.size() - num; i++)
    {
        if(vec[i] <= sum)
            count += getsumnum(vec, num-1, i+1, sum-vec[i]);
    }

    return count;
}

int FindSum(vector<int>& vec, int sum)
{
    int len = vec.size();
    if(len <= 0) return 0;
    int count = 0;
    for(int num = 1; num < len; num++)
    {
        count += getsumnum(vec, num, 0, sum);
    }

    return count;

}


int main()
{
    int n = 0;
    int sum = 0;
    cin >> n;
    cin >> sum;
    vector<int> vec;
    int temp = 0;
    for(auto i = 0; i < n; ++i)
    {
        cin >> temp;
        vec.push_back(temp);
    }

    cout << FindSum(vec, sum) << endl;

    return 0;
}


#endif



//AC       shuzu?????
#if 0
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, sum;
    cin >> n >> sum;
    vector<int> vec(sum+1);
    vector<int> res(n);

    for(int i = 0; i < n; i++)
        cin>>res[i];

    vec[0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = sum; j >= res[i]; j--)
            vec[j] += vec[j - res[i]];
    }

    cout << vec[sum] << endl;
    return 0;
}



#endif



#if 0
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution
{
public:
    string gcdString(string str1, string str2)
    {
        int len1 = str1.size();
        int len2 = str2.size();

        if(len1 == len2)
            if (str1 == str2)
                return str1;
            else
                return "";
        else if(len1 > len2)
        {
            string substr = str1.substr(len2);
//            cout << substr << endl;
            return gcdString(substr, str2);
        }
        else
        {
            string substr = str2.substr(len1);
//            cout << substr << endl;
            return gcdString(substr, str1);
        }
    }
};

int main()
{
    string str1;
    string str2;
    cin >> str1;
    cout << str1.substr(3) << endl;
//    while(cin >> str1 >> str2)
//    {
//        cout << Solution().gcdString(str1, str2) << endl;
//    }
    return 0;
}

#endif

#if 0
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class solution
{
public:
    ListNode *Delete(ListNode* head)
    {

        unordered_map<int, int> hash;
        ListNode* pnode = head;
        hash[head -> val]++;
        for(; pnode-> next != NULL;)
        {
            if(hash.find(pnode -> next -> val) != hash.end())
            {
                pnode->next = pnode->next->next;
            }
            else {

                hash[pnode -> next -> val]++;
                pnode->next = pnode->next->next;
            }

        }
//        cout << head -> val << endl;
        return head;
    }

};


int main()
{
    ListNode* head = new ListNode(-1);
    ListNode* Node = head;
    int val;
    while(cin >> val)
    {

        ListNode* temp = new ListNode(val);
        head -> next = temp;
        temp -> next = NULL;
        head = head -> next;
        char c = cin.get();
        if(c == '\n')     //??????????
            break;
    }
    Node = Node -> next;
    ListNode* pnode = solution().Delete(Node);

    for(; pnode != NULL; pnode = pnode -> next)
    {
        cout << pnode -> val << " ";
    }
    cout << endl;
    return 0;
}
#endif





#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;


vector<int> FindNum(vector<int>& vec, vector<int>& res)
{
    int len1 = vec.size();
    int len2 = res.size();
    if(len1 <= 0 || len2 <= 0)
        return {};

    sort(res.begin(), res.end());
    int val = 0;
    int temp = 0;
    int i = 0;
    for(; i < len1 - 1; i++)
    {
        if(vec[i] >= vec[i+1])
        {
            if(i == 0)
            {
                val = vec[i+1];
                temp = INT_MIN;
            }

            else if(i <= len1 - 2)
                val = vec[i+2];
            else
                val = INT_MIN;

            break;
        }
    }

    bool flag = false;
    int j = len2 - 1;
    for(; j >= 0; j--)
    {
        if(val != INT_MIN && temp != INT_MIN)
        {
            if(res[j] > vec[i] && res[j] < vec[i + 2]) {
                flag = true;
                break;
            }
        }
        else if(val == INT_MIN)
        {
            if(res[j] > vec[i]) {
                flag = true;
                break;
            }
        }
        else if(temp == INT_MIN)
        {
            if(res[j] < vec[i + 1]) {
                flag = true;
                break;
            }
        }
    }
    if(flag == true)
    {
        vec[i+1] = res[j];
        return vec;
    }

    return {};

}

int main()
{
    vector<int> vec1;
    vector<int> vec2;
    int val;
    while(cin >> val)
    {
        vec1.push_back(val);
        char c = cin.get();
        if(c == '\n')
            break;
    }
    while(cin >> val)
    {
        vec2.push_back(val);
        char c = cin.get();
        if(c == '\n')
            break;
    }

    vector<int> res = FindNum(vec1, vec2);
    int len = res.size();

    if(len <= 0)
        cout<< "NO";
    else
        for(int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
    cout << endl;

    return 0;
}
#endif
























