#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define INF 99999999999999
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define endl '\n'
#define getBit(A, bit) ((A & 1 << bit) != 0)
#define turnOn(A, bit) (A |= 1 << bit)
#define turnOff(A, bit) (A &= ~(1 << bit))
#define BTtin "police"

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pi;
typedef unsigned long long ull;

ll n, c[100005], low[100005], num[100005], cnt = 0;
ll sum = 1,summin = 0;
vector <ll> G[100000];
stack <ll> vt;

void visit(ll u)
{
    low[u] = num[u] = ++cnt;

    vt.push(u);

    for(ll v : G[u])
    {
        if(num[v]) /// u da dc tham
        {
            low[u] = min(low[u], num[v]);
        }
        else
        {
            visit(v);

            low[u] = min(low[u], low[v]);
        }
    }

    if(low[u] == num[u]) /// u la chot
    {
        ll dem = 1, minn = INF;

        ll v;

        do
        {
            v = vt.top();

            vt.pop();

            if(minn > c[v])
            {
                minn = c[v];
                dem = 1;
            }
            else if(minn == c[v])
                dem++;

            low[v] = num[v] = INF;
        }
        while(u != v);

        summin += minn;
        sum = (sum * dem) % MOD;

    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen(BTtin".inp","r",stdin);
    freopen(BTtin".out","w",stdout);

    cin>>n;

    for(ll i = 1;i<=n;i++)
        cin>>c[i];

    ll m;

    cin>>m;

    while(m--)
    {
        ll x, y;
        cin>>x>>y;

        G[x].PB(y);
    }

    for(ll i = 1;i<=n;i++)
        num[i] = 0;

    for(ll i = 1;i<=n;i++)
    {
        if(!num[i]) visit(i);
    }

    cout<<summin<<' '<<sum;

    return 0;
}

