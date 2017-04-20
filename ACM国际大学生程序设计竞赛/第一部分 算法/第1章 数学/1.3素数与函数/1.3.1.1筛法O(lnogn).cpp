#include <iostream>

using namespace std;

/*
*�����񡿣�
    ����һ��������N�����[2,N]�е�����������
*��˵������
    ����valid[i]��¼i�Ƿ�Ϊ��������ʼ���е�valid[i]��Ϊtrue����2��ʼ�Ӵ�С
ö��i����valid[i]=true,��Ѵ�i^2��ʼ��ÿһ��i�ı�����valid��ֵΪfalse��
    ����֮��valid[i]=true�ľ���������
*���ӿڡ���
    void getPrime(int n,int &tot,int ans[maxn])
    ���Ӷȣ�O(NlogN)
    ���룺N    ���������ķ�Χ
    �����&tot ���ã���������
          ans  ������
*�����롿
*/

#define maxn 1000000

bool valid[maxn];

void getPrime(int n,int &tot,int ans[maxn]){
    tot = 0;
    int i, j;
    for(i = 2; i <= n; ++ i)valid[i] = true;
    for(i = 2; i <= n; ++ i)
        if(valid[i]){
            if(n/i < i)break;
            for(j = i*i; j <= n; j += i)
                valid[j] = false;
        }
    for(i = 2;i <= n; ++ i)
        if(valid[i])ans[++tot] = i;
}

int main(){

    return 0;
}
