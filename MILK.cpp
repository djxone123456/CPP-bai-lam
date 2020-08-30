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

int m,n,k,chuan[2000006],cntch = 0,xet[2000006],cntxet = 0;
bool full[10000000];

bool greedy(int day)
{
    if(full[day] == 1) return 0;
    for(int i = 1;i<=cntch;i++)
        xet[i] = chuan[i];
    xet[cntch+1] = day;
    cntxet = cntch + 1;
    sort(xet+1,xet+cntxet+1);
    int dangxet = 0,soxet = 0;
    for(int i = 1;i<=cntxet;i++)
    {
        soxet++;
        if(dangxet > xet[i])
        {
            full[day] = 1;
            return 0;
        }
        if(soxet == k)
        {
            dangxet++;
            soxet = 0;
        }
    }
    cntch++;
    chuan[cntch] = day;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    #endif

    cin>>n>>m>>k;

    memset(full,0,sizeof(full));

    for(int i = 1;i<=n;i++)
        {
            int tmp;
            cin>>tmp;
            if(full[tmp]) {cout<<-1; return 0;}
            if(!greedy(tmp)) {cout<<-1; return 0;}
        }
    for(int j = 1;j<=m;j++)
        {
            int tmp;
            cin>>tmp;
            if(!full[tmp])
               greedy(tmp);
        }
    cout<<cntch - n;

    return 0;
}

















