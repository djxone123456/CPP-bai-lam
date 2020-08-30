#include <bits/stdc++.h>

#define fi first
#define se second
#define MP make_pair
#define pb push_back
#define INF 999999999999999
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define endl '\n'
#define getBit(A, bit) ((A & 1 << bit) != 0)
#define turnOn(A, bit) (A |= 1 << bit)
#define turnOff(A, bit) (A &= ~(1 << bit))

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pi;
typedef unsigned long long ull;

ll dd[20001];
ll dg[20001], n;
vector<pi> G[20001];

void dijsktra(ll st)
{
    priority_queue<pi, vector<pi> , greater<pi>> pq;

    for(ll i = 0;i<=n;i++)
        {
            dd[i] = INF;
            dg[i] = 0;
        }

    dd[st] = 0;
    pq.push(pi(0LL, st));

    while(!pq.empty())
    {
        ll u = pq.top().se;
        ll du = pq.top().fi;
        pq.pop();

        if(dd[u] != du) continue;

        for(pi t : G[u])
        {
            ll v = t.se;
            ll uv = t.fi;
            ll cnt = 0;

            if(uv == MOD) cnt = 1; // Bo may thich the

            if(dd[v] > du + uv)
            {
                dd[v] = du + uv;
                dg[v] = dg[u] + cnt;
                pq.push(pi(dd[v], v));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("td.inp","r",stdin);
    freopen("td.out","w",stdout);

    ll k;

    cin>>n>>k;

    for(ll i = 1;i<=k;i++)
    {
        ll x,y;
        cin>>x>>y;

        G[x].pb(pi(MOD, y));
        G[y].pb(pi(MOD, x));
    }

    ll x,y,dai;
    while(cin>>x>>y>>dai)
    {
        G[x].pb(pi(dai, y));
        G[y].pb(pi(dai, x));
    }

    dijsktra(1);

    if(dd[n] - MOD * dg[n] == INF)
        cout<<-1;
    else
      cout<<dd[n] - MOD * dg[n]<<endl<<dg[n];

    return 0;
}
