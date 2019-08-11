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

V<V<int>> G;

int main() {
    int n, m; cin >> n >> m;
    G = V<V<int>>(n * 3, V<int>(0));
    loop (m, i) {
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].push_back(n + v);
        G[n + u].push_back(2 * n + v);
        G[2 * n + u].push_back(v);
    }

    int s, t; cin >> s >> t;
    s--, t--;

    queue<int> Q;
    Q.push(s);

    V<int> dis(n * 3 + 1, -1);
    dis[s] = 0;

    while (1) {
        int u = Q.front();
        Q.pop();
        for (int v : G[u]) {
            if (dis[v] != -1) continue;
            dis[v] = dis[u] + 1;
            Q.push(v);
        }
        if (Q.empty()) break;
    }
    if (dis[t] == -1) cout << -1 << endl;
    else cout << dis[t] / 3 << endl;
    return 0;
}

