unsigned Power(unsigned n,unsigned p)
{
   unsigned main=n; //��main������
   unsigned odd=1; //odd�������㡰ʣ�µġ��˻�
   while( p > 1){//һֱ���㣬ֱ��ָ��С�ڻ����1
    // ���ָ��p����������˵��������ʣһ�������������ô����������˵������
        if((p % 2) != 0)odd*=main; //�ѡ�ʣ�µġ�������
        main*=main; //����˷�
        p/=2; //ָ������2
   }
   return main*odd; //��������͡�ʣ�µġ���������Ϊ���
}

int main(){

    return 0;
}
