#include <bits/stdc++.h>

#define MOD 1000000007
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<char> vc;

ll n,m,sum = 0,f[100005][32];
vi len;
vi ktu;
string s;
ll a[100005];

ll trau(ll pos, ll prev)
{

}

int main()
{
    freopen("password.inp", "r",stdin);
    freopen("password.out", "w",stdout);

    string s1;
    cin>>n>>m>>s>>s1;

    for(ll i = 1;i<=m;i++)
        a[i] = s1[i - 1];

    ktu.push_back((ll)s[0] - 'a');
    ll prev = 0;

    for(ll i = 1;i<s.size();i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
            {
                if(sum + prev < n)
                {
                    len.push_back(prev);
                    sum += prev;
                    ktu.push_back((ll)s[i] - 'a');
                    prev = 0;
                }
                else
                    if(sum + prev >= n)
                    {
                        len.push_back(n - sum);
                        sum = n;
                        break;
                    }
                continue;
            }
        prev = prev * 10 +((ll)s[i] - '0');
        if(i == s.size() - 1)
        {
            if(sum + prev < n)
                {
                    len.push_back(prev);
                    sum += prev;
                    ktu.push_back((ll)s[i] - 'a');
                    prev = 0;
                }
                else
                    if(sum + prev >= n)
                    {
                        len.push_back(n - sum);
                        sum = n;
                        break;
                    }
        }

    }
    s = "";
    for(ll i = 0;i<ktu.size();i++)
    {
        for(ll j = 0;j<len[i];j++)
            s += char(ktu[i] + 'a');
    }

    memset(f, 255, sizeof(f));

    cout<<trau(0, 0);
    return 0;
}
