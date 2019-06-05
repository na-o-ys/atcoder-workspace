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

ll cnt[26] = {};

void solve(long long N, std::string S){
    ll ans = 1;
    for (char c : S) cnt[c - 'a']++;
    loop (26, i) {
        ans = (ans * (cnt[i] + 1)) % MOD;
    }
    cout << ans - 1 << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::string S;
    std::cin >> S;
    solve(N, S);
    return 0;
}

