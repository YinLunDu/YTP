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
void ent() {cout << "\n";}

const int mod = 1e9 + 7;
const int INF = 1e18;
/// ------- Initialization End -------

int a[1000005];

signed main()
{
    IOS
    
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];

    int sum = 0;
    int mx = -INF, mn = INF;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        if (sum > mx) mx = sum;
        if (sum < mn) mn = sum;
        // dbg(mn, mx); ent();
    }

    cout << min(0ll, mn) << " " << max(0ll, mx) << "\n";

    for (int i = 1; i < n; i++) {
        mn = mn - a[i];
        mx = mx - a[i];
        // dbg(mn, mx); ent();
        mn = min(mn, sum);
        mx = max(mx, sum);
        cout << min(0ll, mn) << " " << max(0ll, mx) << "\n";

        // ent();
    }

    return 0;
}