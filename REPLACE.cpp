#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define INF INT_MAX
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef pair <int, int> pi;
typedef unsigned long long ull;

string s,res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    #endif

    cin>>s>>res;
    int n = s.size();

    ll maxsum = 0;

    for(int i = 0;i<n;i++)
    {
        maxsum+= (int) s[i] - '0';
    }

    for(int pos = 0;pos<res.size();pos++)
    {
        ll tmp = maxsum;
        int so = 0;
        while(tmp > 0)
        {
          so++;
          tmp/=10;
        }
        ll tongres = 0;

        for(int i = 1;i<=so;i++)
        {
            ll tongs = 0;
            tongres = tongres*10 + (int)res[pos + i - 1] - '0';
            //cout<<tongres<<endl;
            if(tongres > maxsum) continue;
            if((int)s[pos] - '0' >= tongres) continue;
            bool ok = 0;
            for(int j = pos;j<n;j++)
            {
                tongs += (int)s[j] - '0';
                if(tongs > tongres) break;
                if(tongs == tongres)
                {
                    if(n - j != res.size() - pos - i + 1) break;
                    //cout<<pos<<' '<<j<<' '<<tongres<<' '<<i<<endl;
                    ok = 1;
                    for(int t = j+1, t1 = pos+i;t<n;t++, t1++)
                        if(s[t] != res[t1])
                        {
                            ok = 0;
                            break;
                        }
                    if(ok)
                    {
                        cout<<pos+1<<' '<<j+1;
                        return 0;
                    }
                }
            }
        }
        maxsum -= (int)res[pos] - '0';
    }


    return 0;
}

















