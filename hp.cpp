#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define INF INT_MAX
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pi;
typedef unsigned long long ull;

ll mod,n,a[100005], s1[100003], s2[100004];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    #endif

    cin>>n>>mod;

    if(n < 3)
    {
        cout<<0;
        return 0;
    }

    for(ll i = 1;i<=n;i++)
        cin>>a[i];

    s1[n] = s2[n - 1] = 0;

    for(ll i = n - 1;i>= 1;i--)
        s1[i] = (s1[i + 1] + a[i + 1]) % mod;

    for(ll i = n - 2;i>=1;i--)
        {
            s2[i] = ((a[i + 1] * s1[i + 1]) + s2[i + 1]) % mod;
        }

    ll res = 0;

    for(ll i = 1;i<=n - 2;i++)
        res = (res + a[i] * s2[i]) % mod;

    cout<<res;

    return 0;
}

















