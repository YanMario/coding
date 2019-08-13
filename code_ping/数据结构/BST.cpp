//
// Created by yanpan on 2019/5/11.
//


//二叉树     "剑指offer"

#if 0
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode
{
    int _val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val): _val(val), left(NULL), right(NULL){}
};

TreeNode* ConstructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder);


//前中序重建树
TreeNode* Construct(int *preorder, int *inorder, int length)
{
    if(preorder == NULL || inorder == NULL && length <= 0)
        return nullptr;
    return ConstructCore(preorder, preorder + length -1, inorder, inorder + length -1);
}

TreeNode* ConstructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder) {
    int root_value = startPreorder[0];
    TreeNode *root = new TreeNode(root_value);

    int *rootInorder = startInorder;
    while(rootInorder <= endInorder && *rootInorder != root_value)
        ++rootInorder;

    int leftLength = rootInorder - startInorder;

    if (leftLength > 0)
        root->left = ConstructCore(startPreorder + 1, startPreorder + leftLength, startInorder, startInorder + leftLength - 1);
    if (leftLength < endPreorder - startPreorder)
        root -> right = ConstructCore(startPreorder + leftLength +1, endPreorder, rootInorder  + 1, endInorder);
    return root;
}

void ShowPro(TreeNode *root)
{
    if(root != NULL)
    {
        cout<<root->_val;
        ShowPro(root->left);
        ShowPro(root->right);
    }
    return;
}

TreeNode* ConstructCore1(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder);

TreeNode* Construct1(int* preorder, int* inorder, int length)
{
    if(preorder == nullptr || inorder == nullptr || length <= 0)
        return nullptr;

    return ConstructCore1(preorder, preorder + length - 1,
                         inorder, inorder + length - 1);
}

TreeNode* ConstructCore1
        (
                int* startPreorder, int* endPreorder,
                int* startInorder, int* endInorder
        )
{
    // 前序遍历序列的第一个数字是根结点的值
    int rootValue = startPreorder[0];
    TreeNode* root = new TreeNode(rootValue);
//    root->_val = rootValue;
//    root->m_pLeft = root->m_pRight = nullptr;

    if(startPreorder == endPreorder)
    {
        if(startInorder == endInorder && *startPreorder == *startInorder)
            return root;
//        else
//            throw exception("Invalid input.");
    }

    // 在中序遍历中找到根结点的值
    int* rootInorder = startInorder;
    while(rootInorder <= endInorder && *rootInorder != rootValue)
        ++ rootInorder;

//    if(rootInorder == endInorder && *rootInorder != rootValue)
//        throw std::exception("Invalid input.");

    int leftLength = rootInorder - startInorder;
//    int* leftPreorderEnd = startPreorder + leftLength;
    if(leftLength > 0)
    {
        // 构建左子树
        root->left = ConstructCore(startPreorder + 1, startPreorder + leftLength,
                                      startInorder, rootInorder - 1);
    }
    if(leftLength < endPreorder - startPreorder)
    {
        // 构建右子树
        root->right = ConstructCore(startPreorder + leftLength + 1, endPreorder,
                                       rootInorder + 1, endInorder);
    }

    return root;
}

int main()
{
    int pro_arr[] = {1, 2, 4, 5, 8, 9, 3, 6, 7};
    int in_arr[] = {4, 2, 8, 5, 9, 1, 6, 3, 7};
    int len = sizeof(pro_arr) / sizeof(pro_arr[0]);
    TreeNode * Node = Construct(pro_arr, in_arr, len);
    ShowPro(Node);
    cout << endl;
    return 0;
}

#endif





















#if 0
#include <iostream>
#include <stack>
#include <vector>

using namespace std;



struct TreeNode
{
    int _val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val): _val(val), left(NULL), right(NULL){}
};

TreeNode* BuyNode()
{
    TreeNode *newNode = new TreeNode(NULL);
//    if(!newNode)
//        return NULL;
    return newNode;
}

void DeleteTreeNode(TreeNode* p)
{
    delete(p);
}


//前序遍历
void ShowPro(TreeNode *root)
{
    if(root == NULL)return;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty())
    {
        TreeNode *tmp = s.top();s.pop();
        cout<<tmp->_val;
        if(tmp->right != NULL)s.push(tmp->right);
        if(tmp->left != NULL)s.push(tmp->left);
    }
}
//中序遍历
void ShowIn()
{

}
//后序遍历
void ShowLast()
{

}

//创建二叉树
TreeNode* CreateTree()
{

}

//前中序建立二叉树
TreeNode* ProInCreateTree(char *pro_arr, char *in_arr, int len)
{
    TreeNode *ptr;
    if(pro_arr != NULL && in_arr != NULL && len > 0) {

        ptr = BuyNode();
        ptr->_val = pro_arr[0];      //根结点的值
        int index;
        for (int i = 0; i < len; ++i)
            if (in_arr[i] == pro_arr[0])
                index = i;
        ptr->left = ProInCreateTree(pro_arr + 1, in_arr, index);
        ptr->right = ProInCreateTree(pro_arr + index + 1, in_arr + index + 1, len - index - 1);
    }
    return ptr;
}

/*
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return buildTreeHelp(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }

    TreeNode* buildTreeHelp(vector<int>& preorder, vector<int>& inorder,int pr_s,int pr_e,int in_s,int in_e)
    {
        if(pr_s>pr_e||in_s>in_e) return NULL;
        int pivot=preorder[pr_s];

        //找到在中序序列中的位置
        int k=0;
        for(int i=in_s;i<=in_e;i++)
        {
            if(inorder[i]==pivot)
            {
                k=i;
                break;
            }
        }
        TreeNode* node = new TreeNode(pivot);
        node->left=buildTreeHelp(preorder,inorder,
                                 pr_s+1, pr_s+(k-in_s),
                                 in_s, k-1);
        node->right=buildTreeHelp(preorder,inorder,
                                  pr_s+(k-in_s)+1, pr_e,
                                  k+1, in_e);
        return node;
    }

    TreeNode* creat(vector<int> &pre, vector<int> &in, int pre_begin, int pre_len, int in_begin, int in_len)
    {
        if(pre_len-1 < pre_begin || in_len-1 < in_begin)
            return NULL;
        int pre_pro = pre[pre_begin];
        int k = 0;
        for(int i = in_begin; i < in_len; i++)
            if(in[i] == pre_pro)
            {
                k = i;
                break;
            }
        TreeNode * Node = new TreeNode(pre_pro);

        Node -> left = creat(pre, in, pre_begin + 1, pre_begin + k + 1 - in_begin, in_begin, k-1);
        Node -> left = creat(pre, in, pre_begin + k + 1 - in_begin, pre_len, k +1, in_len);
        return Node;
    }

    void ShowPro(TreeNode *root)
    {
        if(root == NULL)return;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode *tmp = s.top();s.pop();
            cout<<tmp->_val;
            if(tmp->right != NULL)s.push(tmp->right);
            if(tmp->left != NULL)s.push(tmp->left);
        }
    }

};*/


int main()
{
    int pro_arr[] = {1, 2, 4, 5, 8, 9, 3, 6, 7};
    int in_arr[] = {4, 2, 8, 5, 9, 1, 6, 3, 7};
    int len = sizeof(pro_arr) / sizeof(pro_arr[0]);
    vector<int> vec(pro_arr, pro_arr + len);
    vector<int> vec1(in_arr, in_arr + len);
    cout<< "main" << endl;
    /*Solution A;
//    TreeNode * Node = A.buildTree(vec, vec1);
    TreeNode * Node = A.creat(vec, vec1, 0, vec.size(), 0, vec.size());
    A.ShowPro(Node);*/
//    cout<< "ee" <<endl;
    cout << endl;
//    DeleteTreeNode(Node);
    return 0;
}
#endif






















/************************* hello *************************/

#if 0
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
typedef char Type;
typedef struct Node
{
    Type data;
    Node *leftchild;
    Node *rightchild;
}Node;

Node * BuyNode()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL)return NULL;
    memset(newNode,0,sizeof(newNode));
    return newNode;
}
void FreeNode(Node *p)
{
    free(p);
}
//前序遍历：：递归
void ShowPro(Node *root)
{	if(root != NULL)
    {
        cout<<root->data;
        ShowPro(root->leftchild);
        ShowPro(root->rightchild);
    }
}
//前序遍历：：非递归
void ShowPro1(Node *root)
{
    if(root == NULL)return;
    stack<Node*> s;
    s.push(root);
    while(!s.empty())
    {
        Node *tmp = s.top();s.pop();
        cout<<tmp->data;
        if(tmp->rightchild != NULL)s.push(tmp->rightchild);
        if(tmp->leftchild != NULL)s.push(tmp->leftchild);
    }
}
//中序遍历：：递归
void ShowIn(Node *root)
{	if(root != NULL)
    {
        ShowIn(root->leftchild);
        cout<<root->data;
        ShowIn(root->rightchild);
    }
}
//中序遍历：：非递归
void ShowIn1(Node *root)
{
    if(root == NULL)return;
    stack<Node*> s;
    //s.push(root);
    while(root !=NULL || !s.empty())
    {
        //Node *tmp = root;
        while(root != NULL)
        {
            //if(root->leftchild != NULL)
            s.push(root);
            root = root->leftchild;
        }
        root = s.top();s.pop();
        cout<<root->data;
        root = root->rightchild;
    }
}
//后序遍历：：递归
void ShowLast(Node *root)
{	if(root != NULL)
    {
        ShowLast(root->leftchild);
        ShowLast(root->rightchild);
        cout<<root->data;
    }
}
//后序遍历：：非递归
void ShowLast1(Node *root)
{
    if(root == NULL) return;
    stack<Node*> s;
    Node *tag;
    while(root != NULL || !s.empty())
    {
        while(root!=NULL)
        {
            s.push(root);
            root = root->leftchild;
        }
        root = s.top();s.pop();
        if(root->rightchild == NULL || tag == root->rightchild)
        {
            cout<<root->data;
            tag = root;
            root = NULL;
        }
        else
        {
            s.push(root);
            root = root->rightchild;
        }
    }
}
//层次遍历
void ShowLevel(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while(!q.empty())
    {
        Node *tmp = q.front();q.pop();
        cout<<tmp->data;
        if(tmp->leftchild != NULL)q.push(tmp->leftchild);
        if(tmp->rightchild != NULL)q.push(tmp->rightchild);
    }
}
static int FindPos(Type *str,Type key)
{
    if(str == NULL)return -1;
    int i = 0;
    for(; str[i]!='\0'; ++i)
    {
        if(str[i] == key)
            return i;
    }
    return -1;
}
//前序中序建树
Node *ProInCreate(Type *pro,Type *in,int n)
{
    Node *ptr = NULL;
    if(pro!=NULL && in!=NULL && n>0)
    {
        ptr = BuyNode();
        ptr->data = pro[0];
        int index = FindPos(in,pro[0]);
        ptr->leftchild = ProInCreate(pro+1,in,index);
        ptr->rightchild = ProInCreate(pro+index+1,in+index+1,n-index-1);
    }
    return ptr;
}
//后序中序建树
Node *LastInCreate(Type *last,Type *in,int n)
{
    Node *ptr = NULL;
    if(last!=NULL && in!=NULL && n>0)
    {
        ptr = BuyNode();
        ptr->data = last[n-1];
        int index = FindPos(in,last[n-1]);
        ptr->leftchild = LastInCreate(last,in,index);
        ptr->rightchild = LastInCreate(last+index,in+index+1,n-index-1);
    }
    return ptr;
}
//求二叉树深度：：递归
int Depth1(Node *root)
{
    if(root == NULL) return 0;
    if(root->leftchild == NULL && root->rightchild == NULL) return 1;
    int depthl = Depth1(root->leftchild);
    int depthr = Depth1(root->rightchild);

    return depthl>depthr ? depthl+1:depthr+1;
}
//求二叉树深度：：非递归
int Depth2(Node *root)
{
    if(root == NULL) return 0;
    if(root->leftchild == NULL && root->rightchild == NULL) return 1;
    queue<Node*> q;
    q.push(root);
    int depth = 0;
    while(!q.empty())
    {
        int size = q.size();
        for(int i=0; i<size; ++i)
        {
            Node *tmp = q.front();q.pop();
            if(tmp->leftchild !=NULL)q.push(tmp->leftchild);
            if(tmp->rightchild!=NULL)q.push(tmp->rightchild);
        }
        depth++;
    }
    return depth;
}
//求二叉树节点个数
int Size(Node *root)
{
    if(root == NULL) return 0;
    if(root->leftchild == NULL && root->rightchild == NULL) return 1;
    int sizel = Size(root->leftchild);
    int sizer = Size(root->rightchild);
    return sizel+sizer+1;
}
//判断是不是满二叉树
bool IsFullTree(Node *root)
{
    if(root == NULL)return false;
    if(root->leftchild == NULL && root->rightchild == NULL) return true;
    int depth = Depth2(root);
    int num = depth*2+1;
    int size =	Size(root);
    if(num!= size)
        return false;
    return true;
}
//判断是不是完全二叉树
bool IsCompTree(Node *root)
{
    queue<Node *> q;
    q.push(root);
    bool tag = true;
    while(!q.empty())
    {
        root = q.front();q.pop();
        if(root->leftchild == NULL && root->rightchild !=NULL)
            return false;
        if(!tag && (root->leftchild || root->rightchild))
            return false;
        if(root->leftchild==NULL || root->rightchild == NULL)
            tag = false;
        if(root->leftchild)
            q.push(root->leftchild);
        if(root->rightchild)
            q.push(root->rightchild);
    }
    return true;
}
int main()
{
    /*char *pro = "ABCDEFGH";
    char *in = "CBEDFAGH";
    char *last = "CEFDBHGA";*/
    char *pro = "ABDCFG";
    char *in = "DBAFCG";
    char *last = "DBFGCA";
    int len = strlen(pro);
    cout << "begin" << endl;
    Node *root = ProInCreate(pro,in,len);
    ShowPro(root);
    cout << "end" << endl;
    cout<<endl;
    FreeNode(root);
    int depth = Depth2(root);
    cout<<"Depth:"<<depth<<endl;
    int size = Size(root);
    cout<<"Size:"<<size<<endl;
    if(IsFullTree(root))

        cout<<"Tree is full"<<endl;
    else
        cout<<"Tree is nofull"<<endl;

    if(IsCompTree(root))
        cout<<"Tree is Comp"<<endl;
    else
        cout<<"Tree is noComp"<<endl;
    return 0;
}

#endif


#if 0
#include <iostream>
#include <vector>
using namespace std;


int main()
{
    vector<int> vec;
    for(auto i = 0; i < 20; ++i)
        vec.push_back(i);
    for(auto it = vec.cbegin(); it != vec.cend(); ++it)
        cout << *it << " ";
    cout << endl;
    cout << vec.size() << endl;
    for(auto i = 0; i < 3; ++i)
        vec.pop_back();
    cout << vec.capacity() << endl;
    return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;


int main()
{
    //p 存放的就收hello这个字符串，并非地址
    char *p = "hello";
    printf("%s\n", p);
    int a = 10;
    int *b = &a;
    cout << p << endl;
    return 0;
}
#endif