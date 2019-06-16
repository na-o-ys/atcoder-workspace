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
    int n, x; cin >> n >> x;
    V<int> L(n);
    loop (n, i) cin >> L[i];

    int ans = 1;
    int p = 0;
    loop (n, i) {
        p += L[i];
        if (p <= x) ans++;
    }
    cout << ans << endl;
    return 0;
}

