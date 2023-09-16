#pragma GCC optimize("Ofast,unroll-loops,O3")
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
void ent() {cout << "\n";}

const int mod = 1e9 + 7;
const int INF = 1e18;
/// ------- Initialization End -------

struct DSU
{
    int N;
    vector <int> f, sz;
    DSU(int x) {
        init(x);
    }
    void init(int n) {
        N = n;
        f.resize(n + 1);
        iota(f.begin(), f.end(), 0);
        sz.assign(n + 1, 1);
    }
    int find(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        f[y] = x;
        return true;
    }
    bool same(int x, int y) {
        return (find(x) == find(y) ? true : false);
    }
};

vector <pii> G[200005];
int dp[20][200005];
int par[20][200005];
int depth[200005];

void dfs(int v, int p)
{
    depth[v] = (p == -1 ? 1 : depth[p] + 1);
    for (auto [u, w] : G[v]) {
        if (u == p) continue;
        dp[0][u] = w;
        par[0][u] = v;
        dfs(u, v);
    }
}

void build(int N)
{
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][par[i - 1][j]]);
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }
}

int find_mx_w(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    int step = depth[a] - depth[b];
    int res = -1;
    for (int i = 0; i < 20; i++)
        if (step & (1 << i)) {
            res = max(res, dp[i][a]);
            a = par[i][a];
        }
    if (a == b) return res;
    
    for (int i = 19; i >= 0; i--) {
        if (par[i][a] != par[i][b]) {
            res = max(res, dp[i][a]);
            res = max(res, dp[i][b]);
            a = par[i][a];
            b = par[i][b];
        }
    }
    res = max(res, dp[0][a]);
    res = max(res, dp[0][b]);
    return res;
}

struct queries
{
    int k, t;
    vector <int> peo;
};
vector <queries> ask;

signed main()
{
    IOS
    
    int n, q;
    cin >> n >> q;

    DSU D(n);

    int k, a, b;
    int op;
    int times = 0;

    while (q--) {
        times++;
        cin >> op;

        if (op == 1) {
            cin >> a >> b;
            if (!D.same(a, b)) {
                D.merge(a, b);
                G[a].push_back({b, times});
                G[b].push_back({a, times});
            }
        } else {
            cin >> k;
            queries tmp;
            tmp.k = k;
            tmp.t = times;
            tmp.peo.clear();
            for (int i = 1; i <= k; i++) {
                cin >> a;
                tmp.peo.push_back(a);
            }
            ask.push_back(tmp);
        }
    }

    dfs(1, -1);
    build(n);

    

    for (queries Q : ask) {
        vector <int> tmp = Q.peo;
        bool fail = false;
        int ans = -1;
        for (int i = 1; i < Q.k; i++) {
            if (!D.same(tmp[0], tmp[i])) {
                fail = true;
                break;
            } else {
                // dbg(tmp[0], tmp[i], find_mx_w(tmp[0], tmp[i]));
                ans = max(ans, find_mx_w(tmp[0], tmp[i]));
            }
        }
        if (fail || ans > Q.t)
            cout << -1 << "\n";
        else
            cout << ans << "\n";
    }

    return 0;
}