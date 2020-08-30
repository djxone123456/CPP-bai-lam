#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define INF INT_MAX
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define maxn 3

using namespace std;

typedef pair <int, int> pi;
typedef long long ll;
typedef unsigned long long ull;

struct matrix
{
    int val[maxn][maxn];

    matrix ()
    {
        memset(val, 0, sizeof(val));
    }

    matrix operator * (const matrix &B)
    {
        matrix C;
        for (int i = 1; i <= 2; i++)
            for (int j = 1; j <= 2; j++)
            {
                for (int k = 1; k <= 2; k++)
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
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    #endif

    freopen("tile.inp","r",stdin);
    freopen("tile.out","w",stdout);

    int q;

    cin>>q;

    while(q--)
    {
        ll n;
        cin>>n;

        matrix T;

        T.val[1][1] = 1;
        T.val[1][2] = 2;
        T.val[2][1] = 1;

        matrix B = T.power(n);

        cout<<B.val[1][1]<<'\n';
    }
    return 0;
}

















