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

ll a[100005], n, sum, k, f[1000][1000];

ll trau(ll pos, ll page)
{
    if(pos > n && page == 0) return 0;

    if(page == 0) return -INF;

    ll &res = f[pos][page];
    if(res != -1) return res;
    res = 0;

    ll sumx = 0, maxn = -1, sl = sum;

    for(ll i = pos;i<=n;i++)
    {
        if(a[i] + sumx <= sl)
        {
            maxn = max(maxn, a[i]);
            sumx += a[i];
            res = max(res, trau(i + 1, page - 1) + maxn);
        }
        else break;
    }

    return res;
}

void sub1()
{
    ll q;
    cin>>q;

    while(q--)
    {
        cin>>sum;

        ll pos = 1;
        ll cnt = 0;

        while(pos <= n)
        {
            ll maxn = 0;
            for(pos; pos <=n ;pos++)
               if(a[pos] + maxn <= sum) maxn += a[pos];
               else break;

            cnt++;
        }

        k = cnt;

        memset(f, 255, sizeof(f));

        cout<<cnt<<' '<<trau(1, cnt)<<endl;
    }
}

void sub2()
{
    ll q;
    cin>>q;

    while(q--)
    {
        cin>>sum;

        ll pos = 1, maxx = 0;
        ll cnt = 0;

        while(pos <= n)
        {
            ll maxn = 0, maxq = -INF;
            for(pos; pos <=n ;pos++)
               if(a[pos] + maxn <= sum)
               {
                   maxn += a[pos];
                   maxq = max(maxq, a[pos]);
               }
               else break;

            maxx += maxq;
            cnt++;
        }

        k = cnt;

        cout<<cnt<<' '<<maxx<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    #endif

    cin>>n;

    for(ll i = 1;i<=n;i++)
        cin>>a[i];

    if(n <= 1000)
        {
            sub1();
        }
    else
    {
        sub2();
    }

    return 0;
}

















