#include <iostream>
#include <string>

using namespace std;

string bigIntMul(string a,string b)
{
    string c="0",d="0",t;
    int aL,bL,LL,resultL;
    int i,j,k,g,count,jinwei;
    int A[10000],B[10000],result[10000];
    if(a.length()<b.length())
    {
        t=a;
        a=b;
        b=t;
    }
    aL=a.length();
    bL=b.length();
    resultL=aL+bL+1;
//�������󳤶ȳ�ʼ���������
    for(i=0; i<resultL; i++)
        result[i]=0;
    for(i=0; i<aL; i++)                     // ��
        A[i]=a[i]-'0';                      // ��
    for(i=0; i<bL; i++)                     // a
        B[i]=b[i]-'0';                      // b
    for(i=resultL-1; i>=resultL-aL; i--)    // ��
        A[i]=A[i-(resultL-aL)];             // ת
    for(i=0; i<resultL-aL; i++)             // ��
        A[i]=0;                             // ��
    for(i=resultL-1; i>=resultL-bL; i--)    // ��
        B[i]=B[i-(resultL-bL)];             // ��
    for(i=0; i<resultL-bL; i++)             // ��
        B[i]=0;                             //
//��ʼ���˷�������ѭ����b ��ѭ������ a ��ѭ�������ν�����˱����� result ��
    for(i=resultL-1; i>=resultL-bL; i--)
    {
        g=i;
        jinwei=0;
        for(j=resultL-1; j>=resultL-aL; j--)
        {
            result[g]=B[i]*A[j]+result[g]+jinwei;
            jinwei=result[g]/10;
            result[g]=result[g]%10;
            g--;
        }
        if(jinwei>0) result[g]=result[g]+jinwei;
    }
    count=0;
    for(i=0; i<resultL; i++)
    {
        if(result[i]!=0) break;
        else count++;
    }
    for(i=0; i<resultL-count; i++)
    {
        result[i]=result[i+count];
    }
    for(i=1; i<resultL-count; i++)
        c=c+d;
    for(i=0; i<resultL-count; i++)
        c[i]=result[i]+'0';
    return c;
}
int main()
{
    return 0;
}
