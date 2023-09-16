#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mid ((l + r) >> 1)
#define lc ((node << 1))
#define rc ((node << 1) | 1)
using namespace std;

int a[100005];
int seg[4 * 100005];
bool tag[4 * 100005];

void build(int node, int l, int r)
{
    if (l == r) {
        seg[node] = a[l];
        return;
    }
    build(lc, l, mid);
    build(rc, mid + 1, r);
    seg[node] = seg[lc] + seg[rc];
}

void push(int node, int l, int r)
{
    if (tag[node]) {
        tag[lc] ^= 1;
        seg[lc] = (mid - l + 1) - seg[lc];
        tag[rc] ^= 1;
        seg[rc] = (r - (mid + 1) + 1) - seg[rc];

        tag[node] = 0;
    }
}

void update(int node, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr) {
        seg[node] = (r - l + 1) - seg[node];
        tag[node] ^= 1;
        return;
    }

    push(node, l, r);
    if (qr <= mid)
        update(lc, l, mid, ql, qr);
    else if (mid + 1 <= ql)
        update(rc, mid + 1, r, ql, qr);
    else {
        update(lc, l, mid, ql, qr);
        update(rc, mid + 1, r, ql, qr);
    }
    seg[node] = seg[lc] + seg[rc];
}

int query(int node, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
        return seg[node];
    
    push(node, l, r);
    if (qr <= mid)
        return query(lc, l, mid, ql, qr);
    else if (mid + 1 <= ql)
        return query(rc, mid + 1, r, ql, qr);
    else {
        return query(lc, l, mid, ql, qr) + query(rc, mid + 1, r, ql, qr);
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        a[i] = s[i - 1] - '0';
        if (a[i] == 1)
            a[i] = 0;
        else
            a[i] = 1;
    }

    build(1, 1, n);

    int x, y, z;
    while (q--) {
        cin >> x >> y >> z;
        if (x == 1) {
            update(1, 1, n, y, z);
        } else {
            int tmp = query(1, 1, n, y, z);
            int tmp2 = (z - y + 1) - tmp;
            cout << tmp * tmp2 << "\n";
        }

    }

    
    return 0;
}