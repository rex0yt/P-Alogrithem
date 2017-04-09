#include <iostream>

using namespace std;

struct node
{
    int val;
    node *left, *right;
};

// 插入：小值左结点，大于等于右孩子结点 返回插入后的根节点
node* insert(node *root, int val)
{
    if (!root)
    {
        root = new node();
        root->val = val;
    }
    else if (root->val < val)
    {
        root->right = insert(root->right, val);
    }
    else if (root->val > val)
    {
        root->left = insert(root->left, val);
    }
    return root;
}
// 查找：返回具有该值的结点指针
node* find(node *root, int val)
{
    while (root)
    {
        if (root->val < val)
        {
            root = root->right;
        }
        else if (root->val > val)
        {
            root = root->left;
        }
        else
        {
            return root;
        }
    }
    return NULL;
}
// 删除 返回删除后的根节点
// 情况1：同时有左右儿子，找到左儿子里的最大值，替换上来
// 情况2：有0或1个儿子，有左儿子就让左儿子替换当前节点，有右则右替换，都没有就直接删除
node* del(node *root, int val)
{
    if (!root) return NULL;

    if (root->val < val)
    {
        root->right = del(root->right, val);
    }
    else if (root->val > val)
    {
        root->left = del(root->left, val);
    }
    else
    {
        node *son;
        if (root->left && root->right)    //左右都有，返回左子树里的最右，指针修改由上一层递归处理
        {
            son = root->left;
            while (son->right) son = son->right;
            son->right = root->right;     //避免丢了删除点的右子树
        }
        else    //只有一个子树，返回存在的那个子树即可
        {
            if (root->left) son = root->left;
            else if (root->right) son = root->right;
            else son = NULL;    //叶子结点没有子树，返回NULL给一层
        }
        delete root;        //删除点
        return son;
    }
    return root;
}
// 更新值：返回新树根节点
node* update(node *root, int oldVal,int newVal)
{
    root = del(root,oldVal);
    root = insert(root,newVal);
    return root;
}
// 中序遍历：得出递增结果
void inOrder(node *root)
{
    if (!root) return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}
int main()
{
    return 0;
}
