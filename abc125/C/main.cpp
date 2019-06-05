#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define loop1(n, i) for(int i=1;i<=n;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;

ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

void solve(long long N, std::vector<long long> A){
    V<ll> a1(N), a2(N);
    a1[0] = A[0];
    a2[N - 1] = A[N - 1];
    loop (N - 1, i) {
        a1[i + 1] = gcd(a1[i], A[i + 1]);
        a2[N - 1 - (i + 1)] = gcd(a2[N - 1 - i], A[N - 1 - (i + 1)]);
    }
    ll ans = 1;
    loop (N, i) {
        ll l = i == 0 ? a2[1] : a1[i - 1];
        ll r = i == N - 1 ? a1[N - 2] : a2[i + 1];
        ans = max(ans, gcd(l, r));
    }
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}

