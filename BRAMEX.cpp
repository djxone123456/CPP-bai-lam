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

int n,m, cnt = 0, dd[1000000][10] = {};
int child[1000000][10] = {};

void add(string s)
{
    int node = 0;

    for(int i = 0;i<s.size();i++)
    {
        int x = (int)s[i] - 'a';

        if(child[node][x] == 0)
        {
            child[node][x] = ++cnt;
            dd[node][x] = 1;
        }
        else
            dd[node][x]++;

        node = child[node][x];
    }
}

int found(string s)
{
    int node = 0, prevnode = 0;

    for(int i = 0;i<s.size();i++)
    {
        int x = (int)s[i] - 'a';

        if(child[node][x] == 0) return 0;

        prevnode = dd[node][x];
        node = child[node][x];
    }

    return prevnode;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    #endif

    freopen("bramex.inp","r",stdin);
    freopen("bramex.out","w",stdout);

    cin>>n;

    for(int i = 1;i<=n;i++)
    {
        string s;
        cin>>s;

        add(s);
    }

    cin>>m;

    for(int i = 1;i<=m;i++)
    {
        string s;
        cin>>s;

        cout<<found(s)<<'\n';
    }

    return 0;
}

















