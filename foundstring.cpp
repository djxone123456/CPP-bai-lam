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

ll Z[3000006], n;
vector<int> vt;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    #ifdef djxone123456
    freopen("FOUNDSTRING.inp","r",stdin);
    freopen("FOUNDSTRING.out","w",stdout);
//    #endif // djxone123456

    string a,b, S;

    cin>>a>>b;

    S = a;
    S += '#';
    S += b;
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

    for(int i = a.size() + 1;i<n;i++)
       if(Z[i] >= a.size())
          vt.push_back(i - a.size());

    cout<<vt.size()<<endl;

    for(int i = 0;i<vt.size();i++)
        cout<<vt[i]<<' ';

    return 0;
}

















