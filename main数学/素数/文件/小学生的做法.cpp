bool IsPrime(unsigned n){
    //С��2���������Ǻ���Ҳ��������
    if(n < 2)throw 0;
    // �ͱ�����һ��С��������������������֤������
    for(unsigned i = 2; i < n / 2 + 1; ++ i)
        if ( 0 == n % i )return false;

    return true;
}

