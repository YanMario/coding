//
// Created by yanpan on 2019/8/12.
//
#if 0
#include<iostream>
//#include<string>
//#include<limits.h>
//#include<queue>
//#include<stack>
//#include<vector>
//#include<iomanip>
//#include<assert.h>
using namespace std;
// 1
// 2
// 3
#define M 13      //初始化13个table
typedef int KeyType;
typedef struct {} Record;
typedef struct
{
    KeyType key;      //一个整形数据
    Record *recptr;   //一个指针
}ElemType;
typedef struct HashNode
{
    ElemType data;   //一个结构体的数据
    HashNode *next;
}HashNode;

typedef struct
{
    HashNode **table;    //    一维数组 一维链表   数组后边存放的是链表
    int cursize;
}HashTable;

HashNode * Buynode()
{
    HashNode * s = (HashNode*)malloc(sizeof(HashNode));  //申请node节点
    if(NULL == s) exit(1);
    memset(s,0,sizeof(HashNode));
    return s;
}
void Freenode(HashNode *p)
{
    free(p);
}
void InitHashTable(HashTable &ht)     //初始化
{
    ht.table = (HashNode**)malloc(sizeof(HashNode*)*M);   //申请M个 hashNode* 就是链表
    for(int i = 0;i<M;++i)
    {
        ht.table[i] = NULL;
    }
    ht.cursize = 0;
}
int Hash(KeyType kx) { return kx % M;}     //找到在哪一个table里，hash函数%操作

HashNode * FindValue(HashTable &ht,KeyType kx)
{
    int index = Hash(kx);
    HashNode * p = ht.table[index];        //得到hash后的值 对应的一维的链表
    while(p != NULL && p->data.key != kx)  //找到链表里的值val对应着kx
    {
        p = p->next;
    }
    return p;                 //返回链表节点
}
bool Insert(HashTable &ht,ElemType val)
{
    HashNode *p =FindValue(ht,val.key);    //返回p
    if(NULL != p) return false;            //判断这个节点是否存在
    HashNode *s = Buynode();               //不存在的情况下购买一个节点
    int index = Hash(val.key);             //算出插在数组的哪个位置
    s->data = val;                         //给购买的节点的值赋值val
    s->next = ht.table[index];             //头插
    ht.table[index]  = s;                  //将s节点和 ht.table数组对应的值连接上
    ht.cursize+=1;                         //对应的记录实际大小的size++;
    return true;
}
bool Remove(HashTable &ht,KeyType kx)
{
    bool res = false;
    int index = Hash(kx);
    HashNode *pre = NULL;
    HashNode *p = ht.table[index];
    while(p != NULL)
    {
        if(p->data.key == kx)
        {
            if(pre == NULL)
            {
                //p是链表的第一个节点
                ht.table[index] = p->next;
            }
            else
            {
                pre->next = p->next;
            }
            Freenode(p);
            ht.cursize -=1;
            res = true;
            break;
        }
        //当p不是链表的第一个节点后，会进行赋值后移
        pre = p;
        p = p->next;
    }
    return res;
}
int main()
{
    ElemType ar[]={19,NULL,14,NULL,23,NULL,1,NULL,68,NULL,20,NULL,84,NULL,27,NULL,55,NULL,11,NULL,10,NULL,79,NULL};
    int n = sizeof(ar)/sizeof(ar[0]);
    HashTable ht;
    InitHashTable(ht);
    for(int i = 0;i<n;++i)
    {
        Insert(ht,ar[i]);
    }
    HashNode* p = FindValue(ht, 23);
    cout << p -> data.key << endl;
    return 0;
}
#endif


