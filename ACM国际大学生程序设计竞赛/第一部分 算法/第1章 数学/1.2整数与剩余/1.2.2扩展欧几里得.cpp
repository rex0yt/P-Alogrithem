#include <iostream>

using namespace std;

/*�����񡿣�
    ��������a��b�����Լ��gcd(a,b),�����x��y����ax+by=gcd(a,b)��
*��˵������
    Ҫ��x��y����ax+by=gcd(a,b)��
    ��b=0ʱ����x=1��y=0ʹ�õ�ʽ������
    ��b>0ʱ����ŷ������㷨�Ļ����ϣ���֪��
                gcd(a,b) = gcd(a,a mod b)
    �ȵݹ����x1��y1���㣺
                b*x1+(a mod b)*y1 = gcd(b,a mod b) = gcd(a,b)
    Ȼ����Ի��ƣ����ǽ���ʽ����ã�
                b*x1 + (a-a/b*b)*y1 = gcd(a,b)
                a*y1 + b*x1 - (a/b)*b*y1 = gcd(a,b)
    �������ָ�������Ѻ�b����ʽ��ȡһ��b���ɵã�
                a*y1 + b*(x1-a/b*y1) = gcd(a,b)
    ��x = y1, y = x1-a/b*y1��
*���ӿڡ�
    int extend_gcd(int a,int b,int &x,int &y);
    ���Ӷȣ�O(logN),����N��a��bͬ�ס�
    ���룺a��b      ��������
            &x,&y   ���ã�ax+by=gcd(a,b)��һ���
    �����a��b�����Լ��
    ���ú�x��y���㷽��ax+by=gcd(a,b)��
*/

int extend_gcd(int a,int b,int &x,int &y){
    if(b == 0){
        x = 1;y = 0;
        return a;
    }else{
        int r = extend_gcd(b,a%b,y,x);
        y -= x*(a/b);
        return r;
    }
}

int main(){
    return 0;
}
