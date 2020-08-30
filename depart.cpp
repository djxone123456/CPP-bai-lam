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

int n, cnt = 0, dd[900004], f[900004],sz, maxlen = 0;
int child[900004][40] = {};
string m;

void add(string s)
{
    int node = 0;

    for(int i = 0;i<s.size();i++)
    {
        int x = (int)s[i] - 'a';

        if(child[node][x] == 0)
        {
            child[node][x] = ++cnt;
        }

        node = child[node][x];
    }

    dd[node] = 1;
}

int found(string s)
{
    int node = 0, prevnode = 0;

    for(int i = 0;i<s.size();i++)
    {
        int x = (int)s[i] - 'a';

        if(child[node][x] == 0) return 0;

        node = child[node][x];
    }

    return dd[node];
}

int trau(int pos)
{
    if(pos > sz)
    {
//        cout<<1;
        return 1;
    }
    int node = 0;

    int &res = f[pos];
    if(res != -1) return res;
    res = 0;

    for(int i = pos;i<=min(sz,pos + 100);i++)
    {
        int x = (int)m[i] - 'a';

        if(child[node][x] == 0) break;

//        cout<<pos<<endl;
        node = child[node][x];

        if(dd[node] == 1) res = (res + trau(i + 1)) % MOD;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    #endif

    freopen("depart.inp","r",stdin);
    freopen("depart.out","w",stdout);

    cin>>n;

    for(int i = 1;i<=n;i++)
    {
        string s;
        cin>>s;

        add(s);

    }

    cin>>m;

    m = '0' + m;

    sz = m.size() - 1;

    memset(f, 255, sizeof(f));

    cout<<trau(1);

    return 0;
}

















