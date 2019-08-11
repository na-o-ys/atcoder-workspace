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
    ll MOD = 2019;
    ll l, r; cin >> l >> r;

    V<bool> I(MOD);
    for (ll i = l; i <= min(l + MOD - 1, r); i++) {
        I[i % MOD] = 1;
    }

    ll ans = MOD;
    loop (MOD, i) loop (MOD, j) {
        if (i == j || (!I[i] || !I[j])) continue;
        ans = min(ans, (i * j) % MOD);
    }

    cout << ans << endl;
    return 0;
}

