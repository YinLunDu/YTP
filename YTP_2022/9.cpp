// #pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
#define STL(x) for(auto &HEHE:x) cout << HEHE << " "; cout << "\n";
using namespace std;
void dbg() {;}
template<class T, class ...U>
void dbg(T a, U ...b) {cout << a << " "; dbg(b...);}
void enter() {cout << "\n";}

const int mod = 1e9 + 7;
const int INF = 1e18;
/// ------- Initialization End -------

struct edge
{
    int v, u, rev, cap;
};

vector <edge> E;
vector <int> g[200005];
vector <int> G[200005];
int lvl[200005];
int p[200005];
int a[200005];

signed main()
{
    IOS
    
    int n, m;
    cin >> n >> m;


    for (int i = 1; i <= n; i++) cin >> a[i];

    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    int S = n + 1, T = n + 2;

    for (int i = 0; i < m; i++) {
        G[x].push_back(2 * i);
        G[y].push_back(2 * i + 1);
        E.push_back({x, y, 2 * i + 1, INF});
        E.push_back({y, x, 2 * i, INF});
    }

    return 0;
}