// ���ټ���(n ^ e) % m��ֵ����power�㷨������
unsigned Montgomery(unsigned n, unsigned p, unsigned m){
    unsigned r = n % m; // �����r�ɲ���ʡ
    unsigned k = 1;
    while (p > 1){
        if ((p & 1)!=0)k = (k * r) % m; // ֱ��ȡģ
        r = (r * r) % m; // ͬ��
        p /= 2;
    }
    return (r * k) % m; // ����ͬ��
}

int main(){
    return 0;
}
