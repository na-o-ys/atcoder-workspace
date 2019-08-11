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
using P = pair<int, int>;

int n, m;
V<P> G[100010];
int vis[100010] = {};
int evis[100010] = {};
V<P> A;

int dfs(int crr) {
    vis[crr] = 1;
    V<P> E;
    int children = 0;

    for (auto next : G[crr]) {
        if (vis[next.first]) {
            E.push_back(next);
            continue;
        }
        evis[next.second] = 1;
        if (dfs(next.first)) {
            children++;
            A.push_back({ crr, next.first });
        } else {
            A.push_back({ next.first, crr });
        }
    }

    for (auto e : E) {
        if (evis[e.second]) continue;
        evis[e.second] = 1;
        children++;
        A.push_back({ crr, e.first });
    }

    return (children % 2) == 0;
}

int main() {
    cin >> n >> m;
    loop (m, i) {
        int a, b; cin >> a >> b;
        G[a].push_back({ b, i });
        G[b].push_back({ a, i });
    }

    if (dfs(1)) {
        for (auto a : A) {
            cout << a.first << " " << a.second << endl;
        }
    } else {
        cout << -1 << endl;
    }
    return 0;
}

