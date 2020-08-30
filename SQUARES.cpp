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

int a[500][500], m,n,k, ngang[500][500], doc[500][500];
vector<pi> del;

void K0()
{
    ull sum = 0;

    for(int i = 1;i<min(m,n);i++)
    {
        sum += i * (n - i) * (m - i);
    }
    cout<<sum;
}

void diff_k()
{
    ll cnt = 0;
    for(int r = 1;r< min(m,n);r++)
        for(int x = 1;x <= m - r;x++)
           for(int y = 1;y <= n - r;y++)
             {
                 ll AB = ngang[x][y + r];
                 ll CD = ngang[x + r][y + r];
                 ll BC = doc[x + r][y + r];
                 ll AD = doc[x + r][y];

                 cnt += __builtin_popcount(AB & CD & BC & AD & ((1LL << r) - 1));
             }

    cout<<cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    #endif

//    freopen("SQUARES.inp","r",stdin);
//    freopen("SQUARES.out","w",stdout);
    cin>>m>>n>>k;

    for(int i = 1;i<=m;i++)
        for(int j = 1;j<=n;j++)
           {
               a[i][j] = 1;
               ngang[i][j] = 0;
               doc[i][j] = 0;
           }

    for(int i = 1;i<=k;i++)
    {
        int x,y;
        cin>>x>>y;

        a[x][y] = 0;
    }

    for(int i = 1;i<=m;i++)
    {
        for(int j = 1;j<=n;j++)
           {
               ngang[i][j]= ngang[i][j - 1] * 2 + a[i][j];
           }
    }

    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            doc[j][i] = doc[j - 1][i] * 2 + a[j][i];
        }
    }

//    for(int i = 1;i<=m;i++)
//        cout<<ngang[i][n]<<endl;
//    for(int i = 1;i<=n;i++)
//        cout<<doc[m][i]<<endl;

    if(!k) K0();
    else diff_k();

    return 0;
}
