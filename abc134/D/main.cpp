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

    V<int> ans(n);
    loop (n, i) {
        int j = n - i;
        ans[j - 1] = A[j - 1];
        for (int k = j * 2; k <= n; k += j) {
            ans[j - 1] ^= ans[k - 1];
        }
    }

    int os = 0;
    V<int> ot;
    loop (n, i) {
        if (ans[i]) {
            os++;
            ot.push_back(i + 1);
        }
    }

    cout << os << endl;
    if (os) {
        cout << ot[0];
        loop (os - 1, i) {
            cout << " " << ot[i + 1];
        }
        cout << endl;
    }
    return 0;
}

