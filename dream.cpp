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

ll k,n, f[10000000], dd[1003];

struct matrix
{
    vector <vector <ll> > val;

    void nhan2(vector <ll> a)
    {
        for(int i = 0;i<a.size();i++)
          val.push_back({a[i]});
    }

    void nhan1(vector <vector <ll> > a)
    {
        val.clear();

        for(int i = 0;i<a.size();i++)
            val.push_back(a[i]);
    }

    matrix operator * (const matrix &B)
    {
        matrix C;
        for (int i = 0; i <= 100; i++)
            for (int j = 0; j <= 100; j++)
            {
                for (int k = 0; k <= 100; k++)
                    C.val[i][j] = (C.val[i][j] + (ll)val[i][k] * B.val[k][j]) % MOD;
            }
        return C;
    }

    matrix power(ll x)
    {
        matrix C;

        for (int i = 1; i <= 2; i++)
            C.val[i][i] = 1;

        if (x == 0) return C;
        matrix B = power(x/2);
        C = B*B;

        if (x % 2 == 1) C = C * (*this);
        return C;
    }
} n1, n2;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    #endif

    freopen("dream.inp","r",stdin);
    freopen("dream.out","w",stdout);

    cin>>n>>k;

    fill(dd, dd + 101, 0);

    for(ll i = 1;i<=n;i++)
        {
            ll a;
            cin>>a;

            dd[a]++;
        }

    vector <vector<ll>> tt;

    tt[0].push_back(1);
    tt[1].push_back(0);

    for(int i = 1;i<=100;i++)
    {
        tt[0].push_back(dd[i]);
        tt[1].push_back(dd[i]);
    }

    for(int i = 1;i<=99;i++)
    {
        for(int j = 0;j<=100;j++)
            tt[i + 1].push_back(j);
        tt[i + 1][i] = 1;
    }

    n1.nhan1(tt);

    vector <ll> t2;
    for(int i = 1;i<=101;i++)
        t2.push_back(1);

    n2.nhan2(t2);

    n1 = n1.power(99);

    n2 = n2 * n1;

    cout<<n2.val[1][0];

    return 0;
}
