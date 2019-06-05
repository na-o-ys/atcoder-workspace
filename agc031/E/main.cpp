#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;
using P = pair<ll, ll>;


void solve(long long N, std::vector<long long> x, std::vector<long long> y, std::vector<long long> v, long long M, std::vector<std::string> t, std::vector<long long> a, std::vector<long long> b){

}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> x(N);
    std::vector<long long> y(N);
    std::vector<long long> v(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&x[i]);
        scanf("%lld",&y[i]);
        scanf("%lld",&v[i]);
    }
    long long M;
    scanf("%lld",&M);
    std::vector<std::string> t(M);
    std::vector<long long> a(M);
    std::vector<long long> b(M);
    for(int i = 0 ; i < M ; i++){
        std::cin >> t[i];
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
    }
    solve(N, std::move(x), std::move(y), std::move(v), M, std::move(t), std::move(a), std::move(b));
    return 0;
}

