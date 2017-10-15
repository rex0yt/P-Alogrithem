#include <iostream>
#include <cstring>

using namespace std;

/*
*�����񡿣�
    ����һ��������N���ж�N�Ƿ�Ϊ������
*��˵������
    Miller-Rabin���ԣ�Ҫ����N�Ƿ�Ϊ���������Ƚ�N-1�ֽ�Ϊ(2^s)*d����ÿ�β��Կ�ʼʱ��
    �����ѡһ������[1,N-1]������a����������е�r����[0,s-1]������a^d mod N != 1��
    a^((2^r)*d) mod N != -1�����Ǻ���������N��3/4�ļ���Ϊ������Ϊ����߲��Ե���ȷ
    �ԣ�����ѡ��ͬ��a���ж�β��ԡ�
*���ӿڡ���
    bool isPrime(int N);
    ���Ӷȣ�O(log N)
    ���룺N    �����Ե�����
    �����FALSE��ʾNΪ������TRUE��ʾN�кܴ���Ϊ������
*�������ⲿ��������
    ������
*�����롿
*/

bool test(int n,int a,int d){
    if(n == 2)return true;
    if(n == a)return true;
    if((n&1) == 0)return false;
    while(!(d&1))d=d >> 1;
    int t = pow_mod(a,d,n);
    while((d != n-1) && (t != 1) && (t != n-1)){
        t = (long long)t * t % n;
        d = d << 1;
    }
    return (t == n-1 || (d&1) == 1);
}

bool isPrime(int n){
    if(n < 2)return false;
    int a[] = {2,3,61}; //���Լ�������Ĳ��Է�Χ��Ҫ����Ĳ��Լ�
    for(int i = 0;i <= 2; ++ i)
        if(!test(n,a[i],n-1))return false;
    return true;
}

int main(){

    return 0;
}
