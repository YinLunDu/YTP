// #pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
void dbg() {;}
template<class T, class ...U>
void dbg(T a, U ...b) {cout << a << " "; dbg(b...);}
void enter() {cout << "\n";}
/// ------- Initialization End -------

void solve()
{
    int n, m, a1, a2, b1, b2, c1, c2, d1, d2;
    cin >> n >> m >> a1 >> a2 >> b1 >> b2 >> c1 >> c2 >> d1 >> d2;

    int x1 = a1, y1 = a2;
    int x2 = b1, y2 = b2;
    int x3 = c1, y3 = c2;
    int x4 = d1, y4 = d2;

    if (a1 > b1)
        swap(a1, b1);
    if (a2 > b2)
        swap(a2, b2);
    if (c1 > d1)
        swap(c1, d1);
    if (c2 > d2)
        swap(c2, d2);
    
    int x = min(b1, d1) - max(a1, c1) + 1;
    int y = min(b2, d2) - max(a2, c2) + 1;

    if (min(b1, d1) - max(a1, c1) < 0 || min(b2, d2) - max(a2, c2) < 0)
        cout << 0 << "\n";
    else {
        if (x1 > x2) {
            swap(x1, x2); swap(y1, y2);
        }
        if (x3 > x4) {
            swap(x3, x4); swap(y3, y4);
        }

        if ((y1 <= y2 && y3 <= y4) || (y1 >= y2 && y3 >= y4))
            cout << x + y + 1 << "\n";
        else
            cout << max(x, y) + 1 << "\n";
    }
}

/*
1
4 5 4 1 1 3 4 5 1 1
*/

signed main()
{
    IOS
    int t = 1;
    cin >> t;

    while (t--)
        solve();
    
    return 0;
}