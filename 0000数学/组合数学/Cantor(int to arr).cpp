/*  康托展开 及其 逆运算
*
*/
#include <bits/stdc++.h>
#define N 1000
using namespace std;

const long long fac[25] = {/*阶乘数组 下标范围0..20*/
1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,
479001600,6227020800,87178291200,1307674368000,20922789888000,
355687428096000,6402373705728000,121645100408832000,2432902008176640000};                   /*阶乘数组*/

int a[N] = {1,2,3,5,4};

long long Cantor(int *a, int n)
{
    int s;
    long long sum = 0;                  /*康托展开*/
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
    bool vis[n + 1];            /*判断数字是否使用过*/
    int *arr;               /*保存结果*/
    int res;
    int p = 0;
    arr = new int[n + 1];
    memset(vis, 0, sizeof(vis));
    order --;
    for(int i=n-1; i>0; i--)
    {
        res = order / fac[i];
        res ++;
        while(vis[res])res++;
        arr[p ++] = res;
        order %= fac[i];
        vis[res] = 1;
    }
    res = 1;
    while(vis[res])res++;
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
