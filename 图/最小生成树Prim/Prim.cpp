#include"Graph.h"
#define INFINITE INT_MAX
#include<iostream>
using namespace std;
int main(int argc,char **argv){
	int i,j,k,n;
 	cout<<"�����붨����:";
 	cin>>n;
 	Graph *g=new Graph(n);
//��ͼ
 	cout <<"�����������ͼ�������Ǿ���(-1��ʾ�ޱ�����):"<<endl;
 	for(i=0;i<n;i++){
  		for(j=0;j<=i;j++){
   			int tempInput;
   			cin>>tempInput;
   			if(tempInput==-1)tempInput=INFINITE;
   			g->setEdge(i,j,tempInput);
  		}
 	}
//��̬��������u
 	int **u=new int*[n];
 	for(i=0;i<n;i++){
  		u[i]=new int[3];
  	//u�����ʼ��
  		u[i][0]=0;//�洢��i��������һ�ڵ�ı��j
  		u[i][1]=INFINITE;
  		u[i][2]=0;//0��ʾûѡΪu�������棬����Ϊ1
 	}	
 	u[0][2]=1;//�ӵ�һ����ʼѡ����һ��Ĭ��ѡ��u����
//��ʼ����
 	cout<<endl<<"����Prim�������С������:"<<endl;
 	int shortest=INFINITE;
 	int index[2]={0,0};
 	for(k=0;k<n;k++){
  		shortest=INFINITE;
  		index[0]=-1;
  		index[1]=-1;
  		for(i=0;i<n;i++){//�ҳ���u�ж�����������С����
   			if(u[i][2]==1){//��һ������u����
    			for(j=0;j<n;j++){//�ҵ���i����С�ı�
     				if(u[j][2]==0&&g->getEdge(i,j)<INFINITE){//�ö��㲻��u���沢�Ҹñߴ���
				       	if(u[i][1]>g->getEdge(i,j)){//�ñߵ�ֵС�ڵ�ǰ��Сֵ
				        	u[i][0]=j;
				        	u[i][1]=g->getEdge(i,j);
				       	}
				       	if(shortest>g->getEdge(i,j)){
					        shortest=g->getEdge(i,j);
					        index[0]=i;//��¼��ǰ��̵ıߵ�������
					        index[1]=j;
				       	}
     				}
    			}
   			}
  		}
		if(index[0]>=0){
			u[index[1]][0]=index[0];
			u[index[1]][1]=shortest;
			u[index[1]][2]=1;
			cout<<"<"<<(char)('a'+index[0])<<">"<<"--"
				<<shortest<<"--"<<"<"<<(char)('a'+index[1])<<">"<<endl;
		}
 	}
 	cout<<endl<<"����һ�������ʽΪ:"<<endl;
 	for(i=0;i<n;i++){
  		cout<<"<"<<i+1<<">"<<"--"
		  	<<g->getEdge(i,u[i][0])<<"--"<<"<"<<u[i][0]+1<<">"<<endl;
 	}
 	return 0;
}
