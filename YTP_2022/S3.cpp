// #pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define adj u.first
#define id u.second
using namespace std;
void dbg() {;}
template<class T, class ...U>
void dbg(T a, U ...b) {cout << a << " "; dbg(b...);}
void enter() {cout << "\n";}

const int mod = 1e9 + 7;
const int INF = 1e18;
/// ------- Initialization End -------

set <pii> G[100005];
int a[100005];
bool vis[100005];
bool vis2[100005];
vector <int> ans;

int dfs_cal(int v, int p)
{
    vis2[v] = true;
    int sum = 0;
    for (pii u : G[v]) {
        if (adj == p) continue;
        if (!vis2[adj])
            sum += dfs_cal(adj, v);
    }
    return sum + a[v];
}

bool dfs(int v, int p)
{
    vis[v] = true;
    for (pii u : G[v]) {
        if (adj == p) continue;
        if (!vis[adj]) {
            if (!dfs(adj, v)) {
                ans.push_back(id);
                a[v] = !a[v];
                a[adj] = !a[adj];
            }
        }
    }
    if (a[v] == 1)
        return false;
    else
        return true;
}
/*
5 4
1 0 1 1 1
1 2
2 3
3 4
4 5
*/
signed main()
{
    IOS
    
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    int v, u;
    for (int i = 1; i <= m; i++) {
        cin >> v >> u;
        G[v].insert({u, i});
        G[u].insert({v, i});
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int cnt = dfs_cal(i, -1);
            if (cnt % 2 != 0) {
                cout << "No\n";
                return 0;
            }
            dfs(i, -1);
        }
    }

    cout << "Yes\n";
    cout << ans.size() << "\n";
    for (int it : ans)
        cout << it << " ";
    cout << "\n";

    return 0;
}