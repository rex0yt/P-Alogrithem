#include <iostream>
#include <cstring>

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
    ���Ӷȣ�O(N)
    ���룺N    ���������ķ�Χ
    �����&tot ���ã���������
          ans  ������
*�����롿
*/

#define maxn 1000000

bool valid[maxn];

void getPrime(int n,int &tot,int ans[maxn]){
    memset(valid,true,sizeof(valid));
    for(int i = 2; i <= n; i ++){
        if(valid[i]){
            ans[++ tot] = i;
        }
        for(int j = 1;((j <= tot) && (i * ans[j] <= n)); j ++){
            valid[i*ans[j]] = false;
            if(i%ans[j] == 0)break;
        }
    }
}

int main(){

    return 0;
}
