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
    ll s; cin >> s;
    ll y2 = ((ll) pow(s, 0.5));
    if (y2 * y2 < s) y2++;
    ll x2 = y2 * y2 - s;
    cout << 0 << " " << 0 << " ";
    cout << x2 << " " << y2 << " ";
    cout << y2 << " " << 1 << endl;
    return 0;
}
