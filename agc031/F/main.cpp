#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;
using P = pair<ll, ll>;

const long long MOD = 2019;
const string YES = "YES";
const string NO = "NO";

void solve(long long N, long long M, long long Q, long long MOD, std::vector<long long> A, std::vector<long long> B, std::vector<long long> C, std::vector<long long> S, std::vector<long long> T, std::vector<long long> R){

}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    long long Q;
    scanf("%lld",&Q);
    long long MOD;
    scanf("%lld",&MOD);
    std::vector<long long> A(M);
    std::vector<long long> B(M);
    std::vector<long long> C(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&A[i]);
        scanf("%lld",&B[i]);
        scanf("%lld",&C[i]);
    }
    std::vector<long long> S(Q);
    std::vector<long long> T(Q);
    std::vector<long long> R(Q);
    for(int i = 0 ; i < Q ; i++){
        scanf("%lld",&S[i]);
        scanf("%lld",&T[i]);
        scanf("%lld",&R[i]);
    }
    solve(N, M, Q, MOD, std::move(A), std::move(B), std::move(C), std::move(S), std::move(T), std::move(R));
    return 0;
}

