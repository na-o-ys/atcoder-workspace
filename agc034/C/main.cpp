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

void solve(ll n, ll x, vector<ll> B, vector<ll> L, vector<ll> U) {
    ll base = 0;
    loop (n, i) base += B[i] * L[i];

    V<ll> S(n);
    loop (n, i) S[i] = B[i] * L[i] + (x - B[i]) * U[i];

    V<int> I(n);
    iota(I.begin(), I.end(), 0);
    sort(I.begin(), I.end(), [&](auto a, auto b) {
        return S[a] > S[b];
    });

    V<ll> SS = S;
    loop (n - 1, i) SS[I[i + 1]] += SS[I[i]];

    ll left = 0, right = x * n + 1;
    while (left < right) {
        ll m = (left + right) / 2;

        ll k = m / x;
        ll r = m - k * x;

        ll best = 0;
        loop (n, i) {
            ll crr = 0;
            if (k) crr += SS[I[k - 1]];
            int j = I[i];
            crr += L[j] * min(B[j], r) + U[j] * max(0LL, r - B[j]);
            if (k < n && i <= k - 1) {
                crr += S[I[k]] - S[j];
            }
            best = max(best, crr);
        }
        if (base <= best) right = m;
        else left = m + 1;
    }
    cout << left << endl;
}

int main(){
    ll n, x;
    cin >> n >> x;
    vector<ll> B(n), L(n), U(n);
    loop (n, i) {
        cin >> B[i] >> L[i] >> U[i];
    }
    solve(n, x, move(B), move(L), move(U));
    return 0;
}

