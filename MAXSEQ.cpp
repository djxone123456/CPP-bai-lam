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

ll n, a[1000000], maxx = -INF, v[1000000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("maxseq.inp","r",stdin);
    freopen("maxseq.out","w",stdout);

    cin>>n;

    for(ll i = 1;i<=n;i++)
    {
        cin>>a[i];
        maxx = max(maxx, a[i]);
    }

    v[1] = 1;
    ll cnt = 1;

    while(v[cnt] < maxx)
    {
        ++cnt;
        v[cnt] = v[cnt - 1] + cnt;
    }

    ll vt = 1, maxvt = 0;
    a[0] = -INF;

    for(ll i = 1;i<=n;i++)
    {
        if(a[i] >= a[i - 1] && binary_search(v + 1, v + cnt + 1, a[i]))
        {
            maxvt = max(maxvt, i - vt + 1);
        }
        else
        {
            vt = i;
            if(binary_search(v + 1, v + cnt + 1, a[i]))
            {
                maxvt = max(maxvt, i - vt + 1);
            }
            else vt++;
        }
    }

    cout<<maxvt;
    return 0;
}
