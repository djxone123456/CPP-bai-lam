#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define INF INT_MAX
#define MOD 442441073
#define BTtin "BMILKTEA"

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pi;
typedef unsigned long long ull;

char a[1000][1000];

ll trau(ll xp_x,ll xp_y, ll lt_x,ll lt_y,bool bot,bool sua,bool tra,ll len)
{
    if(xp_x > lt_x || xp_y > lt_y) return 0;

    if(a[xp_x][xp_y] == 'T') tra = 1;
    if(a[xp_x][xp_y] == 'S') sua = 1;
    if(a[xp_x][xp_y] == 'M') tra = 1,sua = 1;
    //if(tra && sua)
      if(a[xp_x][xp_y] == 'B') bot = 1;

    if(a[lt_x][lt_y] == 'T') tra = 1;
    if(a[lt_x][lt_y] == 'S') sua = 1;
    if(a[lt_x][lt_y] == 'M') tra = 1,sua = 1;
    if(a[lt_x][lt_y] == 'B') bot = 1;

    if(lt_x - xp_x + lt_y - xp_y <=1)
    {
        if(bot == 1 && sua == 1 && tra == 1 && len )
          return len;
        return 0;
    }

    ll res = 0;
    res = trau(xp_x + 1, xp_y, lt_x - 1, lt_y,bot,sua,tra);
    res %= MOD;
    res += trau(xp_x, xp_y + 1, lt_x - 1, lt_y,bot,sua,tra);
    res %= MOD;
    res += trau(xp_x + 1, xp_y, lt_x , lt_y - 1,bot,sua,tra);
    res %= MOD;
    res += trau(xp_x, xp_y + 1, lt_x , lt_y - 1,bot,sua,tra);
    res %= MOD;
    return res % MOD;
}

void question()
{
    ll n,m;
    bool bot = 0,sua = 0, tra = 0;
    cin>>m>>n;

    for(ll i = 1;i<=m;i++)
        for(ll j = 1;j<=n;j++)
           {
               cin>>a[i][j];
               if(a[i][j] == 'T') tra = 1;
               if(a[i][j] == 'S') sua = 1;
               if(a[i][j] == 'M') tra = 1,sua = 1;
               if(a[i][j] == 'B') bot = 1;
           }
    if((tra == 0 || sua == 0 || bot == 0))
    {
        cout<<0<<endl;
        return;
    }

    cout<<trau(1,1,m,n,0,0,0)%MOD<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen(BTtin".inp","r",stdin);
    freopen(BTtin".out","w",stdout);

    ll t;
    cin>>t;

    while(t--)
    {
        question();
    }

    return 0;
}


















