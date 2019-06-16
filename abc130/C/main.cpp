#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define loop1(n, i) for(int i=1;i<=n;i++)
#define rloop(n, i) for(int i=n;i;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;

int main() {
    ll w, h, x, y; cin >> w >> h >> x >> y;
    cout << fixed << setprecision(14);
    cout << 1.0 * w * h / 2.0 << " ";

    if (x * 2 == w && y * 2 == h) {
        cout << "1";
    } else {
        cout << "0";
    }
    cout << endl;
    return 0;
}

