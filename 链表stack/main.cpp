#include <iostream>

using namespace std;

struct Node//����������
{
    int data;
    Node* next;
};
Node* top = NULL;//ջ��ָ��

void push(int data){//ѹջ
    Node* p = new(Node);
    p->data = data;
    p->next = top;
    top = p;
    return ;
}
int pop(){//��ջ
    int data;
    Node* p = top;
    top = p->next;
    data = p->data;
    delete(p);
    return data;
}
int isEmpty(){//�ж�ջ�Ƿ�Ϊ��
    if(NULL == top)return 1;
    return 0;
}

int main(){

    return 0;
}
