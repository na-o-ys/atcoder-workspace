#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;
using P = pair<ll, ll>;


void solve(long long N, long long M, std::vector<long long> a){
    sort(a.begin(), a.end());
    int l = 0, r = 2 * N;
    while (l < r) {
        int m = (l + r) / 2;
        if (m % 2) m -= 1;
        int ng = 0;
        for (int i = m; i < 2 * N - 1 - i; i++) {
            ng = a[i] + a[2 * N - 1 - i] >= M;
            if (ng) break;
        }
        if (ng) l = m;
        else r = m;
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> a(2*N);
    for(int i = 0 ; i < 2*N ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, M, std::move(a));
    return 0;
}

