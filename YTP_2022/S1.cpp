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

signed main()
{
    IOS
    
    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();

    vector <string> v;

    bool out = false;
    for (int i = 0; i < m; i++) {
        if (i + n - 1 >= m) break;

        int cnt = 0;
        for (int j = 0, k = i; j < n; j++, k++) {
            if (a[j] != b[k])
                cnt++;
        }

        if (cnt <= 1) {
            out = true;
            string tmp = "";
            for (int k = i; k < i + n; k++)
                tmp += b[k];
            v.push_back(tmp);
        }
    }


    if (!out)
        cout << "Not found\n";
    
    sort(v.begin(), v.end());
    for (string s : v)
        cout << s << "\n";

    return 0;
}