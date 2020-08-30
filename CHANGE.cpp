#include <bits/stdc++.h>
#define MaxM 20007
#define MaxN 107

using namespace std;
typedef long long ll;

ll B, N, sum = 0,cnt = 0;
ll so[MaxN];

bool kq[MaxN][MaxM];

bool compare(ll a,ll b)
{
    return a > b;
}

void Possible()
{
    fill(kq[0], kq[0] + 2*sum + 1, 0);
    kq[0][sum] = 1;
    for (ll i = 0; i < N; ++i)
    {
        //fill(kq[i + 1], kq[i + 1] + B + 1, 0);
        copy(kq[i], kq[i] + 2*sum + 1, kq[i + 1]);
        for (ll j = 0; j <= 2*sum; ++j)
        {
            if (kq[i][j])
            {
                if (j - so[i] >= 0) kq[i + 1][j - so[i]] = 1;
                if (j + so[i] <= 2*sum) kq[i + 1][j + so[i]] = 1;
            }
        }
    }
}

void Backtrack()
{
    ll S = B + sum, pos = N;
    while (pos)
    {
        --pos;
        if (kq[pos][S]);
        else if (S - so[pos] >= 0 && kq[pos][S - so[pos]])
        {
            cnt++;
            S -= so[pos];
        }
        else
        {
            cnt++;
            S += so[pos];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie();
    sum = 0;
    cin >> B >> N;
    for (ll i = 0; i < N; ++i)
        {
            cin >> so[i];
            sum += so[i];
        }
    sort(so,so+N,compare);
    Possible();
    Backtrack();
    cout<<cnt;
    return 0;
}
