#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define INF INT_MAX
#define PI 3.1415926535897932384626433832795
#define MOD 10000000000000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair <int, int> pi;
typedef pair <ll, ll> pl;
typedef unsigned long long ull;
typedef pair <pair<int, int>, int> pii;

vector<pl> G[5002];
ll m,n,dd[5002],cnt[5002];

void dijsktra()
{
    priority_queue<pl, vector<pl>, greater<pl>> pq;

    for(int i = 1;i<=n;i++)
    {
        dd[i] = INF;
    }
    dd[1] = 0;
    cnt[1] = 1;

    pq.push(pi(0, 1)); //weight - u

    while(!pq.empty())
    {
        int u = pq.top().second;
        ll du = pq.top().first;
        pq.pop();

        if(du != dd[u]) continue;

        for(pi lay : G[u])
        {
            int v = lay.second;
            ll uv = lay.first;

            if(dd[v] > du + uv)
                {
                    dd[v] = du + uv;
                    cnt[v] = cnt[u];
                    pq.push(pi(dd[v], v));
                }
                else
                    if(dd[v] == du + uv)
                      cnt[v] += cnt[u];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("BAI2CDT18.inp","r",stdin);
    freopen("BAI2CDT18.out","w",stdout);


    cin>>n>>m;

    while(m--)
    {
        int k,x,y,w;
        cin>>k>>x>>y>>w;

        if(k == 1)
        {
            G[x].push_back(pi(w, y));
        }
        else
        {
            G[x].push_back(pi(w, y));
            G[y].push_back(pi(w, x));
        }
    }

    dijsktra();

    cout<<cnt[n]<<' '<<dd[n];
    return 0;
}
