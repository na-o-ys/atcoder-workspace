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

class BIT
{
public:
    vector<int> bit;
    int M;

    BIT(int M):
        bit(vector<int>(M+1, 0)), M(M) {}

    int sum(int i) {
        if (!i) return 0;
        return bit[i] + sum(i-(i&-i));
    }

    void add(int i, int x) {
        if (i > M) return;
        bit[i] += x;
        add(i+(i&-i), x);
    }
};

int main() {
    int n, m; cin >> n >> m;
    V<P> J(n);
    loop (n, i) {
        int a, b; cin >> a >> b;
        J[i] = { b, a };
    }
    sort(J.begin(), J.end(), greater<P>());

    BIT wk((m + 10) * 2);
    ll ans = 0;
    loop (n, i) {
        int a = J[i].second, b = J[i].first;
        int p = m - a;
        if (p < 0) continue;

        int l = 0, r = p + 1;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (m <= 0) {
                if (wk.sum(1) == 1) l = -1;
                else l = 0;
                break;
            }
            if (wk.sum(p + 1) - wk.sum(m) == p - m + 1) {
                r = m;
            } else {
                l = m;
            }
        }
        if (l < 0) continue;
        if (wk.sum(l + 1) - wk.sum(l)) continue;
        wk.add(l + 1, 1);
        ans += b;
    }

    // loop (m + 1, i) {
    //     cout << i << ": " << wk.sum(i + 1) - wk.sum(i) << endl;
    // }

    cout << ans << endl;
    return 0;
}

