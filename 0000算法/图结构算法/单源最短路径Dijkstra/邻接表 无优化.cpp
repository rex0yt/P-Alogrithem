#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 10;
const int maxint = 0xfffffff;

struct node
{
    int fnlpnt, len;
};

int m, n;
vector <node> imap[MAXN];
int dis[MAXN],vis[MAXN];

int* Dijkstra(int srcpnt)
{
    int Min, pnt;
    memset(vis, 0, sizeof(vis));
    for(int i=0; i<=n; i++)dis[i] = maxint;
    for(int i=0; i<(int)imap[srcpnt].size(); i++)
        dis[imap[srcpnt][i].fnlpnt] = imap[srcpnt][i].len;
    vis[srcpnt] = 1;
    dis[srcpnt] = 0;

    for(int i=1; i<n; i++)
    {
        Min = maxint;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j] && Min>dis[j])
            {
                pnt = j;
                Min = dis[j];
            }
        }
        vis[pnt] = 1;

        for(int j=0; j<(int)imap[pnt].size(); j++)
        {
            if(!vis[imap[pnt][j].fnlpnt])
                dis[imap[pnt][j].fnlpnt] =
                    min(Min+imap[pnt][j].len, dis[imap[pnt][j].fnlpnt]);
        }
    }
    return dis;
}

int main()
{
    int x, y, z;
    node tmp;
    while(cin >> n >> m && (m || n))
    {
        while(m --)
        {
            cin >> x >> y >> z;
            tmp.len = z;
            tmp.fnlpnt = y;
            imap[x].push_back(tmp);
            tmp.fnlpnt = x;
            imap[y].push_back(tmp);
        }
        int *a = Dijkstra(1);
        cout << a[n] << endl;
        for(int i=0; i<MAXN; i++)imap[i].clear();
    }
    return 0;
}
