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

int fib(int n) {
  double phi = (1 + sqrt(5)) / 2;
  return round(pow(phi, n) / sqrt(5));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    #endif

    freopen("fibos.inp","r",stdin);
    freopen("fibos.out","w",stdout);

    ll n;
    cin>>n;
    int f0 = 1, f1 = 1;
    int res = 2;

    if(n < 2) {
        if(n == 1) cout<<2;
        else cout<<1;
        return 0;
    }

    for(int i = 2;i<=n;i++)
        {
            int f2 = (f0 + f1) % MOD;
            res = (res + f2) % MOD;

            f0 = f1;
            f1 = f2;
        }

    cout<<res;

    return 0;
}

















