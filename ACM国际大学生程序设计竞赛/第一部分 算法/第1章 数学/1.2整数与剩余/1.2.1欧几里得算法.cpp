#include <iostream>

using namespace std;

/*�����񡿣�
    ��������a��b�����Լ��gcd(a,b)��
*��˵������
    �б��涨��ã�gcd(a,b)=gcd(b,a-b),���У�a>=b��ͨ���������ϵĵ�����ֱ��
    b=0,a����ԭ�����Ե����Լ�������ǵ�ֻʹ�ü����ᳬʱ�����ǹ۲쵽���
    a-b��Ȼ����b�Ļ���Ҫ����һ��ͬ���Ĳ������Ͱ�a��������bΪֹ��������gcd(a,b)
    =gcd(b,a mod b)���ɴ˿�����log��ʱ���������������gcd��
*���ӿڡ�
    int gcd(int a,int b);
    ���Ӷȣ�O(logN),����N��a��bͬ�ס�
    ���룺a��b      ��������
    �����a��b�����Լ��
*/

int gcd(int a,int b){
    return b==0 ? a :gcd(b,a%b);
}

int main(){
    return 0;
}
