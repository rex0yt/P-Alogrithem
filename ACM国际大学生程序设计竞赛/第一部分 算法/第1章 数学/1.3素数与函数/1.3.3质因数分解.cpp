#include <iostream>
#include <cstring>


using namespace std;

/*
*�����񡿣�
    ����һ��������N����N�ֽ���������
*��˵������
    N��������Ҫô��N����N����������Ҫôһ��С�ڵ��ڸ���N����˿�����С�ڵ��ڸ���N
    ������N�����Գ���һֱ�����ܳ�Ϊֹ����ʱ��ʣ�µ����������1���Ǿ���N������������
*���ӿڡ���
    void factor(int n,int a[maxn],int b[maxn],int &tot);
    ���Ӷȣ�O(���� N)
    ���룺n    ���ֽ������
    �����&tot ��ͬ�������ĸ���
            a   a[i]��ʾ��i����������ֵ
            b   b[i]��ʾ��i����������ָ��
*�����롿
*/
#include <cmath>
#define maxn 10000

void factor(int n,int a[maxn],int b[maxn],int &tot){
    int temp,i,now;
    temp = (int)((double)sqrt(n)+1);
    tot = 0;
    now = n;
    for(i = 2;i <= temp; ++ i)
    if(now % i == 0){
        a[++ tot] = i;
        b[tot] = 0;
        while(now % i == 0){
            ++b[tot];
            now /= i;
        }
    }
    if(now != 1){
        a[++tot] = now;
        b[tot] = 1;
    }
}

int main(){

    return 0;
}
