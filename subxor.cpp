
//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "subxor"
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define bit(x, i) (((x) >> (i)) & 1)



using namespace std;

template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar())) x=x*10+c-48;if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}


int Next[3000000][2];
int val[3000000], sl[3000000];
int a[maxn];
int n, k, cnt = 0;
long long res = 0;
void Add(int x){
    int node = 0;
    for (short i = 30; i >= 0; i--)
    {
        short ch = bit(x,i);
        if (Next[node][ch] == 0) Next[node][ch] = ++ cnt;
        node = Next[node][ch];
        sl[node] ++;
    }
    val[node] = x;
}

void Calc(int x){
    int node = 0;
    for (short i = 30; i >= 0; i--)
    {
        short curbit = bit(x,i);
        short dest = bit(k,i);
        if (dest) res += sl[Next[node][curbit]];
        short mov = dest ^ curbit;
        if (!Next[node][mov]) break;
        node = Next[node][mov];
    }
}

int main()
{
	//ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    read(n);
    read(k);
    Add(0);
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		a[i] ^= a[i-1];
        Calc(a[i]);
        Add(a[i]);
	}
	cout << res;
	//cerr << res;
    return 0;
}


