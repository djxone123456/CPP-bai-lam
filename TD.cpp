#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define endl '\n'
#define INF INT_MAX
#define MOD 1000000007
#define pie "TD"

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

vector<pi> G[10000];
vector<ll> song[10000];

ll n,k,dd[10000], cc[10000];

void dijsktra(int st)
{
    priority_queue<pi, vector<pi>, greater<pi>> pq;

    for(int i = 1;i<=n;i++)
    {
        dd[i] = INF;
        cc[i] = 0;
    }
    dd[st] = 0;

    pq.push(pi(0, st)); //weight - u

    while(!pq.empty())
    {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();

        if(du != dd[u]) continue;

        int ok = 0;
        for(pi lay : G[u])
        {
            ok = 1;
            int v = lay.second;
            int uv = lay.first;

            if(dd[v] > du + uv)
                {
                    dd[v] = du + uv;
                    pq.push(pi(dd[v], v));
                }
        }

        if(!ok)
        {
            for(int v : song[u])
            {
                if(dd[v] > du)
                    {
                        dd[v] = du;
                        pq.push(pi(dd[v], v));
                        cc[v]++;
                    }
            }
        }
    }
}

int main()
{
    freopen(pie".inp", "r",stdin);
    freopen(pie".out", "w",stdout);

    cin>>n>>k;

    for(ll i = 1;i<=k;i++)
    {
        ll x, y;
        cin>>x>>y;

        song[x].pb(y);
        song[y].pb(x);
    }

    ll x;
    while(cin>>x)
    {
        ll y,z;
        cin>>y>>z;

        G[x].pb(pi(z, y));
        G[y].pb(pi(z, x));
    }

    dijsktra(1);

    cout<<dd[n]<<endl<<cc[n];

    return 0;
}
