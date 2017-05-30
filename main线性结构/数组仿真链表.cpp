/*
*����������� �ö��Ż�Ѱ��δʹ�ý���±���ٶ�
*rex0yt
*/

#include <bits/stdc++.h>

using namespace std;

const int NN = 100000;
int *data;/*������*/
int *next;/*ָ����*/

vector<int> istack;/*���ڴ��δʹ�õĽ��*/
int stack_head;/*ջ��ָ�� ָ���һ��δʹ�õ�Ԫ��*/

int head;/*�����ͷָ��*/

void init()/*��ʼ������*/
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
void create(int n)/*����n��Ԫ�ص�����*/
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
void output()/*�������Ԫ�� �Կո����� ���һ��Ԫ�غ���ڿո�*/
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
void deleteVal(int val)/*ɾ������ֵΪVal�Ľ��*/
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
