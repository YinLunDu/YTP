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

int split[40005];
bool win[40005];

void solve()
{
    
}

/// 447

signed main()
{
    IOS

    split[0] = 1;
    win[0] = 0;

    int idx = 1;
    for (int i = 2; i <= 40000; i++) {
        if (i * (i + 1) / 2 >= 1000000000) break;

        bool w = false;
        for (int j = 0; j < idx; j++) {
            
        }
    }


    int t = 1;
    cin >> t;

    while (t--)
        solve();
    
    return 0;
}