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

int m,n;
bool a[1000][1000];

int Tong(int x,int y)
{
    int tong = 0;
    for(int i = 1;i<=m-x+1;i++)
    {
        for(int j = 1;j<=n-y+1;j++)
        {
            //cout<<i<<' '<<j<<endl;
            bool ok = 1;
            for(int u = i;u<i+x;u++)
            {
                if(a[u][j])
                    {
                        ok = 0;
                        break;
                    }

                for(int v = j;v<j+y;v++)
                {
                    if(a[u][v])
                    {
                        ok = 0;
                        break;
                    }
                }
            }
            if(ok) tong++;
        }
    }
    //cout<<"mmmmmmmmmm"<<endl;
    cout<<tong<<' ';

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    #endif

    cin>>m>>n;

    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            {
                cin>>a[i][j];

            }

    for(int i = 1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            Tong(i,j);
        }
        cout<<endl;
    }

    return 0;
}

















