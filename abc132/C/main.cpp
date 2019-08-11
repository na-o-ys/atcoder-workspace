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
    V<int> D(n);
    loop (n, i) cin >> D[i];

    sort(D.begin(), D.end());

    int m = D.size() / 2;
    cout << D[m] - D[m - 1] << endl;
    return 0;
}

