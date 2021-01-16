//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x < y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "convex"
#define maxn 200003
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define pii3 pair < pii , int>

using namespace std;

struct toado
{
    int x, y, id;
};

toado a[maxn], b[maxn];
int n, sl, m;

void nhap()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].id = i;
    }
}

bool comp (toado p, toado q)
{
    return (p.x < q.x || (p.x == q.x && p.y < q.y));
}

pii Vect(toado p, toado q)
{
    return mp(q.x - p.x, q.y - p.y);
}

long long CCW(toado p, toado q, toado r)
{
    pii u = Vect(p,q);
    pii v = Vect(q,r);
    return (1ll * u.F * v.S - 1ll * u.S * v.F);
}

bool comp2 (toado p, toado q)
{
    long long cw = CCW(a[1], p, q);
    if (cw == 0) return (comp(p,q));
    return ( cw> 0);
}


void Make_convex(toado a[], int n, toado b[], int &m)
{
    sort (a+1, a+n+1, comp);
    sort (a+2, a+n+1, comp2);
    b[m=1] = a[1];
    for (int i = 2; i <= n; i++){
        while (m > 1 && CCW(b[m-1], b[m], a[i]) <= 0) m--;
        b[++m] = a[i];
    }
}

double KC( toado p, toado q)
{
    long long hx = p.x - q.x;
    long long hy = p.y - q.y;
    return sqrt(hx*hx + hy*hy);
}

int main()
{
	//ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    nhap();
    Make_convex(a, n, b, m);
    printf("%d\n",m);
    for (int i = 1; i <= m; i++) printf("%d ",b[i].id) ;
    b[m+1] = b[1];
    long long dientich = 0;
    double chuvi = 0.0;
    for (int i = 1; i <= m; i++)
    {
        dientich += 1ll*(b[i].x - b[i+1].x) * (b[i].y + b[i+1].y);
        chuvi += KC(b[i], b[i+1]);
    }
    printf("\n%0.6f\n", chuvi);
    printf("%lld.%d", dientich/2, ((dientich % 2) ? 5 : 0));
    //cout << fixed << setprecision(6) << chuvi;
    return 0;
}
