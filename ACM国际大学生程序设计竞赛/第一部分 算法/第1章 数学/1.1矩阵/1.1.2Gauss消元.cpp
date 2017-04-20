/**
 *������
 *      ��һ��nԪһ�η����飬�����ǵĽ⼯
 *��˵����
 *      �����������ɾ�����ʽ�����������ֳ��ȱ任���õ��������Σ����ش��õ��⼯
 *���ӿڡ�
 *      int solve(double a[][MAXN],bool l[],double ans[],ocnst int &n);
 *      ���Ӷ�
 *          O(n^3)
 *      ����
 *          a       �������Ӧ�ľ���
 *          n       δ֪������
 *          l��ans   ����⣬l[]��ʾ�Ƿ�Ϊ����Ԫ
 *      ���
 *          ��ռ��ά��
 */

#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 1000;
const int EPS = 1;

inline int solve(double a[][MAXN],bool l[],double ans[],const int &n){
    int res = 0, r = 0;
    for(int i=0;i<n;i++)l[i]=false;
    for(int i=0;i<n;i++){
        for(int j=r;j<n;j++)
            if(fabs(a[j][i]) < EPS){
                for(int k=i;k<n;++k)
                    swap(a[j][k],a[r][k]);
                break;
            }
        if(fabs(a[r][i]<EPS)){
            ++res;
            continue;
        }
        for(int j=0;j<n;j++)
            if(j!=r && fabs(a[i][j])>EPS){
                double tmp = a[j][i] / a[r][i];
                for(int k=i;k<n;k++)
                    a[j][k]-=tmp*a[r][k];
            }
        l[i]=true,++r;
    }
    for(int i=0;i < n; i ++)
        if(l[i])
            for(int j=0;j < n; j ++)
                if(fabs(a[j][i]) > 0)
                    ans[i] = a[j][n] / a[j][i];
    return res;
}
int main(){

    return 0;
}
