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

int Z[300005], n;
int a[300005];

void Z_func()
{
    int L = 0, R = 0;
    Z[0] = n;
    for (int i = 1; i < n; i++)
       if (i > R)
       {
          L = R = i;
          while (R < n && a[R] == a[R - L]) R++;
          Z[i] = R - L; R--;
       }
       else
       {
          int k = i - L;
          if (Z[k] < R - i + 1) Z[i] = Z[k];
          else
          {
              L = i;
              while (R < n && a[R] == a[R - L]) R++;
              Z[i] = R - L; R--;
          }
       }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    #ifdef djxone123456
    freopen("DIVSEQ.inp","r",stdin);
    freopen("DIVSEQ.out","w",stdout);
//    #endif

    cin>>n;

    for(int i = 0;i<n;i++)
        {
            cin>>a[i];
        }

    Z_func();

    for(int i = 1;i<n;i++)
        if(n - Z[i] == i)
        {
            return cout<<i, 0;
        }

    return 0;
}


















