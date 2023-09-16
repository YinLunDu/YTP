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

const int N = 500005;
int dp[N];
int bit[N];
int a[N];

void update(int idx, int val)
{
    while (idx <= 500000) {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

int qry(int idx)
{
    int sum = 0;
    while (idx > 0) {
        sum = (sum + bit[idx]) % mod;
        idx -= idx & -idx; 
    }
    return sum;
}

int query(int l, int r)
{
    return (((qry(r) - qry(l - 1)) % mod) + mod) % mod;
}

signed main()
{
    IOS
    
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1ll + query(max(1ll, a[i] - 2), min(n, a[i] + 2));
        update(a[i], dp[i]);

        // dbg(dp[i]);
        cnt = (cnt + dp[i]) % mod;
    }

    cout << cnt << "\n";

    return 0;
}