#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define INF INT_MAX
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

ll n, a[101][101], dd[101][101], f[101][101];

ll trau(ll x, ll y)
{
    if(x == n && y == n)
        return a[x][y];

    ll &res = f[x][y];
    if(dd[x][y] != 0) return res;
    dd[x][y] = 1;
    res = INF;

    if(x + 1 <= n)
        res = min(res, trau(x + 1, y) + a[x][y]);
    if(y + 1 <= n)
        res = min(res, trau(x, y + 1) + a[x][y]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("duongdi.inp","r",stdin);
    freopen("duongdi.out","w",stdout);

    cin>>n;

    for(ll i = 1;i<=n;i++)
        for(ll j = 1;j<=n;j++)
           cin>>a[i][j];

    memset(f, 255, sizeof(f));

    cout<<trau(1, 1);

    return 0;
}
