/// Hí ae :3
#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define INF INT_MAX
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define endl '\n'
#define getBit(A, bit) ((A & 1ll << bit) != 0)
#define turnOn(A, bit) (A |= 1ll << bit)
#define turnOff(A, bit) (A &= ~(1ll << bit))

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pi;
typedef unsigned long long ull;

int n, isOK[50000], mainsum = 0, curr = 0;
vector<pi> G[50001];

int dfs(int u, int par, int sum)
{
    if(isOK[u] == curr)
    {
        mainsum += sum;
        sum = 0;
    }

    int res = 0;

    for(pi d: G[u])
    {
        int v = d.second;
        int w = d.first;

        if(v == par) continue;

        res += dfs(v, u, sum + w);

        if(res > 1)
        {
            mainsum -= sum;
            res--;
        }
    }

    return (res | isOK[u]);
}

void query()
{
    int dis[5];
    mainsum = 0;
    curr++;

    for(int i = 0; i < 5; i++)
    {
        cin >> dis[i];
        isOK[dis[i]] = curr;
    }

    dfs(dis[0], dis[0], 0);

    cout << mainsum << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("tree.inp","r",stdin);
    freopen("tree.out","w",stdout);

    cin >> n;

    for(int i = 1; i < n; i++)
    {
        int u, v, w;

        cin >> u >> v >> w;

        G[u].pb(pi(w, v));
        G[v].pb(pi(w, u));
    }

    int t;

    cin >> t;

    while(t--)
    {
        query();
    }

    return 0;
}
