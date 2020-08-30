#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define INF INT_MAX
#define MOD 1000000007
#define BTtin "GRID"

using namespace std;

typedef pair <int, int> pi;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen(BTtin".inp","r",stdin);
    freopen(BTtin".out","w",stdout);

    ll n;
    cin>>n;

    n++;
    ll gt = n*(n-1)/2 % MOD;

    cout<<((gt*2048)%MOD*gt)%MOD;
    return 0;
}


















