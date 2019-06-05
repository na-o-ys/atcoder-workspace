#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;
using P = pair<int, int>;

int G[110][110] = {};

void solve(long long N){
    V<P> ans;
    if (N % 2 == 0) {
        loop (N, i) {
            loop (N, j) {
                if (i >= j) continue;
                if (i + j == N - 1) continue;
                ans.push_back({ i, j });
            }
        }
    } else {
        loop (N, i) {
            loop (N, j) {
                if (i >= j) continue;
                if (i + j == N - 2) continue;
                ans.push_back({ i, j });
            }
        }
    }
    cout << ans.size() << endl;
    for (auto p : ans) {
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}

