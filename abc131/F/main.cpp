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

int vis[100010] = {};
V<int> Xi[100010], Yi[100010];
V<int> X, Y;

ll pts;
unordered_set<int> xx, yy;

void rec(int i) {
    if (vis[i]) return;
    vis[i] = 1;
    xx.emplace(X[i]);
    yy.emplace(Y[i]);
    pts++;

    for (int j : Xi[X[i]]) {
        rec(j);
    }
    for (int j : Yi[Y[i]]) {
        rec(j);
    }
} 

int main() {
    int n; cin >> n;
    X = V<int>(n);
    Y = V<int>(n);
    loop (n, i) cin >> X[i] >> Y[i];

    loop (n, i) {
        Xi[X[i]].push_back(i);
        Yi[Y[i]].push_back(i);
    }

    V<int> vis(n);

    ll ans = 0;
    loop (n, i) {
        if (Xi[X[i]].size() >= 2 && Yi[Y[i]].size() >= 2) {
            xx.clear();
            yy.clear();
            pts = 0;
            rec(i);
            ans += xx.size() * yy.size() - pts;
        }
    }

    cout << ans << endl;
    return 0;
}

