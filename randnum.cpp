#include <bits/stdc++.h>

#define getBit(x, i) (((x) >> (i)) & 1)

using namespace std;

int child[9000000][2] = {}, sum[9000000] = {}, cnt = 0;

void add(int s)
{
    int node = 0;

    for(short i = 30;i>= 0;i--)
    {
        short x = getBit(s, i);
        if(child[node][x] == 0)
        {
            child[node][x] = ++cnt;
        }

        sum[ child[node][x] ]++;
        node = child[node][x];
    }
}

int found(int k)
{
    int node = 0, res = 0;

    for(short i = 30;i>=0;i--)
    {
        if(k > sum[ child[node][0] ] || child[node][0] == 0)
        {
            res = (res << 1) | 1;
            k -= sum[ child[node][0] ];
            node = child[node][1];
        }
        else
        {
            res <<= 1;
            node = child[node][0];
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("randnum.inp","r",stdin);
    freopen("randnum.out","w",stdout);

    int q;

    cin>>q;

    while(q--)
    {
        int t, a;
        cin>>t>>a;

        if(t == 1)
        {
            add(a);
        }
        else
            cout<<found(a)<<'\n';
    }
    return 0;
}

















