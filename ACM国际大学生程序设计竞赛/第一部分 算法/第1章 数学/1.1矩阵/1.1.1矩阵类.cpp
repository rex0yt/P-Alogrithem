/**
 *������
 *      ʵ�־���Ļ����任
 *���ӿڡ�
 *      �ṹ�壺Matrix
 *      ��Ա������
 *          int n,m         ����Ĵ�С
 *          int a[][]       ���������
 *      �����������+  ��  *
 *      ��Ա������
 *          void clear()    ��վ���
 */

#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 1000;
const int MAXM = 1000;
struct Matrix{
    int n,m;
    int a[MAXN][MAXM];
    void clear(){
        n=m=0;
        memset(a, 0, sizeof(a));
    }
    Matrix operator +(const Matrix &b) const{
        Matrix tmp;
        tmp.n=n;tmp.m=m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                tmp.a[i][j]=a[i][j]+b.a[i][j];
        return tmp;
    }
    Matrix operator -(const Matrix &b) const{
        Matrix tmp;
        tmp.n=n;tmp.m=m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                tmp.a[i][j]=a[i][j]-b.a[i][j];
        return tmp;
    }
    Matrix operator *(const Matrix &b) const{
        Matrix tmp;
        tmp.clear();
        tmp.n=n;tmp.m=m;
        for(int i=0;i<n;i++)
            for(int j=0;j<b.m;j++)
                for(int k=0;k<m;k++)
                    tmp.a[i][j]+=a[i][k]*b.a[i][j];
        return tmp;
    }
};
int main(){

    return 0;
}
