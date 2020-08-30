#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define INF INT_MAX
#define MOD 1000000007
#define BTtin "TRIP"

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pi;
typedef unsigned long long ull;

ll n,a[1000000];

ll trau(ll pos, set <ll> s, int st)
{
    if(pos > n)
    {
        return 0;
    }
    ll res = 0;

    s.insert(a[pos]);

    res = trau()
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen(BTtin".inp","r",stdin);
    freopen(BTtin".out","w",stdout);

    cin>>n;

    for(ll i = 1;i<=n;i++)
    {
        cin>>a[i];
    }

    ll res = 0;

    for(ll i = 1;i<n;i++)
    {
        set <ll> xau;
        res += trau(i, xau, a[i]);
    }

    cout<<res;
    return 0;
}


















