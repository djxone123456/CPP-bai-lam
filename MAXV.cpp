#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define INF INT_MAX
#define MOD 1000000007
#define BTtin "MAXV"

using namespace std;

typedef pair <int, int> pi;
typedef long long ll;
typedef unsigned long long ull;

int a[100005], n;

bool compare(int x, int y)
{
    string tmp1 = to_string(x) + to_string(y);
    string tmp2 = to_string(y) + to_string(x);

    return tmp1 > tmp2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen(BTtin".inp","r",stdin);
    freopen(BTtin".out","w",stdout);

    cin>>n;

    for(int i = 1;i<=n;i++)
        cin>>a[i];

    sort(a + 1, a + n + 1, compare);

    for(int i = 1;i<=n;i++)
        cout<<a[i];

    return 0;
}


















