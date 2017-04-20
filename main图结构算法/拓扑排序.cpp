#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int N = 500 + 10;

int m, n;
vector <int> arr[N];
bool f[N];
int deg[N];

int main()
{
    int i, j;
    int p1, p2;
    int h;

    while(cin >> n >> m)
    {
        memset(f, 0, N*sizeof(bool));
        memset(deg, 0, N*sizeof(int));
        for(i=0; i<N; i++)arr[i].clear();
        while(m --)
        {
            cin >> p1 >> p2;
            arr[p1].push_back(p2);
            deg[p2] ++;
        }
        h = n;
        while(h --)
        {
            for(i=1; i<=n; i++)
            {
                if(deg[i]==0 && f[i]==0)break;
            }

            cout << i;
            if(h)cout << " ";
            f[i] = 1;
            for(j=0; j<arr[i].size(); j ++)
            {
                deg[arr[i][j]] --;
            }
        }
        cout << endl;
    }
    return 0;
}
