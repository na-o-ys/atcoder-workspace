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
    int n;
    ll k;
    cin >> n >> k;
    V<ll> A(n + 1, 0);
    loop (n, i) cin >> A[i + 1];

    loop (n, i) {
        A[i + 1] += A[i];
    }

    ll ans = 0;

    loop (n, i) {
        auto it = lower_bound(A.begin(), A.end(), k + A[i]);
        if (it == A.end()) continue;
        int d = distance(A.begin(), it);
        ans += n + 1 - d;
    }

    cout << ans << endl;
    return 0;
}

