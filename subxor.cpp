#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define INF int_MAX
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define endl '\n'
#define getB(A, bit) ((A & (1 << bit)) != 0)

using namespace std;

typedef long long ll;
typedef pair <int, int> pi;
typedef unsigned long long ull;

int child[3000000][2] = {}, n,sum[3000000] = {}, k, cnt = 0;
ll res = 0;

void solve(int s)
{
    int node = 0;

    for(int i = 30;i>=0;i--)
    {
        int curr_s = getB(s, i);
        int curr_k = getB(k, i);

        if(curr_k) res += sum[ child[node][curr_s] ];

        int xorr = curr_k ^ curr_s;

        if(child[node][xorr] == 0) break;

        node = child[node][xorr];
    }
}

void add(int s)
{
    int node = 0;

    for(int i = 30;i>=0;i--)
    {
        int x = getB(s, i);

        if(child[node][x] == 0) child[node][x] = ++cnt;

        sum[ child[node][x] ]++;

        node = child[node][x];
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

    freopen("subxor.inp","r",stdin);
    freopen("subxor.out","w",stdout);

    cin>>n>>k;

    int prev = 0;

    add(0);

    for(int i = 1;i<=n;i++)
    {
        int now;

        cin>>now;

        prev ^= now;

        solve(prev);
        add(prev);
    }

    cout<<res;

    return 0;
}

















