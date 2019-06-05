#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;
using P = pair<ll, ll>;

const long long MOD = 1000000007;

void solve(long long N, long long Q, std::vector<long long> A, std::vector<long long> X, std::vector<long long> Y){

}

int main(){
    long long N;
    scanf("%lld",&N);
    long long Q;
    scanf("%lld",&Q);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    std::vector<long long> X(Q);
    std::vector<long long> Y(Q);
    for(int i = 0 ; i < Q ; i++){
        scanf("%lld",&X[i]);
        scanf("%lld",&Y[i]);
    }
    solve(N, Q, std::move(A), std::move(X), std::move(Y));
    return 0;
}

