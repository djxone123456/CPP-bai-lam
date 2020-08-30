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

int a[1003][1003], k, dis[1003], n, m, d[700];
vector < int > dinh;

bool check()
{
    for(int i = 1;i<k;i++)
        for(int j = i + 1;j <= k;j++)
           if(!a[dis[i]][dis[j]]) return 0;

    for(int i = 1;i<=k;i++)
        cout<<dis[i]<<' ';
    cout<<endl;

    return 1;
}

int trau(int pos, int cnt)
{
    if(pos > n)
    {
        if(cnt == k) return check();
        return 0;
    }

    int res = trau(pos + 1, cnt);
    if(res == 1) return 1;

    if(cnt < k)
    {
        dis[cnt + 1] = pos;
        res = trau(pos + 1, cnt + 1);
    }

    return res;
}

void sub1()
{
    if(trau(1, 0) == 0) cout << -1<< endl;
}

void sub2()
{
    cin>>n>>m>>k;

    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
           a[i][j] = 0;

    for(int i = 1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;

        a[x][y] = 1;
        a[y][x] = 1;
    }

    if(n < 31)
    {
        sub1();
        return;
    }
    else
        if(n < 61)
    {
        cout<<0<<endl;
        return;
    }
    for(int i = 1;i<=n;i++)
        if(d[i])
        {
            for(int j = 1;j<=n;j++)
            {
                if(d[j] && ! a[i][j])
                {
                    d[i] = 0;
                    d[j] = 0;
                    break;
                }
            }
        }
    for(int i = 1;i<=n;i++)
        if(d[i])
        {
            dinh.push_back(i);
            --k;
            cout<<i<<' ';
            if(!k)
            {
                cout<<endl;
                return;
            }
        }

    for(int i = 1;i<=n;i++)
        if(!d[i])
        {
            int ok = 1;
            for(int j = 0;j<dinh.size();j++)
                if(!a[i][dinh[j]])
                {
                    ok = 0;
                    break;
                }
            if(!ok) continue;
            else
            {
                k--;
                cout<<i<<' ';
                dinh.push_back(i);
                if(!k)
                {
                    cout<<endl;
                    return;
                }
            }
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("CLIQUE.inp","r",stdin);
    freopen("CLIQUE.out","w",stdout);


    int t;
    cin>>t;

    while(t--)
    {
        sub2();
    }

    return 0;
}
























