#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define loop1(n, i) for(int i=1;i<=n;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;
using P = pair<int, int>;

int vis[1010][1010] = {};
int dir[] = { -1, 0, 1, 0, -1 };

void solve(long long H, long long W, std::vector<std::string> A){
    V<P> q;
    loop (H, i) loop (W, j) {
        if (A[i][j] == '#') {
            q.push_back({ i, j });
            vis[i][j] = 1;
        }
    }
    int ans = 0;
    while (1) {
        V<P> nxt;
        for (auto p : q) {
            loop (4, di) {
                int i = p.first + dir[di], j = p.second + dir[di + 1];
                if (i < 0 || i >= H || j < 0 || j >= W) continue;
                if (vis[i][j]) continue;
                vis[i][j] = 1;
                nxt.push_back({ i, j });
            }
        }
        if (nxt.empty()) break;
        q = nxt;
        ans++;
    }
    cout << ans << endl;
}

int main(){
    long long H;
    scanf("%lld",&H);
    long long W;
    scanf("%lld",&W);
    std::vector<std::string> A(H);
    for(int i = 0 ; i < H ; i++){
        std::cin >> A[i];
    }
    solve(H, W, std::move(A));
    return 0;
}

