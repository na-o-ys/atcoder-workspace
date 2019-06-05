#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define loop1(n, i) for(int i=1;i<=n;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;


void solve(long long N, long long M, std::vector<long long> a, std::vector<long long> b, std::vector<long long> c, std::vector<long long> d){

}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> a(N-1);
    std::vector<long long> b(N-1);
    for(int i = 0 ; i < N-1 ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
    }
    std::vector<long long> c(M);
    std::vector<long long> d(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&c[i]);
        scanf("%lld",&d[i]);
    }
    solve(N, M, std::move(a), std::move(b), std::move(c), std::move(d));
    return 0;
}

