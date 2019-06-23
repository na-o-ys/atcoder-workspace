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

struct ModInt {
    ll v;
    static unsigned M;
    ModInt() : v(0) {}
    ModInt(ll x) : v((x % M + M) % M) {}

    ModInt& operator+=(const ModInt& r) {
        v = (v + r.v) % M;
        return *this;
    }
    ModInt& operator-=(const ModInt& r) {
        v = (v - r.v + M) % M;
        return *this;
    }
    ModInt& operator*=(const ModInt& r) {
        v = (v * r.v) % M;
        return *this;
    }
    ModInt operator-() const { return (M - v % M); }

    friend ModInt operator+(ModInt l, const ModInt& r) { return l += r; }
    friend ModInt operator-(ModInt l, const ModInt& r) { return l -= r; }
    friend ModInt operator*(ModInt l, const ModInt& r) { return l *= r; }
    friend bool operator==(ModInt l, const ModInt& r) { return l.v == r.v; }
    friend bool operator!=(ModInt l, const ModInt& r) { return !(l == r); }

    ModInt pow(ll n) const {
        ModInt base = *this, ans = 1;
        while (n) {
            if (n & 1) ans *= base;
            base *= base;
            n /= 2;
        }
        return ans;
    }
};
unsigned ModInt::M;
ostream& operator<<(ostream& o, const ModInt& r) {
    o << r.v;
    return o;
}

template <class T>
using Mat = V<V<T>>;

template <class T>
Mat<T> product(const Mat<T>& a, const Mat<T>& b) {
    int lrows = a.size();
    int lcols = a[0].size();
    int rcols = b[0].size();

    Mat<T> ret(lrows, V<T>(rcols, 0));
    loop (lrows, i) loop (rcols, j) loop (lcols, k) {
        ret[i][j] += a[i][k] * b[k][j];
    }
    return ret;
}

template <class T>
Mat<T> pow(const Mat<T>& a, ll n) {
    int rows = a.size();
    auto base = a;
    Mat<T> ans(rows, V<T>(rows, 0));
    loop (rows, i) ans[i][i] = 1;

    while (n) {
        if (n & 1) ans = product(ans, base);
        base = product(base, base);
        n /= 2;
    }
    return ans;
}

template <class T>
ostream& operator<<(ostream& o, const Mat<T>& r) {
    int rows = r.size();
    int cols = r[0].size();
    loop (rows, i) {
        loop (cols, j) {
            o << r[i][j] << " ";
        }
        o << endl;
    }
    return o;
}

int main() {
    ll l, a, b; cin >> l >> a >> b >> ModInt::M;
    ll crr = a;

    ModInt x = 0, s = a;

    loop1 (18, d) {
        ll last = 1;
        loop (d, i) last *= 10;
        last--;
        last = min(last, a + b * (l - 1));
        if (last < crr) continue;
        ll c = (last - crr) / b + 1;
        crr += b * c;

        ModInt shift = ModInt(10).pow(d);
        Mat<ModInt> mat = {
            { shift, 0, 0 },
            { 1, 1, 0 },
            { 0, b, 1 }
        };
        mat = pow(mat, c);

        auto nx = x * mat[0][0] + s * mat[1][0] + mat[2][0];
        auto ns = x * mat[0][1] + s * mat[1][1] + mat[2][1];
        x = nx, s = ns;
    }

    cout << x << endl;

    return 0;
}

