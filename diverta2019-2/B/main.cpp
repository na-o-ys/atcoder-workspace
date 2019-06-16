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
    int n; cin >> n;
    V<ll> X(n), Y(n);
    loop (n, i) cin >> X[i] >> Y[i];

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    int ans = 1<<29;
    loop (n, i) loop (n, j) {
        if (i == j) continue;
        ll p = X[i] - X[j], q = Y[i] - Y[j];
        int cnt = 0;
        loop (n, s) loop (n, t) {
            if (X[s] - X[t] == p && Y[s] - Y[t] == q) cnt++;
        }
        ans = min(ans, n - cnt);
    }
    cout << ans << endl;
    return 0;
}

