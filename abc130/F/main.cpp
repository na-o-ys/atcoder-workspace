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
const ll INF = 1LL<<40;

int main() {
    int n; cin >> n;
    char D[4] = { 'R', 'L', 'U', 'D' };
    V<long double> Xmin(4, INF), Xmax(4, -INF), Ymin(4, INF), Ymax(4, -INF);
    int hit[4] = {};
    loop (n, i) {
        long double x, y;
        char d;
        cin >> x >> y >> d;
        int di = 0;
        while (D[di] != d) di++;
        hit[di] = 1;
        Xmin[di] = min(Xmin[di], x);
        Xmax[di] = max(Xmax[di], x);
        Ymin[di] = min(Ymin[di], y);
        Ymax[di] = max(Ymax[di], y);
    }
    
    V<long double> T;

    T.push_back((1.0 * Xmin[1] - Xmin[0]) / 2);
    T.push_back(Xmin[2] - Xmin[0]);
    T.push_back(Xmin[3] - Xmin[0]);
    T.push_back(Xmin[1] - Xmin[2]);
    T.push_back(Xmin[1] - Xmin[3]);

    T.push_back((1.0 * Xmax[1] - Xmax[0]) / 2);
    T.push_back(Xmax[2] - Xmax[0]);
    T.push_back(Xmax[3] - Xmax[0]);
    T.push_back(Xmax[1] - Xmax[2]);
    T.push_back(Xmax[1] - Xmax[3]);

    T.push_back((1.0 * Ymin[3] - Ymin[2]) / 2);
    T.push_back(Ymin[0] - Ymin[2]);
    T.push_back(Ymin[1] - Ymin[2]);
    T.push_back(Ymin[3] - Ymin[0]);
    T.push_back(Ymin[3] - Ymin[1]);

    T.push_back((1.0 * Ymax[3] - Ymax[2]) / 2);
    T.push_back(Ymax[0] - Ymax[2]);
    T.push_back(Ymax[1] - Ymax[2]);
    T.push_back(Ymax[3] - Ymax[0]);
    T.push_back(Ymax[3] - Ymax[1]);

    sort(T.begin(), T.end());

    long double ans = INF;
    for (auto t : T) {
        if (t < 0) continue;

        long double r = -INF, l = INF, u = -INF, d = INF;

        if (hit[0]) {
            r = max(r, Xmax[0] + t);
            l = min(l, Xmin[0] + t);
            u = max(u, Ymax[0]);
            d = min(d, Ymin[0]);
        }

        if (hit[1]) {
            r = max(r, Xmax[1] - t);
            l = min(l, Xmin[1] - t);
            u = max(u, Ymax[1]);
            d = min(d, Ymin[1]);
        }

        if (hit[2]) {
            r = max(r, Xmax[2]);
            l = min(l, Xmin[2]);
            u = max(u, Ymax[2] + t);
            d = min(d, Ymin[2] + t);
        }

        if (hit[3]) {
            r = max(r, Xmax[3]);
            l = min(l, Xmin[3]);
            u = max(u, Ymax[3] - t);
            d = min(d, Ymin[3] - t);
        }

        ans = min(ans, (r - l) * (u - d));
    }

    cout << fixed << setprecision(14);
    cout << ans << endl;
    return 0;
}

