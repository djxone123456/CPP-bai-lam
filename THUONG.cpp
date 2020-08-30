#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

const int base = 31;

ll p ,lt[1000000],lm,ln,arr[1000000], arr1[1000000];
string m,n;

ll hash_find(ll i, ll j, bool choose)
{
    if(!choose)
      return (arr[j] - arr[i - 1] * lt[j - i + 1]);

    return (arr1[j] - arr1[i - 1] * lt[j - i + 1]);
}

int ask(ll x, ll y)
{
    if(hash_find(x, y, 0) == hash_find(lm + 1 - y, lm + 1 - x, 1))
        return 1;
    return -1;
}

int main()
{
    cin>>m;

    lm = m.size();

    m = ' ' + m;

    arr[0] = 0;
    arr1[0] = 0;
    lt[0] = 1;

    for(int i = 1;i <= lm;i++)
        {
            arr[i] = (arr[i-1] * base + (int) m[i] - 'a' + 1);
            lt[i] = (lt[i-1] * base);
        }

    for(int i = lm; i>=1;i--)
    {
        arr1[lm - i + 1] = (arr1[lm - i] * base + (int)m[i] - 'a' + 1);
    }

    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        cout<<ask(x,y)<<endl;
    }

    return 0;
}
