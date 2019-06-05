#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define loop1(n, i) for(int i=1;i<=n;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;

const long long MOD = 1000000007;

ll P[200010];
ll ans[200010] = {};

void solve(long long N){
    ans[0] = 1;
    fill(P, P + 200010, -1);
    loop1 (N, i) {
        int c; cin >> c;
        ans[i] = ans[i - 1];
        if (P[c] >= 0) {
            int p = P[c];
            if (p <= i - 2) {
                ans[i] = (ans[i] + ans[p]) % MOD;
            }
        }
        P[c] = i;
    }
    cout << ans[N] << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}

