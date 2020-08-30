#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define INF INT_MAX
#define PI 3.1415926535897932384626433832795
#define MOD 1000000009
#define getBit(A, bit) (A & (1 << bit) != 0)
#define turnOn(A, bit) (A |= (1 << bit))
#define turnOff(A, bit) (A &= ~(1 << bit))

using namespace std;

typedef pair <int, int> pi;
typedef long long ll;
typedef unsigned long long ull;

int m,n, f[39062][1 << 4][1 << 4];

int trau(int pos, int prev1, int prev2)
{
    if(pos > n) return 1;

    int &res = f[pos][prev1][prev2];
    if(res != -1) return res;

    res = 0;

    for(int rnow = 0;rnow < (1 << m);rnow++)
    {
        if((rnow & (prev1 << 2)) || (prev1 & (rnow << 2))) continue;
        if((rnow & (prev2 << 1)) || (prev2 & (rnow << 1))) continue;

        res = (res + trau(pos + 1, rnow, prev1)) % MOD;
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

    freopen("knights.inp","r",stdin);
    freopen("knights.out","w",stdout);

    cin>>m>>n;

    memset(f, 255, sizeof(f));

    cout<<trau(1, 0, 0);

    return 0;
}

















