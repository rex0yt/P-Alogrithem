bool IsPrime(unsigned n){
     //С��2���������Ǻ���Ҳ��������
    if(n < 2)throw 0;
    //�ͱ���С�����е���������������������֤������
    for (unsigned i = 2; i < n; ++ i){
        //�����ˣ����Ǻ���
        if (n % i == 0)
            return false;
    }
    return true;
}

