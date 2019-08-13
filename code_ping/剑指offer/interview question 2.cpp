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
private:
    Singleton(){cout<<"Singleton()"<<endl;}
    volatile static Singleton *project;
};
pthread_mutex_t Singleton::mutex;
volatile Singleton *Singleton::project = new Singleton();

int main()
{
    volatile Singleton *sing1 = Singleton::getsingleton();//一个类只创建一个实例
    volatile Singleton *sing2 = Singleton::getsingleton();
    sing1->release();
    sing2->release();
    return 0;
}
#endif