#include <bits/stdc++.h>

#define x first
#define y second
#define MP make_pair
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pi;

bool dd[300000];
pi toado[300000];
ll n,dai,hcn = 0;

bool compare(pi a,pi b)
{
    if(a.x != b.x) return a.x < b.x;
    return a.y > b.y;
}

struct bro
{
  ll result = 0;
  ll posh = 0, posw = 0;
};

int main()
{
    #ifdef hello
      freopen("debug.inp","r",stdin);
      freopen("debug.out","w",stdout);
    #endif // hello

    cin>>n>>dai;

    for(ll i = 1;i<=n;i++)
    {
        cin>>toado[i].x>>toado[i].y;
    }
    sort(toado+1,toado+1+n);

    #ifdef hello
    for(ll i = 1;i<=n;i++)
    {
        dd[i] = 0;
        cout<<toado[i].x<<' '<<toado[i].y<<endl;
    }
    cout<<endl;
    #endif // hello

    for(ll i = 1;i<=n;i++)
        {
            if(!dd[i])
            {
                dd[i] = 1;
                bro res;
                ll cnt = 0;
                for(ll j = toado[i].y; j<=dai;j++)
                {
                        cnt = 0;
                        ll height = dai / j + toado[i].x;
                        ll width = j;


                        for(ll t = i+1;t<=n;t++)
                        {
                            if((toado[t].x >= toado[i].x) &&
                               (toado[t].x <= height) &&
                               (toado[t].y <= width)
                               && (!dd[t]))
                                cnt++;
                        }
                        if(cnt > res.result)
                        {
                            res.result = cnt;
                            res.posh = height;
                            res.posw = width;
                        }
                }

                if(res.result > 0)
                {
                    #ifdef hello
                    cout<<res.result<<' '<<toado[i].x<<' '<<toado[i].y<<endl;
                    #endif // hello
                    for(ll t = i+1;t<=n;t++)
                     {
                        if((toado[t].x >= toado[i].x) &&
                          (toado[t].x <= res.posh) &&
                          (toado[t].y <= res.posw) && (!dd[t]))
                          {
                              dd[t] = 1;
                          }
                    }
                }
                hcn++;
            }
        }
    cout<<hcn;
    return 0;
}
