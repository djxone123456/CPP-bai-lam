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

int Z[200005], n;
vector<int> a;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    #ifdef djxone123456
    freopen("CPREFIX.inp","r",stdin);
    freopen("CPREFIX.out","w",stdout);
//    #endif

    string S;

    cin>>S;

    n = S.size();

    int L = 0, R = 0;
    Z[0] = n;
    for (int i = 1; i < n; i++)
       if (i > R)
       {
          L = R = i;
          while (R < n && S[R] == S[R - L]) R++;
          Z[i] = R - L; R--;
       }
       else
       {
          int k = i - L;
          if (Z[k] < R - i + 1) Z[i] = Z[k];
          else
          {
              L = i;
              while (R < n && S[R] == S[R - L]) R++;
              Z[i] = R - L; R--;
          }
       }

//    a.push_back(n);

    for(int i = 0;i<n;i++)
    {
        if(Z[i] > 0)
            a.push_back(Z[i]);
//            cout<<Z[i]<<' ';
    }

    sort(a.begin(), a.end());

    for(int i = 1;i<=n;i++)
    {
        cout<<a.size() - (upper_bound(a.begin(), a.end(), i - 1) - a.begin())<<' ';
    }

    return 0;
}

















