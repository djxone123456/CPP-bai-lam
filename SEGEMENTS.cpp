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

int n,a[10000000],maxa = 0,diff = 1,L[10000000],maxchia = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    #endif

    cin>>n;

    L[0] = 0;
    for(int i = 1;i<=n;i++)
        {
            cin>>a[i];
            maxa = max(maxa,a[i]);
            if(a[i] == a[1] && i > 1) diff++;
            L[i] = L[i-1]+a[i];
        }

    if(n == 1)
    {
        cout<<1;
        return 0;
    }
    if(diff == n)
    {
        cout<<n;
        return 0;
    }

    for(int i = 1;i<=n;i++)
    {
        if(L[i] < maxa) continue;
        int cnt = 1,sum = 0;
        for(int j = i+1;j<=n;j++)
        {
            sum+=a[j];
            if(sum > L[i] || (j == n && sum != L[i]))
            {
                cnt = 0;
                break;
            }
            if(sum == L[i])
            {
                cnt++;
                sum = 0;
            }
        }
        if(cnt != 0)
        {
            cout<<cnt;
            return 0;
        }
    }

    return 0;
}

















