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

struct Edge {
    int u;
    int v;
    int cost;
};

const int INF = 1<<29;

int main() {
    int n, m, p; cin >> n >> m >> p;
    V<Edge> E(m);
    loop (m, i) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        E[i] = { a, b, p - c };
    }

    V<int> dist(n, INF);
    dist[0] = 0;
    loop (n - 1, i) {
        loop (E.size(), j) {
            auto e = E[j];
            if (dist[e.u] != INF && dist[e.v] > dist[e.u] + e.cost) {
                dist[e.v] = dist[e.u] + e.cost;
            }
        }
    }

    V<int> vis(n);
    vis[n - 1] = 1;
    loop (n - 1, i) {
        loop (E.size(), j) {
            auto e = E[j];
            if (vis[e.v]) vis[e.u] = 1;
        }
    }

    unordered_set<int> pnts;
    loop (n, i) {
        if (dist[i] < INF && vis[i]) pnts.insert(i);
    }
    loop (E.size(), j) {
        auto e = E[j];
        if (dist[e.v] > dist[e.u] + e.cost) {
            if (pnts.count(e.v)) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << max(0, -dist[n - 1]) << endl;
    return 0;
}

