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
using M = V<V<ll>>;
const int MSIZE = 3;

ll m;

void printmat(M a) {
    loop (MSIZE, i) {
        loop (MSIZE, j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

M matmul(M a, M b) {
    M ret = V<V<ll>>(MSIZE, V<ll>(MSIZE));
    loop (MSIZE, i) loop (MSIZE, j) {
        loop (MSIZE, s) {
            ret[i][j] += a[i][s] * b[s][j] % m;
            ret[i][j] %= m;
        }
    }
    return ret;
}

int main() {
    ll l, a, b; cin >> l >> a >> b >> m;
    ll crr = a;

    ll x = 0, s = a % m;

    loop1 (18, d) {
        ll last = 1;
        loop (d, i) last *= 10;
        last--;
        last = min(last, a + b * (l - 1));
        if (last < crr) continue;
        ll c = (last - crr) / b + 1;
        crr += b * c;

        ll shift = 1;
        loop (d, i) shift = (shift * 10) % m;
        M base = {
            { shift, 0, 0 },
            { 1, 1, 0 },
            { 0, b % m, 1 }
        };
        M mat = { { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 } };

        while (c) {
            if (c % 2) mat = matmul(mat, base);
            base = matmul(base, base);
            c /= 2;
        }

        ll nx = (x * mat[0][0] + s * mat[1][0] + mat[2][0]) % m;
        ll ns = (x * mat[0][1] + s * mat[1][1] + mat[2][1]) % m;
        x = nx, s = ns;
    }

    cout << x << endl;

    return 0;
}

