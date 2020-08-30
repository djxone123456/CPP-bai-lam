#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define INF INT_MAX
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define endl '\n'
#define getBit(A, bit) ((A & 1 << bit) != 0)
#define turnOn(A, bit) (A |= 1 << bit)
#define turnOff(A, bit) (A &= ~(1 << bit))
#define BTtin "rau"

using namespace std;

typedef long long ll;
typedef pair <int, int> pi;
typedef unsigned long long ull;

ll n, sum, tong = 0;
pi a[1000000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen(BTtin".inp","r",stdin);
    freopen(BTtin".out","w",stdout);

    cin>>sum>>n;

    for(int i = 1;i<=n;i++)
        cin>>a[i].first>> a[i].second;

    sort(a + 1, a + n + 1);

    for(int i = 1;i<=n;i++)
    {
        if(a[i].second < sum)
        {
            tong += a[i].first * a[i].second;
            sum -= a[i].second;
        }
        else
        {
            tong += a[i].first * sum;
            break;
        }
    }

    cout<<tong;

    return 0;
}

