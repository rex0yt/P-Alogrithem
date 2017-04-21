/*  ����չ�� ���� ������
*
*/
#include <bits/stdc++.h>
#define N 1000
using namespace std;

const long long fac[25] = {/*�׳����� �±귶Χ0..20*/
1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,
479001600,6227020800,87178291200,1307674368000,20922789888000,
355687428096000,6402373705728000,121645100408832000,2432902008176640000};                   /*�׳�����*/

int a[N] = {5,2,3,4,1};

long long Cantor(int *a, int n)
{
    int s;
    long long sum = 0;                  /*����չ��*/
    for(int i=0; i<n-1; i++)
    {
        s = 0;
        for(int j=i+1; j<n; j++)
        {
            if(a[i]>a[j])s++;
        }
        sum += s*fac[n-1-i];
    }
    return sum + 1;
}
int* unCantor(long long order, int n)
{
    int un[n+1];            /*���鼯 �ж������Ƿ�ʹ�ù�*/
    int *arr;               /*������*/
    int res;
    int p = 0;
    arr = new int[n+1];
    for(int i=0; i<=n; i++) /*��ʼ�����鼯*/
    {
        un[i] = 0;
    }
    order --;
    for(int i=n-1; i>0; i--)
    {
        res = order / fac[i];
        while(un[res] != 0)res++;

        arr[p ++] = res + 1;
        order %= fac[i];
        un[res] = res;
    }
    res = 0;
    while(!un[res])res++;
    arr[p] = res;
    return arr;
}

int main()
{
    cout << Cantor(a, 5) << endl;
    int* p = unCantor(96, 5);

    for(int i=0; i<5; i++)
        cout << p[i] << " ";

    return 0;
}
