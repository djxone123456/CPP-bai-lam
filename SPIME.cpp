#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define INF INT_MAX
#define MOD 1000000007
#define BTtin "SPIME"

using namespace std;

typedef pair <int, int> pi;
typedef long long ll;
typedef unsigned long long ull;

int n,cnt = 0;
bool ngto[10000000];

void sang(int last)
{
    if(last == (int)1e7) last--;
    memset(ngto,1,sizeof(ngto));

    ngto[0] = 0;
    ngto[1] = 0;

    for(int i=2;i*i<=last;i++)
    {
        for(int j=i*i;j<=last;j+=i)
            ngto[j] = 0;
    }
    for(int i=2;i<=last;i++)
        if(ngto[i]) cnt++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen(BTtin".inp","r",stdin);
    freopen(BTtin".out","w",stdout);

    cin>>n;

    sang(n);

    int tmp = 0,abc = 0;
    if(cnt == 1)
    {
        cout<<0<<' '<<0<<endl;
        return 0;
    }
    if(cnt == 2)
    {
        cout<<1<<' '<<0<<endl;
        return 0;
    }
    if(cnt == 3)
    {
        cout<<1<<' '<<1<<endl;
        return 0;
    }
    if(cnt == 4)
    {
        cout<<0<<' '<<1<<endl;
        return 0;
    }
    cout<<cnt;
    while(1)
    {
        tmp++;
        if((abc+tmp*4) > cnt) break;
        abc += tmp*4;
    }
    tmp --;
    int x = - tmp ;
    int y = tmp;
    cnt -= max(0,(tmp+1) * 4 + 1);
    cout<<tmp;
    cout<<cnt;
    if(cnt == 0)
    {
        cout<<x<<' '<<y;
        return 0;
    }

    for(int i=1;i<=tmp+1;i++)
    {
        if(cnt > 0)
        {
            cnt--;
            y--;
        }
        else
        {
            //cout<<1;
            cout<<x<<' '<<y;
            return 0;
        }
    }

    for(int i=1;i<=tmp+2;i++)
    {
        if(cnt > 0)
        {
            cnt--;
            x ++;
        }
        else
        {
            //cout<<2;
            cout<<x<<' '<<y;
            return 0;
        }
    }

    for(int i=1;i<=tmp+2;i++)
    {
        if(cnt > 0)
        {
            cnt--;
            y ++;
        }
        else
        {
            //cout<<3;
            cout<<x<<' '<<y;
            return 0;
        }
    }

    for(int i=1;i<=tmp+2;i++)
    {
        if(cnt > 0)
        {
            cnt--;
            x --;
        }
        else
        {
            //cout<<4;
            cout<<x<<' '<<y;
            return 0;
        }
    }
    return 0;
}


















