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

int n, m;
set<string> tim, a;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    #ifdef djxone123456
//    freopen("debug.inp","r",stdin);
//    freopen("debug.out","w",stdout);
//    #endif

    freopen("foundstr.inp","r",stdin);
    freopen("foundstr.out", "w",stdout);

    cin>>n;

    for(int i = 1;i<=n;i++)
    {
        string s;
        cin>>s;

        a.insert(s);
    }

    cin>>m;

    for(int i = 1;i<=m;i++)
    {
        string s;
        cin>>s;

        if(a.find(s) != a.end()) cout<<1<<endl;
        else cout<<0<<endl;
    }

    return 0;
}

















