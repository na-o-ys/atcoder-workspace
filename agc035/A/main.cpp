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
    sort(A.begin(), A.end());
    string YES = "Yes", NO = "No";

    if (n % 3) {
        if (A[n - 1] == 0) {
            cout << YES << endl;
        } else {
            cout << NO << endl;
        }
        return 0;
    }

    if ((A[0] == A[n / 3 - 1] && A[n / 3] == A[n * 2 / 3 - 1] && A[n * 2 / 3] == A[n - 1]) &&
        (A[0] ^ A[n / 3] ^ A[n * 2 / 3]) == 0) {
        cout << YES << endl;
    } else {
        cout << NO << endl;
    }


    return 0;
}

