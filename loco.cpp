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

ll m,n, f[10000000];

int trau(int pos)
{
    if(pos > n) return 0;
    if(pos == n) return 1;

    ll &res = f[pos];
    if(res != -1) return res;
    res = 0;

    for(int i = 1;i<=min(3LL, n - pos);i++)
    {
        res = (res + trau(pos + i)) % m;
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

    freopen("loco.inp","r",stdin);
    freopen("loco.out","w",stdout);

    cin>>n>>m;

    memset(f, 255, sizeof(f));

    cout<<trau(0);

    return 0;
}

















