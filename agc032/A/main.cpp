#include <bits/stdc++.h>
#define loop(n, i) for(int i=0;i<n;i++)
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;
using namespace std;
using ll = long long;
template <class T>
using V = vector<T>;
using P = pair<ll, ll>;



int main(){
    int n; cin >> n;
    int b[200] = {};
    loop (n, i) cin >> b[i];

    int ans[200] = {};
    loop (n, i) {
        int m = n - i;
        int p = -1;
        loop (m, j) {
            int k = m - 1 - j;
            if (b[k] >= b[k + 1] && b[k] == k + 1) {
                p = k;
                break;
            }
        }
        if (p == -1) {
            cout << -1 << endl;
            return 0;
        }
        ans[m - 1] = b[p];
        for (int j = p; j < m; j++) {
            b[j] = b[j + 1];
        }
    }

    loop (n, i) cout << ans[i] << endl;

    return 0;
}

