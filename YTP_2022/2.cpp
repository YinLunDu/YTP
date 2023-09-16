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

double a[15], b[15];
int N;

double fa(double x)
{
    double cnt = 0.0, res = 1.0;
    for (int i = 0; i < N; i++) {
        cnt += res * a[i];
        res *= x;
    }
    return cnt;
}

double fb(double x)
{
    double cnt = 0.0, res = 1.0;
    for (int i = 0; i < N - 1; i++) {
        cnt += res * b[i];
        res *= x;
    }
    return cnt;
}

signed main()
{
    IOS
    
    string s;
    getline(cin, s);
    
    stringstream ss(s);
    vector <int> v;

    int tmp;
    while (ss >> tmp)
        v.push_back(tmp);
    
    reverse(v.begin(), v.end());
    
    N = v.size();

    for (int i = 0; i < N; i++)
        a[i] = (double)(v[i]);
    
    for (int i = 0; i < N - 1; i++)
        b[i] = a[i + 1] * ((double)(i + 1));
/*
    for (int i = 0; i < N; i++)
        cout << setprecision(2) << a[i] << " ";
    cout << "\n";
    for (int i = 0; i < N - 1; i++)
        cout << setprecision(2) << b[i] << " ";
    cout << "\n";
*/
    double x = 0.0;

    for (int t = 1; t <= 100; t++) {
        x = x - fa(x) / fb(x);
        if (t > 1 && fabs(x) <= 0.0001)
            break;
    }

    printf("%.2lf\n", x);
    
    return 0;
}