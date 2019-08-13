//
// Created by yanpan on 2019/5/20.
//

#if 0
#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct Node
{
    ElemType _date;
    struct Node* _pnext;
}Node,*List;

void Init_list(List plist)
{
    if(NULL == plist)
        return;
    plist -> _pnext = NULL;
}


Node *BuyNode()
{
    Node *PNode = (Node*)malloc(sizeof(Node));
    if(NULL == PNode)
        return NULL;
    return PNode;
}

bool Inser_Head(List plist, ElemType date)
{
    if(NULL == plist)
        return false;
    Node *PNode = BuyNode();
    PNode -> _date = date;
    PNode -> _pnext = plist -> _pnext;
    plist -> _pnext = PNode;
    return true;
}

bool Inser_Tail(List plist, ElemType date)
{
    if(NULL == plist)
        return false;
    Node *PNode = BuyNode();
    Node *TempNode = plist;
    PNode -> _date = date;
    while(TempNode -> _pnext != NULL)
    {
        TempNode = TempNode -> _pnext;
    }
    TempNode -> _pnext = PNode;
    PNode -> _pnext = NULL;
    return true;
}

//链表逆置
void Reserve(List plist)
{
    if(NULL == plist)
        return;
    Node *pnode = plist -> _pnext;
    Node *pre = plist -> _pnext;
    //如果只有一个节点或者没有节点
    if(pre == NULL || pre -> _pnext == NULL)
        return;
    Node *cur, *rear;    //cur 当前指针， rear 后一个节点的指针
    cur = pre -> _pnext;
    //将链表的指针指向进行反转
    while(cur)
    {
        rear = cur -> _pnext;
        cur -> _pnext = pre;
        pre = cur;
        cur = rear;
    }
    pnode -> _pnext = NULL;      //当前链表的尾节点置成NULL
    plist -> _pnext = pre;       //头节点指向最后一个节点
    return;
}


List FindK(List plist, unsigned int k)
{
    if(plist == NULL || k == 0)
        return NULL;
    Node *pnode = plist;
    Node *phead = plist;
    Node *prest = plist;
    int len = 0;
    while(pnode)
    {
        len++;
        pnode= pnode -> _pnext;
    }
    if(k > len)
        return NULL;
    for(auto i = 0; i < k-1; ++i)
    {
        if(phead -> _pnext != NULL)
            phead = phead -> _pnext;
    }
    while(phead -> _pnext)
    {
        phead = phead -> _pnext;
        prest = prest -> _pnext;
    }
    return prest;
}


//List removeNthFromEnd(List head, int n)
//{
//    List pnode = head;
//    List prest = head;
//    int len = 0;
//
//    for(auto i = 0; i < n; ++i)
//    {
//        // if(pnode -> next != NULL)
//        cout << i << endl;
//        pnode = pnode -> _pnext;
//        cout << pnode -> _date <<endl;
//    }
//    if(!pnode)
//    {
//        cout << "pnode: " << endl;
////        return head;
//    }
//}


void Delete(Node *plist)
{
    if(NULL == plist)
        return;
    Node *pnode = plist;
    Node *qnode;
    while(pnode != NULL)
    {
        qnode = pnode;
        pnode = pnode -> _pnext;
        free(qnode);
    }
    return;
}



void show(List plist)
{
    if(NULL == plist)
        return;
    Node *node = plist -> _pnext;
    while(node != NULL)
    {
        cout << node -> _date << endl;
        node = node -> _pnext;
    }
    return;
}
void test()
{
    Node *plist = BuyNode();
    if(plist == NULL)
    {
        perror("BuyNode is fail");
        return;
    }
    Init_list(plist);
    Inser_Head(plist, 50);
    Inser_Head(plist, 40);
    Inser_Head(plist, 30);
    Inser_Head(plist, 20);
    Inser_Head(plist, 10);
    Inser_Head(plist, 0);
    show(plist);
    return;
}

void test1(Node *plist)
{
    if(plist == NULL)
    {
        perror("BuyNode is fail");
        return;
    }
    Init_list(plist);
    Inser_Tail(plist, 50);
    Inser_Tail(plist, 40);
//    Inser_Tail(plist, 30);
//    Inser_Tail(plist, 20);
//    Inser_Tail(plist, 10);
//    Inser_Tail(plist, 0);
    show(plist);
    return;
}

int main()
{
    Node *plist = BuyNode();
    test1(plist);
//    Reserve(plist);
//    show(plist);
    Node *pnode = FindK(plist, 1);
    cout << pnode -> _date << endl;
//    removeNthFromEnd(plist, 2);
//    Delete(plist);
    return 0;
}
#endif