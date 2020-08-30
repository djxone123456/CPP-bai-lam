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


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    #endif

    int t;

    cin>>t;

    while(t--)
    {
        int k,m,n,q;
        cin>>k>>m>>n;

        cin>>q;

        while(q--)
        {
            int a,b;
            cin>>a>>b;
            if(a>=b) cout<<"NO";
            else
            {
                cout<<"YES";
            }
            cout<<endl;
        }
    }

    return 0;
}

















