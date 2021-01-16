#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define INF INT_MAX
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define file "scales"

using namespace std;

typedef pair <int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

int n, w, f[1000][100000], a[1001];

int trau(int pos, int sum)
{
    if(pos == n) return sum;

    int &res = f[pos][sum];
    if(res != -1) return res;
    res = sum;

    for(int i = pos; i < n; i++)
    {
        if(sum + a[i] <= w)
            res = max(res, trau(i + 1, sum + a[i]));
    }

    return res;
}

int trau1(int pos, int sum)
{
    if(pos == n) return sum;

    int res = sum;

    for(int i = pos; i < n; i++)
    {
        if(sum + a[i] <= w)
            res = max(res, trau1(i + 1, sum + a[i]));
        else break;
    }

    return res;
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

    cin >> n >> w;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if(w >= 100000)
    {
        cout << trau1(0, 0);
        return 0;
    }

    memset(f, 255, sizeof(f));

    cout << trau(0, 0);

    return 0;
}

















