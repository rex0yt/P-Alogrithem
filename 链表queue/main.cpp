#include <iostream>

using namespace std;

struct Node{//����������
    int data;
    Node* next;
};
Node* rear = NULL, *front = NULL;//��ʼ������ͷβָ��
int count = 0;//ͳ�ƶ�����Ԫ�صĸ���

void push(int data){//�ڶ�β��������
    Node* p = new(Node);
    p->data = data;
    p->next = NULL;
    if(NULL != rear)rear->next = p;
    rear = p;
    if(NULL == front)front = p;
    count ++;
    return ;
}
int pop(){//�ڶ�ͷɾ������
    int data;
    Node* p = front;
    front = p->next;
    data = p->data;
    delete(p);
    count --;
    return data;
}
int getFront(){//��ö�ͷ����
    int data = front->data;
    return data;
}
int isEmpty(){//�ж϶����Ƿ�Ϊ��
    if(NULL == front)return 1;
    return 0;
}
void printQueue(){//�����������
    Node* p = front;
    while(NULL != p){
        cout << p->data << " ";
        p = p->next;
    }
}
int main(){

    return 0;
}
