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
    int n, d; cin >> n >> d;
    int X[15][15] = {};
    loop (n, i) loop (d, j) cin >> X[i][j];

    int SQ[300] = {};
    loop (300, i) SQ[i] = i * i;

    int ans = 0;
    loop (n, i) loop (n, j) {
        if (i >= j) continue;
        int z = 0;
        loop (d, k) {
            int v = X[i][k] - X[j][k];
            z += v * v;
        }
        loop (300, k) {
            if (z == SQ[k]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

