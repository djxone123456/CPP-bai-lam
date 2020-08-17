#include <bits/stdc++.h>

using namespace std;

#define getBit(bit,A) ((A & (1 << bit)) != 0)
#define turnOn(A,bit) (A |= 1 << bit)
#define turnOff(A,bit) (A &= ~(1 << bit))
#define INF 1000000007
typedef long long ll;

ll n, a[5][30003], f[30003][2][2][2][2],total = -INF;
bool dd[30003][2][2][2][2],check = 0;

ll bitmask(int pos,bool x,bool y,bool z, bool t)
{
    if(!check)
        return total;
    if(pos > n)
    {
        return 0;
    }

    ll &res = f[pos][x][y][z][t];

    if(dd[pos][x][y][z][t]) return res;
    res = -INF;
    dd[pos][x][y][z][t] = 1;

    for(ll i = 0; i< 16 ; i++)
    {
        bool xx = getBit(0, i);
        bool yy = getBit(1, i);
        bool zz = getBit(2, i);
        bool tt = getBit(3, i);

        if(x + xx != 2 && y + yy != 2 && z + zz != 2 && t + tt != 2 &&
           xx + yy != 2 && yy + zz != 2 && zz + tt != 2)
        {
            ll tong = xx * a[1][pos] + yy * a[2][pos] + zz * a[3][pos] + tt * a[4][pos];
            res = max(res, bitmask(pos + 1, xx, yy, zz, tt) + tong);
        }
    }
    return res;
}

int main()
{
    #ifdef hello
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    #endif // hello
    cin>>n;
    for(ll i = 1;i<=4;i++)
        for(ll j = 1;j<=n;j++)
           {
               cin>>a[i][j];
               if(a[i][j] > 0) check = 1;
               total = max(total, a[i][j]);
           }

    memset(dd,0,sizeof(dd));
    cout<<bitmask(1, 0, 0, 0, 0);

    return 0;
}
