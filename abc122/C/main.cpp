#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;
using P = pair<ll, ll>;


void solve(long long N, long long Q, std::string S, std::vector<long long> l, std::vector<long long> r){
    V<int> C(N + 10);
    loop (N, i) {
        if (i == 0) continue;
        C[i] = C[i - 1];
        if (S[i - 1] == 'A' && S[i] == 'C') {
            C[i] += 1;
        }
    }

    loop (Q, i) {
        r[i]--;
        l[i]--;
        int ans = C[r[i]] - C[l[i]];
        cout << ans << endl;
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long Q;
    scanf("%lld",&Q);
    std::string S;
    std::cin >> S;
    std::vector<long long> l(Q);
    std::vector<long long> r(Q);
    for(int i = 0 ; i < Q ; i++){
        scanf("%lld",&l[i]);
        scanf("%lld",&r[i]);
    }
    solve(N, Q, S, std::move(l), std::move(r));
    return 0;
}

