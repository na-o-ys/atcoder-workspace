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

void solve(long long N, std::vector<long long> A){

}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(2*N);
    for(int i = 0 ; i < 2*N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}

