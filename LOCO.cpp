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
#define maxn 4
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define Task "loco"

using namespace std;

typedef long long ll;
typedef long double ld;

int MOD;

struct matrix{
    int val[maxn][maxn];
    matrix (){
        memset(val, 0, sizeof(val));
    }
    matrix operator * (const matrix &B){
        matrix C;
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3; j++)
            {
                for (int k = 1; k <= 3; k++)
                    C.val[i][j] = (C.val[i][j] + (ll)val[i][k] * B.val[k][j]) % MOD;
            }
        return C;
    }

    matrix POWW(ll x){
        matrix C;
        for (int i = 1; i <= 3; i++) C.val[i][i] = 1;
        if (x == 0) return C;
        matrix B = POWW(x/2);
        C = B*B;
        if (x % 2 == 1) C = C * (*this);
        return C;
    }
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);

    ll n;
    cin >> n >> MOD;

    if(n == 0)
    {
        cout<<0;
        return 0;
    }
    else
        if(n == 1)
    {
        cout<<1 % MOD;
        return 0;
    }

    matrix T;
    T.val[1][1] = T.val[1][2] = T.val[1][3] = 1;
    T.val[2][1] = T.val[3][2] = 1;

    matrix A = T.POWW(n - 1);

    matrix B;
    B.val[1][1] = 1;
    B.val[2][1] = 1;

    matrix C =  A*B;

    cout<<C.val[1][1];

    return 0;
}
