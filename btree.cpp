#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF INT_MAX
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define ten "btree"

using namespace std;

typedef pair <int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef string bigint;

const int mod = 1e8;
int n, f[100003], directL[100003], directR[100003], N;
bool Link[100003];
unordered_map<int, bool> dd;
string s, s1, t;

//////////////////////Subtask 1//////////////////////////////

int ChangeDir(int node, char a)
{
    if(a == 'U') return max(1, node / 2);
    if(a == 'L') return node * 2;
    return node * 2 + 1;
}

int Trau(int pos, int node)
{
    if(pos > n)
    {
        bool ok = !dd[node];
        dd[node] = 1;
        return ok;
    }

    int res = 0;

    res += Trau(pos + 1, node);
    res += Trau(pos + 1, ChangeDir(node, s[pos]));

    return res;
}

void subtask1()
{
    dd.clear();
    int node = 1;
    s = s1;
    n = s1.size() - 1;
    for(int i = 1; i < t.size(); i++)
        node = ChangeDir(node, t[i]);


    cout << Trau(1, node) << "\n";
}

//////////////////////////////////////////////////////////////

///////////////////Initialize for subtask 2 & 3/////////////////

void initDirectLR()
{
    int L = 1, R = 1;

    for(int i = 1; i <= n; i++)
    {
        if(L <= i)
        {
            while(L <= n && s[L] != 'L' || L <= i) L++;
        }
        if(R <= i)
        {
            while(R <= n && s[R] != 'R' || R <= i) R++;
        }

        directL[i] = L;
        directR[i] = R;
    }
}

int trau(int pos)
{
    if(pos > n) return 0;

    int &res = f[pos];
    if(res != -1) return res;
    res = 1;

    res = (res + trau(directL[pos])) % mod;
    res = (res + trau(directR[pos])) % mod;

    return res;
}

////////////////////////////////////////////////////////////////

/////////////////////////Subtask 2//////////////////////////////

void subtask2()
{
    s = "#";
    for(int i = 0; i < s1.size(); i++)
        if(s1[i] != 'U') s += s1[i];

    n = s.size() - 1;
    initDirectLR();

    memset(f, 255, sizeof(f));

    cout << trau(1) << "\n";
}

///////////////////////////////////////////////////////////////////

//////////////////////////Subtask 3///////////////////////////////

void Changedir(char a)
{
    if(a == 'U') N = max(N - 1, 0);
    else
    if(a == 'L') Link[++N] = 0;
    else
    if(a == 'R') Link[++N] = 1;
}

int Process()
{
    int res = trau(1);

    for(int i = 1; i < t.size(); i++)
        Changedir(t[i]);

    for(int i = 2; i <= n; i++)
    {
        if(N <= 0) break;

        if(s[i] == 'U')
        {
            if(Link[N])
            {
                res = (res + trau(directL[i]) + 1) % mod;
            }
            else res = (res + trau(directR[i]) + 1) % mod;
            N--;
        }
    }

    return res;
}

void subtask3()
{
    N = 0;
    s = "#" + s1;

    n = s.size() - 1;
    initDirectLR();

    memset(f, 255, sizeof(f));

    cout << Process() << "\n";
}

//////////////////////////////////////////////////////////////////

void query()
{
    cin >> t >> s1;

//    if(s.size() <= 22) subtask1();
//    else if(t.size() == 1) subtask2();
//    else
    subtask3();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if(fopen("debug.inp", "r"))
    {
        freopen("debug.inp", "r", stdin);
        freopen("debug.ans", "w", stdout);
    }
    else
    {
        freopen(ten".inp", "r", stdin);
        freopen(ten".ans", "w", stdout);
    }

    int t;

    cin >> t;

    while(t--)
        query();

    return 0;
}
