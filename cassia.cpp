#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define INF INT_MAX
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define file "CASSIA"

using namespace std;

typedef pair <int, int> pi;
typedef long long ll;
typedef unsigned long long ull;

int n, a[1000000], res = INF;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if(fopen("debug.inp", "r"))
    {
        freopen("debug.inp","r",stdin);
        freopen("debug.out","w",stdout);
    }
    else
    {
        freopen(file".inp","r",stdin);
        freopen(file".out","w",stdout);
    }

    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + n + 1);

    for(int i = 1; i <= n; i++)
    {
        int pos = upper_bound(a + 1, a + n + 1, a[i] + n - 1) - a;

        res = min(res, n - pos + i);
    }

    cout << res;

    return 0;
}
