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

ModInt prod(ll a, ll b) {
    ModInt ans = 1;
    loop (b, i) ans *= (a - i);
    return ans;
}

V<int> G[100010];
int k;
int vis[100010] = {};

ModInt dfs(int par, int node, int ancs, int sibs) {
    ModInt ans = 1;
    if (!vis[par]) {
        if (k - ancs < sibs) return 0;
        ans = prod(k - ancs, sibs);
        vis[par] = 1;
    }

    int n_sibs = 0;
    for (int c : G[node]) if (c != par) n_sibs++;
    for (int c : G[node]) {
        if (c == par) continue;
        ans *= dfs(node, c, min(ancs + 1, 2), n_sibs);
    }
    return ans;
}

int main() {
    ModInt::M = 1000000007;
    int n; cin >> n >> k;
    loop (n - 1, i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    cout << dfs(0, 1, 0, 1) << endl;
    return 0;
}


