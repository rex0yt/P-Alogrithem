//����ͼ�� 
class Graph{
public:
	Graph(){}
	Graph(int n){
		matrix=new int*[n];
		for(int i=0;i<n;i++){
			matrix[i]=new int[i+1];
		}
	}
 	void setEdge(int i,int j,int val);
 	int getEdge(int i,int j);
private:
	int **matrix;
};
void Graph::setEdge(int i,int j,int val){
 	int temp;
 	if(i<j){temp=i;i=j;j=temp;}//����i��j��ֵ
 	matrix[i][j]=val;
}
int Graph::getEdge(int i,int j){
 	int temp;
 	if(i<j){temp=i;i=j;j=temp;}//����i��j��ֵ 
 	return matrix[i][j];
}
