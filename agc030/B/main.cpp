#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;


void solve(long long L, long long N, std::vector<long long> X){
    V<ll> xL(N + 1), xR(N + 1);
    loop (N, i) xL[i + 1] = X[i];
    loop (N, i) xR[i + 1] = L - X[N - 1 - i];
    V<ll> sumL(N + 1), sumR(N + 1);
    loop1 (N, i) sumL[i] = sum[i - 1] + X[i + 1];
    loop1 (N, i) sumR[i] = sum[i - 1] + L - X[N - 1 - i];

    ll ans = 0;

    loop (N + 1, i) {
        int l = i, r = N - i;
        int c = max(min(l, r), 1);
        ll lenL = 0, lenR = 0;
        if (l > 0) lenL = sumL[l] - sumL[l - c];
        if (r > 0) lenR = sumR[r] - sumR[r - c];
        ll tmp = lenL * 2 + lenR * 2 - min(X[l - 1]);
        ans = max(ans, a);
    }

    cout << ans << endl;
}

int main(){
    long long L;
    scanf("%lld",&L);
    long long N;
    scanf("%lld",&N);
    std::vector<long long> X(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&X[i]);
    }
    solve(L, N, std::move(X));
    return 0;
}

