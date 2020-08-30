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

int n, m, child[100004][40] = {}, dd[100004][40] = {}, cnt = 0;

void add(string s)
{
    int node = 0;

    for(char c: s)
    {
        int x = (int)c - 'a';

        if(!child[node][x])
        {
            child[node][x] = ++cnt;
            dd[node][x] = 1;
        }
        else dd[node][x]++;

        node = child[node][x];
    }
}

int found(string s)
{
    int node = 0, cntnode = 0;

    for(char c: s)
    {
        int x = (int) c - 'a';

        if(!child[node][x]) return cntnode;

        cntnode += dd[node][x];
        node = child[node][x];
    }

    return cntnode;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    #endif

    freopen("lookup.inp","r",stdin);
    freopen("lookup.out","w",stdout);

    cin>>n;

    for(int i = 1;i<=n;i++)
    {
        string s;
        cin>>s;

        add('a' + s);
    }

    cin>>m;

    for(int i = 1;i<=m;i++)
    {
        string s;
        cin>>s;

        cout<<found('a' + s)<<endl;
    }

    return 0;
}

















