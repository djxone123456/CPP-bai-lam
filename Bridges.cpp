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

ll best = INF, k, n;

void k1()
{
    vector<int> a;
    vector<pi> pos;
    best = 0;
    for(int i = 1;i<=n;i++)
    {
        char t1, t2;
        int dau, cuoi;
        cin>>t1>>dau>>t2>>cuoi;

        if(t1 == t2)
        {
            best += abs(cuoi - dau);
        }
        else
        {
            a.push_back(dau);
            a.push_back(cuoi);
            pos.push_back(MP(dau, cuoi));
        }
    }

    sort(a.begin(), a.end());

    ll sum1 = 0, sum2 = 0;
    int pos1 = a[n / 2 - 1], pos2 = a[n / 2];

    for(int i = 0;i<a.size();i++)
    {
        sum1 += abs(a[i] - pos1);
        sum2 += abs(a[i] - pos2);
    }

    cout<<best + min(sum1, sum2);
}

void k2()
{

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    #endif

//    freopen("Bridges.inp","r",stdin);
//    freopen("Bridges.out","w",stdout);
    cin>>k>>n;

    if(k == 1)
    {
        k1();
    }
    else k2();

    return 0;
}

















