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

const int MAX = 5000 * 5100;
ll G[2][3];
ll dp[MAX];

int main() {
    int n; cin >> n;
    loop (2, i) loop (3, j) cin >> G[i][j];

    fill(dp, dp + MAX, 0);
    loop (n, i) {
        dp[i + 1] = max(dp[i + 1], dp[i] + 1);
        loop (3, j) {
            int k = i + G[0][j];
            dp[k] = max(dp[k], dp[i] + G[1][j]);
        }
    }

    int m = dp[n];
    fill(dp, dp + MAX, 0);
    loop (m, i) {
        dp[i + 1] = max(dp[i + 1], dp[i] + 1);
        loop (3, j) {
            int k = i + G[1][j];
            dp[k] = max(dp[k], dp[i] + G[0][j]);
        }
    }

    cout << dp[m] << endl;
    return 0;
}

