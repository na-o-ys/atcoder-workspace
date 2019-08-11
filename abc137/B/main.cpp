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
    int k, x; cin >> k >> x;
    int mi = x - k + 1, ma = x + k - 1;
    cout << mi;
    for (int i = mi + 1; i <= ma; i++) {
        cout << " " << i;
    }
    cout << endl;
    return 0;
}

