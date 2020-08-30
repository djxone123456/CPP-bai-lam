#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define INF INT_MAX
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

using namespace std;

typedef pair <int, int> pi;
typedef long long ll;
typedef unsigned long long ull;

int mod = 2017, n,m, k, f[50][200000];
vector <int> G[100];

int trau(int u, int path)
{
    if(path > k)
    {
        return (u == n);
    }
    if(G[u].empty()) return 0;

    int &res = f[u][path];
    if(res != -1) return res;
    res = 0;

    for(int v : G[u])
    {
        res = (res + trau(v, path + 1)) % mod;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    #endif
    freopen("cpath.inp","r",stdin);
    freopen("cpath.out","w",stdout);

    cin>>n>>m>>k;

    for(int i = 1;i<=m;i++)
    {
        int x, y;
        cin>>x>>y;

        G[x].push_back(y);
    }

    memset(f, 255, sizeof(f));

    cout<<trau(1, 1);

    return 0;
}

















