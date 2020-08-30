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

int n,k;
int num[14] = {0};
int ngto[14] = {1,2 ,3 ,5 ,7 ,11 ,13 ,17 ,19 ,23 ,29 ,31 ,37 ,41};

ll lcm(ll a,ll b)
{
    return a*b/__gcd(a,b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    #endif

    cin>>n>>k;
    ///Sinh test
    //srand(time(NULL));
    //n = rand()% 9999 + 1;
    //k = rand()% 5 + 1;
    //cout<<n<<' '<<k<<endl;

    ull res = (1);
    for(int i=1;i<=n;i++)
    {
        int a,pos = 1;
        cin>>a;
        //a = rand() % 42 + 1;
        //cout<<a<<' ';
        res = lcm(a,res);

    }
    //cout<<res<<' ';
    //cout<<endl;

    if(k == 1) cout<<res;
    else
    {
        ll tmp = 1;
        for(int i=1;i<=13;i++)
        {
            num[i] = 0;
            while(res % ngto[i] == 0)
            {
                res/=ngto[i];
                num[i]++;
            }
            if(num[i] > 1)
            {
                if(num[i] % k) num[i]+=k;
                num[i] /= k;
            }
            tmp*=max(1,num[i]*ngto[i]);
        }
        cout<<tmp;
    }

    return 0;
}
