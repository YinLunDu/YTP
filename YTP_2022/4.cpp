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

int A[1005], C[1005], B[1005], D[1005];

signed main()
{
    IOS
    
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
        if (A[i] > C[i])
            swap(A[i], C[i]);
        if (B[i] > D[i])
            swap(B[i], D[i]);
    }

    int x, y, r;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> r;
        
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            int X, Y;
            if (x <= A[j])
                X = A[j];
            else if (C[j] <= x)
                X = C[j];
            else
                X = x;
                
            if (y <= B[j])
                Y = B[j];
            else if (D[j] <= y)
                Y = D[j];
            else
                Y = y;

            int dx = abs(x - X);
            int dy = abs(Y - y);
            if (dx * dx + dy * dy <= r * r)
                cnt++;
        }
        cout << cnt << "\n";
    }

    
    return 0;
}

