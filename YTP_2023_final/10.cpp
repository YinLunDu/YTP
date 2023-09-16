// #pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
void dbg() {;}
template<class T, class ...U>
void dbg(T a, U ...b) {cout << a << " "; dbg(b...);}
void ent() {cout << "\n";}

const int mod = 1e9 + 7;
const int INF = 1e18;
/// ------- Initialization End -------

pii E[200005];
vector <pii> span[200005];
int depth[200005];
int par[25][200005];
int mx_w[25][200005];
bool chs[200005];
int round_cnt[200005];

void dfs(int v, int p)
{
    depth[v] = (p == -1 ? 1 : depth[p] + 1);
    for (pii u : span[v]) {
        if (u.first == p) continue;
        par[0][u.first] = v;
        mx_w[0][u.first] = u.second;
        dfs(u.first, v);
    }
}

int find_mx(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    int step = depth[a] - depth[b];
    int mx = -1;
    for (int i = 0; i <= 20; i++) {
        if (step & (1 << i)) {
            mx = max(mx, mx_w[i][a]);
            a = par[i][a];
        }
    }
    if (a == b)
        return mx;
    for (int i = 20; i >= 0; i--) {
        if (par[i][a] != par[i][b]) {
            mx = max(mx, mx_w[i][a]);
            mx = max(mx, mx_w[i][b]);
            a = par[i][a];
            b = par[i][b];
        }
    }
    mx = max(mx, mx_w[0][a]);
    mx = max(mx, mx_w[0][b]);
    return mx;
}

signed main()
{
    IOS

    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        E[i] = {a, b};
    }

    vector <pair<pii, int>> span_E;
    int x;
    for (int i = 1; i <= n - 1; i++) {
        cin >> x;
        chs[x] = true;
        span_E.push_back({E[x], x});
    }

    sort(span_E.begin(), span_E.end());

    int num = 0;
    for (auto it : span_E) {
        auto e = it.first;
        num++;
        span[e.first].push_back({e.second, num});
        span[e.second].push_back({e.first, num});
        round_cnt[it.second] = num;
    }

    dfs(1, -1);
    for (int lg = 1; lg <= 20; lg++) {
        for (int i = 1; i <= n; i++) {
            mx_w[lg][i] = max(mx_w[lg - 1][i], mx_w[lg - 1][par[lg - 1][i]]);
            par[lg][i] = par[lg - 1][par[lg - 1][i]];
        }
    }

    priority_queue <pair<int, pii>, vector <pair<int, pii>>, greater <pair<int, pii>>> not_ok;
    priority_queue <pair<pii, int>, vector <pair<pii, int>>, greater <pair<pii, int>>> can_use;
    for (int i = 1; i <= m; i++) {
        if (chs[i]) {
            can_use.push({{E[i].first, E[i].second}, round_cnt[i]});
            continue;
        }
        int res = find_mx(E[i].first, E[i].second);
        not_ok.push({res, E[i]});
        // dbg(res, E[i].first, E[i].second);
        // ent();
    }

    int cnt = 0;
    while (!can_use.empty()) {
        pii now = can_use.top().first;
        int round = can_use.top().second;
        cout << now.first << " " << now.second << "\n";
        can_use.pop();
        if (round != -1) {
            while (!not_ok.empty()) {
                if (not_ok.top().first != round) break;

                can_use.push({{not_ok.top().second}, -1});
                not_ok.pop();
            }
        }
    }

    return 0;
}