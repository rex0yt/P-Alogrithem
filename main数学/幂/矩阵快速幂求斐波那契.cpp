#include<bits/stdc++.h>

using namespace std;

class bignumber
{
    vector<int> num;
public:
    bignumber(int n = 0);
    void clr();
    bignumber operator+ (const bignumber &left);
    void operator= (const bignumber &left);
    int getNumI(int i);
    int getNumSize();

};

bignumber a11(1), a12(1), a21(1), a22(0);
bignumber b11(1), b12(1), b21(1), b22(0);

void mat(int n)
{
    while(n--)
    {
        b11=a11+a12;
        b12=a11;
        b21=a21+a22;
        b22=a21;
        a11=b11;
        a12=b12;
        a21=b21;
        a22=b22;
    }
    return ;
}
int main()
{
    int n;
    cin >> n;
    mat(n-2);
    for(int i=a11.getNumSize()-1; i>=0; i--)
        cout << a11.getNumI(i);
    cout << endl;

    return 0;
}

void bignumber::clr()
{
    num.clear();
}
bignumber bignumber::operator+ (const bignumber &left)
{
    if(num.size()==0)return left;
    if(left.num.size()==0)return *this;
    bignumber tmp(0);
    bignumber minnum(0);
    if(num.size()>left.num.size())
    {
        tmp = *this;
        minnum = left;
    }
    else
    {
        tmp = left;
        minnum = *this;
    }
    for(int i=0; i<minnum.num.size(); i++)
    {
        tmp.num[i] += minnum.num[i];
    }
    for(int i=0; i<tmp.num.size()-1; i++)
    {
        if(tmp.num[i]>=10)
        {
            tmp.num[i+1] ++;
            tmp.num[i] -= 10;
        }
    }
    if(tmp.num[tmp.num.size()-1]>10)
    {
        tmp.num[tmp.num.size()-1] -= 10;
        tmp.num.resize(tmp.num.size()+1);
        tmp.num[tmp.num.size()-1] ++;
    }
    return tmp;
}
bignumber::bignumber(int n)
{
    num.clear();
    while(n)
    {
        num.push_back(n % 10);
        n /= 10;
    }
}
int bignumber::getNumI(int i)
{
    return num[i];
}
int bignumber::getNumSize()
{
    return num.size();
}
void bignumber::operator= (const bignumber &left)
{
    this->num.resize(left.num.size());
    for(int i=0; i<num.size(); i++)
    {
        num[i] = left.num[i];
    }
}
