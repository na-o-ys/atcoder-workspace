#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define loop1(n, i) for(int i=1;i<=n;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;


void solve(int X, int Y, int Z, int K, std::vector<long long> A, std::vector<long long> B, std::vector<long long> C){
    auto a = A;
    V<ll> b(Y * Z);
    loop (Y * Z, i) {
        b[i] = B[i % Y] + C[i / Y];
    }
    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end(), greater<>());

    V<ll> ans;
    loop (X, i) loop (min(K, Y * Z), j) {
        ans.push_back(a[i] + b[j]);
    }
    sort(ans.begin(), ans.end(), greater<>());
    loop (K, i) cout << ans[i] << endl;
}

int main(){
    long long X;
    scanf("%lld",&X);
    long long Y;
    scanf("%lld",&Y);
    long long Z;
    scanf("%lld",&Z);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> A(X);
    for(int i = 0 ; i < X ; i++){
        scanf("%lld",&A[i]);
    }
    std::vector<long long> B(Y);
    for(int i = 0 ; i < Y ; i++){
        scanf("%lld",&B[i]);
    }
    std::vector<long long> C(Z);
    for(int i = 0 ; i < Z ; i++){
        scanf("%lld",&C[i]);
    }
    solve(X, Y, Z, K, std::move(A), std::move(B), std::move(C));
    return 0;
}

