#include <iostream>
#include <string>

using namespace std;

string bigintadd(string a,string b)
{
    string t,res="0";
    int numa[1000],numb[1000],result[1000],i,j;
    int la,lb,tt,left=0,jinwei=0;
    la=a.length();
    lb=b.length();
    if(la<lb) //make la the longst;
    {
        tt=la;
        la=lb;
        lb=tt;
        t=a;
        a=b;
        b=t;
    }
    for(i=1; i<=lb; i++)
    {
        numa[i]=a[i-1]-'0';
        numb[i]=b[i-1]-'0';
    }
    for(i=lb+1; i<=la; i++)
    {
        numa[i]=a[i-1]-'0';
    }
    for(i=la; i>la-lb; i--)
    {
        numb[i]=numb[i-la+lb];
    }
    numa[0]=numb[0]=0;
    for(i=1; i<=la-lb; i++)
    {
        numb[i]=0;
    }
    for(i=la; i>=0; i--)
    {
        result[i]=numa[i]+numb[i]+jinwei;
        jinwei=result[i]/10;
        left=result[i]%10;
        result[i]=left;
    }
    if(result[0]!=0) cout<<result[0];
    for(i=1; i<=la-1; i++)
        res=res+"0";
    for(i=1; i<=la; i++)
    {
        res[i-1]=result[i]+'0';
    }
    return res;
}
int main()
{
    return 0;
}
