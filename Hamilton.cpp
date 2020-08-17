#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define INF INT_MAX
#define PI 3.1415926535897932384626433832795
#define MOD 10000000000000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair <int, int> pi;
typedef pair <ll, ll> pl;
typedef unsigned long long ull;
typedef pair <pair<int, int>, int> pii;

int dix[5] = {0, +1, -1,  0,  0};
int diy[5] = {0,  0,  0, +1, -1};

int Free[100][100],m,n,dem = 0,res[100][100], deg[100][100];

void printscr()
{
    for(int i = 1;i<=m;i++)
    {
        for(int j = 1;j<=n;j++)
            cout<<(res[i][j] / 10 == 0 ? "0" : "")<<res[i][j]<<' ';
        cout<<endl;
    }
}

int cnt_deg(int x, int y)
{
    int cnt = 0;
    for(int i = 1;i<=4;i++)
    {
        int nx = x + dix[i];
        int ny = y + diy[i];

        if(nx >= 1 && nx <= m && ny >= 1 && ny <= n && Free[nx][ny])
            cnt++;
    }
    return cnt;
}

void trau(int x, int y,int cnt)
{
    res[x][y] = cnt;

    if(cnt == dem)
    {
        printscr();
        exit(0);
    }

    set<pii> a;

    for(int i = 1;i<=4;i++)
    {
        int nx = x + dix[i];
        int ny = y + diy[i];

        if(nx >= 1 && nx <= m && ny >= 1 && ny <= n && Free[nx][ny])
        {
            pii tmp;
            tmp.first.first = cnt_deg(nx, ny);
            tmp.first.second = nx;
            tmp.second = ny;
            a.insert(tmp);
        }
    }

    for(set<pii>::iterator it = a.begin();it != a.end();it++)
    {
        pii tmp = *it;

        int nx = tmp.first.second;
        int ny = tmp.second;

        Free[nx][ny] = 0;
        trau(nx, ny, cnt + 1);
        Free[nx][ny] = 1;

    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    #endif

    int stx,sty;

    cin>>m>>n>>stx>>sty;

    for(int i = 1;i<=m;i++)
        for(int j = 1;j<=n;j++)
           {
               res[i][j] = 0;
               cin>>Free[i][j];
               dem += (Free[i][j] == 1);
           }

    Free[stx][sty] = 0;
    trau(stx, sty, 1);

    cout<<"No path!";

    return 0;
}
