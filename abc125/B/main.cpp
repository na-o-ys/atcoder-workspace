#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define loop1(n, i) for(int i=1;i<=n;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;


void solve(long long N, std::vector<long long> V, std::vector<long long> C){
    ll ans = 0;
    loop (N, i) {
        if (V[i] > C[i]) ans += V[i] - C[i];
    }
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> V(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&V[i]);
    }
    std::vector<long long> C(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&C[i]);
    }
    solve(N, std::move(V), std::move(C));
    return 0;
}

