#include <iostream>
#include <stdio.h>
#include <cstring>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define Rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define For(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 110
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define Task "debug"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll MOD = 1e9 + 7;

struct matrix{
    int val[maxn][maxn];
    int height , width;

    matrix (){
        memset(val, 0, sizeof(val));
    }

    matrix operator * (const matrix &B)
    {
        ll MOD2 = MOD * MOD;
        matrix C;
        for (int i = 1; i <= height; i++)
            for (int j = 1; j <= B.width; j++)
            {
                ll tmp = 0;
                for (int k = 1; k <= B.height; k++)
                {
                    tmp += (ll)val[i][k] * B.val[k][j];
                    while(tmp > MOD2) tmp -= MOD2;
                }
                C.val[i][j] = tmp % MOD;
            }
        C.height = height;
        C.width = B.width;
        return C;
    }

    matrix POWW(ull x)
    {
        if(x == 1) return (*this);
        if(x == 2) return (*this) * (*this);

        matrix tmp = POWW(x / 2);

        if(x & 1) return tmp * tmp * (*this);

        return tmp * tmp;
    }
};

ull k;
int dd[110], n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);

    memset(dd, 0, sizeof(dd));

    cin>> n >> k;

    int tt;

    for(int i = 1;i<=n;i++)
    {
        cin>> tt;

        dd[tt]++;
    }

    matrix a;

    a.height = 101;
    a.width = 101;
    a.val[1][1] = 1;

    for(int i = 2;i<=101;i++)
        a.val[1][i] = dd[i - 1], a.val[2][i] = dd[i - 1];

    for(int i = 3;i<=101;i++)
        a.val[i][i - 1] = 1;

    a = a.POWW(k);

    matrix b;
    b.height = 101;
    b.width = 1;
    b.val[1][1] = b.val[2][1] = 1;

    matrix c = a * b;

    cout<<c.val[1][1];

    return 0;
}
