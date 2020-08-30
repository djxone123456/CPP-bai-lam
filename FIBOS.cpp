#include <bits/stdc++.h>
#define p 1000000007

using namespace std;
long long n;

struct Matrix
{
    vector<vector<long long>> x;

    void init_3(long long a, long long b, long long c)
    {
        x.clear();
        x.push_back({a});
        x.push_back({b});
        x.push_back({c});
    }

    void init_9(vector<long long> a, vector<long long> b, vector<long long> c)
    {
        x.clear();
        x.push_back(a);
        x.push_back(b);
        x.push_back(c);
    }

    Matrix operator * (Matrix a)
    {
        Matrix C;
        int h = x.size(), w=a.x[0].size();
        if(w==1) C.init_3(0, 0, 0);
        else C.init_9({0, 0, 0}, {0, 0, 0}, {0, 0, 0});
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                for(int z=0; z<3; z++)
                {
                    C.x[i][j] = (C.x[i][j]+(x[i][z]*a.x[z][j])%p)%p;
                }
            }
        }
        return C;
    }

    Matrix POW(long long a)
    {
        if(a==1) return (*this);
        if(a==2) return (*this) * (*this);
        Matrix B = POW(a/2);
        if(a%2) return B*B*(*this);
        return B*B;
    }

    void print()
    {
        for(vector<long long> a: x)
        {
            for(long long b: a) cout<<b<<" "; cout<<"\n";
        }
    }

}A, B;

int main()
{
    freopen("FIBOS.inp", "r", stdin);
    freopen("FIBOS.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    B.init_9({0, 1, 0}, {1, 1, 0}, {1, 1, 1});
    A.init_3(1, 1, 2);
    cin>>n;
    if(n==1) return cout<<2, 0;
    B = B.POW(n-1);
    A = B*A;
    cout<<A.x[2][0];
    return 0;
}
