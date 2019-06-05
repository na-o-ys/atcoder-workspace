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

ll dp[110][64] = {};
string S = "ACGT";
void solve(long long N){
    loop (64, i) {
        string s = S.substr((i / 16) % 4, 1) + S.substr((i / 4) % 4, 1) + S.substr(i % 4, 1);
        if (s != "AGC" && s != "GAC" && s != "ACG") {
            dp[3][i] = 1;
        }
    }

    loop (105, i) {
        if (i < 3) continue;
        loop (64, j) {
            int base = (j * 4) % 64;
            string s = S.substr((j / 16) % 4, 1) + S.substr((j / 4) % 4, 1) + S.substr(j % 4, 1);
            string l2 = s.substr(1, 2);
            // +A
            dp[i + 1][base] += dp[i][j];
            dp[i + 1][base] %= MOD;
            // +C
            if (l2 != "AG" && l2 != "GA" && s != "ATG" && s != "AGG" && s != "AGT") {
                dp[i + 1][base + 1] += dp[i][j];
                dp[i + 1][base + 1] %= MOD;
            } 
            // +G
            if (l2 != "AC") {
                dp[i + 1][base + 2] += dp[i][j];
                dp[i + 1][base + 2] %= MOD;
            }
            // +T
            dp[i + 1][base + 3] += dp[i][j];
            dp[i + 1][base + 4] %= MOD;
        }
    }

    ll ans = 0;
    loop (64, i) ans = (ans + dp[N][i]) % MOD;
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}

