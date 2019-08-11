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
    if (n < 3 || ((n - 3) % 4) == 2 || ((n - 3) % 4) == 3) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

    if (((n - 3) % 4) == 0) {
        loop1 (2, i) {
            cout << i << " " << i + 1 << endl;
        }
        cout << 3 << " " << n + 1 << endl;
        loop1 (2, i) {
            cout << n + i << " " << n + i + 1 << endl;
        }

        int prev = n + 3;

        loop1 ((n - 3) / 4, i) {
            cout << prev << " " << 4 * i << endl;
            cout << 4 * i << " " << 4 * i + 1 << endl;
            cout << 4 * i + 1 << " " << 4 * i + 2 << endl;
            cout << 4 * i + 2 << " " << 4 * i + 3 << endl;
            cout << 4 * i + 3 << " " << n + 4 * i << endl;
            cout << n + 4 * i << " " << n + 4 * i + 1 << endl;
            cout << n + 4 * i + 1 << " " << n + 4 * i + 2 << endl;
            cout << n + 4 * i + 2 << " " << n + 4 * i + 3 << endl;
            prev = n + 4 * i + 3;
        }
    } else {
        loop1 (2, i) {
            cout << i << " " << i + 1 << endl;
        }
        cout << 3 << " " << n + 1 << endl;
        loop1 (2, i) {
            cout << n + i << " " << n + i + 1 << endl;
        }

        int prev = n + 3;

        loop1 ((n - 3) / 4, i) {
            cout << prev << " " << 4 * i << endl;
            cout << 4 * i << " " << 4 * i + 1 << endl;
            cout << 4 * i + 1 << " " << 4 * i + 2 << endl;
            cout << 4 * i + 2 << " " << 4 * i + 3 << endl;
            cout << 4 * i + 3 << " " << n + 4 * i << endl;
            cout << n + 4 * i << " " << n + 4 * i + 1 << endl;
            cout << n + 4 * i + 1 << " " << n + 4 * i + 2 << endl;
            cout << n + 4 * i + 2 << " " << n + 4 * i + 3 << endl;
            prev = n + 4 * i + 3;
        }
    }

    return 0;
}


