#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define INF INT_MAX
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define file "COLLIDER"

using namespace std;

typedef pair <int, int> pi;
typedef long long ll;
typedef unsigned long long ull;

int n, m, pos = 1;
pi a[300000];
vector<int> f;

void nxt(int info = 2, int fi = 0)
{
    for(pos; pos <= n + 1; pos++)
    {
        if(a[pos].first == 1)
        {
            pos++;
            nxt(-1, a[pos - 1].second);
        }
        else
        {
            if(a[pos].first == info)
            {
                if(info == 2) return;
                int se = a[pos].second;

                f.pb((se - fi) / 2 + (se - fi) % 2);
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if(fopen("debug.inp", "r"))
    {
        freopen("debug.inp","r",stdin);
        freopen("debug.out","w",stdout);
    }
    else
    {
        freopen(file".inp","r",stdin);
        freopen(file".out","w",stdout);
    }

    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> a[i].second >> a[i].first;

    a[n + 1] = pi(2, 0);

    nxt();

    sort(f.begin(), f.end());

    cin >> m;

    while(m--)
    {
        int t;

        cin >> t;

        cout << n - (int)(upper_bound(f.begin(), f.end(), t) - f.begin()) * 2 << "\n";
    }

    return 0;
}
