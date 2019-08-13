//
// Created by yanpan on 2019/8/3.
//

#if 0
#include <iostream>
using namespace std;

class singleton
{
private:
    singleton(){cout << "signal()" << endl; }
    static singleton* object;

public:
    static pthread_mutex_t mutex;
    static singleton* getsingleton()
    {
        if(object == NULL)
        {
            pthread_mutex_lock(&mutex);
            if(object == NULL)
            {
                object = new singleton();
            }
            pthread_mutex_unlock(&mutex);
        }
        return object;
    }
    static void release()
    {
        if(object != NULL)
        {
            cout << "delete" << endl;
            delete object;
            object = NULL;
        }

    }
};
pthread_mutex_t singleton::mutex;
singleton* singleton::object = NULL;

int main()
{
    singleton *a = singleton::getsingleton();

    singleton *sing2 = singleton::getsingleton();
    a->release();
    sing2->release();
    return 0;


}
#endif


//
// Created by yanpan on 2018/9/30.
// 实现单例模式
#if 0
#include <iostream>
#include <pthread.h>
using namespace std;
class Singleton
{
public:
    static pthread_mutex_t mutex;
    volatile static Singleton* getsingleton()//加上volatile关键字
    {
//        if(project == NULL)
//        {
//            pthread_mutex_lock(&mutex);//互斥锁  保证原子操作 多线程安全
//            if(project == NULL)  //双重检测
//            {
//                project = new Singleton();
//            }
//            pthread_mutex_unlock(&mutex);
//        }
        return project;
    }
    static void release() //释放资源
    {
        if(project!=NULL)
        {
            cout<<"delete"<<endl;
            delete project;
            project = NULL;
        }
    }
//    Singleton* project2;   不可以在类外初始化，none - static
    volatile static Singleton *project1;
private:
    Singleton(){cout<<"Singleton()"<<endl;}
    volatile static Singleton *project;
};
pthread_mutex_t Singleton::mutex;
//Singleton* Singleton::project2 = new Singleton();
volatile Singleton *Singleton::project = new Singleton();
volatile Singleton *Singleton::project1 = new Singleton();
int main()
{
//    Singleton* A = new Singleton();
    cout << "hello" << endl;
    volatile Singleton *sing1 = Singleton::getsingleton();//一个类只创建一个实例
    volatile Singleton *sing2 = Singleton::getsingleton();
//    sing1->release();
    cout << "endl" << endl;
    sing2->release();
    cout << "endl" << endl;
    return 0;
}
#endif


//静态方法
#if 0
#include <iostream>
using namespace std;


class A
{
public:
    void find()
    {
        cout << size << endl;
        cout << a << endl;
    }
    static void Find()
    {
        cout << size << endl;

    }
private:
   static int size;
    int a = 10;
};

//const int A::size = 12;
int A::size = 1;
int main()
{
    A a;
    a.find();
    a.Find();
}


#endif





#if 0
#include <iostream>
using namespace std;

long long t = 0;

int Fun(long long m, long long n)
{


    t = m > n ? n : m;
    m = m > n ? m : n;
    n = t;
    if(m % n == 0)
        return n;
    return Fun(m % n, n);
}

int main()
{
    long long m;
    long long n;

    cin >> m;
    cin >> n;
    cout << Fun(m, n) << endl;
}
#endif


//最大值中的最小值
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Fun(vector<int>& vec, int len)
{
    if(len <= 0)
        return {};
    vector<int> res;
    vector<int> dp;
    int max = 0;
    for(int k = 0; k < len; k++)    //k个连续的序列
    {
        for(int i = 0; i < len - k; i++)    //从0开始计算一直到len -k
        {
            for(int j = i, h = 0; h <= k; h++,j++) // 一次计算k个
            {
                if(vec[j] >= max)
                {
                    max = vec[j];     //保存max
                }
            }
            dp.push_back(max);   //将max放在数组中
            max = 0;  //重置max
        }
        sort(dp.begin(), dp.end());  //排序数组
        res.push_back(dp[0]);
        dp.clear();    //清空数组
    }
    return res;
}

int main()
{
    int len;
    cin >> len;
    vector<int> vec;
    int num;
    for(int i = 0; i < len; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    vector<int> res = Fun(vec, len);
    for(int i = 0; i < len; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

}
#endif