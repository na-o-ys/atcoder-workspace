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
    V<ll> A(n);
    loop (n, i) cin >> A[i];

    ll b = 0;
    loop (n - 1, i) {
        b = A[i] * 2 - b;
    }
    ll a = (A[n - 1] * 2 - b) / 2;
    cout << a;
    loop (n - 1, i) {
        a = A[i] * 2 - a;
        cout << " " << a;
    }
    cout << endl;
    return 0;
}

