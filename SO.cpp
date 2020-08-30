#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define endl '\n'
#define INF ll_MAX
#define MOD 1000000007
#define pie "SO"

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
bool getBit(ll A, ll bit) {return (A & (1LL << bit)) != 0;}

ll n, f[32][32][2][2];
string s;

ll trau(ll pos, ll k, ll isLess, ll isLead)
{
    if(k < 0) return 0;
    if(pos > n) return (k == 0);

    ll &res = f[pos][k][isLess][isLead];
    if(res != -1) return res;
    res = 0;

    ll lim = (ll)s[pos] - '0';
    if(isLess) lim = 1;

    for(ll i = 0;i<=lim;i++)
    {
        res += trau(pos + 1, k - (isLead && i == 0), isLess | (i < lim), isLead | i);
    }
    return res;
}

int main()
{
    freopen(pie".inp", "r",stdin);
    freopen(pie".out", "w",stdout);

    ll k;
    cin>> n>> k;

    ll isLead = 1;
    s = "0";

    for(ll i = 30;i>=0;i--)
    {
        if(getBit(n, i) == 1)
        {
            isLead = 0;
            s += "1";
        }
        else
        {
            if(!isLead) s += "0";
        }
    }
    n = s.size() - 1;

    memset(f, 255, sizeof(f));

    cout<<trau(1, k, 0, 0) + 1;

    return 0;
}
