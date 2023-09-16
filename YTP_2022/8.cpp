// #pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
#define STL(x) for(auto &HEHE:x) cout << HEHE << " "; cout << "\n";
#define lc (node << 1)
#define rc ((node << 1) | 1)
#define mid ((l + r) >> 1)
using namespace std;
void dbg() {;}
template<class T, class ...U>
void dbg(T a, U ...b) {cout << a << " "; dbg(b...);}
void enter() {cout << "\n";}

const int mod = 1e9 + 7;
const int INF = 1e18;
/// ------- Initialization End -------

vector <pii> order;
int a[200005];
struct Segment_tree
{
    int N;
    vector <int> info;
    Segment_tree(int n) : N(n), info(4 * n + 5) {}
    Segment_tree(vector <int> init) : Segment_tree(init.size()) { /// init : [0, N-1]
        function <void(int, int, int)> build = [&](int node, int l, int r) {
            if (l == r) {
                info[node] = init[l - 1];
                return;
            }
            build(lc, l, mid);
            build(rc, mid + 1, r);
            pull(node);
        };
        build(1, 1, N);
    }
    int merge(int a, int b) {
        return min(a, b);
    }
    void pull(int node) {
        info[node] = merge(info[lc], info[rc]);
    }
    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            info[node] += val;
            return;
        }
        if (idx <= mid)
            update(lc, l, mid, idx, val);
        else
            update(rc, mid + 1, r, idx, val);
        pull(node);
    }
    int query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return info[node];
        if (qr <= mid)
            return query(lc, l, mid, ql, qr);
        else if (mid+1 <= ql)
            return query(rc, mid + 1, r, ql, qr);
        else
            return merge(query(lc, l, mid, ql, qr), query(rc, mid + 1, r, ql, qr));
    }
    void update(int idx, int val) { update(1, 1, N, idx, val); }
    int query(int l, int r) { if (l > r) return 0; return query(1, 1, N, l, r); }
};

signed main()
{
    IOS
    
    int n;
    cin >> n;

    vector <int> v;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v.push_back(a[i]);
        order.push_back({a[i], i});
    }

    Segment_tree S(v);

    sort(order.begin(), order.end());

    set <int> now_idx;
    now_idx.insert(1);
    now_idx.insert(n + 1);

    int ans = -1;
    int res = n * S.query(1, n);
    ans = res;

    for (pii it : order) {
        int upd_idx = it.second;

        auto ptr = now_idx.upper_bound(upd_idx);
        auto ptr2 = prev(ptr);
        int l = *ptr2;
        int r = *(next(ptr2)) - 1;

        int del = (r - l + 1) * S.query(l, r);
        int add = ((upd_idx - 1) - l + 1) * S.query(l, upd_idx - 1) + (r - (upd_idx + 1) + 1) * S.query(upd_idx + 1, r);

        res = res - del + add;
        ans = max(ans, res);
        now_idx.insert(upd_idx);
        now_idx.insert(upd_idx + 1);
    }
    
    cout << ans << "\n";
    
    return 0;
}