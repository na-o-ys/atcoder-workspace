#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define loop1(n, i) for(int i=1;i<=n;i++)
#define rloop(n, i) for(int i=n;i;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;
const ll MOD = 1000000007LL;
ll dp[2010][2010] = {};

int main() {
    int n, m; cin >> n >> m;
    V<int> S(n), T(m);
    loop (n, i) cin >> S[i];
    loop (m, i) cin >> T[i];

    loop (n + 1, i) dp[i][0] = 1;
    loop (m + 1, i) dp[0][i] = 1;

    loop1 (n, i) {
        ll gt = 0;
        loop1 (m, j) {
            if (T[j - 1] == S[i - 1]) {
                gt = (gt + dp[i - 1][j - 1]) % MOD;
            }
            dp[i][j] = (dp[i - 1][j] + gt) % MOD;
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}

