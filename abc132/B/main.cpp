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
    V<int> P(n);
    loop (n, i) cin >> P[i];

    int ans = 0;
    loop (n - 2, i) {
        if (min(P[i], P[i + 2]) < P[i + 1] && max(P[i], P[i + 2]) > P[i + 1]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

