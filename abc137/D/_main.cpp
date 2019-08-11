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
using P = pair<int, int>;

int main() {
    int n, m; cin >> n >> m;
    V<P> J(n);
    loop (n, i) {
        int a, b; cin >> a >> b;
        J[i] = { b, a };
    }
    sort(J.begin(), J.end(), greater<P>());

    V<int> ng(m + 1), wk(m + 1);
    ll ans = 0;
    loop (n, i) {
        int a = J[i].second, b = J[i].first;
        int p = m - a;
        int j = p;
        while (1) {
            if (j < 0 || ng[j]) {
                for (int k = max(j, 0); k <= p; k++) {
                    ng[k] = 1;
                }
                break;
            }
            if (!wk[j]) {
                wk[j] = 1;
                ans += b;
                break;
            }
            j--;
        }
    }

    cout << ans << endl;
    return 0;
}

