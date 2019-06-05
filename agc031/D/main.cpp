#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;
using P = pair<ll, ll>;


void solve(long long N, long long K, std::vector<long long> p, std::vector<long long> q){

}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> p(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&p[i]);
    }
    std::vector<long long> q(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&q[i]);
    }
    solve(N, K, std::move(p), std::move(q));
    return 0;
}

