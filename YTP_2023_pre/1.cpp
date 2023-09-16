// #pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
void dbg() {;}
template<class T, class ...U>
void dbg(T a, U ...b) {cout << a << " "; dbg(b...);}
void ent() {cout << "\n";}

const int mod = 1e9 + 7;
const int INF = 1e18;
/// ------- Initialization End -------

signed main()
{
    IOS
    
    int nx1, nx2, nx3, ny1, ny2, ny3;
    int dx1, dx2, dx3, dy1, dy2, dy3;

    cin >> nx1 >> ny1 >> nx2 >> ny2 >> nx3 >> ny3;
    cin >> dx1 >> dy1 >> dx2 >> dy2 >> dx3 >> dy3;

    int A[3];
    A[0] = (nx1 - nx2) * (nx1 - nx2) + (ny1 - ny2) * (ny1 - ny2);
    A[1] = (nx1 - nx3) * (nx1 - nx3) + (ny1 - ny3) * (ny1 - ny3);
    A[2] = (nx2 - nx3) * (nx2 - nx3) + (ny2 - ny3) * (ny2 - ny3);

    int B[3];
    B[0] = (dx1 - dx2) * (dx1 - dx2) + (dy1 - dy2) * (dy1 - dy2);
    B[1] = (dx1 - dx3) * (dx1 - dx3) + (dy1 - dy3) * (dy1 - dy3);
    B[2] = (dx2 - dx3) * (dx2 - dx3) + (dy2 - dy3) * (dy2 - dy3);
    
    sort(A, A + 3);
    sort(B, B + 3);

    int q;
    cin >> q;

    while (q--) {
        int qx1, qy1, qx2, qy2, qx3, qy3;
        cin >> qx1 >> qy1 >> qx2 >> qy2 >> qx3 >> qy3;
        int arr[3];
        arr[0] = (qx1 - qx2) * (qx1 - qx2) + (qy1 - qy2) * (qy1 - qy2);
        arr[1] = (qx1 - qx3) * (qx1 - qx3) + (qy1 - qy3) * (qy1 - qy3);
        arr[2] = (qx2 - qx3) * (qx2 - qx3) + (qy2 - qy3) * (qy2 - qy3);
        sort(arr, arr + 3);

        bool f = true;
        for (int i = 0; i < 3; i++) {
            if (arr[i] != A[i]) {
                f = false;
                break;
            }
        }
        if (f) {
            cout << "Nijika\n";
            continue;
        }
        f = true;
        for (int i = 0; i < 3; i++) {
            if (arr[i] != B[i]) {
                f = false;
                break;
            }
        }
        if (f) {
            cout << "Doritos\n";
            continue;
        }

        cout << "None\n";
    }

    return 0;
}