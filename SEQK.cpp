#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define INF INT_MAX
#define PI 3.1415926535897932384626433832795
#define MOD 10000000007

using namespace std;

typedef pair <int, int> pi;
typedef long long ll;
typedef unsigned long long ull;

ll n,k,m,cnt = 0;

void haiyo(ll pos,ll sum)
{
    if(pos >= n)
    {
        cnt++;
        return;
    }
    for(int i=0;i<=1;i++)
    {
        if(i == 0)
        {
            if(sum - k >= 1) haiyo(pos+1,sum-k);
        }
        else
        {
            if(sum+k < m) haiyo(pos +1,sum+k);
        }
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

    cin>>k>>m>>n;

    for(ll i=1;i<m;i++)
        haiyo(1,i);
    cout<<cnt%MOD;
    return 0;
}

















