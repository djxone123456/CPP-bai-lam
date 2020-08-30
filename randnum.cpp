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
#define Task "randnum"
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


int Child[10000000][2];
int val[10000000], num[10000000];
int n, q, cnt = 0;

void Add(int x){
    int node = 0;
    for (short i = 30; i >= 0; i--)
    {
        short ch = bit(x,i);
        if (Child[node][ch] == 0) Child[node][ch] = ++ cnt;
        node = Child[node][ch];
        num[node] ++;
    }
    val[node] = x;
}

int Get(int k){
    int node = 0;
	int res = 0;
    for (short i = 30; i >= 0; i--)
    {
        if (Child[node][0] == 0 || k > num[Child[node][0]]){
            k -= num[Child[node][0]];
            node = Child[node][1];
			res = res * 2 + 1;
        } else node = Child[node][0], res = res * 2;
    }
    return res;
}

int main()
{
	//ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    //cin >> n >> q;
	int test, type, x;
	read(test);
	while (test--){
        read(type);
        read(x);
		if (type == 1) Add(x);
            else writeln(Get(x));
	}

    return 0;
}
