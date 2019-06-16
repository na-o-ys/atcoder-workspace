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
    sort(A.begin(), A.end());
    if (n == 2) {
        cout << A[n - 1] - A[0] << endl;
        cout << A[n - 1] << " " << A[0] << endl;
        return 0;
    }

    ll ans = A[n - 1] - A[0];
    loop (n - 2, i) {
        int j = i + 1;
        ans += abs(A[j]);
    }
    cout << ans << endl;

    int n_right = 0;
    loop (n - 2, i) {
        int j = i + 1;
        if (A[j] < 0 && (A[j + 1] >= 0 || j + 1 == n - 1)) n_right = j;
    }
    int positive = A[n - 2] > 0;

    ll m = A[n - 1];
    loop (n - 1, i) {
        if (positive && (i == n_right || i == n - 2)) {
            cout << A[i] << " " << m << endl;
            m = A[i] - m;
        } else {
            cout << m << " " << A[i] << endl;
            m = m - A[i];
        }
    }
    return 0;
}

