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

int n;
V<int> A;
V<int> vis;
int n_vis = 0;

int idx(const V<int>& arr, int x) {
    return distance(arr.begin(), lower_bound(arr.begin(), arr.end(), x));
}

void lis() {
    V<int> L(n, 1000000010);
    V<int> I(n);
    loop (n, i) {
        if (vis[i]) continue;
        I[i] = idx(L, A[i]);
        L[I[i]] = A[i];
    }

    int m = *max_element(I.begin(), I.end());
    for (int i = n - 1; i >= 0; i--) {
        if (I[i] == m) {
            vis[i] = 1;
            n_vis++;
            m--;
        }
    }
}

int main() {
    cin >> n;
    A.resize(n);
    loop (n, i) cin >> A[i];
    vis.resize(n, 0);

    int ans = 0;

    while (n_vis < n) {
        lis();
        ans++;
    }

    cout << ans << endl;
    return 0;
}

