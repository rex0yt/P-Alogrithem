#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct node
{
    int lc,rc;
    int s;
} tree[101];
    //i-j����������
    //iΪ�ڵ���j��֦������ֵ
int apple[101][101],f[101][101];
int  v[101];//���ʱ�־
int n,q;

void dfs(int k){
    int i;
    v[k]=0;
    for (i=1;i<=n;i++)
        if (v[i] && apple[k][i]!=-1){//û�з������븸������
            if (tree[k].lc==0) tree[k].lc=i;
            else tree[k].rc=i;//����� ����˭����û��ϵ ��ʵֻ��Ϊ�˽���
            tree[i].s=apple[k][i];//���Ӽ̳и��� Ϊ����dp������׼��
            dfs(i);
        }
}

int dp_max(int t,int k){
    int i,ls,lt,rs;
    if (f[t][k]!=-1) return f[t][k];//��Ϊ���Ե�����dp ǰ��ıض�����
    if (t==0 || k==0){//�ֵ�֦���Ѿ�û�л��Ѿ���Ҷ�ӽڵ�
        f[t][k]=0;
        return 0;
    }
    f[t][k]=0;
    for ( i=0;i<=k-1;i++){//ö�����Һ��Ӹ�ȡ����֦�����ﵽ������ֵ��
        ls=dp_max(tree[t].lc,i);
        rs=dp_max(tree[t].rc,k-1-i);
        if (f[t][k]<ls+rs) f[t][k]=ls+rs;
    }
    f[t][k]+=tree[t].s;//����ʱ����ҲҪ�㡣
    return f[t][k];
}

int main(){

    cin >> n >> q;
    memset(apple,-1,sizeof(apple));
    int a,b,c;
    for (int i=2;i<=n;i++){
        cin >> a >> b >> c;
        apple[a][b]=c;apple[b][a]=c;
    }
    memset(v,true,sizeof(v));
    memset(tree,0,sizeof(tree));
    dfs(1);
    memset(f,-1,sizeof(f));
    int ans=dp_max(1,q+1);
    cout << ans;
    return 0;
}
