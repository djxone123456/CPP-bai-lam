//Dai Ca Di Hoc
#include <bits/stdc++.h>

#define pb push_back
#define maxn 100005

using namespace std;

int n, m, res = 0, current = 0, maxN = 0;
vector <int> a[maxn];
int mx[maxn], Used[maxn], b[1001][1001];
vector<int> arr;

bool dfs(int u){
    if (Used[u] == current)
        return 0;
    Used[u] = current;
    for (int v : a[u])
    {
        if(b[u][v] < m) continue;
        if (mx[v] == 0){
            mx[v] = u;
            return 1;
        }

        if(dfs(mx[v]))
        {
            mx[v] = u;
            return 1;
        }
    }

    return 0;
}

set<int> _arr;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	#ifdef hello
	freopen("debug.inp", "r", stdin);
	freopen("debug.out", "w", stdout);
	#endif // hello

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        for(int j = n + 1; j <= n * 2; j++)
        {
            cin >> b[i][j];
            b[j][i] = b[i][j];
            _arr.insert(b[i][j]);

            a[i].pb(j);
            a[j].pb(i);
        }
    }

    for(set<int>::iterator it = _arr.begin(); it != _arr.end(); it++)
        arr.pb(*it);

    int l = 0, r = arr.size() - 1;

    while(l <= r)
    {
        memset(mx, 0, sizeof(mx));
        memset(Used, 0, sizeof(Used));

        int mid = (l + r) / 2;
        m = arr[mid];

        res = 0;

        for (current = n; current >= 1; current--)
            res += dfs(current);

        if(res == n)
        {
            maxN = m;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << maxN;

    return 0;
}
