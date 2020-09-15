#include <bits/stdc++.h>
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
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define Task "dream"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct matrix{
    int val[maxn][maxn];
    matrix (){
        memset(val, 0, sizeof(val));
    }
    matrix operator * (const matrix &B){
        matrix C;
        for (int i = 1; i <= 101; i++)
            for (int j = 1; j <= 101; j++)
            {
                for (int k = 1; k <= 101; k++)
                    C.val[i][j] = (C.val[i][j] + (ll)val[i][k] * B.val[k][j]) % MOD;
            }
        return C;
    }

    matrix POWW(ull x){
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
    cin.tie(0); cout.tie();

    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);

    memset(dd, 0, sizeof(dd));

    cin>> n >> k;

    for(int i = 1;i<=n;i++)
    {
        int tt;
        cin>>tt;

        dd[tt]++;
    }

    matrix a;
    a.val[1][1] = 1;

    for(int i = 2;i<=101;i++)
        a.val[1][i] = a.val[2][i] = dd[i - 1];

    for(int i = 3;i<=101;i++)
        a.val[i][i - 1] = 1;

    a = a.POWW(k);

    matrix b;

    b.val[1][1] = b.val[2][1] = 1;

    matrix c = a * b;

    cout<<c.val[1][1];

    return 0;
}
