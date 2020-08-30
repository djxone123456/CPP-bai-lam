#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define endl '\n'
#define INF INT_MAX
#define MOD 1000000007
#define pie "DEM"


using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pi;

ll n, dd[3000][3000];
ull f[3000][3000];

ull trau(ll pos, ll prev)
{
    if(pos == n)
    {
        return 1;
    }

    ull &res = f[pos][prev];
    if(dd[pos][prev] != 0) return res;
    dd[pos][prev] = 1;
    res = 0;

    for(ll i = prev + 1;i<n;i++)
    {
        if(pos + i > n) break;
        res += trau(pos + i, i);
    }
    return res;
}

int main()
{
    freopen(pie".inp", "r",stdin);
    freopen(pie".out", "w",stdout);

    cin>>n;

    memset(dd, 0, sizeof(dd));

    cout<<trau(0, 0);

    return 0;
}
