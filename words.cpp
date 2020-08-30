#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define INF INT_MAX
#define MOD 1000000007
#define BTtin "words"

using namespace std;

typedef pair <int, int> pi;
typedef long long ll;
typedef unsigned long long ull;

int n, f[200000], Z[200000], m;
string s;

void Zf()
{
    int L = 0, R = 0;
    Z[0] = m;

    for(int i = 1;i<s.size();i++)
    {
        if(i > R)
        {
            R = L = i;

            while(R < s.size() && s[R] == s[R - L])
                R++;

            Z[i] = R - L; R--;
        }
        else
        {
            int k = i - L;
            if(Z[k] <= R - i + 1) Z[i] = Z[k];
            else
            {
                L = i;

                while(R < s.size() && s[R] == s[R - L]) R++;
                Z[i] = R - L; R--;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen(BTtin".inp","r",stdin);
    freopen(BTtin".out","w",stdout);

    cin>>n;

    cin>>s;

    m = s.size();
    reverse(s.begin(), s.end());
    Zf();

    reverse(Z + 1, Z + m + 1);

    for(int i = 1;i<=m;i++)
        cout<<Z[i]<<' ';

    fill(f, f + m + n + 3, 0);
    f[m] = 1;

    for(int i = m;i<=n - 1;i++)
        for(int j = 1;j<=m;j++)
           if(Z[j] == 0)
            f[i + j] += f[i];

    for(int i = 1;i<=n;++i)
        cout<<f[i]<<' ';

    return 0;
}


















