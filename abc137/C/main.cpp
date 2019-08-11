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
    int n; cin >> n;
    unordered_map<string, int> M;
    loop (n, i) {
        string s; cin >> s;
        sort(s.begin(), s.end());
        M[s]++;
    }

    ll ans = 0;
    for (auto e : M) {
        ll v = e.second;
        ans += v * (v - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}

