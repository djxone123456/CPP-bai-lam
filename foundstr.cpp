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

int n,m, cnt = 0, isEnd[200004] = {};
int child[200004][40] = {};

void add(string s)
{
    int node = 0;

    for(int i = 0; i < s.size(); i++)
    {
        int x = (int)s[i] - '0';

        if(child[node][x] == 0) child[node][x] = ++cnt;
        node = child[node][x];
    }

    isEnd[node] = 1;
}

int found(string s)
{
    int node = 0;

    for(int i = 0; i < s.size(); i++)
    {
        int x = (int)s[i] - '0';

        if(child[node][x] == 0) return 0;
        node = child[node][x];
    }
    return isEnd[node];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    #endif

    cin>>n;

    for(int i = 1;i<=n;i++)
    {
        string s;
        cin>>s;

        add(s);
    }

    int m;

    cin >> m;

    for(int i = 1; i <= m; i++)
    {
        string s;
        cin >> s;

        cout << found(s) << endl;
    }

    return 0;
}
