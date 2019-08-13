//
// Created by yanpan on 2018/6/24.
//

//interview question 5


//Problems encountered:

/*
 * 1.c++复习 一周
 * 2.数据结构算法复习一周
 * 3.剑指offer和程序员自我修养系列书阅读
 * 4.项目5天时间
*/

#if 0
#include <iostream>
using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};





// 链表尾插法

ListNode** AddToTail(ListNode** pHead,int value)
{
    ListNode* pNew = new ListNode();
    pNew -> m_nValue = value;
    pNew -> m_pNext = NULL;

    if(*pHead == NULL)
        *pHead = pNew;
    else
    {
        ListNode* pNode = *pHead;
        while(pNode -> m_pNext != NULL)
            pNode = pNode -> m_pNext;
        pNode -> m_pNext = pNew;
    }
    ListNode* pNode = *pHead;
    while(pNode -> m_pNext != NULL)
    {
        cout<<pNode -> m_nValue<<endl;
        pNode = pNode -> m_pNext;
    }
    return pHead;
}


/*
//在链表中找到一个含某值的节点并删除该结点
void RemoveNode(ListNode** pHead,int value)
{
    ListNode *pNode = *pHead;
    if(pHead==NULL || *pHead == NULL)
        return;
//    ListNode *pNode = *pHead;
    ListNode *ptobeDeleted = NULL;
    if((*pHead) -> m_nValue == value)
    {
        ptobeDeleted = *pHead;
        *pHead = (*pHead) -> m_pNext;
    }
    else
    {

        if(pNode -> m_pNext != NULL && pNode -> m_pNext ->m_nValue !=value)
        {
            pNode = pNode -> m_pNext;
            if(pNode -> m_nValue == value)
            {
                ptobeDeleted = pNode -> m_;

            }
        }
    }
    if(ptobeDeleted != NULL)
    {
        delete(ptobeDeleted);
        ptobeDeleted = NULL;
    }
    while((*pHead) -> m_nValue != NULL)
    {
        cout<<(*pHead) -> m_nValue<<endl;
        *pHead = (*pHead) -> m_pNext;
    }
    return;
}
*/


int main()
{
    ListNode *p = NULL;
//    p->m_nValue = 9;
    ListNode** phead = &p;
    ListNode** pHead = AddToTail(phead,8);
    ListNode** pHead1 = AddToTail(pHead,9);
    ListNode** pHead2 = AddToTail(pHead1,6);
    ListNode** pHead3 = AddToTail(pHead2,7);
//    RemoveNode(pHead1,8);
//    AddToTail(phead,7);
//    AddToTail(phead,6);
//    AddToTail(phead,5);
//    AddToTail(phead,4);
//    AddToTail(phead,3);
//    AddToTail(phead,2);
//    AddToTail(phead,1);
    return 0;
}
#endif





#if 0
#include <stdio.h>




int main()
{
    return 0;
}
#endif