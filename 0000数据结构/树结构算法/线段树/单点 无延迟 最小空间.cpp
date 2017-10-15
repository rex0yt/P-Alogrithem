//***任意区间用[x,y)表示****
//还没完成版本//
//最省空间的版本//
//没有延迟修改//

using namespace std;

#include <iostream>
#include <cstdio>

#define MaxN (100000)
#define MaxSize (2*MaxN+100)

struct Node
{
    int Left, Right;//表示左右区间
    int data;

    Node() {data = 0;}
};

int n = 4;
Node SegmentTree[MaxSize];
int arr[MaxN];

int Mid(int left, int right)//(left+right) / 2
{
    return (left+right)>>1;
}

bool Diff(int a, int b)//whether a != b
{
    return a==b;
}

int Pos(int left, int right) //position of [left, right)
{
//    return ((left+right-1) | Diff(left, right-1));
    return ((left+right) | Diff(left, right));
}

void Travel(int left, int right) //Travel the Segment Tree
{
    int mid = Mid(left, right);
    int pos = Pos(left, right);

//    cout << pos << " " << left << " " << right << " " << endl;
    cout << left << " " << right << " " << SegmentTree[pos].data << endl;

    if (left+1 < right)
    {
        Travel(left, mid);
        Travel(mid, right);
    }
    return ;
}

int Build(int left, int right) //Build the Segment Tree
{
    int mid = Mid(left, right);
    int pos = Pos(left, right);

    SegmentTree[pos].Left = left;
    SegmentTree[pos].Right = right;

    if (left+1 < right)
    {
        SegmentTree[pos].data += Build(left, mid);
        SegmentTree[pos].data += Build(mid, right);
    }
    else  SegmentTree[pos].data = arr[left];
    return SegmentTree[pos].data;
}

int Query(int pos, int left, int right) //Query data of [left, right)
{
    int ans = 0;
    int _left = SegmentTree[pos].Left;
    int _right = SegmentTree[pos].Right;
    int _mid = Mid(_left, _right);

    if(_left<=left && right<=_right)
        ans = SegmentTree[pos].data;
    else
    {
        if(left < _mid)
            ans += Query(Pos(_left, _mid), left, right);
        if(_mid < right)
            ans += Query(Pos(_mid, _right), left, right);
    }
    return ans;
}

void Change(int pos, int x, int delta) //data[x] += delta
{
    int _left = SegmentTree[pos].Left;
    int _right = SegmentTree[pos].Right;
    int _mid = Mid(_left, _right);
    int leftChild = Pos(_left, _mid);
    int rightChild = Pos(_mid, _right);

    if (_left+1 == _right)
        SegmentTree[pos].data += delta;
    else
    {
        if(x < _mid)
            Change(leftChild, x, delta);
        if(x >= _mid)
            Change(rightChild, x, delta);
        SegmentTree[pos].data = SegmentTree[leftChild].data + SegmentTree[rightChild].data;
    }
    return ;
}

int main()
{
    freopen("data.txt", "r", stdin);

    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> arr[i];

    Build(1, n+1);
    int pos = Pos(1, n+1);
    Change(pos, 1, 2);
    Travel(1, n+1);

    fclose(stdin);
    return 0;
}
