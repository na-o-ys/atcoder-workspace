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
using P = pair<ll, ll>;

ll dis(ll a, ll b, ll c, ll d) {
    return abs(a - c) + abs(b - d);
}

int main() {
    ll k, x, y; cin >> k >> x >> y;
    ll a = 0, b = 0;
    V<ll> Ax, Ay;

    while (dis(a, b, x, y) > k) {
        ll sx = x >= a ? 1 : -1;
        ll sy = y >= b ? 1 : -1;
        ll dx = min(abs(x - a), k);
        ll dy = min(abs(y - b), k - dx);
        a += dx * sx;
        b += dy * sy;
        Ax.push_back(a);
        Ay.push_back(b);
    };

    while (dis(a, b, x, y) != k) {
        ll d = dis(a, b, x, y);
        ll sx = x >= a ? 1 : -1;
        ll sy = y >= b ? 1 : -1;
        if (d % 2) {
            V<P> ps = { { a + k, b }, { a - k, b }, { a, b + k, }, { a, b - k } };
            for (P p : ps) {
                if (dis(p.first, p.second, x, y) <= k) {
                    a = p.first, b = p.second;
                    Ax.push_back(a);
                    Ay.push_back(b);
                }
            }
            continue;
        }

        
    }
    return 0;
}

