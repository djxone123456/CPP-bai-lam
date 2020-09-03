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

string s;
int mo = 0, dong = 0;

void choi()
{

    int pos = 0, prev = 0;

    for(int i = s.size() - 1;i>=0;i--)
    {
        if(s[i] == ')')
            pos++;
       else pos--;
       if(pos < 0)
       {
           mo = max(mo, (int)s.size() - i);
           pos = 0;
       }
    }

    pos =0;

    for(int i = 0;i<s.size();i++)
    {
        if(s[i] == '(')
            pos++;
       else pos--;
       if(pos < 0)
       {
           dong = max(dong, i + 1);
           pos = 0;
       }
    }

    if(mo == 0) cout<<0;
    else
      cout<<min(mo, dong);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    #endif

    cin>>s;

    int sum = 0;

    for(int i = 0;i<s.size();i++)
      if(s[i] == '(')
            sum++;
      else sum--;

    if(sum != 0)
    {
        cout<<-1;
        return 0;
    }

    if(s.size() >= 10)
      choi();

    return 0;
}
