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
        v = (v * r.pow(M - 2).v) % M;
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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ModInt fact(ll n) {
    if (n == 0) return 1;
    return ModInt(n) * fact(n - 1);
}

ModInt comb(ll n, ll a) {
    return fact(n) * (fact(a) * fact(n - a)).pow(ModInt::M - 2);
}

ll k[2];
const int MAX = 1010;

// patterns to generate
//   (1 2 ... l) (l+1 l+2 ... l+l) ... ((p-1)l (p-1)l+1 ... pl)
ModInt rec2(int l, int p, int k) {
    if (gcd(l, k) != 1) {
        if (p % k) return 0;
        ModInt ans = fact(p) / fact(k).pow(p / k) / fact(p / k);
        ans *= (fact(k - 1) * ModInt(l).pow(k - 1)).pow(p / k);
        return ans;
    }
    if (gcd(l, k) != 1 && (p % k)) return 0;
    ModInt ans = 1;
    loop1 (p / k, i) {
        ModInt t = fact(p) / fact(k).pow(i) / fact(p - k * i) / fact(i);
        t *= (fact(k - 1) * ModInt(l).pow(k - 1)).pow(i);
        ans += t;
    }
    return ans;
}

int vis[MAX][MAX] = {};
ModInt dp[MAX][MAX] = {};
ModInt rec(int n, int l) {
    if (n == 0 && l == 0) return 1;
    if (n == 0 || l == 0) return 0;

    if (vis[n][l]) return dp[n][l];
    vis[n][l] = 1;
    INSP(n);
    INSP(l);

    ModInt ans = 0;

    for (int p = 1; n - l * p >= 0; p++) {
        int m = n - l * p;
        for (int i = 0; i < l; i++) {
            ModInt t = comb(n, l * p);
            t *= fact(l * p) / fact(l).pow(p) / fact(p);
            t *= (fact(l) / l).pow(p);

            ans += rec(m, i) * rec2(l, p, k[0]) * rec2(l, p, k[1]) * t;
        }
    }

    dp[n][l] = ans;
    return ans;
}

int main() {
    ModInt::M = 1000000007;
    int n; cin >> n;
    ll x, y, z; cin >> x >> y >> z;
    k[0] = abs(x + z - y);
    k[1] = 2;

    ModInt ans = 0;
    loop1 (n, i) {
        ans += rec(n, i);
    }
    cout << ans << endl;

    return 0;
}

