//
// Created by yanpan on 2019/8/11.
//



#if 0
#include <iostream>
using namespace std;
char *g_bitmap = NULL;
int g_size = 0;
int g_base = 0;
//功能：初始化bitmap
//参数： size：bitmap的大小，即bit位的个数
//      start：起始值
//返回值：0表示失败，1表示成功
int bitmap_init(int size, int start)
{
    g_size = size/8+1;    //100个位／8  就是 100/8 + 1 个字节
    g_base = start;
    g_bitmap = new char[g_size];
    if(g_bitmap == NULL)
    {
        return 0;
    }
    memset(g_bitmap, 0x0, g_size);    //每个位都是0
    return 1;
}
//功能：将值index的对应位设为1
//index:要设的值
//返回值：0表示失败，1表示成功
int bitmap_set(int index)
{
    int quo = (index-g_base)/8 ;  //确定所在的字节  a[i] - 0 / 8   看看在哪个字节 值 <= 7 在第一字节
    cout << "quo: " << quo << endl;
    int remainder = (index-g_base)%8;  //字节内的偏移   //%8  看看在第一个字节的哪一个位
    unsigned char x = (0x1<<remainder);       //将这个字节的位置为1
    if( quo > g_size)                         //如果字节大于申请的字节 则直接返回0  fail
        return 0;
    g_bitmap[quo] |= x;   //所在字节内的特定位置为1   //将该字节直接或等1   0|0=0 0|1=1 1|0=1 1|1=1
    return 1;
}

//功能：取bitmap第i位的值
//i：待取位
//返回值：-1表示失败，否则返回对应位的值
int bitmap_get(int i)
{
    int quo = (i)/8 ;
    int remainder = (i)%8;
    unsigned char x = (0x1<<remainder);   //将0x1 在二进制中左移 i%8 位
    unsigned char res;
    if( quo > g_size)
        return -1;
    res = g_bitmap[quo] & x;       //
    return res > 0 ? 1 : 0;
}

//功能：返回index位对应的值
int bitmap_data(int index)
{
    return (index + g_base);
}
//释放内存
int bitmap_free()
{
    delete [] g_bitmap;
    return 0;
}



int main(int argc, char* argv[])
{
    int a[] = {5,8,7,6,3,1,10,78,56,34,23,12,43,54,65,76,87,98,89,100};
    int i;
    bitmap_init(100, 0);
    for(i=0; i<20; i++)
    {
        bitmap_set(a[i]);
    }
    for(i=0; i<=100; i++)
    {
        if(bitmap_get(i) > 0 )
            cout << bitmap_data(i)<< " ";
    }
    cout << endl;
    bitmap_free();
    return 0;
}

#endif
#if 0
#include<iostream>
#include<vector>
using namespace std;

class BitMap {
public:
    BitMap(int num):n(num), mask(0x1F), shift(5),pos(1<<mask),a(1+n/32,0){}
    void set(int i) {
        a[i>>shift] |= (pos>>(i & mask));
    }
    int get(int i) {
        return a[i>>shift] & (pos>>(i & mask));
    }
    void clr(int i) {
        a[i>>shift] &= ~(pos>>(i & mask));
    }
private:
    int n;
    const int mask;
    const int shift;
    const unsigned int pos;
    vector<unsigned int> a;
};

int main() {
    BitMap bitmap(100);
    bitmap.set(27);
    bitmap.set(29);
    bitmap.set(131);
    int res = bitmap.get(27);
    cout<<res<<endl;
    return 0;
}
#endif















#if 0
#include <iostream>
#include <vector>
using namespace std;


int MinCoin(vector<int>& vec)
{
    int len = vec.size();
    if(len <= 0)
        return 0;
    vector<int> res(len, 100);
    for(int i = 1; i < len; i++)
    {
        if(vec[i] > vec[i-1])
            res[i] = res[i-1]+100;
    }
    for(int i = len-2; i >= 0; i--)
    {
        if(vec[i] > vec[i+1] && res[i] < res[i+1] + 100)
            res[i] = res[i+1] + 100;
    }
    int sum = 0, i = 0;
    while(i < len)
    {
        sum += res[i];
        i++;
    }

    return sum;
}


int main()
{
    int n;
    cin >> n;
    vector<int> vec;
    int val;
    for(int i = 0; i < n; i++)
    {
        cin >> val;
        vec.push_back(val);
    }
    cout << MinCoin(vec) << endl;
    return 0;
}



#endif

#if 0
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int len, x, y, j, k, ans;
    int vec[256];
    cin >> len;
    for(int i = 0; i < len; i++)
    {
        cin >> x >> y;
//        vec.push_back(x*60+y);
        vec[i] = x*60 + y;
    }
    cin >> j >> x >> y;
    k = x*60+y;
    int i = 0;
    while(i < len)
    {
        if(vec[i] + j <= k && vec[i] > ans)
        {
            ans = vec[i];
        }
        i++;
    }
    cout << ans / 60 << ' ' << ans % 60;

    return 0;
}

#endif



#if 0

#include <iostream>
#include <vector>
using namespace std;


vector<int> Fun(vector<int>& vec, int len, int k)
{
    if(len <= 0) return {};
    int x;
    vector<vector<int>> res1(len, vector<int>(k));

    vector<int> res(len - k + 2);
    for(int i = 0; i < k - 1; i++)
    {
        res[0] = vec[0] ^ 0;
    }

    for(int i = 1; i < len - k + 2; i++) {
        for(int j = 0; j < i; j++) {
            res[i] = vec[i] ^ res[j];
            vec[i] = res[i];
        }
    }


    for(int j = 0; j < len; j++)
    {
        if(j == 0)

        if(j == 1)
        {
            for(int i = 0; i < k - 2; i++)
            {
                res[j] = vec[0] ^ 0;
            }
            res[j] ^= res[j-1];
        }

    }

}


int main()
{
    int len, k;
    cin >> len >> k;
    int val;
    vector<int> vec;
    for(int i = 0; i < k; i++)
    {
        cin >> val;
        vec.push_back(val);
    }

}


//

}



#endif




//字节笔试 加密
#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> func(string &str, int N, int K)
{
    int size = str.size();
    vector<int> nums;
    for (int i = 0; i < size; i++)
    {
        nums.push_back(str[i] - '0');
    }
    vector<int> res;
    res.push_back(nums[0]);
    int tmp_sum = nums[0];
    for (int i = 1; i < K; i++)
    {
        if (tmp_sum ^ 1 == nums[i])
        {
            res.push_back(1);
        }
        else
        {
            res.push_back(0);
        }
        tmp_sum = tmp_sum ^ res[i];
    }

    if (K > N)
    {
        res.erase(res.begin() + N, res.end());
    }

    for (int i = K; i < N; i++)
    {
        tmp_sum = tmp_sum ^ res[i - K];
        if (tmp_sum ^ 1 == nums[i])
        {
            res.push_back(1);
        }
        else
        {
            res.push_back(0);
        }
        tmp_sum = tmp_sum ^ res[i];
    }
    return res;
}



int main()
{
    int N, K;
    string str;
    cin >> N >> K;
    cin >> str;

    vector<int> res = func(str, N, K);
    for (int val : res)
    {
        cout << val;
    }
    cout << endl;
    return 0;
}
#endif