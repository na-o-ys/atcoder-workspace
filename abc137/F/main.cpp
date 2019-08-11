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
    ModInt& operator/=(const ModInt& r) {
        auto s = r.pow(ModInt::M - 2);
        v = (v * s.v) % M;
        return *this;
    }
    ModInt operator-() const { return (M - v % M); }

    friend ModInt operator+(ModInt l, const ModInt& r) { return l += r; }
    friend ModInt operator-(ModInt l, const ModInt& r) { return l -= r; }
    friend ModInt operator*(ModInt l, const ModInt& r) { return l *= r; }
    friend ModInt operator/(ModInt l, const ModInt& r) { return l /= r; }
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

ModInt fact[100000] = {};
ModInt ifact[100000] = {};
void calc_fact(int m) {
    fact[0] = 1;
    for (int i = 1; i <= m; i++) {
        fact[i] = i * fact[i - 1];
    }
    for (int i = 0; i <= m; i++) {
        ifact[i] = fact[i].pow(ModInt::M - 2).v;
    }
}

ModInt comb(int n, int a) {
    return fact[n] * ifact[a] * ifact[n - a];
}

int main() {
    int p; cin >> p;
    ModInt::M = p;
    calc_fact(p + 10);
    V<int> A(p);
    loop (p, i) {
        cin >> A[i];
    }

    V<ModInt> B(p);
    loop (p, i) {
        if (A[i] == 0) continue;
        ModInt mi = 1;
        
        B[0] += 1;
        for (int j = p - 1; j >= 0; j--) {
            B[j] -= comb(p - 1, j) * mi;
            mi *= -i;
        };
    }

    loop (p - 1, i) {
        cout << B[i] << " ";
    }
    cout << B[p - 1] << endl;
    return 0;
}

