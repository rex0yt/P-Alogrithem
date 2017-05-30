/*
*数组仿真链表 用堆优化寻找未使用结点下标的速度
*rex0yt
*/

#include <bits/stdc++.h>

using namespace std;

const int NN = 100000;
int *data;/*数据域*/
int *next;/*指针域*/

vector<int> istack;/*用于存放未使用的结点*/
int stack_head;/*栈顶指针 指向第一个未使用的元素*/

int head;/*链表的头指针*/

void init()/*初始化链表*/
{
    head = -1;
    data = new int [NN];
    next = new int [NN];
    istack.clear();
    istack.resize(NN);
    stack_head = 0;
    for(int i=0; i<NN; i++)
    {
        data[i] = -1;
        next[i] = -1;
        istack[i] = i;
    }
}
void create(int n)/*创建n个元素的链表*/
{
    head = 0;
    for(int i=0; i<n; i++)
    {
        scanf("%d",data+i);
        next[i] = i+1;
    }
    stack_head = n;
    next[n-1] = -1;
}
void output()/*输出所有元素 以空格区分 最后一个元素后存在空格*/
{
    if(head == -1)return ;
    int pnt = head;
    do
    {
        cout << data[pnt] << " ";
        pnt = next[pnt];
    }
    while(pnt != -1);
    cout << endl;
}
void headinsert(int val)
{
    if(head == -1)
    {
        head = istack[stack_head++];
        data[head] = val;
        next[head] = -1;
    }
    else
    {
        int pnt = istack[stack_head++];
        next[pnt] = head;
        data[pnt] = val;
        head = pnt;
    }
}
void tailinsert(int val)
{
    if(head == -1)
    {
        head = istack[stack_head++];
        data[head] = val;
        next[head] = -1;
    }
    else
    {
        int tail = head;
        while(next[tail] != -1)
        {
            tail = next[tail];
        }
        int pnt = istack[stack_head ++];
        next[tail] = pnt;
        next[pnt] = -1;
        data[pnt] = val;
    }
}
void deleteVal(int val)/*删除所有值为Val的结点*/
{
    if(head == -1)
    {
        return ;
    }
    else
    {
        int pnt = head, pre = -1;
        while(pnt != -1)
        {
            if(data[pnt] == val)
            {
                if(pnt == head)
                {
                    head = next[pnt];
                }
                else
                {
                    next[pre] = next[pnt];
                }
                data[pnt] = -1;
                int tmp = pnt;
                pnt = next[pnt];
                next[tmp] = -1;
                istack[-- stack_head] = pnt;

                continue;
            }
            pre = pnt;
            pnt = next[pnt];
        }
    }
}
int main()
{
    init();
    create(5);
    output();
    headinsert(777);
    output();
    tailinsert(666);
    output();
    deleteVal(34);
    output();
    return 0;
}
