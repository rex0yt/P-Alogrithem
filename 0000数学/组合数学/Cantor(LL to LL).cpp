/*  ����չ�� ���� ������
*
*/
#include <bits/stdc++.h>
#define N 1000
#define CantorN 5

using namespace std;

typedef long long LL;

const LL fac[25] = {/*�׳����� �±귶Χ0..20*/
1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,
479001600,6227020800,87178291200,1307674368000,20922789888000,
355687428096000,6402373705728000,121645100408832000,2432902008176640000};                   /*�׳�����*/

const LL arr[11] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000};
//const LL arr[11] = {10000000000,1000000000,100000000,10000000,1000000,100000,10000,1000,100,10,1};


LL Cantor(LL &number)/*����չ��*/
{
    LL s, sum = 0;
    for(int i=0; i<CantorN-1; i++)
    {
        s = 0;
        for(int j=i+1; j<CantorN; j++)
        {
            if(number/arr[CantorN-i-1]%10 > number/arr[CantorN-j-1]%10)s++;
        }
        sum += s*fac[CantorN-1-i];
    }
    return sum + 1;
}

LL unCantor(LL order)
{
    bool vis[CantorN + 1];            /*�ж������Ƿ�ʹ�ù�*/
    int tmp[CantorN + 1];               /*������*/
    int res;
    int p = 0;
    memset(vis, 0, sizeof(vis));
    order --;
    for(int i=CantorN-1; i>0; i--)
    {
        res = order / fac[i];
        res ++;
        while(vis[res])res++;
        tmp[p ++] = res;
        order %= fac[i];
        vis[res] = 1;
    }
    res = 1;
    while(vis[res])res++;
    tmp[p] = res;
    LL ans = 0;
    for(int i=0; i<=p; i++)
    {
        ans *= 10;
        ans += tmp[i];
    }
    return ans;
}

int main()
{
    LL a = 45321;
//    cout << Cantor(a) << endl;
    cout << unCantor(96) << endl;


    return 0;
}
