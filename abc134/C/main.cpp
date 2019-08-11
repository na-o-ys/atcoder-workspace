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
    V<int> A(n);
    loop (n, i) cin >> A[i];
    V<int> B = A;
    sort(B.begin(), B.end());
    int m1 = B[n - 1], m2 = B[n - 2];
    loop (n, i) {
        if (A[i] == m1) cout << m2 << endl;
        else cout << m1 << endl;
    }
    return 0;
}

