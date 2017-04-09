#include <iostream>

using namespace std;

struct node
{
    int val;
    node *left, *right;
};

// ���룺Сֵ���㣬���ڵ����Һ��ӽ�� ���ز����ĸ��ڵ�
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
// ���ң����ؾ��и�ֵ�Ľ��ָ��
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
// ɾ�� ����ɾ����ĸ��ڵ�
// ���1��ͬʱ�����Ҷ��ӣ��ҵ������������ֵ���滻����
// ���2����0��1�����ӣ�������Ӿ���������滻��ǰ�ڵ㣬���������滻����û�о�ֱ��ɾ��
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
        if (root->left && root->right)    //���Ҷ��У�����������������ң�ָ���޸�����һ��ݹ鴦��
        {
            son = root->left;
            while (son->right) son = son->right;
            son->right = root->right;     //���ⶪ��ɾ�����������
        }
        else    //ֻ��һ�����������ش��ڵ��Ǹ���������
        {
            if (root->left) son = root->left;
            else if (root->right) son = root->right;
            else son = NULL;    //Ҷ�ӽ��û������������NULL��һ��
        }
        delete root;        //ɾ����
        return son;
    }
    return root;
}
// ����ֵ�������������ڵ�
node* update(node *root, int oldVal,int newVal)
{
    root = del(root,oldVal);
    root = insert(root,newVal);
    return root;
}
// ����������ó��������
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
