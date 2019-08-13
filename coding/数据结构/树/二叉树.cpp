//
// Created by yanpan on 2019/6/10.
//


//二叉树     come on!
#if 0
#include <iostream>
#include <stack>
using namespace std;


typedef struct TreeNode
{
    int _data;
    struct TreeNode* left;
    struct TreeNode* right;
}BtNode;

//申请内存
BtNode* BuyNode()
{
    BtNode* node = (BtNode*) malloc(sizeof(BtNode));
    if(NULL == node)
        return NULL;
    memset(node, 0, sizeof(node));
    return node;
}

//释放内存
void FreeNode(BtNode *node)
{
    free(node);
}

//前中后序列建树
int Find(const int* arr, int n, int data)
{
    if(NULL == arr || n < 0)
        exit(1);
    for(auto i = 0; i < n; ++i)
        if(arr[i] == data)
            return i;
    return -1;
}

BtNode* CreatePI(const int *ps, const int *is, int n)
{
    BtNode *node = NULL;
    if(ps != NULL && is != NULL && n > 0)
    {
        node = BuyNode();
        node -> _data = ps[0];
        int pos = Find(is, n, ps[0]);   //找到根节点在中序的下标
        if(pos < 0)
            exit(1);
        node -> left = CreatePI(ps + 1, is, pos);
        node -> right = CreatePI(ps + pos + 1, is + pos + 1, n - pos - 1);
    }
    return node;
}




//中后序列建立二叉树

BtNode* CreateIL(const int *is, const int *ls, int n)
{
    BtNode *node = NULL;
    if(is != NULL && ls != NULL && n > 0)
    {
        node = BuyNode();
        node -> _data = ls[n-1];
        int pos = Find(is, n, ls[n-1]);
        if(pos < 0)
            exit(1);
        node -> left = CreateIL(is , ls , pos);
        node -> right = CreateIL(is + pos + 1, ls + pos, n - pos -1);
    }
    return node;
}

//前序遍历
void ShowPro(TreeNode *root)
{
    if(root != NULL)
    {
        cout<<root -> _data << " ";
        ShowPro(root -> left);
//        cout<< "hello ";
        ShowPro(root -> right);
//        cout << "world ";
    }
    return;
}

void ShowIn(BtNode* root)
{
    if(root != NULL)
    {
        ShowIn(root -> left);
        cout << root -> _data << " ";
        ShowIn(root -> right);
    }
}


void ShowLast(BtNode* root)
{
    if(root != NULL)
    {
        ShowLast(root -> left);
        ShowLast(root -> right);
        cout << root -> _data << " ";
    }
}

//非递前序归遍历二叉树
void PreNiceOrder(BtNode* root)
{
    if(root == NULL)
        return;
    stack<BtNode*> st;
    st.push(root);
    while(!st.empty())
    {
        root = st.top();
        st.pop();
        cout << root -> _data << " ";
        if(root -> right != NULL)
            st.push(root -> right);
        if(root -> left != NULL)
            st.push(root -> left);
    }
}

void InNiceOrder(BtNode* root)
{
    if(root == NULL)
        return;
    stack<BtNode*> st;
    while(!st.empty() || root != NULL)
    {
        while(root != NULL)
        {
            st.push(root);
            root = root -> left;
        }
        root = st.top();
        st.pop();
        cout << root -> _data << " ";
        root = root -> right;
    }
}


void LastNiceOrder(BtNode* root)
{
    if(root == NULL)
        return;
    stack<BtNode*> st;
    BtNode* flag = NULL;
    while(!st.empty() || root != NULL)
    {
        while(root != NULL)
        {
            st.push(root);
            root = root -> left;
        }
        root = st.top();
        st.pop();
        if(root -> right == NULL || root -> right == flag)
        {
            cout << root -> _data << " ";
            flag = root;
            root = NULL;
        }
        else
        {
            st.push(root);
            root = root -> right;
        }
    }
}


int main()
{
    int pro_arr[] = {15, 10, 8, 12, 11, 14, 20, 16, 24};
    int in_arr[] = {8, 10, 11, 12, 14, 15, 16, 20, 24};
    int last_arr[] = {8, 11, 14, 12, 10, 16, 24, 20, 15};

    int len = sizeof(pro_arr) / sizeof(pro_arr[0]);

    TreeNode * Node = CreateIL(in_arr, last_arr, len);

//    LastNiceOrder(Node);
    ShowPro(Node);
    return 0;
}
#endif