//
// Created by yanpan on 2019/7/14.
//



//*****************leetcode 160***************//
#if 0
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if(headA == NULL || headB == NULL)
            return NULL;
        ListNode* nodeA = headA;
        ListNode* nodeB = headB;
        while(nodeA != nodeB)
        {
            if(nodeA != NULL)
                nodeA = nodeA -> next;
            else
                nodeA = headB;
            if(nodeB != NULL)
                nodeB = nodeB -> next;
            else
                nodeB = headA;
        }
        return nodeA;

    }
};


int main()
{
    ListNode * headA = new ListNode(1);
    ListNode * node1 = new ListNode(3);
    ListNode * node2 = new ListNode(6);
    ListNode * node3 = new ListNode(8);
    ListNode * node4 = new ListNode(5);


    ListNode * headB = new ListNode(1);
    ListNode * nodeB1 = new ListNode(3);
    ListNode * nodeB2 = new ListNode(6);
    ListNode * nodeB3 = new ListNode(8);

    headA -> next = node1;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;

    headB -> next = nodeB1;
    nodeB1 -> next = nodeB2;
    nodeB2 -> next = nodeB3;
    nodeB3 -> next = node4;

    Solution text;
    ListNode* temp = text.getIntersectionNode(headA, headB);
    cout << temp -> val << endl;

}
#endif