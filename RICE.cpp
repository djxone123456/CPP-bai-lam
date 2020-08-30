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
const int lim = 2e5;

int a[lim],f[lim];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    #endif

    int m,n,k,pos = 0;
    ll sum = 0;
    cin>>m>>n>>k;

    if(k == m)
    {
        cout<<k<<endl;
        return 0;
    }
    a[0] = -1e9;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }

    sort(a+1,a+n+1);

    if(a[n] - a[1] <= k)
    {
        cout<<k<<endl;
        return 0;
    }
    pos = a[1];
    for(int i = 1,ok = 0;i<=n;ok ? i+=2 :i++)
    {
        if(ok) ok = 0;
        if(a[i] - a[i-1] < a[i+1] - a[i])
        {
            int tmp = min(k,max(0,a[i] - a[i-1]+1));
            sum+=tmp;
            a[i]++;
        }
        else
        {
            int tmp = min(k,max(0,a[i+1] - a[i]+1));
            sum+=tmp;
            a[i+1]++;
            ok = 1;
        }
    }
    cout<<sum;
    return 0;
}

















