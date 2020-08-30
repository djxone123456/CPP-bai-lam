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

void dien_so(int x, int y, int n)
{
    if(n == 1)
    {
        a[x][y] = 0;
        return;
    }

    int pos = ?, prevx = x, prevy = y;

    for(int i = 0;i<=n - 2;i++)
        a[x++][y] = pos++;

    for(int i = 0;i<=n - 2;i++)
        a[x++][y++] = pos++;

    for(int i = 0;i<=n - 2;i++)
        a[x][y++] = pos++;

    for(int i = 0;i<=n - 2;i++)
        a[x--][y] = pos++;

    for(int i = 0;i<=n - 2;i++)
        a[x--][y--] = pos++;

    for(int i = 0;i<=n - 2;i++)
        a[x][y--] = pos++;

    dien_so(x + 1, y + 1, n - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    #endif

    return 0;
}

















