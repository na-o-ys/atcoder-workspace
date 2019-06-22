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

int main() {
    int n; cin >> n;
    V<P> A(n);
    loop (n, i) {
        int a, b; cin >> a >> b;
        A[i] = { b, a };
    }
    sort(A.begin(), A.end());

    ll crr = 0;
    loop (n, i) {
        crr += A[i].second;
        if (crr > A[i].first) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}

