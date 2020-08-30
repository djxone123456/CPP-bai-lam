//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x < y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "knights"
#define maxn 82
#define MOD 1000000009
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define ll long long
#define bit(x,i) ((x >> i) & 1)

using namespace std;

const long long M2 = 8ll * MOD * MOD;


int m;
long long n;
int sl = 0, state[100];
long long f[100][100];


struct matrix
{
    long long val[maxn][maxn];
    matrix()
    {
        memset(val, 0, sizeof(val));
    }

    matrix operator * ( const matrix & x)
    {
        matrix res;
        for (int u = 0; u < sl; u++)            
                for (int i = 0; i < sl; i++)
					for (int v = 0; v < sl; v++){
						res.val[u][v] += (val[u][i] * x.val[i][v] );
						if (res.val[u][v] >= M2) res.val[u][v] -= M2;
					}
		for (int u = 0; u < sl; u++)            
			for (int v = 0; v < sl; v++) res.val[u][v] %= MOD;
        return res;
    }
	
	matrix POWW(matrix A, long long b)
{
    matrix C;
    for (int i = 0; i < sl; i++) C.val[i][i] = 1;
    for ( ; b; b /= 2, A = A * A)
        if (b % 2) C = C * A;
    return C;
}
};

matrix A;

matrix POWW(matrix A, long long b)
{
    matrix C;
    for (int i = 0; i < sl; i++) C.val[i][i] = 1;
    for ( ; b; b /= 2, A = A * A)
        if (b % 2) C = C * A;
    return C;
}

bool check_state(int x)
{
    int a = x >> m;
	int b = x & ((1<<m) - 1);
	return !((a & (b>>2)) || (b & (a>>2)));	
}

bool khop(int x, int y)
{
    if ((x >> m) != (y&((1<<m) - 1))) return 0;
	int a = x & ((1<<m) - 1);
	int b = y >> m;    
    return !((a & (b>>1)) || (b & (a>>1)));	
}


void Prepare()
{
    for (int i = 0; i < 1 << (2*m); i++)
        if (check_state(i)) state[sl++] = i;
    //cout << sl << endl;
    for (int i = 0; i < sl; i++)
        for (int j = 0; j < sl; j++)
            A.val[i][j] = khop(state[i],state[j]);
}

int main()
{
	ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> m >> n;
    if (n == 1)
    {
        cout << (1 << m);
        return 0;
    }
    Prepare();

    matrix B = POWW(A,n-2);
    long long ans = 0;
    for (int i = 0; i < sl; i++)
        for (int j = 0; j < sl; j++) ans += B.val[i][j];
    cout << ans % MOD;
}

// 0 1 1 2 3 5 8
