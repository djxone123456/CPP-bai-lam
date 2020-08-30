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

int dd[50000], t[50000], n, d, start,di[50000];

int tham_quan(int pos, int day)
{
    if(day < 0) return -INF;
    if(day == 0) return 0;

    int res = 0;

    if(!di[pos])
      {
          di[pos] = 1;
          res = max(res, tham_quan(pos, day - 1) + t[pos]);
          di[pos] = 0;
      }

    for(int i = max(1, pos - day);i<=min(n, pos + day);i++)
    {
        if(pos - i == 0) continue;
        else
        res = max(res, tham_quan(i, day - abs(pos - i)));
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

    cin>>n>>start>>d;

    for(int i = 1;i<=n;i++)
        {
            cin>>t[i];
            dd[i] = 0;
            di[i] = 0;
        }

    cout<<tham_quan(start + 1, d);

    return 0;
}

















