#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define loop1(n, i) for(int i=1;i<=n;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;


void solve(long long N, std::vector<long long> A){
    sort(A.begin(), A.end());
    ll ans = 0;
    loop (N / 2, i) {
        ll v = A[i * 2] + A[i * 2 + 1];
        ans += max(v, -v);
    }
    if (N % 2) ans += A[N - 1];
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

