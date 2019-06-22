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

int main() {
    int n, k; cin >> n >> k;

    int tr = (n - 1) * (n - 2) / 2;
    if (tr < k) {
        cout << -1 << endl;
        return 0;
    }

    int m = n - 1 + tr - k;
    cout << m << endl;

    loop (n - 1, i) {
        cout << 1 << " " << i + 2 << endl;
    }
    int cnt = 0;
    loop (n - 1, i) loop (n - 1, j) {
        if (i >= j) continue;
        if (cnt >= tr - k) break;
        cout << i + 2 << " " << j + 2 << endl;
        cnt++;
    }
    return 0;
}

