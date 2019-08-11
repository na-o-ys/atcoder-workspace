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

const int SMAX = 32000;
ModInt dp[110][SMAX][2] = {};
int main() {
    ModInt::M = 1000000007;
    ll n, k; cin >> n >> k;
    loop1 (32000 - 1, j) {
        dp[0][j][0] = 1;
        dp[0][j][1] = 1;
    }

    int sqn = 0;
    while (sqn * sqn <= n) sqn++;

    loop1 (k, i) {
        loop1 (sqn, j) {
            dp[i][j][0] = dp[i][j - 1][0] + dp[i - 1][j][1];
        }

        dp[i][sqn][1] = dp[i][n / sqn][0];
        for (int j = sqn - 1; j >= 1; j--) {
            ModInt cnt = n / j - n / (j + 1);
            dp[i][j][1] = dp[i][j + 1][1] + dp[i - 1][j][0] * cnt;
        }
    }

    cout << dp[k][1][1] << endl;
    return 0;
}

