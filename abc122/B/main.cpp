#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;
using P = pair<ll, ll>;


void solve(std::string S){
    int ans = 0;
    loop (S.size(), i) {
        for (int j = i + 1; j <= S.size(); j++) {
            int ng = 0;
            for (int k = i; k < j; k++) {
                if (S[k] != 'A' && S[k] != 'C' && S[k] != 'G' && S[k] != 'T') {
                    ng = 1;
                    break;
                }
            }
            if (!ng) ans = max(ans, j - i);
        }
    }
    cout << ans << endl;
}

int main(){
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}

