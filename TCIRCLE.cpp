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

ull C(ull n, ull k)
{
    ull ngt = 1;
    for(int i = n - k + 1;i<=n;i++)
        ngt *= i;
    for(int i = 1;i<=k;i++)
        ngt/= i;
    return ngt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("TCIRCLE.inp","r",stdin);
    freopen("TCIRCLE.out","w",stdout);

    ull n;
    cin>> n;

    if(n % 2 == 1)
    {
        cout<<C(n, 3) - n * C((n - 1)/2, 2);
    }
    else
    {
        cout<<C(n, 3) - n * C(n / 4, 2);
    }
    return 0;
}

















