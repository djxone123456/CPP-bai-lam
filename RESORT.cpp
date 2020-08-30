#include <bits/stdc++.h>

#define MP make_pair
#define pb push_back
#define INF INT_MAX
#define MOD 1000000007
#define BTtin "RESORT"

using namespace std;

typedef pair <int, int> pi;
typedef long long ll;
typedef unsigned long long ull;

int n,a[3],ngto[200000];
vector<int> snt;

void sang()
{
    int sum = a[1] + a[2] * 2;

    memset(ngto,1,sizeof(ngto));

    for(int i = 2;i*i<=sum;i++)
        for(int j = i*i;j<=sum;j+=i)
            ngto[j] = 0;

    for(int i = 2;i<=sum;i++)
        if(ngto[i]) snt.pb(i);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen(BTtin".inp","r",stdin);
    freopen(BTtin".out","w",stdout);

    cin>>n;

    for(int i = 1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        a[tmp]++;
    }
    sang();

    int sum = 0,dem = 0;
    for(int i = 0;i<snt.size();i++)
    {
        int cach = snt[i] - sum;
        sum = snt[i];
        if(cach % 2 == 0)
        {
            if(a[2] >= cach / 2)
            {
                a[2] -= cach / 2;
                dem++;
                continue;
            }
            else
            {
                cach -= a[2] * 2;
                a[2] = 0;
                if(a[1] >= cach)
                {
                    a[1]-= cach;
                    dem++;
                    continue;
                }
                else break;
            }
        }
        else
        {
            if(a[1] == 0)
            {
                if(a[2] >= (cach + 1) / 2)
                {
                    dem++;
                    a[2] -= (cach + 1) / 2;
                    continue;
                }
                else break;
            }
            sum++;
            if(a[2] >= cach / 2)
            {
                a[2] -= cach / 2;
                cach  = 1;
                a[1] --;
                dem++;
                continue;
            }
            else
            {
                cach -= a[2] * 2;
                a[2] = 0;
                if(a[1] >= cach)
                {
                    a[1]-= cach;
                    dem++;
                    continue;
                }
                else break;
            }

        }
    }
    cout<<dem;

    return 0;
}


















