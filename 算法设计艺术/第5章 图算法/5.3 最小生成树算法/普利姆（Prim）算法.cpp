void Prim(int n,int u0,int C[n][n]){//�������n,��ʼ����u0,��Ȩ�ڽӾ���C[n][n] 
//���s[i]=ture,˵������i�Ѽ�����С�������Ķ��㼯��U;���򶥵�i���ڼ���V-U
	bool s[n];
	int closest[n];
	double lowcost[n];
	s[u0]=1;					//��ʼʱ,����U��ֻ��һ��Ԫ�� 
	for(int i=0;i<n;i++){
		if(i!=u0){
			lowcost[i]=C[u0][i];
			closest[i]=u0;
			s[i]=false;
		}
	}
	for(int i=0;i<n;i++){			//�ڼ���V-U��Ѱ�Ҿ��뼯��U����Ķ��㲢���� 
								//lowcost��closest 
		double temp=INF;		//temp��ʼ��Ϊ����� 
		int t=u0;
		for(int j=0;j<n;i++){	//�ڼ���V-U��Ѱ�Ҿ��뼯��U����Ķ���t 
			if((!s[j])&&(lowcost[j]<temp)){
				t=j;
				temp=lowcost[j];
			}
		}
		if(t==u0)
			break;				//�Ҳ���t,����ѭ�� 
		s[t]=true;				//����,��t���뼯��U 
		for(j=0;j<n;j++){		//����lowcost��closest 
			if((!s[j])&&(C[t][j]<lowcost[j])){
				lowcost[j]=C[t][j];
				closest[j]=t;
			}
		} 
	}
}
