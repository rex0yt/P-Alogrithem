#include <iostream>

using namespace std;

const int NN = 5000 + 10;

int father[NN];
int ranki[NN] = {0};
/*查找操作，返回父节点，顶结点*/
int find(int x)
{
    if(x != father[x])
        father[x] = find(father[x]);
    return father[x];
}
/*合并操作，路径压缩*/
void unioni(int x, int y)
{
    int r1 = find(x);
    int r2 = find(y);
    if(r1 == r2)return ;
    if(ranki[r1] < ranki[r2])
        father[r2] = r1;
    else{
        if(ranki[r1] < ranki[r2])
            ranki[r2] ++;
        father[r1] = r2;
    }
    return ;
}
/*初始化并查集，让每个元素指向自身，构成单独的集合*/
void init()
{
    for(int i = 0; i <= NN;i ++)
        father[i] = i;
    return ;
}

int main()
{
    /*测试，Relation 题解*/
    int m, n, p;
    int tmp1, tmp2;
    cin >> n >> m >> p;
    while(m --)
    {
        cin >> tmp1 >> tmp2;
        unioni(tmp1, tmp2);
    }
    while(p --)
    {
        cin >> tmp1 >> tmp2;
        if(find(tmp1) == find(tmp2))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
